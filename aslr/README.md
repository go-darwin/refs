# Disable ASRL on macOS

## References

### via debbugger

- [Disable ASLR when debugging with LLDB on macOS](http://www.jakubkonka.com/2021/02/05/lldb-disable-aslr-macos.html)

in `lldbinit`:

```gdb
settings set target.disable-aslr false
```

### Use posix_spawnattr_setflags

- [Disable ASLR on MacOSX](https://gist.github.com/YukiSakamoto/3776193)


## How to make sure ASRL can be disabled on macOS

First, make sure `src/random.c` will outputs pointer registers randomly.

```console
$ clang -o ./src/random ./src/random.c
$ for i in $(seq 1 10); do ./src/random; done
main: 0x10c234f40, here: 0x10c234f64
main: 0x1071a4f40, here: 0x1071a4f64
main: 0x105351f40, here: 0x105351f64
main: 0x103f3ff40, here: 0x103f3ff64
main: 0x108d66f40, here: 0x108d66f64
main: 0x10a807f40, here: 0x10a807f64
main: 0x102d8df40, here: 0x102d8df64
main: 0x1077b6f40, here: 0x1077b6f64
main: 0x107e4ff40, here: 0x107e4ff64
main: 0x1043d7f40, here: 0x1043d7f64
```

Second, a test that can be disabled ASRL if run the `random.c` program via `src/spawn.c`.

```console
$ clang -o ./src/spawn ./src/spawn.c
$ for i in $(seq 1 10); do ./src/spawn; done
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
main: 0x100003f40, here: 0x100003f64
```

As a result, `posix_spawnattr_setflags` can be disabled ASRL with `POSIX_SPAWN_SETEXEC` and `_POSIX_SPAWN_DISABLE_ASLR(0x0100)` flags.


## Inside Docker container

On Docker for Mac:

```console
# enter docker vm
$ docker container run -it --rm --privileged --pid=host tonistiigi/nsenter:v2.35
# disable ASLR
$ echo 0  > /proc/sys/kernel/randomize_va_space 
# enable ASLR
$ echo 2  > /proc/sys/kernel/randomize_va_space 
```

For `tonistiigi/nsenter`, see:

- https://github.com/tonistiigi/nsenter

For `justincormack/nsenter1`, see:

- https://gist.github.com/BretFisher/5e1a0c7bcca4c735e716abf62afad389
- https://github.com/justincormack/nsenter1

nsenter1/nsenter1.c

```c
#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

// Reassociate with the most important namespaces of pid 1

int main(int argc, char **argv) {
	char *shell = "/bin/sh";
	char *def[] = {shell, NULL};
	char *cmd = shell;
	char **args = def;
	int fdm = open("/proc/1/ns/mnt", O_RDONLY);
	int fdu = open("/proc/1/ns/uts", O_RDONLY);
	int fdn = open("/proc/1/ns/net", O_RDONLY);
	int fdi = open("/proc/1/ns/ipc", O_RDONLY);
	int froot = open("/proc/1/root", O_RDONLY);

	if (fdm == -1 || fdu == -1 || fdn == -1 || fdi == -1 || froot == -1) {
		fprintf(stderr, "Failed to open /proc/1 files, are you root?\n");
		exit(1);
	}

	if (setns(fdm, 0) == -1) {
		perror("setns:mnt");
		exit(1);
	}
	if (setns(fdu, 0) == -1) {
		perror("setns:uts");
		exit(1);
	}
	if (setns(fdn, 0) == -1) {
		perror("setns:net");
		exit(1);
	}
	if (setns(fdi, 0) == -1) {
		perror("setns:ipc");
		exit(1);
	}
	if (fchdir(froot) == -1) {
		perror("fchdir");
		exit(1);
	}
	if (chroot(".") == -1) {
		perror("chroot");
		exit(1);
	}
	if (argc > 1) {
		cmd = argv[1];
		args = argv + 1;
	}
	if (execve(cmd, args, environ) == -1) {
		perror("execve");
		exit(1);
	}
	exit(0);	
}
```

nsenter1/Dockerfile

```dockerfile
FROM alpine:edge as BUILD
RUN apk update && apk add build-base
COPY nsenter1.c ./
RUN cc -Wall -static nsenter1.c -o /usr/bin/nsenter1

FROM scratch
COPY --from=BUILD /usr/bin/nsenter1 /usr/bin/nsenter1
ENTRYPOINT ["/usr/bin/nsenter1"]
```
