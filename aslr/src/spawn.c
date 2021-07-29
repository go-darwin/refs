// https://gist.github.com/YukiSakamoto/3776193
//
//  $ clang -o ./src/spawn ./src/spawn.c

#include <spawn.h>
#include <stdio.h>

int main(void)
{
  int ret;
  short ps_flags = 0;
  pid_t pid;
  posix_spawn_file_actions_t actions;
  posix_spawnattr_t attrs;

  char *args[] = {"./src/random", NULL};

  posix_spawn_file_actions_init(&actions);
  posix_spawnattr_init(&attrs);
#ifndef _POSIX_SPAWN_DISABLE_ASLR
#define _POSIX_SPAWN_DISABLE_ASLR 0x0100
#endif

  ps_flags |= POSIX_SPAWN_SETEXEC;
  ps_flags |= _POSIX_SPAWN_DISABLE_ASLR;
  ret = posix_spawnattr_setflags(&attrs, ps_flags);

  if (ret != 0) {
    printf("cannot set posix_spawn flags\n");
  }

  posix_spawn(&pid, args[0], &actions, &attrs, args, NULL);
  printf("pid: %d\n", pid);
  printf("========================\n");
  return 0;
}
