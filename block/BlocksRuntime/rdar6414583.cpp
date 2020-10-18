#ifndef __OBJC2__
#define __OBJC2__
#endif
struct objc_selector; struct objc_class;
struct __rw_objc_super { 
	struct objc_object *object; 
	struct objc_object *superClass; 
	__rw_objc_super(struct objc_object *o, struct objc_object *s) : object(o), superClass(s) {} 
};
#ifndef _REWRITER_typedef_Protocol
typedef struct objc_object Protocol;
#define _REWRITER_typedef_Protocol
#endif
#define __OBJC_RW_DLLIMPORT extern
__OBJC_RW_DLLIMPORT void objc_msgSend(void);
__OBJC_RW_DLLIMPORT void objc_msgSendSuper(void);
__OBJC_RW_DLLIMPORT void objc_msgSend_stret(void);
__OBJC_RW_DLLIMPORT void objc_msgSendSuper_stret(void);
__OBJC_RW_DLLIMPORT void objc_msgSend_fpret(void);
__OBJC_RW_DLLIMPORT struct objc_class *objc_getClass(const char *);
__OBJC_RW_DLLIMPORT struct objc_class *class_getSuperclass(struct objc_class *);
__OBJC_RW_DLLIMPORT struct objc_class *objc_getMetaClass(const char *);
__OBJC_RW_DLLIMPORT void objc_exception_throw( struct objc_object *);
__OBJC_RW_DLLIMPORT int objc_sync_enter( struct objc_object *);
__OBJC_RW_DLLIMPORT int objc_sync_exit( struct objc_object *);
__OBJC_RW_DLLIMPORT Protocol *objc_getProtocol(const char *);
#ifdef _WIN64
typedef unsigned long long  _WIN_NSUInteger;
#else
typedef unsigned int _WIN_NSUInteger;
#endif
#ifndef __FASTENUMERATIONSTATE
struct __objcFastEnumerationState {
	unsigned long state;
	void **itemsPtr;
	unsigned long *mutationsPtr;
	unsigned long extra[5];
};
__OBJC_RW_DLLIMPORT void objc_enumerationMutation(struct objc_object *);
#define __FASTENUMERATIONSTATE
#endif
#ifndef __NSCONSTANTSTRINGIMPL
struct __NSConstantStringImpl {
  int *isa;
  int flags;
  char *str;
#if _WIN64
  long long length;
#else
  long length;
#endif
};
#ifdef CF_EXPORT_CONSTANT_STRING
extern "C" __declspec(dllexport) int __CFConstantStringClassReference[];
#else
__OBJC_RW_DLLIMPORT int __CFConstantStringClassReference[];
#endif
#define __NSCONSTANTSTRINGIMPL
#endif
#ifndef BLOCK_IMPL
#define BLOCK_IMPL
struct __block_impl {
  void *isa;
  int Flags;
  int Reserved;
  void *FuncPtr;
};
// Runtime copy/destroy helper functions (from Block_private.h)
#ifdef __OBJC_EXPORT_BLOCKS
extern "C" __declspec(dllexport) void _Block_object_assign(void *, const void *, const int);
extern "C" __declspec(dllexport) void _Block_object_dispose(const void *, const int);
extern "C" __declspec(dllexport) void *_NSConcreteGlobalBlock[32];
extern "C" __declspec(dllexport) void *_NSConcreteStackBlock[32];
#else
__OBJC_RW_DLLIMPORT void _Block_object_assign(void *, const void *, const int);
__OBJC_RW_DLLIMPORT void _Block_object_dispose(const void *, const int);
__OBJC_RW_DLLIMPORT void *_NSConcreteGlobalBlock[32];
__OBJC_RW_DLLIMPORT void *_NSConcreteStackBlock[32];
#endif
#endif
#define __block
#define __weak

#include <stdarg.h>
struct __NSContainer_literal {
  void * *arr;
  __NSContainer_literal (unsigned int count, ...) {
	va_list marker;
	va_start(marker, count);
	arr = new void *[count];
	for (unsigned i = 0; i < count; i++)
	  arr[i] = va_arg(marker, void *);
	va_end( marker );
  };
  ~__NSContainer_literal() {
	delete[] arr;
  }
};
extern "C" __declspec(dllimport) void * objc_autoreleasePoolPush(void);
extern "C" __declspec(dllimport) void objc_autoreleasePoolPop(void *);

struct __AtAutoreleasePool {
  __AtAutoreleasePool() {atautoreleasepoolobj = objc_autoreleasePoolPush();}
  ~__AtAutoreleasePool() {objc_autoreleasePoolPop(atautoreleasepoolobj);}
  void * atautoreleasepoolobj;
};

#define __OFFSETOFIVAR__(TYPE, MEMBER) ((long long) &((TYPE *)0)->MEMBER)
typedef void (*os_function_t)(void *_Nullable);
typedef void (*os_block_t)(void);











typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;





typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;







typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;





typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;


typedef int64_t register_t;






typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;



typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];


struct __darwin_pthread_handler_rec {
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_cond_t {
 long __sig;
 char __opaque[40];
};

struct _opaque_pthread_condattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_mutex_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_once_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
 long __sig;
 char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
 long __sig;
 char __opaque[16];
};

struct _opaque_pthread_t {
 long __sig;
 struct __darwin_pthread_handler_rec *__cleanup_stack;
 char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;

static inline
__uint16_t
_OSSwapInt16(
 __uint16_t _data
 )
{
 return (__uint16_t)((_data << 8) | (_data >> 8));
}

static inline
__uint32_t
_OSSwapInt32(
 __uint32_t _data
 )
{

 return __builtin_bswap32(_data);




}


static inline
__uint64_t
_OSSwapInt64(
 __uint64_t _data
 )
{
 return __builtin_bswap64(_data);
}


typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef unsigned long u_long;


typedef unsigned short ushort;
typedef unsigned int uint;


typedef u_int64_t u_quad_t;
typedef int64_t quad_t;
typedef quad_t * qaddr_t;


typedef char * caddr_t;

typedef int32_t daddr_t;


typedef __darwin_dev_t dev_t;

typedef u_int32_t fixpt_t;


typedef __darwin_blkcnt_t blkcnt_t;
typedef __darwin_blksize_t blksize_t;
typedef __darwin_gid_t gid_t;
typedef __uint32_t in_addr_t;
typedef __uint16_t in_port_t;
typedef __darwin_ino_t ino_t;


typedef __darwin_ino64_t ino64_t;


typedef __int32_t key_t;
typedef __darwin_mode_t mode_t;
typedef __uint16_t nlink_t;
typedef __darwin_id_t id_t;
typedef __darwin_pid_t pid_t;
typedef __darwin_off_t off_t;

typedef int32_t segsz_t;
typedef int32_t swblk_t;


typedef __darwin_uid_t uid_t;
static inline __int32_t
major(__uint32_t _x)
{
 return (__int32_t)(((__uint32_t)_x >> 24) & 0xff);
}

static inline __int32_t
minor(__uint32_t _x)
{
 return (__int32_t)((_x) & 0xffffff);
}

static inline dev_t
makedev(__uint32_t _major, __uint32_t _minor)
{
 return (dev_t)(((_major) << 24) | (_minor));
}
typedef __darwin_clock_t clock_t;
typedef __darwin_size_t size_t;
typedef __darwin_ssize_t ssize_t;
typedef __darwin_time_t time_t;

typedef __darwin_useconds_t useconds_t;
typedef __darwin_suseconds_t suseconds_t;


typedef __darwin_size_t rsize_t;
typedef int errno_t;








extern "C" {
typedef struct fd_set {
 __int32_t fds_bits[((((1024) % ((sizeof(__int32_t) * 8))) == 0) ? ((1024) / ((sizeof(__int32_t) * 8))) : (((1024) / ((sizeof(__int32_t) * 8))) + 1))];
} fd_set;

int __darwin_check_fd_set_overflow(int, const void *, int) __attribute__((availability(macosx,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)));
}

inline __attribute__ ((__always_inline__)) int
__darwin_check_fd_set(int _a, const void *_b)
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunguarded-availability-new"

 if ((uintptr_t)&__darwin_check_fd_set_overflow != (uintptr_t) 0) {



  return __darwin_check_fd_set_overflow(_a, _b, 0);

 } else {
  return 1;
 }

#pragma clang diagnostic pop

}


inline __attribute__ ((__always_inline__)) int
__darwin_fd_isset(int _fd, const struct fd_set *_p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  return _p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] & ((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8))));
 }

 return 0;
}

inline __attribute__ ((__always_inline__)) void
__darwin_fd_set(int _fd, struct fd_set *const _p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  (_p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] |= ((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8)))));
 }
}

inline __attribute__ ((__always_inline__)) void
__darwin_fd_clr(int _fd, struct fd_set *const _p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  (_p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] &= ~((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8)))));
 }
}




typedef __int32_t fd_mask;










typedef __darwin_pthread_attr_t pthread_attr_t;
typedef __darwin_pthread_cond_t pthread_cond_t;
typedef __darwin_pthread_condattr_t pthread_condattr_t;
typedef __darwin_pthread_mutex_t pthread_mutex_t;
typedef __darwin_pthread_mutexattr_t pthread_mutexattr_t;
typedef __darwin_pthread_once_t pthread_once_t;
typedef __darwin_pthread_rwlock_t pthread_rwlock_t;
typedef __darwin_pthread_rwlockattr_t pthread_rwlockattr_t;
typedef __darwin_pthread_t pthread_t;



typedef __darwin_pthread_key_t pthread_key_t;




typedef __darwin_fsblkcnt_t fsblkcnt_t;
typedef __darwin_fsfilcnt_t fsfilcnt_t;
typedef long int ptrdiff_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef long int intmax_t;
typedef long unsigned int uintmax_t;
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;






extern "C" {
void *memchr(const void *__s, int __c, size_t __n);
int memcmp(const void *__s1, const void *__s2, size_t __n);
void *memcpy(void *__dst, const void *__src, size_t __n);
void *memmove(void *__dst, const void *__src, size_t __len);
void *memset(void *__b, int __c, size_t __len);
char *strcat(char *__s1, const char *__s2);
char *strchr(const char *__s, int __c);
int strcmp(const char *__s1, const char *__s2);
int strcoll(const char *__s1, const char *__s2);
char *strcpy(char *__dst, const char *__src);
size_t strcspn(const char *__s, const char *__charset);
char *strerror(int __errnum) __asm("_" "strerror" );
size_t strlen(const char *__s);
char *strncat(char *__s1, const char *__s2, size_t __n);
int strncmp(const char *__s1, const char *__s2, size_t __n);
char *strncpy(char *__dst, const char *__src, size_t __n);
char *strpbrk(const char *__s, const char *__charset);
char *strrchr(const char *__s, int __c);
size_t strspn(const char *__s, const char *__charset);
char *strstr(const char *__big, const char *__little);
char *strtok(char *__str, const char *__sep);
size_t strxfrm(char *__s1, const char *__s2, size_t __n);
}
extern "C" {
char *strtok_r(char *__str, const char *__sep, char **__lasts);
}
extern "C" {
int strerror_r(int __errnum, char *__strerrbuf, size_t __buflen);
char *strdup(const char *__s1);
void *memccpy(void *__dst, const void *__src, int __c, size_t __n);
}
extern "C" {
char *stpcpy(char *__dst, const char *__src);
char *stpncpy(char *__dst, const char *__src, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strndup(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
size_t strnlen(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strsignal(int __sig);
}
extern "C" {
errno_t memset_s(void *__s, rsize_t __smax, int __c, rsize_t __n) __attribute__((availability(macosx,introduced=10.9)));
}







extern "C" {
void *memmem(const void *__big, size_t __big_len, const void *__little, size_t __little_len) __attribute__((availability(macosx,introduced=10.7)));
void memset_pattern4(void *__b, const void *__pattern4, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern8(void *__b, const void *__pattern8, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern16(void *__b, const void *__pattern16, size_t __len) __attribute__((availability(macosx,introduced=10.5)));

char *strcasestr(const char *__big, const char *__little);
char *strnstr(const char *__big, const char *__little, size_t __len);
size_t strlcat(char *__dst, const char *__source, size_t __size);
size_t strlcpy(char *__dst, const char *__source, size_t __size);
void strmode(int __mode, char *__bp);
char *strsep(char **__stringp, const char *__delim);


void swab(const void * , void * , ssize_t);

__attribute__((availability(macosx,introduced=10.12.1))) __attribute__((availability(ios,introduced=10.1)))
__attribute__((availability(tvos,introduced=10.0.1))) __attribute__((availability(watchos,introduced=3.1)))
int timingsafe_bcmp(const void *__b1, const void *__b2, size_t __len);

__attribute__((availability(macosx,introduced=11.0))) __attribute__((availability(ios,introduced=14.0)))
__attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
int strsignal_r(int __sig, char *__strsignalbuf, size_t __buflen);
}







extern "C" {


int bcmp(const void *, const void *, size_t) ;
void bcopy(const void *, void *, size_t) ;
void bzero(void *, size_t) ;
char *index(const char *, int) ;
char *rindex(const char *, int) ;


int ffs(int);
int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);
}



extern "C" {
int ffsl(long) __attribute__((availability(macosx,introduced=10.5)));
int ffsll(long long) __attribute__((availability(macosx,introduced=10.9)));
int fls(int) __attribute__((availability(macosx,introduced=10.5)));
int flsl(long) __attribute__((availability(macosx,introduced=10.5)));
int flsll(long long) __attribute__((availability(macosx,introduced=10.9)));
}



struct accessx_descriptor {
 unsigned int ad_name_offset;
 int ad_flags;
 int ad_pad[2];
};
extern "C" {

int getattrlistbulk(int, void *, void *, size_t, uint64_t) __attribute__((availability(macosx,introduced=10.10)));
int getattrlistat(int, const char *, void *, void *, size_t, unsigned long) __attribute__((availability(macosx,introduced=10.10)));
int setattrlistat(int, const char *, void *, void *, size_t, uint32_t) __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));

}
extern "C" {

int faccessat(int, const char *, int, int) __attribute__((availability(macosx,introduced=10.10)));
int fchownat(int, const char *, uid_t, gid_t, int) __attribute__((availability(macosx,introduced=10.10)));
int linkat(int, const char *, int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));
ssize_t readlinkat(int, const char *, char *, size_t) __attribute__((availability(macosx,introduced=10.10)));
int symlinkat(const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));
int unlinkat(int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));

}
extern "C" {
void _exit(int) __attribute__((__noreturn__));
int access(const char *, int);
unsigned int
  alarm(unsigned int);
int chdir(const char *);
int chown(const char *, uid_t, gid_t);

int close(int) __asm("_" "close" );

int dup(int);
int dup2(int, int);
int execl(const char * __path, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execle(const char * __path, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execlp(const char * __file, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execv(const char * __path, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execve(const char * __file, char * const * __argv, char * const * __envp) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execvp(const char * __file, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
pid_t fork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
long fpathconf(int, int);
char *getcwd(char *, size_t);
gid_t getegid(void);
uid_t geteuid(void);
gid_t getgid(void);



int getgroups(int, gid_t []);

char *getlogin(void);
pid_t getpgrp(void);
pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
int isatty(int);
int link(const char *, const char *);
off_t lseek(int, off_t, int);
long pathconf(const char *, int);

int pause(void) __asm("_" "pause" );

int pipe(int [2]);

ssize_t read(int, void *, size_t) __asm("_" "read" );

int rmdir(const char *);
int setgid(gid_t);
int setpgid(pid_t, pid_t);
pid_t setsid(void);
int setuid(uid_t);

unsigned int
  sleep(unsigned int) __asm("_" "sleep" );

long sysconf(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);
char *ttyname(int);


int ttyname_r(int, char *, size_t) __asm("_" "ttyname_r" );




int unlink(const char *);

ssize_t write(int __fd, const void * __buf, size_t __nbyte) __asm("_" "write" );
}
extern "C" {
size_t confstr(int, char *, size_t) __asm("_" "confstr" );

int getopt(int, char * const [], const char *) __asm("_" "getopt" );

extern char *optarg;
extern int optind, opterr, optopt;
}
extern "C" {

char *ctermid(char *);

}






 extern "C" {





__attribute__((__deprecated__)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *brk(const void *);
int chroot(const char *) ;


char *crypt(const char *, const char *);

void encrypt(char *, int) __asm("_" "encrypt" );



int fchdir(int);
long gethostid(void);
pid_t getpgid(pid_t);
pid_t getsid(pid_t);



int getdtablesize(void) ;
int getpagesize(void) __attribute__((__const__)) ;
char *getpass(const char *) ;




char *getwd(char *) ;


int lchown(const char *, uid_t, gid_t) __asm("_" "lchown" );

int lockf(int, int, off_t) __asm("_" "lockf" );

int nice(int) __asm("_" "nice" );

ssize_t pread(int __fd, void * __buf, size_t __nbyte, off_t __offset) __asm("_" "pread" );

ssize_t pwrite(int __fd, const void * __buf, size_t __nbyte, off_t __offset) __asm("_" "pwrite" );






__attribute__((__deprecated__)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *sbrk(int);



pid_t setpgrp(void) __asm("_" "setpgrp" );




int setregid(gid_t, gid_t) __asm("_" "setregid" );

int setreuid(uid_t, uid_t) __asm("_" "setreuid" );

void swab(const void * , void * , ssize_t);
void sync(void);
int truncate(const char *, off_t);
useconds_t ualarm(useconds_t, useconds_t);
int usleep(useconds_t) __asm("_" "usleep" );
pid_t vfork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));


int fsync(int) __asm("_" "fsync" );

int ftruncate(int, off_t);
int getlogin_r(char *, size_t);
}
extern "C" {
int fchown(int, uid_t, gid_t);
int gethostname(char *, size_t);
ssize_t readlink(const char * , char * , size_t);
int setegid(gid_t);
int seteuid(uid_t);
int symlink(const char *, const char *);
}








struct timespec
{
 __darwin_time_t tv_sec;
 long tv_nsec;
};
struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};








typedef __darwin_sigset_t sigset_t;
extern "C" {


int pselect(int, fd_set * , fd_set * ,
    fd_set * , const struct timespec * ,
    const sigset_t * )




__asm("_" "pselect" "$1050")




;



int select(int, fd_set * , fd_set * ,
    fd_set * , struct timeval * )





__asm("_" "select" "$1050")




;

}



typedef __darwin_uuid_t uuid_t;

extern "C" {
void _Exit(int) __attribute__((__noreturn__));
int accessx_np(const struct accessx_descriptor *, size_t, int *, uid_t);
int acct(const char *);
int add_profil(char *, size_t, unsigned long, unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
void endusershell(void);
int execvP(const char * __file, const char * __searchpath, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *fflagstostr(unsigned long);
int getdomainname(char *, int);
int getgrouplist(const char *, int, int *, int *);





int gethostuuid(uuid_t, const struct timespec *) __attribute__((availability(macosx,introduced=10.5)));




mode_t getmode(const void *, mode_t);
int getpeereid(int, uid_t *, gid_t *);
int getsgroups_np(int *, uuid_t);
char *getusershell(void);
int getwgroups_np(int *, uuid_t);
int initgroups(const char *, int);
int issetugid(void);
char *mkdtemp(char *);
int mknod(const char *, mode_t, dev_t);
int mkpath_np(const char *path, mode_t omode) __attribute__((availability(macosx,introduced=10.8)));
int mkpathat_np(int dfd, const char *path, mode_t omode)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int mkstemp(char *);
int mkstemps(char *, int);
char *mktemp(char *);
int mkostemp(char *path, int oflags)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int mkostemps(char *path, int slen, int oflags)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));

int mkstemp_dprotected_np(char *path, int dpclass, int dpflags)
  __attribute__((availability(macosx,unavailable))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
char *mkdtempat_np(int dfd, char *path)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int mkstempsat_np(int dfd, char *path, int slen)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int mkostempsat_np(int dfd, char *path, int slen, int oflags)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int nfssvc(int, void *);
int profil(char *, size_t, unsigned long, unsigned int);

__attribute__((__deprecated__("Use of per-thread security contexts is error-prone and discouraged.")))
int pthread_setugid_np(uid_t, gid_t);
int pthread_getugid_np( uid_t *, gid_t *);

int reboot(int);
int revoke(const char *);

__attribute__((__deprecated__)) int rcmd(char **, int, const char *, const char *, const char *, int *);
__attribute__((__deprecated__)) int rcmd_af(char **, int, const char *, const char *, const char *, int *,
  int);
__attribute__((__deprecated__)) int rresvport(int *);
__attribute__((__deprecated__)) int rresvport_af(int *, int);
__attribute__((__deprecated__)) int iruserok(unsigned long, int, const char *, const char *);
__attribute__((__deprecated__)) int iruserok_sa(const void *, int, int, const char *, const char *);
__attribute__((__deprecated__)) int ruserok(const char *, int, const char *, const char *);

int setdomainname(const char *, int);
int setgroups(int, const gid_t *);
void sethostid(long);
int sethostname(const char *, int);

void setkey(const char *) __asm("_" "setkey" );



int setlogin(const char *);
void *setmode(const char *) __asm("_" "setmode" );
int setrgid(gid_t);
int setruid(uid_t);
int setsgroups_np(int, const uuid_t);
void setusershell(void);
int setwgroups_np(int, const uuid_t);
int strtofflags(char **, unsigned long *, unsigned long *);
int swapon(const char *);
int ttyslot(void);
int undelete(const char *);
int unwhiteout(const char *);
void *valloc(size_t);

__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
__attribute__((availability(ios,deprecated=10.0,message="syscall(2) is unsupported; " "please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost().")))

__attribute__((availability(macosx,deprecated=10.12,message="syscall(2) is unsupported; " "please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost().")))

int syscall(int, ...);

extern char *suboptarg;
int getsubopt(char **, char * const *, char **);



int fgetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int fsetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int getattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "getattrlist" );
int setattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "setattrlist" );
int exchangedata(const char*,const char*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int getdirentriesattr(int,void*,void*,size_t,unsigned int*,unsigned int*,unsigned int*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
struct fssearchblock;
struct searchstate;

int searchfs(const char *, struct fssearchblock *, unsigned long *, unsigned int, unsigned int, struct searchstate *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int fsctl(const char *,unsigned long,void*,unsigned int);
int ffsctl(int,unsigned long,void*,unsigned int) __attribute__((availability(macosx,introduced=10.6)));




int fsync_volume_np(int, int) __attribute__((availability(macosx,introduced=10.8)));
int sync_volume_np(const char *, int) __attribute__((availability(macosx,introduced=10.8)));

extern int optreset;

}






struct flock {
 off_t l_start;
 off_t l_len;
 pid_t l_pid;
 short l_type;
 short l_whence;
};
struct flocktimeout {
 struct flock fl;
 struct timespec timeout;
};
struct radvisory {
 off_t ra_offset;
 int ra_count;
};
typedef struct fsignatures {
 off_t fs_file_start;
 void *fs_blob_start;
 size_t fs_blob_size;



 size_t fs_fsignatures_size;
 char fs_cdhash[20];
 int fs_hash_type;
} fsignatures_t;

typedef struct fsupplement {
 off_t fs_file_start;
 off_t fs_blob_start;
 size_t fs_blob_size;
 int fs_orig_fd;
} fsupplement_t;
typedef struct fchecklv {
 off_t lv_file_start;
 size_t lv_error_message_size;
 void *lv_error_message;
} fchecklv_t;
typedef struct fgetsigsinfo {
 off_t fg_file_start;
 int fg_info_request;
 int fg_sig_is_platform;
} fgetsigsinfo_t;
typedef struct fstore {
 unsigned int fst_flags;
 int fst_posmode;
 off_t fst_offset;
 off_t fst_length;
 off_t fst_bytesalloc;
} fstore_t;


typedef struct fpunchhole {
 unsigned int fp_flags;
 unsigned int reserved;
 off_t fp_offset;
 off_t fp_length;
} fpunchhole_t;


typedef struct ftrimactivefile {
 off_t fta_offset;
 off_t fta_length;
} ftrimactivefile_t;


typedef struct fspecread {
 unsigned int fsr_flags;
 unsigned int reserved;
 off_t fsr_offset;
 off_t fsr_length;
} fspecread_t;



typedef struct fbootstraptransfer {
 off_t fbt_offset;
 size_t fbt_length;
 void *fbt_buffer;
} fbootstraptransfer_t;
#pragma pack(4)

struct log2phys {
 unsigned int l2p_flags;
 off_t l2p_contigbytes;


 off_t l2p_devoffset;


};

#pragma pack()
struct _filesec;
typedef struct _filesec *filesec_t;

typedef enum {
 FILESEC_OWNER = 1,
 FILESEC_GROUP = 2,
 FILESEC_UUID = 3,
 FILESEC_MODE = 4,
 FILESEC_ACL = 5,
 FILESEC_GRPUUID = 6,


 FILESEC_ACL_RAW = 100,
 FILESEC_ACL_ALLOCSIZE = 101
} filesec_property_t;





extern "C" {
int open(const char *, int, ...) __asm("_" "open" );

int openat(int, const char *, int, ...) __asm("_" "openat" ) __attribute__((availability(macosx,introduced=10.10)));

int creat(const char *, mode_t) __asm("_" "creat" );
int fcntl(int, int, ...) __asm("_" "fcntl" );


int openx_np(const char *, int, filesec_t);




int open_dprotected_np( const char *, int, int, int, ...);
int flock(int, int);
filesec_t filesec_init(void);
filesec_t filesec_dup(filesec_t);
void filesec_free(filesec_t);
int filesec_get_property(filesec_t, filesec_property_t, void *);
int filesec_query_property(filesec_t, filesec_property_t, int *);
int filesec_set_property(filesec_t, filesec_property_t, const void *);
int filesec_unset_property(filesec_t, filesec_property_t) __attribute__((availability(macosx,introduced=10.6)));



}




typedef struct objc_class *Class;


struct objc_object {
    Class _Nonnull isa __attribute__((deprecated));
};


typedef struct objc_object *id;



typedef struct objc_selector *SEL;



typedef void (*IMP)(void );
    typedef signed char BOOL;
extern "C" __attribute__((visibility("default"))) const char * _Nonnull sel_getName(SEL _Nonnull sel)
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) SEL _Nonnull sel_registerName(const char * _Nonnull str)
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) const char * _Nonnull object_getClassName(id _Nullable obj)
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) void * _Nullable object_getIndexedIvars(id _Nullable obj)
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) BOOL sel_isMapped(SEL _Nonnull sel)
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
extern "C" __attribute__((visibility("default"))) SEL _Nonnull sel_getUid(const char * _Nonnull str)
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));

typedef const void* objc_objectptr_t;




extern "C" __attribute__((visibility("default"))) id _Nullable objc_retainedObject(objc_objectptr_t _Nullable obj)

    __attribute__((unavailable("use CFBridgingRelease() or a (__bridge_transfer id) cast instead")))

    ;
extern "C" __attribute__((visibility("default"))) id _Nullable objc_unretainedObject(objc_objectptr_t _Nullable obj)

    __attribute__((unavailable("use a (__bridge id) cast instead")))

    ;
extern "C" __attribute__((visibility("default"))) objc_objectptr_t _Nullable objc_unretainedPointer(id _Nullable obj)

    __attribute__((unavailable("use a __bridge cast instead")))

    ;
typedef long NSInteger;
typedef unsigned long NSUInteger;

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif

#ifndef _REWRITER_typedef_NSInvocation
#define _REWRITER_typedef_NSInvocation
typedef struct objc_object NSInvocation;
typedef struct {} _objc_exc_NSInvocation;
#endif


// @protocol NSObject

// - (BOOL)isEqual:(id)object;
// @property (readonly) NSUInteger hash;

// @property (readonly) Class superclass;
// - (Class)class __attribute__((availability(swift, unavailable, message="use 'type(of: anObject)' instead")));
// - (instancetype)self;

// - (id)performSelector:(SEL)aSelector;
// - (id)performSelector:(SEL)aSelector withObject:(id)object;
// - (id)performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2;

// - (BOOL)isProxy;

// - (BOOL)isKindOfClass:(Class)aClass;
// - (BOOL)isMemberOfClass:(Class)aClass;
// - (BOOL)conformsToProtocol:(Protocol *)aProtocol;

// - (BOOL)respondsToSelector:(SEL)aSelector;

// - (instancetype)retain ;
// - (oneway void)release ;
// - (instancetype)autorelease ;
// - (NSUInteger)retainCount ;

// - (struct _NSZone *)zone ;

// @property (readonly, copy) NSString *description;
/* @optional */
// @property (readonly, copy) NSString *debugDescription;

/* @end */



__attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)))
__attribute__((objc_root_class))
extern "C" __attribute__((visibility("default")))

#ifndef _REWRITER_typedef_NSObject
#define _REWRITER_typedef_NSObject
typedef struct objc_object NSObject;
typedef struct {} _objc_exc_NSObject;
#endif

struct NSObject_IMPL {
	Class isa;
};


// + (void)load;

// + (void)initialize;
#if 0
- (instancetype)init

    __attribute__((objc_designated_initializer))

    ;
#endif


// + (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// + (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// + (instancetype)alloc __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// - (void)dealloc __attribute__((availability(swift, unavailable, message="use 'deinit' to define a de-initializer")));

// - (void)finalize __attribute__((deprecated("Objective-C garbage collection is no longer supported")));

// - (id)copy;
// - (id)mutableCopy;

// + (id)copyWithZone:(struct _NSZone *)zone ;
// + (id)mutableCopyWithZone:(struct _NSZone *)zone ;

// + (BOOL)instancesRespondToSelector:(SEL)aSelector;
// + (BOOL)conformsToProtocol:(Protocol *)protocol;
// - (IMP)methodForSelector:(SEL)aSelector;
// + (IMP)instanceMethodForSelector:(SEL)aSelector;
// - (void)doesNotRecognizeSelector:(SEL)aSelector;

// - (id)forwardingTargetForSelector:(SEL)aSelector __attribute__((availability(macosx,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
// - (void)forwardInvocation:(NSInvocation *)anInvocation __attribute__((availability(swift, unavailable, message="")));
// - (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="")));

// + (NSMethodSignature *)instanceMethodSignatureForSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="")));

// - (BOOL)allowsWeakReference __attribute__((unavailable));
// - (BOOL)retainWeakReference __attribute__((unavailable));

// + (BOOL)isSubclassOfClass:(Class)aClass;

// + (BOOL)resolveClassMethod:(SEL)sel __attribute__((availability(macosx,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));
// + (BOOL)resolveInstanceMethod:(SEL)sel __attribute__((availability(macosx,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(watchos,introduced=1.0)));

// + (NSUInteger)hash;
// + (Class)superclass;
// + (Class)class __attribute__((availability(swift, unavailable, message="use 'aClass.self' instead")));
// + (NSString *)description;
// + (NSString *)debugDescription;

/* @end */

extern __attribute__((__visibility__("default")))

#ifndef _REWRITER_typedef_OS_object
#define _REWRITER_typedef_OS_object
typedef struct objc_object OS_object;
typedef struct {} _objc_exc_OS_object;
#endif

struct OS_object_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};
 // - (instancetype)init __attribute__((__availability__(swift, unavailable, message="Unavailable in Swift"))); /* @end */
;
extern "C" {
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((__visibility__("default"))) __attribute__((__availability__(swift, unavailable, message="Can't be used with ARC")))
void*
os_retain(void *object);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((__visibility__("default")))
void __attribute__((__availability__(swift, unavailable, message="Can't be used with ARC")))
os_release(void *object);





}











typedef enum {
 P_ALL,
 P_PID,
 P_PGID
} idtype_t;
typedef int sig_atomic_t;
struct __darwin_i386_thread_state
{
    unsigned int __eax;
    unsigned int __ebx;
    unsigned int __ecx;
    unsigned int __edx;
    unsigned int __edi;
    unsigned int __esi;
    unsigned int __ebp;
    unsigned int __esp;
    unsigned int __ss;
    unsigned int __eflags;
    unsigned int __eip;
    unsigned int __cs;
    unsigned int __ds;
    unsigned int __es;
    unsigned int __fs;
    unsigned int __gs;
};
struct __darwin_fp_control
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
      :2,
    __pc :2,





    __rc :2,






             :1,
      :3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;
struct __darwin_fp_status
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
    __stkflt :1,
    __errsumm :1,
    __c0 :1,
    __c1 :1,
    __c2 :1,
    __tos :3,
    __c3 :1,
    __busy :1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;
struct __darwin_mmst_reg
{
 char __mmst_reg[10];
 char __mmst_rsrv[6];
};
struct __darwin_xmm_reg
{
 char __xmm_reg[16];
};
struct __darwin_ymm_reg
{
 char __ymm_reg[32];
};
struct __darwin_zmm_reg
{
 char __zmm_reg[64];
};
struct __darwin_opmask_reg
{
 char __opmask_reg[8];
};
struct __darwin_i386_float_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
};


struct __darwin_i386_avx_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
};


struct __darwin_i386_avx512_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_opmask_reg __fpu_k0;
 struct __darwin_opmask_reg __fpu_k1;
 struct __darwin_opmask_reg __fpu_k2;
 struct __darwin_opmask_reg __fpu_k3;
 struct __darwin_opmask_reg __fpu_k4;
 struct __darwin_opmask_reg __fpu_k5;
 struct __darwin_opmask_reg __fpu_k6;
 struct __darwin_opmask_reg __fpu_k7;
 struct __darwin_ymm_reg __fpu_zmmh0;
 struct __darwin_ymm_reg __fpu_zmmh1;
 struct __darwin_ymm_reg __fpu_zmmh2;
 struct __darwin_ymm_reg __fpu_zmmh3;
 struct __darwin_ymm_reg __fpu_zmmh4;
 struct __darwin_ymm_reg __fpu_zmmh5;
 struct __darwin_ymm_reg __fpu_zmmh6;
 struct __darwin_ymm_reg __fpu_zmmh7;
};
struct __darwin_i386_exception_state
{
 __uint16_t __trapno;
 __uint16_t __cpu;
 __uint32_t __err;
 __uint32_t __faultvaddr;
};
struct __darwin_x86_debug_state32
{
 unsigned int __dr0;
 unsigned int __dr1;
 unsigned int __dr2;
 unsigned int __dr3;
 unsigned int __dr4;
 unsigned int __dr5;
 unsigned int __dr6;
 unsigned int __dr7;
};


struct __x86_instruction_state
{
        int __insn_stream_valid_bytes;
        int __insn_offset;
 int __out_of_synch;





        __uint8_t __insn_bytes[(2448 - 64 - 4)];

 __uint8_t __insn_cacheline[64];
};


struct __last_branch_record
{
 __uint64_t __from_ip;
 __uint64_t __to_ip;
 __uint32_t __mispredict : 1,
   __tsx_abort : 1,
   __in_tsx : 1,
   __cycle_count: 16,
   __reserved : 13;
};


struct __last_branch_state
{
        int __lbr_count;
 __uint32_t __lbr_supported_tsx : 1,
     __lbr_supported_cycle_count : 1,
     __reserved : 30;

 struct __last_branch_record __lbrs[32];
};
struct __x86_pagein_state
{
 int __pagein_error;
};







struct __darwin_x86_thread_state64
{
 __uint64_t __rax;
 __uint64_t __rbx;
 __uint64_t __rcx;
 __uint64_t __rdx;
 __uint64_t __rdi;
 __uint64_t __rsi;
 __uint64_t __rbp;
 __uint64_t __rsp;
 __uint64_t __r8;
 __uint64_t __r9;
 __uint64_t __r10;
 __uint64_t __r11;
 __uint64_t __r12;
 __uint64_t __r13;
 __uint64_t __r14;
 __uint64_t __r15;
 __uint64_t __rip;
 __uint64_t __rflags;
 __uint64_t __cs;
 __uint64_t __fs;
 __uint64_t __gs;
};
struct __darwin_x86_thread_full_state64
{
 struct __darwin_x86_thread_state64 __ss64;
 __uint64_t __ds;
 __uint64_t __es;
 __uint64_t __ss;
 __uint64_t __gsbase;
};
struct __darwin_x86_float_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
};


struct __darwin_x86_avx_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_xmm_reg __fpu_ymmh8;
 struct __darwin_xmm_reg __fpu_ymmh9;
 struct __darwin_xmm_reg __fpu_ymmh10;
 struct __darwin_xmm_reg __fpu_ymmh11;
 struct __darwin_xmm_reg __fpu_ymmh12;
 struct __darwin_xmm_reg __fpu_ymmh13;
 struct __darwin_xmm_reg __fpu_ymmh14;
 struct __darwin_xmm_reg __fpu_ymmh15;
};


struct __darwin_x86_avx512_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_xmm_reg __fpu_ymmh8;
 struct __darwin_xmm_reg __fpu_ymmh9;
 struct __darwin_xmm_reg __fpu_ymmh10;
 struct __darwin_xmm_reg __fpu_ymmh11;
 struct __darwin_xmm_reg __fpu_ymmh12;
 struct __darwin_xmm_reg __fpu_ymmh13;
 struct __darwin_xmm_reg __fpu_ymmh14;
 struct __darwin_xmm_reg __fpu_ymmh15;
 struct __darwin_opmask_reg __fpu_k0;
 struct __darwin_opmask_reg __fpu_k1;
 struct __darwin_opmask_reg __fpu_k2;
 struct __darwin_opmask_reg __fpu_k3;
 struct __darwin_opmask_reg __fpu_k4;
 struct __darwin_opmask_reg __fpu_k5;
 struct __darwin_opmask_reg __fpu_k6;
 struct __darwin_opmask_reg __fpu_k7;
 struct __darwin_ymm_reg __fpu_zmmh0;
 struct __darwin_ymm_reg __fpu_zmmh1;
 struct __darwin_ymm_reg __fpu_zmmh2;
 struct __darwin_ymm_reg __fpu_zmmh3;
 struct __darwin_ymm_reg __fpu_zmmh4;
 struct __darwin_ymm_reg __fpu_zmmh5;
 struct __darwin_ymm_reg __fpu_zmmh6;
 struct __darwin_ymm_reg __fpu_zmmh7;
 struct __darwin_ymm_reg __fpu_zmmh8;
 struct __darwin_ymm_reg __fpu_zmmh9;
 struct __darwin_ymm_reg __fpu_zmmh10;
 struct __darwin_ymm_reg __fpu_zmmh11;
 struct __darwin_ymm_reg __fpu_zmmh12;
 struct __darwin_ymm_reg __fpu_zmmh13;
 struct __darwin_ymm_reg __fpu_zmmh14;
 struct __darwin_ymm_reg __fpu_zmmh15;
 struct __darwin_zmm_reg __fpu_zmm16;
 struct __darwin_zmm_reg __fpu_zmm17;
 struct __darwin_zmm_reg __fpu_zmm18;
 struct __darwin_zmm_reg __fpu_zmm19;
 struct __darwin_zmm_reg __fpu_zmm20;
 struct __darwin_zmm_reg __fpu_zmm21;
 struct __darwin_zmm_reg __fpu_zmm22;
 struct __darwin_zmm_reg __fpu_zmm23;
 struct __darwin_zmm_reg __fpu_zmm24;
 struct __darwin_zmm_reg __fpu_zmm25;
 struct __darwin_zmm_reg __fpu_zmm26;
 struct __darwin_zmm_reg __fpu_zmm27;
 struct __darwin_zmm_reg __fpu_zmm28;
 struct __darwin_zmm_reg __fpu_zmm29;
 struct __darwin_zmm_reg __fpu_zmm30;
 struct __darwin_zmm_reg __fpu_zmm31;
};
struct __darwin_x86_exception_state64
{
    __uint16_t __trapno;
    __uint16_t __cpu;
    __uint32_t __err;
    __uint64_t __faultvaddr;
};
struct __darwin_x86_debug_state64
{
 __uint64_t __dr0;
 __uint64_t __dr1;
 __uint64_t __dr2;
 __uint64_t __dr3;
 __uint64_t __dr4;
 __uint64_t __dr5;
 __uint64_t __dr6;
 __uint64_t __dr7;
};
struct __darwin_x86_cpmu_state64
{
 __uint64_t __ctrs[16];
};




struct __darwin_mcontext32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_float_state __fs;
};


struct __darwin_mcontext_avx32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_avx_state __fs;
};



struct __darwin_mcontext_avx512_32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_avx512_state __fs;
};
struct __darwin_mcontext64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};


struct __darwin_mcontext64_full
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_full_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};


struct __darwin_mcontext_avx64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_avx_state64 __fs;
};


struct __darwin_mcontext_avx64_full
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_full_state64 __ss;
 struct __darwin_x86_avx_state64 __fs;
};



struct __darwin_mcontext_avx512_64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_avx512_state64 __fs;
};


struct __darwin_mcontext_avx512_64_full
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_full_state64 __ss;
 struct __darwin_x86_avx512_state64 __fs;
};
typedef struct __darwin_mcontext64 *mcontext_t;



struct __darwin_sigaltstack
{
 void *ss_sp;
 __darwin_size_t ss_size;
 int ss_flags;
};
typedef struct __darwin_sigaltstack stack_t;



struct __darwin_ucontext
{
 int uc_onstack;
 __darwin_sigset_t uc_sigmask;
 struct __darwin_sigaltstack uc_stack;
 struct __darwin_ucontext *uc_link;
 __darwin_size_t uc_mcsize;
 struct __darwin_mcontext64 *uc_mcontext;



};


typedef struct __darwin_ucontext ucontext_t;






union sigval {

 int sival_int;
 void *sival_ptr;
};





struct sigevent {
 int sigev_notify;
 int sigev_signo;
 union sigval sigev_value;
 void (*sigev_notify_function)(union sigval);
 pthread_attr_t *sigev_notify_attributes;
};


typedef struct __siginfo {
 int si_signo;
 int si_errno;
 int si_code;
 pid_t si_pid;
 uid_t si_uid;
 int si_status;
 void *si_addr;
 union sigval si_value;
 long si_band;
 unsigned long __pad[7];
} siginfo_t;
union __sigaction_u {
 void (*__sa_handler)(int);
 void (*__sa_sigaction)(int, struct __siginfo *,
     void *);
};


struct __sigaction {
 union __sigaction_u __sigaction_u;
 void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
 sigset_t sa_mask;
 int sa_flags;
};




struct sigaction {
 union __sigaction_u __sigaction_u;
 sigset_t sa_mask;
 int sa_flags;
};
typedef void (*sig_t)(int);
struct sigvec {
 void (*sv_handler)(int);
 int sv_mask;
 int sv_flags;
};
struct sigstack {
 char *ss_sp;
 int ss_onstack;
};
extern "C" {
    void(*signal(int, void (*)(int)))(int);
}
typedef __uint64_t rlim_t;
struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
 long ru_maxrss;

 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;


};
typedef void *rusage_info_t;

struct rusage_info_v0 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
};

struct rusage_info_v1 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
};

struct rusage_info_v2 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
};

struct rusage_info_v3 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
};

struct rusage_info_v4 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
 uint64_t ri_logical_writes;
 uint64_t ri_lifetime_max_phys_footprint;
 uint64_t ri_instructions;
 uint64_t ri_cycles;
 uint64_t ri_billed_energy;
 uint64_t ri_serviced_energy;
 uint64_t ri_interval_max_phys_footprint;
 uint64_t ri_runnable_time;
};

struct rusage_info_v5 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
 uint64_t ri_logical_writes;
 uint64_t ri_lifetime_max_phys_footprint;
 uint64_t ri_instructions;
 uint64_t ri_cycles;
 uint64_t ri_billed_energy;
 uint64_t ri_serviced_energy;
 uint64_t ri_interval_max_phys_footprint;
 uint64_t ri_runnable_time;
 uint64_t ri_flags;
};

typedef struct rusage_info_v5 rusage_info_current;
struct rlimit {
 rlim_t rlim_cur;
 rlim_t rlim_max;
};
struct proc_rlimit_control_wakeupmon {
 uint32_t wm_flags;
 int32_t wm_rate;
};
extern "C" {
int getpriority(int, id_t);

int getiopolicy_np(int, int) __attribute__((availability(macosx,introduced=10.5)));

int getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);

int setiopolicy_np(int, int, int) __attribute__((availability(macosx,introduced=10.5)));

int setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );
}
union wait {
 int w_status;



 struct {

  unsigned int w_Termsig:7,
      w_Coredump:1,
      w_Retcode:8,
      w_Filler:16;







 } w_T;





 struct {

  unsigned int w_Stopval:8,
      w_Stopsig:8,
      w_Filler:16;






 } w_S;
};
extern "C" {
pid_t wait(int *) __asm("_" "wait" );
pid_t waitpid(pid_t, int *, int) __asm("_" "waitpid" );

int waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );


pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);

}

extern "C" {
void *alloca(size_t);
}








typedef __darwin_ct_rune_t ct_rune_t;
typedef __darwin_rune_t rune_t;



typedef struct {
 int quot;
 int rem;
} div_t;

typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef struct {
 long long quot;
 long long rem;
} lldiv_t;



extern int __mb_cur_max;
extern "C" {

void *malloc(size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(1)));
void *calloc(size_t __count, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(1,2)));
void free(void *);
void *realloc(void *__ptr, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(2)));

void *valloc(size_t) __attribute__((alloc_size(1)));




void *aligned_alloc(size_t __alignment, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(2))) __attribute__((availability(macosx,introduced=10.15))) __attribute__((availability(ios,introduced=13.0))) __attribute__((availability(tvos,introduced=13.0))) __attribute__((availability(watchos,introduced=6.0)));

int posix_memalign(void **__memptr, size_t __alignment, size_t __size) __attribute__((availability(macosx,introduced=10.6)));

}

extern "C" {
void abort(void) __attribute__((__cold__)) __attribute__((__noreturn__));
int abs(int) __attribute__((__const__));
int atexit(void (* _Nonnull)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);

long long
  atoll(const char *);

void *bsearch(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (* _Nonnull __compar)(const void *, const void *));

div_t div(int, int) __attribute__((__const__));
void exit(int) __attribute__((__noreturn__));

char *getenv(const char *);
long labs(long) __attribute__((__const__));
ldiv_t ldiv(long, long) __attribute__((__const__));

long long
  llabs(long long);
lldiv_t lldiv(long long, long long);


int mblen(const char *__s, size_t __n);
size_t mbstowcs(wchar_t * , const char * , size_t);
int mbtowc(wchar_t * , const char * , size_t);

void qsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));
int rand(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));

void srand(unsigned) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
double strtod(const char *, char **) __asm("_" "strtod" );
float strtof(const char *, char **) __asm("_" "strtof" );
long strtol(const char *__str, char **__endptr, int __base);
long double
  strtold(const char *, char **);

long long
  strtoll(const char *__str, char **__endptr, int __base);

unsigned long
  strtoul(const char *__str, char **__endptr, int __base);

unsigned long long
  strtoull(const char *__str, char **__endptr, int __base);
__attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")))
__attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable)))
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
int system(const char *) __asm("_" "system" );



size_t wcstombs(char * , const wchar_t * , size_t);
int wctomb(char *, wchar_t);


void _Exit(int) __attribute__((__noreturn__));
long a64l(const char *);
double drand48(void);
char *ecvt(double, int, int *, int *);
double erand48(unsigned short[3]);
char *fcvt(double, int, int *, int *);
char *gcvt(double, int, char *);
int getsubopt(char **, char * const *, char **);
int grantpt(int);

char *initstate(unsigned, char *, size_t);



long jrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *mktemp(char *);
int mkstemp(char *);
long mrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
long nrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int posix_openpt(int);
char *ptsname(int);


int ptsname_r(int fildes, char *buffer, size_t buflen) __attribute__((availability(macos,introduced=10.13.4))) __attribute__((availability(ios,introduced=11.3))) __attribute__((availability(tvos,introduced=11.3))) __attribute__((availability(watchos,introduced=4.3)));


int putenv(char *) __asm("_" "putenv" );
long random(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int rand_r(unsigned *) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));

char *realpath(const char * , char * ) __asm("_" "realpath" "$DARWIN_EXTSN");



unsigned short
 *seed48(unsigned short[3]);
int setenv(const char * __name, const char * __value, int __overwrite) __asm("_" "setenv" );

void setkey(const char *) __asm("_" "setkey" );



char *setstate(const char *);
void srand48(long);

void srandom(unsigned);



int unlockpt(int);

int unsetenv(const char *) __asm("_" "unsetenv" );
uint32_t arc4random(void);
void arc4random_addrandom(unsigned char * , int )
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(macosx,deprecated=10.12,message="use arc4random_stir")))
    __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(ios,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(tvos,introduced=2.0))) __attribute__((availability(tvos,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(watchos,introduced=1.0))) __attribute__((availability(watchos,deprecated=3.0,message="use arc4random_stir")));
void arc4random_buf(void * __buf, size_t __nbytes) __attribute__((availability(macosx,introduced=10.7)));
void arc4random_stir(void);
uint32_t
  arc4random_uniform(uint32_t __upper_bound) __attribute__((availability(macosx,introduced=10.7)));

int atexit_b(void (^ _Nonnull)(void)) __attribute__((availability(macosx,introduced=10.6)));
void *bsearch_b(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));



char *cgetcap(char *, const char *, int);
int cgetclose(void);
int cgetent(char **, char **, const char *);
int cgetfirst(char **, char **);
int cgetmatch(const char *, const char *);
int cgetnext(char **, char **);
int cgetnum(char *, const char *, long *);
int cgetset(const char *);
int cgetstr(char *, const char *, char **);
int cgetustr(char *, const char *, char **);

int daemon(int, int) __asm("_" "daemon" "$1050") __attribute__((availability(macosx,introduced=10.0,deprecated=10.5,message="Use posix_spawn APIs instead."))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *devname(dev_t, mode_t);
char *devname_r(dev_t, mode_t, char *buf, int len);
char *getbsize(int *, long *);
int getloadavg(double [], int);
const char
 *getprogname(void);
void setprogname(const char *);
int heapsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int heapsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

int mergesort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int mergesort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void psort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *))
     __attribute__((availability(macosx,introduced=10.6)));

void psort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void psort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *))
     __attribute__((availability(macosx,introduced=10.6)));

void qsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void qsort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *));
int radixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
int rpmatch(const char *)
 __attribute__((availability(macos,introduced=10.15))) __attribute__((availability(ios,introduced=13.0))) __attribute__((availability(tvos,introduced=13.0))) __attribute__((availability(watchos,introduced=6.0)));
int sradixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
void sranddev(void);
void srandomdev(void);
void *reallocf(void *__ptr, size_t __size) __attribute__((alloc_size(2)));
long long
 strtonum(const char *__numstr, long long __minval, long long __maxval, const char **__errstrp)
 __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)));

long long
  strtoq(const char *__str, char **__endptr, int __base);
unsigned long long
  strtouq(const char *__str, char **__endptr, int __base);

extern char *suboptarg;







}

typedef unsigned int boolean_t;
typedef __darwin_natural_t natural_t;
typedef int integer_t;






typedef uintptr_t vm_offset_t;
typedef uintptr_t vm_size_t;
typedef uint64_t mach_vm_address_t;
typedef uint64_t mach_vm_offset_t;
typedef uint64_t mach_vm_size_t;

typedef uint64_t vm_map_offset_t;
typedef uint64_t vm_map_address_t;
typedef uint64_t vm_map_size_t;

typedef mach_vm_address_t mach_port_context_t;
typedef natural_t mach_port_name_t;
typedef mach_port_name_t *mach_port_name_array_t;
typedef __darwin_mach_port_t mach_port_t;


typedef mach_port_t *mach_port_array_t;
typedef natural_t mach_port_right_t;
typedef natural_t mach_port_type_t;
typedef mach_port_type_t *mach_port_type_array_t;
typedef natural_t mach_port_urefs_t;
typedef integer_t mach_port_delta_t;



typedef natural_t mach_port_seqno_t;
typedef natural_t mach_port_mscount_t;
typedef natural_t mach_port_msgcount_t;
typedef natural_t mach_port_rights_t;






typedef unsigned int mach_port_srights_t;

typedef struct mach_port_status {
 mach_port_rights_t mps_pset;
 mach_port_seqno_t mps_seqno;
 mach_port_mscount_t mps_mscount;
 mach_port_msgcount_t mps_qlimit;
 mach_port_msgcount_t mps_msgcount;
 mach_port_rights_t mps_sorights;
 boolean_t mps_srights;
 boolean_t mps_pdrequest;
 boolean_t mps_nsrequest;
 natural_t mps_flags;
} mach_port_status_t;
typedef struct mach_port_limits {
 mach_port_msgcount_t mpl_qlimit;
} mach_port_limits_t;
typedef struct mach_port_info_ext {
 mach_port_status_t mpie_status;
 mach_port_msgcount_t mpie_boost_cnt;
 uint32_t reserved[6];
} mach_port_info_ext_t;

typedef integer_t *mach_port_info_t;


typedef int mach_port_flavor_t;
typedef struct mach_port_qos {
 unsigned int name:1;
 unsigned int prealloc:1;
 boolean_t pad1:30;
 natural_t len;
} mach_port_qos_t;
typedef struct mach_port_options {
 uint32_t flags;
 mach_port_limits_t mpl;
 union {
  uint64_t reserved[2];
  mach_port_name_t work_interval_port;
 };
}mach_port_options_t;

typedef mach_port_options_t *mach_port_options_ptr_t;
enum mach_port_guard_exception_codes {
 kGUARD_EXC_DESTROY = 1u << 0,
 kGUARD_EXC_MOD_REFS = 1u << 1,
 kGUARD_EXC_SET_CONTEXT = 1u << 2,
 kGUARD_EXC_UNGUARDED = 1u << 3,
 kGUARD_EXC_INCORRECT_GUARD = 1u << 4,
 kGUARD_EXC_IMMOVABLE = 1u << 5,
 kGUARD_EXC_STRICT_REPLY = 1u << 6,
 kGUARD_EXC_MSG_FILTERED = 1u << 7,

 kGUARD_EXC_INVALID_RIGHT = 1u << 8,
 kGUARD_EXC_INVALID_NAME = 1u << 9,
 kGUARD_EXC_INVALID_VALUE = 1u << 10,
 kGUARD_EXC_INVALID_ARGUMENT = 1u << 11,
 kGUARD_EXC_RIGHT_EXISTS = 1u << 12,
 kGUARD_EXC_KERN_NO_SPACE = 1u << 13,
 kGUARD_EXC_KERN_FAILURE = 1u << 14,
 kGUARD_EXC_KERN_RESOURCE = 1u << 15,
 kGUARD_EXC_SEND_INVALID_REPLY = 1u << 16,
 kGUARD_EXC_SEND_INVALID_VOUCHER = 1u << 17,
 kGUARD_EXC_SEND_INVALID_RIGHT = 1u << 18,
 kGUARD_EXC_RCV_INVALID_NAME = 1u << 19,
 kGUARD_EXC_RCV_GUARDED_DESC = 1u << 20,
};




typedef enum : uint32_t { OS_CLOCK_MACH_ABSOLUTE_TIME = 32, } os_clockid_t;
struct __attribute__((__swift_private__)) os_workgroup_attr_opaque_s {
 uint32_t sig;
 char opaque[60];
};


struct __attribute__((__swift_private__)) os_workgroup_interval_data_opaque_s {
 uint32_t sig;
 char opaque[56];
};

struct __attribute__((__swift_private__)) os_workgroup_join_token_opaque_s {
 uint32_t sig;
 char opaque[36];
};
extern "C" {

#pragma clang assume_nonnull begin
__attribute__((__swift_name__("WorkGroup"))) extern __attribute__((__visibility__("default"))) 
#ifndef _REWRITER_typedef_OS_os_workgroup
#define _REWRITER_typedef_OS_os_workgroup
typedef struct objc_object OS_os_workgroup;
typedef struct {} _objc_exc_OS_os_workgroup;
#endif

struct OS_os_workgroup_IMPL {
	struct OS_object_IMPL OS_object_IVARS;
};
 // - (instancetype)init __attribute__((__availability__(swift, unavailable, message="Unavailable in Swift"))); /* @end */
 typedef OS_os_workgroup * __attribute__((objc_independent_class)) os_workgroup_t;
typedef struct os_workgroup_attr_opaque_s os_workgroup_attr_s;
typedef struct os_workgroup_attr_opaque_s *os_workgroup_attr_t;
__attribute__((availability(macos,introduced=11.0)))
__attribute__((availability(ios,unavailable))) __attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default"))) __attribute__((__warn_unused_result__))
int
os_workgroup_copy_port(os_workgroup_t wg, mach_port_t *mach_port_out);
__attribute__((availability(macos,introduced=11.0)))
__attribute__((availability(ios,unavailable))) __attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
__attribute__((__swift_name__("WorkGroup.init(__name:port:)"))) extern __attribute__((__visibility__("default"))) __attribute__((__ns_returns_retained__))
os_workgroup_t _Nullable
os_workgroup_create_with_port(const char *_Nullable name, mach_port_t mach_port);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default"))) __attribute__((__ns_returns_retained__))
os_workgroup_t _Nullable
os_workgroup_create_with_workgroup(const char * _Nullable name, os_workgroup_t wg);
__attribute__((__swift_private__))
typedef struct os_workgroup_join_token_opaque_s os_workgroup_join_token_s;
__attribute__((__swift_private__))
typedef struct os_workgroup_join_token_opaque_s *os_workgroup_join_token_t;
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default"))) __attribute__((__warn_unused_result__))
int
os_workgroup_join(os_workgroup_t wg, os_workgroup_join_token_t token_out);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default")))
void
os_workgroup_leave(os_workgroup_t wg, os_workgroup_join_token_t token);


typedef uint32_t os_workgroup_index;

typedef void (*os_workgroup_working_arena_destructor_t)(void * _Nullable);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default"))) __attribute__((__warn_unused_result__))
int
os_workgroup_set_working_arena(os_workgroup_t wg, void * _Nullable arena,
 uint32_t max_workers, os_workgroup_working_arena_destructor_t destructor);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default")))
void * _Nullable
os_workgroup_get_working_arena(os_workgroup_t wg,
  os_workgroup_index * _Nullable index_out);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default")))
void
os_workgroup_cancel(os_workgroup_t wg);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default")))
bool
os_workgroup_testcancel(os_workgroup_t wg);
__attribute__((__swift_private__))
typedef struct os_workgroup_max_parallel_threads_attr_s os_workgroup_mpt_attr_s;
__attribute__((__swift_private__))
typedef struct os_workgroup_max_parallel_threads_attr_s *os_workgroup_mpt_attr_t;
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default")))
int
os_workgroup_max_parallel_threads(os_workgroup_t wg, os_workgroup_mpt_attr_t
  _Nullable attr);
#pragma clang assume_nonnull end


}
extern "C" {

#pragma clang assume_nonnull begin








__attribute__((__swift_name__("Repeatable"))) // @protocol OS_os_workgroup_interval /* @end */
;
__attribute__((__swift_name__("WorkGroupInterval"))) extern __attribute__((__visibility__("default"))) 
#ifndef _REWRITER_typedef_OS_os_workgroup_interval
#define _REWRITER_typedef_OS_os_workgroup_interval
typedef struct objc_object OS_os_workgroup_interval;
typedef struct {} _objc_exc_OS_os_workgroup_interval;
#endif

struct OS_os_workgroup_interval_IMPL {
	struct OS_os_workgroup_IMPL OS_os_workgroup_IVARS;
};
 // - (instancetype)init __attribute__((__availability__(swift, unavailable, message="Unavailable in Swift"))); /* @end */
; typedef OS_os_workgroup/*<OS_os_workgroup_interval>*/ * __attribute__((objc_independent_class)) os_workgroup_interval_t;
typedef struct os_workgroup_interval_data_opaque_s os_workgroup_interval_data_s;
typedef struct os_workgroup_interval_data_opaque_s *os_workgroup_interval_data_t;
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default"))) __attribute__((__warn_unused_result__))
int
os_workgroup_interval_start(os_workgroup_interval_t wg, uint64_t start, uint64_t
  deadline, os_workgroup_interval_data_t _Nullable data);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default"))) __attribute__((__warn_unused_result__))
int
os_workgroup_interval_update(os_workgroup_interval_t wg, uint64_t deadline,
  os_workgroup_interval_data_t _Nullable data);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
__attribute__((__swift_private__)) extern __attribute__((__visibility__("default"))) __attribute__((__warn_unused_result__))
int
os_workgroup_interval_finish(os_workgroup_interval_t wg,
  os_workgroup_interval_data_t _Nullable data);
#pragma clang assume_nonnull end


}
extern "C" {

#pragma clang assume_nonnull begin







__attribute__((__swift_name__("Parallelizable"))) // @protocol OS_os_workgroup_parallel /* @end */
;
__attribute__((__swift_name__("WorkGroupParallel"))) extern __attribute__((__visibility__("default"))) 
#ifndef _REWRITER_typedef_OS_os_workgroup_parallel
#define _REWRITER_typedef_OS_os_workgroup_parallel
typedef struct objc_object OS_os_workgroup_parallel;
typedef struct {} _objc_exc_OS_os_workgroup_parallel;
#endif

struct OS_os_workgroup_parallel_IMPL {
	struct OS_os_workgroup_IMPL OS_os_workgroup_IVARS;
};
 // - (instancetype)init __attribute__((__availability__(swift, unavailable, message="Unavailable in Swift"))); /* @end */
; typedef OS_os_workgroup/*<OS_os_workgroup_parallel>*/ * __attribute__((objc_independent_class)) os_workgroup_parallel_t;
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
extern __attribute__((__visibility__("default"))) __attribute__((__ns_returns_retained__))
__attribute__((__swift_name__("WorkGroupParallel.init(__name:attr:)")))
os_workgroup_parallel_t _Nullable
os_workgroup_parallel_create(const char * _Nullable name,
 os_workgroup_attr_t _Nullable attr);
#pragma clang assume_nonnull end


}
typedef void (*dispatch_function_t)(void *_Nullable);
struct time_value {
 integer_t seconds;
 integer_t microseconds;
};

typedef struct time_value time_value_t;




typedef int alarm_type_t;
typedef int sleep_type_t;
typedef int clock_id_t;
typedef int clock_flavor_t;
typedef int *clock_attr_t;
typedef int clock_res_t;




struct mach_timespec {
 unsigned int tv_sec;
 clock_res_t tv_nsec;
};
typedef struct mach_timespec mach_timespec_t;


#pragma clang assume_nonnull begin
extern "C" {

struct timespec;
typedef uint64_t dispatch_time_t;

enum {
 DISPATCH_WALLTIME_NOW __attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0))) = ~1ull,

};
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_time_t
dispatch_time(dispatch_time_t when, int64_t delta);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_time_t
dispatch_walltime(const struct timespec *_Nullable when, int64_t delta);

}
#pragma clang assume_nonnull end
typedef enum : unsigned int { QOS_CLASS_USER_INTERACTIVE __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x21, QOS_CLASS_USER_INITIATED __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x19, QOS_CLASS_DEFAULT __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x15, QOS_CLASS_UTILITY __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x11, QOS_CLASS_BACKGROUND __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x09, QOS_CLASS_UNSPECIFIED __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x00, } qos_class_t;
extern "C" {
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
qos_class_t
qos_class_self(void);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
qos_class_t
qos_class_main(void);

}


#pragma clang assume_nonnull begin
// @protocol OS_dispatch_object <NSObject> /* @end */
 typedef NSObject/*<OS_dispatch_object>*/ * __attribute__((objc_independent_class)) dispatch_object_t;
static __inline__ __attribute__((__always_inline__)) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
_dispatch_object_validate(dispatch_object_t object)
{
 void *isa = *(void *volatile*)( void*)object;
 (void)isa;
}
typedef void (*dispatch_block_t)(void);


extern "C" {






typedef qos_class_t dispatch_qos_class_t;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
__attribute__((__availability__(swift, unavailable, message="Can't be used with ARC")))
void
dispatch_retain(dispatch_object_t object);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
__attribute__((__availability__(swift, unavailable, message="Can't be used with ARC")))
void
dispatch_release(dispatch_object_t object);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__pure__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
void *_Nullable
dispatch_get_context(dispatch_object_t object);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__))
void
dispatch_set_context(dispatch_object_t object, void *_Nullable context);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__))
void
dispatch_set_finalizer_f(dispatch_object_t object,
  dispatch_function_t _Nullable finalizer);
__attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_activate(dispatch_object_t object);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_suspend(dispatch_object_t object);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_resume(dispatch_object_t object);
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__))
void
dispatch_set_qos_class_floor(dispatch_object_t object,
  dispatch_qos_class_t qos_class, int relative_priority);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
intptr_t
dispatch_wait(void *object, dispatch_time_t timeout);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_notify(void *object, dispatch_object_t queue,
  dispatch_block_t notification_block);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_cancel(void *object);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
intptr_t
dispatch_testcancel(void *object);
__attribute__((availability(macos,introduced=10.6,deprecated=10.9,message="unsupported interface"))) __attribute__((availability(ios,introduced=4.0,deprecated=6.0,message="unsupported interface")))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nothrow__)) __attribute__((__cold__))
__attribute__((__format__(printf,2,3)))
void
dispatch_debug(dispatch_object_t object, const char *message, ...);

__attribute__((availability(macos,introduced=10.6,deprecated=10.9,message="unsupported interface"))) __attribute__((availability(ios,introduced=4.0,deprecated=6.0,message="unsupported interface")))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nothrow__)) __attribute__((__cold__))
__attribute__((__format__(printf,2,0)))
void
dispatch_debugv(dispatch_object_t object, const char *message, va_list ap);

}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin
// @protocol OS_dispatch_queue <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_queue>*/ * __attribute__((objc_independent_class)) dispatch_queue_t;
// @protocol OS_dispatch_queue_global <OS_dispatch_queue> /* @end */
 typedef NSObject/*<OS_dispatch_queue_global>*/ * __attribute__((objc_independent_class)) dispatch_queue_global_t;
// @protocol OS_dispatch_queue_serial <OS_dispatch_queue> /* @end */
 typedef NSObject/*<OS_dispatch_queue_serial>*/ * __attribute__((objc_independent_class)) dispatch_queue_serial_t;
// @protocol OS_dispatch_queue_main <OS_dispatch_queue_serial> /* @end */
 typedef NSObject/*<OS_dispatch_queue_main>*/ * __attribute__((objc_independent_class)) dispatch_queue_main_t;
// @protocol OS_dispatch_queue_concurrent <OS_dispatch_queue> /* @end */
 typedef NSObject/*<OS_dispatch_queue_concurrent>*/ * __attribute__((objc_independent_class)) dispatch_queue_concurrent_t;

extern "C" {
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_async(dispatch_queue_t queue, dispatch_block_t block);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_async_f(dispatch_queue_t queue,
  void *_Nullable context, dispatch_function_t work);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_sync(dispatch_queue_t queue, __attribute__((__noescape__)) dispatch_block_t block);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_sync_f(dispatch_queue_t queue,
  void *_Nullable context, dispatch_function_t work);
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_async_and_wait(dispatch_queue_t queue,
  __attribute__((__noescape__)) dispatch_block_t block);
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_async_and_wait_f(dispatch_queue_t queue,
  void *_Nullable context, dispatch_function_t work);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_apply(size_t iterations,
  dispatch_queue_t _Nullable queue,
  __attribute__((__noescape__)) void (^block)(size_t));
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(4))) __attribute__((__nothrow__))
void
dispatch_apply_f(size_t iterations,
  dispatch_queue_t _Nullable queue,
  void *_Nullable context, void (*work)(void *_Nullable, size_t));
__attribute__((availability(macos,introduced=10.6,deprecated=10.9,message="unsupported interface"))) __attribute__((availability(ios,introduced=4.0,deprecated=6.0,message="unsupported interface")))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_queue_t
dispatch_get_current_queue(void);

__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default")))
struct dispatch_queue_s _dispatch_main_q;
static __inline__ __attribute__((__always_inline__)) __attribute__((__const__)) __attribute__((__nothrow__))
dispatch_queue_main_t
dispatch_get_main_queue(void)
{
 return (( dispatch_queue_main_t)&(_dispatch_main_q));
}
typedef long dispatch_queue_priority_t;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__const__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_queue_global_t
dispatch_get_global_queue(intptr_t identifier, uintptr_t flags);







// @protocol OS_dispatch_queue_attr <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_queue_attr>*/ * __attribute__((objc_independent_class)) dispatch_queue_attr_t;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3)))
extern __attribute__((visibility("default")))
struct dispatch_queue_attr_s _dispatch_queue_attr_concurrent;
__attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__pure__)) __attribute__((__nothrow__))
dispatch_queue_attr_t
dispatch_queue_attr_make_initially_inactive(
  dispatch_queue_attr_t _Nullable attr);
typedef enum : unsigned long { DISPATCH_AUTORELEASE_FREQUENCY_INHERIT __attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 0, DISPATCH_AUTORELEASE_FREQUENCY_WORK_ITEM __attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 1, DISPATCH_AUTORELEASE_FREQUENCY_NEVER __attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 2, } __attribute__((__enum_extensibility__(open))) dispatch_autorelease_frequency_t;
__attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__pure__)) __attribute__((__nothrow__))
dispatch_queue_attr_t
dispatch_queue_attr_make_with_autorelease_frequency(
  dispatch_queue_attr_t _Nullable attr,
  dispatch_autorelease_frequency_t frequency);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__pure__)) __attribute__((__nothrow__))
dispatch_queue_attr_t
dispatch_queue_attr_make_with_qos_class(dispatch_queue_attr_t _Nullable attr,
  dispatch_qos_class_t qos_class, int relative_priority);
__attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_queue_t
dispatch_queue_create_with_target(const char *_Nullable label,
  dispatch_queue_attr_t _Nullable attr, dispatch_queue_t _Nullable target)
  __asm__("_" "dispatch_queue_create_with_target" "$V2");
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_queue_t
dispatch_queue_create(const char *_Nullable label,
  dispatch_queue_attr_t _Nullable attr);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
const char *
dispatch_queue_get_label(dispatch_queue_t _Nullable queue);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
dispatch_qos_class_t
dispatch_queue_get_qos_class(dispatch_queue_t queue,
  int *_Nullable relative_priority_ptr);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__))
void
dispatch_set_target_queue(dispatch_object_t object,
  dispatch_queue_t _Nullable queue);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__)) __attribute__((__noreturn__))
void
dispatch_main(void);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_after(dispatch_time_t when, dispatch_queue_t queue,
  dispatch_block_t block);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(4))) __attribute__((__nothrow__))
void
dispatch_after_f(dispatch_time_t when, dispatch_queue_t queue,
  void *_Nullable context, dispatch_function_t work);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_barrier_async_f(dispatch_queue_t queue,
  void *_Nullable context, dispatch_function_t work);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_barrier_sync(dispatch_queue_t queue,
  __attribute__((__noescape__)) dispatch_block_t block);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_barrier_sync_f(dispatch_queue_t queue,
  void *_Nullable context, dispatch_function_t work);
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_barrier_async_and_wait(dispatch_queue_t queue,
  __attribute__((__noescape__)) dispatch_block_t block);
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_barrier_async_and_wait_f(dispatch_queue_t queue,
  void *_Nullable context, dispatch_function_t work);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_queue_set_specific(dispatch_queue_t queue, const void *key,
  void *_Nullable context, dispatch_function_t _Nullable destructor);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__pure__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
void *_Nullable
dispatch_queue_get_specific(dispatch_queue_t queue, const void *key);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
void *_Nullable
dispatch_get_specific(const void *key);
__attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1)))
void
dispatch_assert_queue(dispatch_queue_t queue)
  __asm__("_" "dispatch_assert_queue" "$V2");
__attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1)))
void
dispatch_assert_queue_barrier(dispatch_queue_t queue);
__attribute__((availability(macos,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1)))
void
dispatch_assert_queue_not(dispatch_queue_t queue)
  __asm__("_" "dispatch_assert_queue_not" "$V2");
}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin

extern "C" {
typedef enum : unsigned long { DISPATCH_BLOCK_BARRIER __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x1, DISPATCH_BLOCK_DETACHED __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x2, DISPATCH_BLOCK_ASSIGN_CURRENT __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x4, DISPATCH_BLOCK_NO_QOS_CLASS __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x8, DISPATCH_BLOCK_INHERIT_QOS_CLASS __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x10, DISPATCH_BLOCK_ENFORCE_QOS_CLASS __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x20, } __attribute__((__flag_enum__)) __attribute__((__enum_extensibility__(open))) dispatch_block_flags_t;
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_block_t
dispatch_block_create(dispatch_block_flags_t flags, dispatch_block_t block);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(4))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_block_t
dispatch_block_create_with_qos_class(dispatch_block_flags_t flags,
  dispatch_qos_class_t qos_class, int relative_priority,
  dispatch_block_t block);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nothrow__))
void
dispatch_block_perform(dispatch_block_flags_t flags,
  __attribute__((__noescape__)) dispatch_block_t block);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
intptr_t
dispatch_block_wait(dispatch_block_t block, dispatch_time_t timeout);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_block_notify(dispatch_block_t block, dispatch_queue_t queue,
  dispatch_block_t notification_block);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_block_cancel(dispatch_block_t block);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
intptr_t
dispatch_block_testcancel(dispatch_block_t block);

}
#pragma clang assume_nonnull end
typedef int kern_return_t;
typedef natural_t mach_msg_timeout_t;
typedef unsigned int mach_msg_bits_t;
typedef natural_t mach_msg_size_t;
typedef integer_t mach_msg_id_t;



typedef unsigned int mach_msg_priority_t;




typedef unsigned int mach_msg_type_name_t;
typedef unsigned int mach_msg_copy_options_t;
typedef unsigned int mach_msg_guard_flags_t;
typedef unsigned int mach_msg_descriptor_type_t;







#pragma pack(push, 4)

typedef struct{
 natural_t pad1;
 mach_msg_size_t pad2;
 unsigned int pad3 : 24;
 mach_msg_descriptor_type_t type : 8;
} mach_msg_type_descriptor_t;

typedef struct{
 mach_port_t name;

 mach_msg_size_t pad1;
 unsigned int pad2 : 16;
 mach_msg_type_name_t disposition : 8;
 mach_msg_descriptor_type_t type : 8;
} mach_msg_port_descriptor_t;

typedef struct{
 uint32_t address;
 mach_msg_size_t size;
 boolean_t deallocate: 8;
 mach_msg_copy_options_t copy: 8;
 unsigned int pad1: 8;
 mach_msg_descriptor_type_t type: 8;
} mach_msg_ool_descriptor32_t;

typedef struct{
 uint64_t address;
 boolean_t deallocate: 8;
 mach_msg_copy_options_t copy: 8;
 unsigned int pad1: 8;
 mach_msg_descriptor_type_t type: 8;
 mach_msg_size_t size;
} mach_msg_ool_descriptor64_t;

typedef struct{
 void* address;



 boolean_t deallocate: 8;
 mach_msg_copy_options_t copy: 8;
 unsigned int pad1: 8;
 mach_msg_descriptor_type_t type: 8;

 mach_msg_size_t size;

} mach_msg_ool_descriptor_t;

typedef struct{
 uint32_t address;
 mach_msg_size_t count;
 boolean_t deallocate: 8;
 mach_msg_copy_options_t copy: 8;
 mach_msg_type_name_t disposition : 8;
 mach_msg_descriptor_type_t type : 8;
} mach_msg_ool_ports_descriptor32_t;

typedef struct{
 uint64_t address;
 boolean_t deallocate: 8;
 mach_msg_copy_options_t copy: 8;
 mach_msg_type_name_t disposition : 8;
 mach_msg_descriptor_type_t type : 8;
 mach_msg_size_t count;
} mach_msg_ool_ports_descriptor64_t;

typedef struct{
 void* address;



 boolean_t deallocate: 8;
 mach_msg_copy_options_t copy: 8;
 mach_msg_type_name_t disposition : 8;
 mach_msg_descriptor_type_t type : 8;

 mach_msg_size_t count;

} mach_msg_ool_ports_descriptor_t;

typedef struct{
 uint32_t context;
 mach_port_name_t name;
 mach_msg_guard_flags_t flags : 16;
 mach_msg_type_name_t disposition : 8;
 mach_msg_descriptor_type_t type : 8;
} mach_msg_guarded_port_descriptor32_t;

typedef struct{
 uint64_t context;
 mach_msg_guard_flags_t flags : 16;
 mach_msg_type_name_t disposition : 8;
 mach_msg_descriptor_type_t type : 8;
 mach_port_name_t name;
} mach_msg_guarded_port_descriptor64_t;

typedef struct{
 mach_port_context_t context;



 mach_msg_guard_flags_t flags : 16;
 mach_msg_type_name_t disposition : 8;
 mach_msg_descriptor_type_t type : 8;

 mach_port_name_t name;

} mach_msg_guarded_port_descriptor_t;






typedef union{
 mach_msg_port_descriptor_t port;
 mach_msg_ool_descriptor_t out_of_line;
 mach_msg_ool_ports_descriptor_t ool_ports;
 mach_msg_type_descriptor_t type;
 mach_msg_guarded_port_descriptor_t guarded_port;
} mach_msg_descriptor_t;

typedef struct{
 mach_msg_size_t msgh_descriptor_count;
} mach_msg_body_t;




typedef struct{
 mach_msg_bits_t msgh_bits;
 mach_msg_size_t msgh_size;
 mach_port_t msgh_remote_port;
 mach_port_t msgh_local_port;
 mach_port_name_t msgh_voucher_port;
 mach_msg_id_t msgh_id;
} mach_msg_header_t;




typedef struct{
 mach_msg_header_t header;
 mach_msg_body_t body;
} mach_msg_base_t;

typedef unsigned int mach_msg_trailer_type_t;



typedef unsigned int mach_msg_trailer_size_t;
typedef char *mach_msg_trailer_info_t;

typedef struct{
 mach_msg_trailer_type_t msgh_trailer_type;
 mach_msg_trailer_size_t msgh_trailer_size;
} mach_msg_trailer_t;
typedef struct{
 mach_msg_trailer_type_t msgh_trailer_type;
 mach_msg_trailer_size_t msgh_trailer_size;
 mach_port_seqno_t msgh_seqno;
} mach_msg_seqno_trailer_t;

typedef struct{
 unsigned int val[2];
} security_token_t;

typedef struct{
 mach_msg_trailer_type_t msgh_trailer_type;
 mach_msg_trailer_size_t msgh_trailer_size;
 mach_port_seqno_t msgh_seqno;
 security_token_t msgh_sender;
} mach_msg_security_trailer_t;
typedef struct{
 unsigned int val[8];
} audit_token_t;

typedef struct{
 mach_msg_trailer_type_t msgh_trailer_type;
 mach_msg_trailer_size_t msgh_trailer_size;
 mach_port_seqno_t msgh_seqno;
 security_token_t msgh_sender;
 audit_token_t msgh_audit;
} mach_msg_audit_trailer_t;

typedef struct{
 mach_msg_trailer_type_t msgh_trailer_type;
 mach_msg_trailer_size_t msgh_trailer_size;
 mach_port_seqno_t msgh_seqno;
 security_token_t msgh_sender;
 audit_token_t msgh_audit;
 mach_port_context_t msgh_context;
} mach_msg_context_trailer_t;



typedef struct{
 mach_port_name_t sender;
} msg_labels_t;

typedef int mach_msg_filter_id;







typedef struct{
 mach_msg_trailer_type_t msgh_trailer_type;
 mach_msg_trailer_size_t msgh_trailer_size;
 mach_port_seqno_t msgh_seqno;
 security_token_t msgh_sender;
 audit_token_t msgh_audit;
 mach_port_context_t msgh_context;
 mach_msg_filter_id msgh_ad;
 msg_labels_t msgh_labels;
} mach_msg_mac_trailer_t;
typedef mach_msg_mac_trailer_t mach_msg_max_trailer_t;
typedef mach_msg_security_trailer_t mach_msg_format_0_trailer_t;







extern const security_token_t KERNEL_SECURITY_TOKEN;


extern const audit_token_t KERNEL_AUDIT_TOKEN;

typedef integer_t mach_msg_options_t;

typedef struct{
 mach_msg_header_t header;
} mach_msg_empty_send_t;

typedef struct{
 mach_msg_header_t header;
 mach_msg_trailer_t trailer;
} mach_msg_empty_rcv_t;

typedef union{
 mach_msg_empty_send_t send;
 mach_msg_empty_rcv_t rcv;
} mach_msg_empty_t;

#pragma pack(pop)
typedef natural_t mach_msg_type_size_t;
typedef natural_t mach_msg_type_number_t;
typedef integer_t mach_msg_option_t;
typedef kern_return_t mach_msg_return_t;
extern "C" {
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
extern mach_msg_return_t mach_msg_overwrite(
 mach_msg_header_t *msg,
 mach_msg_option_t option,
 mach_msg_size_t send_size,
 mach_msg_size_t rcv_size,
 mach_port_name_t rcv_name,
 mach_msg_timeout_t timeout,
 mach_port_name_t notify,
 mach_msg_header_t *rcv_msg,
 mach_msg_size_t rcv_limit);
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
extern mach_msg_return_t mach_msg(
 mach_msg_header_t *msg,
 mach_msg_option_t option,
 mach_msg_size_t send_size,
 mach_msg_size_t rcv_size,
 mach_port_name_t rcv_name,
 mach_msg_timeout_t timeout,
 mach_port_name_t notify);







__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
extern kern_return_t mach_voucher_deallocate(
 mach_port_name_t voucher);


}






#pragma clang assume_nonnull begin
// @protocol OS_dispatch_source <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_source>*/ * __attribute__((objc_independent_class)) dispatch_source_t;;

extern "C" {
typedef const struct dispatch_source_type_s *dispatch_source_type_t;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_data_add;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_data_or;
__attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_data_replace;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_mach_send;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_mach_recv;
__attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=8.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_memorypressure;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_proc;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_read;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_signal;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_timer;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_vnode;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_write;
typedef unsigned long dispatch_source_mach_send_flags_t;





typedef unsigned long dispatch_source_mach_recv_flags_t;
typedef unsigned long dispatch_source_memorypressure_flags_t;
typedef unsigned long dispatch_source_proc_flags_t;
typedef unsigned long dispatch_source_vnode_flags_t;
typedef unsigned long dispatch_source_timer_flags_t;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_source_t
dispatch_source_create(dispatch_source_type_t type,
 uintptr_t handle,
 uintptr_t mask,
 dispatch_queue_t _Nullable queue);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_event_handler(dispatch_source_t source,
 dispatch_block_t _Nullable handler);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_event_handler_f(dispatch_source_t source,
 dispatch_function_t _Nullable handler);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_cancel_handler(dispatch_source_t source,
 dispatch_block_t _Nullable handler);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_cancel_handler_f(dispatch_source_t source,
 dispatch_function_t _Nullable handler);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_source_cancel(dispatch_source_t source);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
intptr_t
dispatch_source_testcancel(dispatch_source_t source);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
uintptr_t
dispatch_source_get_handle(dispatch_source_t source);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
uintptr_t
dispatch_source_get_mask(dispatch_source_t source);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
uintptr_t
dispatch_source_get_data(dispatch_source_t source);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_source_merge_data(dispatch_source_t source, uintptr_t value);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_source_set_timer(dispatch_source_t source,
 dispatch_time_t start,
 uint64_t interval,
 uint64_t leeway);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_registration_handler(dispatch_source_t source,
 dispatch_block_t _Nullable handler);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_registration_handler_f(dispatch_source_t source,
 dispatch_function_t _Nullable handler);

}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin






// @protocol OS_dispatch_group <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_group>*/ * __attribute__((objc_independent_class)) dispatch_group_t;

extern "C" {
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_group_t
dispatch_group_create(void);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_async(dispatch_group_t group,
 dispatch_queue_t queue,
 dispatch_block_t block);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(4)))
__attribute__((__nothrow__))
void
dispatch_group_async_f(dispatch_group_t group,
 dispatch_queue_t queue,
 void *_Nullable context,
 dispatch_function_t work);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
intptr_t
dispatch_group_wait(dispatch_group_t group, dispatch_time_t timeout);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_notify(dispatch_group_t group,
 dispatch_queue_t queue,
 dispatch_block_t block);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(4)))
__attribute__((__nothrow__))
void
dispatch_group_notify_f(dispatch_group_t group,
 dispatch_queue_t queue,
 void *_Nullable context,
 dispatch_function_t work);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_enter(dispatch_group_t group);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_leave(dispatch_group_t group);

}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin







// @protocol OS_dispatch_semaphore <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_semaphore>*/ * __attribute__((objc_independent_class)) dispatch_semaphore_t;

extern "C" {
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_semaphore_t
dispatch_semaphore_create(intptr_t value);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
intptr_t
dispatch_semaphore_wait(dispatch_semaphore_t dsema, dispatch_time_t timeout);
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
intptr_t
dispatch_semaphore_signal(dispatch_semaphore_t dsema);

}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin

extern "C" {
typedef intptr_t dispatch_once_t;
__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))

void
dispatch_once(dispatch_once_t *predicate,
  __attribute__((__noescape__)) dispatch_block_t block);


static __inline__ __attribute__((__always_inline__)) __attribute__((__nonnull__)) __attribute__((__nothrow__))

void
_dispatch_once(dispatch_once_t *predicate,
  __attribute__((__noescape__)) dispatch_block_t block)
{
 if (__builtin_expect((*predicate), (~0l)) != ~0l) {
  dispatch_once(predicate, block);
 } else {
  __asm__ __volatile__("" ::: "memory");
 }
 __builtin_assume(*predicate == ~0l);
}





__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))

void
dispatch_once_f(dispatch_once_t *predicate, void *_Nullable context,
  dispatch_function_t function);


static __inline__ __attribute__((__always_inline__)) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3)))
__attribute__((__nothrow__))

void
_dispatch_once_f(dispatch_once_t *predicate, void *_Nullable context,
  dispatch_function_t function)
{
 if (__builtin_expect((*predicate), (~0l)) != ~0l) {
  dispatch_once_f(predicate, context, function);
 } else {
  __asm__ __volatile__("" ::: "memory");
 }
 __builtin_assume(*predicate == ~0l);
}




}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin

extern "C" {
// @protocol OS_dispatch_data <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_data>*/ * __attribute__((objc_independent_class)) dispatch_data_t;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) struct dispatch_data_s _dispatch_data_empty;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) const dispatch_block_t _dispatch_data_destructor_free;







__attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)))
extern __attribute__((visibility("default"))) const dispatch_block_t _dispatch_data_destructor_munmap;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create(const void *buffer,
 size_t size,
 dispatch_queue_t _Nullable queue,
 dispatch_block_t _Nullable destructor);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
size_t
dispatch_data_get_size(dispatch_data_t data);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create_map(dispatch_data_t data,
 const void *_Nullable *_Nullable buffer_ptr,
 size_t *_Nullable size_ptr);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create_concat(dispatch_data_t data1, dispatch_data_t data2);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create_subrange(dispatch_data_t data,
 size_t offset,
 size_t length);
typedef bool (*dispatch_data_applier_t)(dispatch_data_t region,
 size_t offset,
 const void *buffer,
 size_t size);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
bool
dispatch_data_apply(dispatch_data_t data,
 __attribute__((__noescape__)) dispatch_data_applier_t applier);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_copy_region(dispatch_data_t data,
 size_t location,
 size_t *offset_ptr);

}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin

extern "C" {
typedef int dispatch_fd_t;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(3))) __attribute__((__nonnull__(4))) __attribute__((__nothrow__))
void
dispatch_read(dispatch_fd_t fd,
 size_t length,
 dispatch_queue_t queue,
 void (^handler)(dispatch_data_t data, int error));
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(3))) __attribute__((__nonnull__(4)))
__attribute__((__nothrow__))
void
dispatch_write(dispatch_fd_t fd,
 dispatch_data_t data,
 dispatch_queue_t queue,
 void (^handler)(dispatch_data_t _Nullable data, int error));
// @protocol OS_dispatch_io <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_io>*/ * __attribute__((objc_independent_class)) dispatch_io_t;
typedef unsigned long dispatch_io_type_t;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_io_t
dispatch_io_create(dispatch_io_type_t type,
 dispatch_fd_t fd,
 dispatch_queue_t queue,
 void (^cleanup_handler)(int error));
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_io_t
dispatch_io_create_with_path(dispatch_io_type_t type,
 const char *path, int oflag, mode_t mode,
 dispatch_queue_t queue,
 void (^cleanup_handler)(int error));
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_io_t
dispatch_io_create_with_io(dispatch_io_type_t type,
 dispatch_io_t io,
 dispatch_queue_t queue,
 void (^cleanup_handler)(int error));
typedef void (*dispatch_io_handler_t)(bool done, dispatch_data_t _Nullable data,
  int error);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(4))) __attribute__((__nonnull__(5)))
__attribute__((__nothrow__))
void
dispatch_io_read(dispatch_io_t channel,
 off_t offset,
 size_t length,
 dispatch_queue_t queue,
 dispatch_io_handler_t io_handler);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nonnull__(4)))
__attribute__((__nonnull__(5))) __attribute__((__nothrow__))
void
dispatch_io_write(dispatch_io_t channel,
 off_t offset,
 dispatch_data_t data,
 dispatch_queue_t queue,
 dispatch_io_handler_t io_handler);
typedef unsigned long dispatch_io_close_flags_t;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_close(dispatch_io_t channel, dispatch_io_close_flags_t flags);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_io_barrier(dispatch_io_t channel, dispatch_block_t barrier);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_fd_t
dispatch_io_get_descriptor(dispatch_io_t channel);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_set_high_water(dispatch_io_t channel, size_t high_water);
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_set_low_water(dispatch_io_t channel, size_t low_water);
typedef unsigned long dispatch_io_interval_flags_t;
__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_set_interval(dispatch_io_t channel,
 uint64_t interval,
 dispatch_io_interval_flags_t flags);

}
#pragma clang assume_nonnull end
#pragma clang assume_nonnull begin

extern "C" {
// @protocol OS_dispatch_workloop <OS_dispatch_queue> /* @end */
 typedef NSObject/*<OS_dispatch_workloop>*/ * __attribute__((objc_independent_class)) dispatch_workloop_t;
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_workloop_t
dispatch_workloop_create(const char *_Nullable label);
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_workloop_t
dispatch_workloop_create_inactive(const char *_Nullable label);
__attribute__((availability(macos,introduced=10.14))) __attribute__((availability(ios,introduced=12.0))) __attribute__((availability(tvos,introduced=12.0))) __attribute__((availability(watchos,introduced=5.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_workloop_set_autorelease_frequency(dispatch_workloop_t workloop,
  dispatch_autorelease_frequency_t frequency);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_workloop_set_os_workgroup(dispatch_workloop_t workloop,
  os_workgroup_t workgroup);

}
#pragma clang assume_nonnull end
extern "C" {





extern "C" __attribute__((__visibility__("default"))) void *_Block_copy(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) void _Block_release(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) void _Block_object_assign(void *, const void *, const int);


extern "C" __attribute__((__visibility__("default"))) void _Block_object_dispose(const void *, const int);






extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteGlobalBlock[32];
extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteStackBlock[32];



}
typedef __darwin_va_list va_list;


extern "C" {

int renameat(int, const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));






int renamex_np(const char *, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int renameatx_np(int, const char *, int, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));



}

typedef __darwin_off_t fpos_t;
struct __sbuf {
 unsigned char *_base;
 int _size;
};


struct __sFILEX;
typedef struct __sFILE {
 unsigned char *_p;
 int _r;
 int _w;
 short _flags;
 short _file;
 struct __sbuf _bf;
 int _lbfsize;


 void *_cookie;
 int (* _Nullable _close)(void *);
 int (* _Nullable _read) (void *, char *, int);
 fpos_t (* _Nullable _seek) (void *, fpos_t, int);
 int (* _Nullable _write)(void *, const char *, int);


 struct __sbuf _ub;
 struct __sFILEX *_extra;
 int _ur;


 unsigned char _ubuf[3];
 unsigned char _nbuf[1];


 struct __sbuf _lb;


 int _blksize;
 fpos_t _offset;
} FILE;

extern "C" {
extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
}
extern "C" {
void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE * , fpos_t *);
char *fgets(char * , int, FILE *);



FILE *fopen(const char * __filename, const char * __mode) __asm("_" "fopen" );

int fprintf(FILE * , const char * , ...) __attribute__((__format__ (__printf__, 2, 3)));
int fputc(int, FILE *);
int fputs(const char * , FILE * ) __asm("_" "fputs" );
size_t fread(void * __ptr, size_t __size, size_t __nitems, FILE * __stream);
FILE *freopen(const char * , const char * ,
                 FILE * ) __asm("_" "freopen" );
int fscanf(FILE * , const char * , ...) __attribute__((__format__ (__scanf__, 2, 3)));
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void * __ptr, size_t __size, size_t __nitems, FILE * __stream) __asm("_" "fwrite" );
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *) __attribute__((__cold__));
int printf(const char * , ...) __attribute__((__format__ (__printf__, 1, 2)));
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename (const char *__old, const char *__new);
void rewind(FILE *);
int scanf(const char * , ...) __attribute__((__format__ (__scanf__, 1, 2)));
void setbuf(FILE * , char * );
int setvbuf(FILE * , char * , int, size_t);
int sprintf(char * , const char * , ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((__availability__(swift, unavailable, message="Use snprintf instead.")));
int sscanf(const char * , const char * , ...) __attribute__((__format__ (__scanf__, 2, 3)));
FILE *tmpfile(void);

__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tmpnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE * , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0)));
int vprintf(const char * , va_list) __attribute__((__format__ (__printf__, 1, 0)));
int vsprintf(char * , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((__availability__(swift, unavailable, message="Use vsnprintf instead.")));
}
extern "C" {





FILE *fdopen(int, const char *) __asm("_" "fdopen" );

int fileno(FILE *);
}
extern "C" {
int pclose(FILE *) __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));



FILE *popen(const char *, const char *) __asm("_" "popen" ) __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));

}
extern "C" {
int __srget(FILE *);
int __svfscanf(FILE *, const char *, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int __swbuf(int, FILE *);
}







inline __attribute__ ((__always_inline__)) int __sputc(int _c, FILE *_p) {
 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf(_c, _p));
}
extern "C" {
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);



int getw(FILE *);
int putw(int, FILE *);


__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tempnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tempnam(const char *__dir, const char *__prefix) __asm("_" "tempnam" );
}
extern "C" {
int fseeko(FILE * __stream, off_t __offset, int __whence);
off_t ftello(FILE * __stream);
}



extern "C" {
int snprintf(char * __str, size_t __size, const char * __format, ...) __attribute__((__format__ (__printf__, 3, 4)));
int vfscanf(FILE * __stream, const char * __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int vscanf(const char * __format, va_list) __attribute__((__format__ (__scanf__, 1, 0)));
int vsnprintf(char * __str, size_t __size, const char * __format, va_list) __attribute__((__format__ (__printf__, 3, 0)));
int vsscanf(const char * __str, const char * __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
}
extern "C" {
int dprintf(int, const char * , ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((availability(macosx,introduced=10.7)));
int vdprintf(int, const char * , va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getdelim(char ** __linep, size_t * __linecapp, int __delimiter, FILE * __stream) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getline(char ** __linep, size_t * __linecapp, FILE * __stream) __attribute__((availability(macosx,introduced=10.7)));
FILE *fmemopen(void * __buf, size_t __size, const char * __mode) __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
FILE *open_memstream(char **__bufp, size_t *__sizep) __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
}







extern "C" {
extern const int sys_nerr;
extern const char *const sys_errlist[];

int asprintf(char ** , const char * , ...) __attribute__((__format__ (__printf__, 2, 3)));
char *ctermid_r(char *);
char *fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *);
int fpurge(FILE *);
void setbuffer(FILE *, char *, int);
int setlinebuf(FILE *);
int vasprintf(char ** , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0)));
FILE *zopen(const char *, const char *, int);





FILE *funopen(const void *,
                 int (* _Nullable)(void *, char *, int),
                 int (* _Nullable)(void *, const char *, int),
                 fpos_t (* _Nullable)(void *, fpos_t, int),
                 int (* _Nullable)(void *));
}

struct __Block_byref_c_0 {
  void *__isa;
__Block_byref_c_0 *__forwarding;
 int __flags;
 int __size;
 int c;
};

struct __main_block_impl_0 {
  struct __block_impl impl;
  struct __main_block_desc_0* Desc;
  int i;
  __Block_byref_c_0 *c; // by ref
  __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int _i, __Block_byref_c_0 *_c, int flags=0) : i(_i), c(_c->__forwarding) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
  __Block_byref_c_0 *c = __cself->c; // bound by ref
  int i = __cself->i; // bound by copy
 (c->__forwarding->c) = i; }
static void __main_block_copy_0(struct __main_block_impl_0*dst, struct __main_block_impl_0*src) {_Block_object_assign((void*)&dst->c, (void*)src->c, 8/*BLOCK_FIELD_IS_BYREF*/);}

static void __main_block_dispose_0(struct __main_block_impl_0*src) {_Block_object_dispose((void*)src->c, 8/*BLOCK_FIELD_IS_BYREF*/);}

static struct __main_block_desc_0 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __main_block_impl_0*, struct __main_block_impl_0*);
  void (*dispose)(struct __main_block_impl_0*);
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0), __main_block_copy_0, __main_block_dispose_0};
int main(int argc, char* argv[]) {
  __attribute__((__blocks__(byref))) __Block_byref_c_0 c = {(void*)0,(__Block_byref_c_0 *)&c, 0, sizeof(__Block_byref_c_0), 1};



  int i;
  for (i = 0; i < 2; i++) {
    dispatch_block_t block = ((void (*)())_Block_copy((const void *)(((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, i, (__Block_byref_c_0 *)&c, 570425344)))));



    ((void (*)(__block_impl *))((__block_impl *)block)->FuncPtr)((__block_impl *)block);


    _Block_release((const void *)(block));
  }
  printf("%s: success\n", argv[0]);
  return 0;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };
