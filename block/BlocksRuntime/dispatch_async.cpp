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
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;

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


typedef __darwin_sigset_t sigset_t;



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







struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};








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
extern "C" {
void __assert_rtn(const char *, const char *, int, const char *) __attribute__((__noreturn__)) __attribute__((__cold__)) __attribute__((__disable_tail_calls__));



}
typedef __darwin_wint_t wint_t;
typedef struct {
 __darwin_rune_t __min;
 __darwin_rune_t __max;
 __darwin_rune_t __map;
 __uint32_t *__types;
} _RuneEntry;

typedef struct {
 int __nranges;
 _RuneEntry *__ranges;
} _RuneRange;

typedef struct {
 char __name[14];
 __uint32_t __mask;
} _RuneCharClass;

typedef struct {
 char __magic[8];
 char __encoding[32];

 __darwin_rune_t (*__sgetrune)(const char *, __darwin_size_t, char const **);
 int (*__sputrune)(__darwin_rune_t, char *, __darwin_size_t, char **);
 __darwin_rune_t __invalid_rune;

 __uint32_t __runetype[(1 <<8 )];
 __darwin_rune_t __maplower[(1 <<8 )];
 __darwin_rune_t __mapupper[(1 <<8 )];






 _RuneRange __runetype_ext;
 _RuneRange __maplower_ext;
 _RuneRange __mapupper_ext;

 void *__variable;
 int __variable_len;




 int __ncharclasses;
 _RuneCharClass *__charclasses;
} _RuneLocale;



extern "C" {
extern _RuneLocale _DefaultRuneLocale;
extern _RuneLocale *_CurrentRuneLocale;
}
extern "C" {
unsigned long ___runetype(__darwin_ct_rune_t);
__darwin_ct_rune_t ___tolower(__darwin_ct_rune_t);
__darwin_ct_rune_t ___toupper(__darwin_ct_rune_t);
}

inline int
isascii(int _c)
{
 return ((_c & ~0x7F) == 0);
}
extern "C" {
int __maskrune(__darwin_ct_rune_t, unsigned long);
}


inline int
__istype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (isascii(_c) ? !!(_DefaultRuneLocale.__runetype[_c] & _f)
  : !!__maskrune(_c, _f));

}

inline __darwin_ct_rune_t
__isctype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (_c < 0 || _c >= (1 <<8 )) ? 0 :
  !!(_DefaultRuneLocale.__runetype[_c] & _f);

}
extern "C" {
__darwin_ct_rune_t __toupper(__darwin_ct_rune_t);
__darwin_ct_rune_t __tolower(__darwin_ct_rune_t);
}


inline int
__wcwidth(__darwin_ct_rune_t _c)
{
 unsigned int _x;

 if (_c == 0)
  return (0);
 _x = (unsigned int)__maskrune(_c, 0xe0000000L|0x00040000L);
 if ((_x & 0xe0000000L) != 0)
  return ((_x & 0xe0000000L) >> 30);
 return ((_x & 0x00040000L) != 0 ? 1 : -1);
}






inline int
isalnum(int _c)
{
 return (__istype(_c, 0x00000100L|0x00000400L));
}

inline int
isalpha(int _c)
{
 return (__istype(_c, 0x00000100L));
}

inline int
isblank(int _c)
{
 return (__istype(_c, 0x00020000L));
}

inline int
iscntrl(int _c)
{
 return (__istype(_c, 0x00000200L));
}


inline int
isdigit(int _c)
{
 return (__isctype(_c, 0x00000400L));
}

inline int
isgraph(int _c)
{
 return (__istype(_c, 0x00000800L));
}

inline int
islower(int _c)
{
 return (__istype(_c, 0x00001000L));
}

inline int
isprint(int _c)
{
 return (__istype(_c, 0x00040000L));
}

inline int
ispunct(int _c)
{
 return (__istype(_c, 0x00002000L));
}

inline int
isspace(int _c)
{
 return (__istype(_c, 0x00004000L));
}

inline int
isupper(int _c)
{
 return (__istype(_c, 0x00008000L));
}


inline int
isxdigit(int _c)
{
 return (__isctype(_c, 0x00010000L));
}

inline int
toascii(int _c)
{
 return (_c & 0x7F);
}

inline int
tolower(int _c)
{
        return (__tolower(_c));
}

inline int
toupper(int _c)
{
        return (__toupper(_c));
}


inline int
digittoint(int _c)
{
 return (__maskrune(_c, 0x0F));
}

inline int
ishexnumber(int _c)
{
 return (__istype(_c, 0x00010000L));
}

inline int
isideogram(int _c)
{
 return (__istype(_c, 0x00080000L));
}

inline int
isnumber(int _c)
{
 return (__istype(_c, 0x00000400L));
}

inline int
isphonogram(int _c)
{
 return (__istype(_c, 0x00200000L));
}

inline int
isrune(int _c)
{
 return (__istype(_c, 0xFFFFFFF0L));
}

inline int
isspecial(int _c)
{
 return (__istype(_c, 0x00100000L));
}
extern "C" {
extern int * __error(void);

}





struct lconv {
 char *decimal_point;
 char *thousands_sep;
 char *grouping;
 char *int_curr_symbol;
 char *currency_symbol;
 char *mon_decimal_point;
 char *mon_thousands_sep;
 char *mon_grouping;
 char *positive_sign;
 char *negative_sign;
 char int_frac_digits;
 char frac_digits;
 char p_cs_precedes;
 char p_sep_by_space;
 char n_cs_precedes;
 char n_sep_by_space;
 char p_sign_posn;
 char n_sign_posn;
 char int_p_cs_precedes;
 char int_n_cs_precedes;
 char int_p_sep_by_space;
 char int_n_sep_by_space;
 char int_p_sign_posn;
 char int_n_sign_posn;
};



extern "C" {
struct lconv *localeconv(void);
}
extern "C" {
char *setlocale(int, const char *);
}
extern "C" {
    typedef float float_t;
    typedef double double_t;
extern int __math_errhandling(void);
extern int __fpclassifyf(float);
extern int __fpclassifyd(double);
extern int __fpclassifyl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float);
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double);
inline __attribute__ ((__always_inline__)) int __inline_isinff(float);
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double);
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnand(double);
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double);
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double);
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float);
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double);
inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double);

inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float __x) {
    return __x == __x && __builtin_fabsf(__x) != __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double __x) {
    return __x == __x && __builtin_fabs(__x) != __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double __x) {
    return __x == __x && __builtin_fabsl(__x) != __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isinff(float __x) {
    return __builtin_fabsf(__x) == __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double __x) {
    return __builtin_fabs(__x) == __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double __x) {
    return __builtin_fabsl(__x) == __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnand(double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float __x) {
    union { float __f; unsigned int __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 31);
}
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double __x) {
    union { double __f; unsigned long long __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 63);
}

inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double __x) {
    union {
        long double __ld;
        struct{ unsigned long long __m; unsigned short __sexp; } __p;
    } __u;
    __u.__ld = __x;
    return (int)(__u.__p.__sexp >> 15);
}







inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float __x) {
    return __inline_isfinitef(__x) && __builtin_fabsf(__x) >= 1.17549435e-38F;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double __x) {
    return __inline_isfinited(__x) && __builtin_fabs(__x) >= 2.2250738585072014e-308;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double __x) {
    return __inline_isfinitel(__x) && __builtin_fabsl(__x) >= 3.36210314311209350626e-4932L;
}
extern float acosf(float);
extern double acos(double);
extern long double acosl(long double);

extern float asinf(float);
extern double asin(double);
extern long double asinl(long double);

extern float atanf(float);
extern double atan(double);
extern long double atanl(long double);

extern float atan2f(float, float);
extern double atan2(double, double);
extern long double atan2l(long double, long double);

extern float cosf(float);
extern double cos(double);
extern long double cosl(long double);

extern float sinf(float);
extern double sin(double);
extern long double sinl(long double);

extern float tanf(float);
extern double tan(double);
extern long double tanl(long double);

extern float acoshf(float);
extern double acosh(double);
extern long double acoshl(long double);

extern float asinhf(float);
extern double asinh(double);
extern long double asinhl(long double);

extern float atanhf(float);
extern double atanh(double);
extern long double atanhl(long double);

extern float coshf(float);
extern double cosh(double);
extern long double coshl(long double);

extern float sinhf(float);
extern double sinh(double);
extern long double sinhl(long double);

extern float tanhf(float);
extern double tanh(double);
extern long double tanhl(long double);

extern float expf(float);
extern double exp(double);
extern long double expl(long double);

extern float exp2f(float);
extern double exp2(double);
extern long double exp2l(long double);

extern float expm1f(float);
extern double expm1(double);
extern long double expm1l(long double);

extern float logf(float);
extern double log(double);
extern long double logl(long double);

extern float log10f(float);
extern double log10(double);
extern long double log10l(long double);

extern float log2f(float);
extern double log2(double);
extern long double log2l(long double);

extern float log1pf(float);
extern double log1p(double);
extern long double log1pl(long double);

extern float logbf(float);
extern double logb(double);
extern long double logbl(long double);

extern float modff(float, float *);
extern double modf(double, double *);
extern long double modfl(long double, long double *);

extern float ldexpf(float, int);
extern double ldexp(double, int);
extern long double ldexpl(long double, int);

extern float frexpf(float, int *);
extern double frexp(double, int *);
extern long double frexpl(long double, int *);

extern int ilogbf(float);
extern int ilogb(double);
extern int ilogbl(long double);

extern float scalbnf(float, int);
extern double scalbn(double, int);
extern long double scalbnl(long double, int);

extern float scalblnf(float, long int);
extern double scalbln(double, long int);
extern long double scalblnl(long double, long int);

extern float fabsf(float);
extern double fabs(double);
extern long double fabsl(long double);

extern float cbrtf(float);
extern double cbrt(double);
extern long double cbrtl(long double);

extern float hypotf(float, float);
extern double hypot(double, double);
extern long double hypotl(long double, long double);

extern float powf(float, float);
extern double pow(double, double);
extern long double powl(long double, long double);

extern float sqrtf(float);
extern double sqrt(double);
extern long double sqrtl(long double);

extern float erff(float);
extern double erf(double);
extern long double erfl(long double);

extern float erfcf(float);
extern double erfc(double);
extern long double erfcl(long double);




extern float lgammaf(float);
extern double lgamma(double);
extern long double lgammal(long double);

extern float tgammaf(float);
extern double tgamma(double);
extern long double tgammal(long double);

extern float ceilf(float);
extern double ceil(double);
extern long double ceill(long double);

extern float floorf(float);
extern double floor(double);
extern long double floorl(long double);

extern float nearbyintf(float);
extern double nearbyint(double);
extern long double nearbyintl(long double);

extern float rintf(float);
extern double rint(double);
extern long double rintl(long double);

extern long int lrintf(float);
extern long int lrint(double);
extern long int lrintl(long double);

extern float roundf(float);
extern double round(double);
extern long double roundl(long double);

extern long int lroundf(float);
extern long int lround(double);
extern long int lroundl(long double);




extern long long int llrintf(float);
extern long long int llrint(double);
extern long long int llrintl(long double);

extern long long int llroundf(float);
extern long long int llround(double);
extern long long int llroundl(long double);


extern float truncf(float);
extern double trunc(double);
extern long double truncl(long double);

extern float fmodf(float, float);
extern double fmod(double, double);
extern long double fmodl(long double, long double);

extern float remainderf(float, float);
extern double remainder(double, double);
extern long double remainderl(long double, long double);

extern float remquof(float, float, int *);
extern double remquo(double, double, int *);
extern long double remquol(long double, long double, int *);

extern float copysignf(float, float);
extern double copysign(double, double);
extern long double copysignl(long double, long double);

extern float nanf(const char *);
extern double nan(const char *);
extern long double nanl(const char *);

extern float nextafterf(float, float);
extern double nextafter(double, double);
extern long double nextafterl(long double, long double);

extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);

extern float fdimf(float, float);
extern double fdim(double, double);
extern long double fdiml(long double, long double);

extern float fmaxf(float, float);
extern double fmax(double, double);
extern long double fmaxl(long double, long double);

extern float fminf(float, float);
extern double fmin(double, double);
extern long double fminl(long double, long double);

extern float fmaf(float, float, float);
extern double fma(double, double, double);
extern long double fmal(long double, long double, long double);
extern float __inff(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="use `(float)INFINITY` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
extern double __inf(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="use `INFINITY` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
extern long double __infl(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="use `(long double)INFINITY` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
extern float __nan(void)
__attribute__((availability(macos,introduced=10.0,deprecated=10.14,message="use `NAN` instead"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
extern float __exp10f(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __exp10(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));





inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp);
extern float __cospif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __cospi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern float __sinpif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __sinpi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern float __tanpif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __tanpi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp);






struct __float2 { float __sinval; float __cosval; };
struct __double2 { double __sinval; double __cosval; };

extern struct __float2 __sincosf_stret(float);
extern struct __double2 __sincos_stret(double);
extern struct __float2 __sincospif_stret(float);
extern struct __double2 __sincospi_stret(double);

inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincosf_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincos_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincospif_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincospi_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}







extern double j0(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double j1(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double jn(int, double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double y0(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double y1(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double yn(int, double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double scalb(double, double);
extern int signgam;
extern long int rinttol(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="lrint"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern long int roundtol(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="lround"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern double drem(double, double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="remainder"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern int finite(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use `isfinite((double)x)` instead."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern double gamma(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,replacement="tgamma"))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern double significand(double)
__attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use `2*frexp( )` or `scalbn(x, -ilogb(x))` instead."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
}
typedef int jmp_buf[((9 * 2) + 3 + 16)];
typedef int sigjmp_buf[((9 * 2) + 3 + 16) + 1];
extern "C" {
extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int) __attribute__((__noreturn__));


int _setjmp(jmp_buf);
void _longjmp(jmp_buf, int) __attribute__((__noreturn__));
int sigsetjmp(sigjmp_buf, int);
void siglongjmp(sigjmp_buf, int) __attribute__((__noreturn__));



void longjmperror(void);

}
extern const char *const sys_signame[32];
extern const char *const sys_siglist[32];


extern "C" {
int raise(int);
}


extern "C" {
void (* _Nullable bsd_signal(int, void (* _Nullable)(int)))(int);
int kill(pid_t, int) __asm("_" "kill" );
int killpg(pid_t, int) __asm("_" "killpg" );
int pthread_kill(pthread_t, int);
int pthread_sigmask(int, const sigset_t *, sigset_t *) __asm("_" "pthread_sigmask" );
int sigaction(int, const struct sigaction * ,
     struct sigaction * );
int sigaddset(sigset_t *, int);
int sigaltstack(const stack_t * , stack_t * ) __asm("_" "sigaltstack" ) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int sigdelset(sigset_t *, int);
int sigemptyset(sigset_t *);
int sigfillset(sigset_t *);
int sighold(int);
int sigignore(int);
int siginterrupt(int, int);
int sigismember(const sigset_t *, int);
int sigpause(int) __asm("_" "sigpause" );
int sigpending(sigset_t *);
int sigprocmask(int, const sigset_t * , sigset_t * );
int sigrelse(int);
void (* _Nullable sigset(int, void (* _Nullable)(int)))(int);
int sigsuspend(const sigset_t *) __asm("_" "sigsuspend" );
int sigwait(const sigset_t * , int * ) __asm("_" "sigwait" );

void psignal(unsigned int, const char *);
int sigblock(int);
int sigsetmask(int);
int sigvec(int, struct sigvec *, struct sigvec *);

}


inline __attribute__ ((__always_inline__)) int
__sigbits(int __signo)
{
    return __signo > 32 ? 0 : (1 << (__signo - 1));
}
typedef long int ptrdiff_t;
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

extern "C" {

char *ctermid(char *);

}




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


struct timespec
{
 __darwin_time_t tv_sec;
 long tv_nsec;
};

struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long tm_gmtoff;
 char *tm_zone;
};
extern char *tzname[];


extern int getdate_err;

extern long timezone __asm("_" "timezone" );

extern int daylight;

extern "C" {
char *asctime(const struct tm *);
clock_t clock(void) __asm("_" "clock" );
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *) __asm("_" "mktime" );
size_t strftime(char * , size_t, const char * , const struct tm * ) __asm("_" "strftime" );
char *strptime(const char * , const char * , struct tm * ) __asm("_" "strptime" );
time_t time(time_t *);


void tzset(void);



char *asctime_r(const struct tm * , char * );
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t * , struct tm * );
struct tm *localtime_r(const time_t * , struct tm * );


time_t posix2time(time_t);



void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm * const);
time_t timegm(struct tm * const);



int nanosleep(const struct timespec *__rqtp, struct timespec *__rmtp) __asm("_" "nanosleep" );
typedef enum {
_CLOCK_REALTIME __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 0,

_CLOCK_MONOTONIC __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 6,


_CLOCK_MONOTONIC_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 4,

_CLOCK_MONOTONIC_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 5,

_CLOCK_UPTIME_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 8,

_CLOCK_UPTIME_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 9,


_CLOCK_PROCESS_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 12,

_CLOCK_THREAD_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 16

} clockid_t;

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_getres(clockid_t __clock_id, struct timespec *__res);

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_gettime(clockid_t __clock_id, struct timespec *__tp);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
__uint64_t clock_gettime_nsec_np(clockid_t __clock_id);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,unavailable)))
__attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
int clock_settime(clockid_t __clock_id, const struct timespec *__tp);
}






extern "C" {





extern "C" __attribute__((__visibility__("default"))) void *_Block_copy(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) void _Block_release(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) void _Block_object_assign(void *, const void *, const int);


extern "C" __attribute__((__visibility__("default"))) void _Block_object_dispose(const void *, const int);






extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteGlobalBlock[32];
extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteStackBlock[32];



}




extern "C" {


#pragma pack(push, 2)
typedef unsigned char UInt8;
typedef signed char SInt8;
typedef unsigned short UInt16;
typedef signed short SInt16;


typedef unsigned int UInt32;
typedef signed int SInt32;
struct wide {
  UInt32 lo;
  SInt32 hi;
};
typedef struct wide wide;
struct UnsignedWide {
  UInt32 lo;
  UInt32 hi;
};
typedef struct UnsignedWide UnsignedWide;
      typedef signed long long SInt64;
        typedef unsigned long long UInt64;
typedef SInt32 Fixed;
typedef Fixed * FixedPtr;
typedef SInt32 Fract;
typedef Fract * FractPtr;
typedef UInt32 UnsignedFixed;
typedef UnsignedFixed * UnsignedFixedPtr;
typedef short ShortFixed;
typedef ShortFixed * ShortFixedPtr;
typedef float Float32;
typedef double Float64;
struct Float80 {
    SInt16 exp;
    UInt16 man[4];
};
typedef struct Float80 Float80;

struct Float96 {
    SInt16 exp[2];
    UInt16 man[4];
};
typedef struct Float96 Float96;
struct Float32Point {
    Float32 x;
    Float32 y;
};
typedef struct Float32Point Float32Point;
typedef char * Ptr;
typedef Ptr * Handle;
typedef long Size;
typedef SInt16 OSErr;
typedef SInt32 OSStatus;
typedef void * LogicalAddress;
typedef const void * ConstLogicalAddress;
typedef void * PhysicalAddress;
typedef UInt8 * BytePtr;
typedef unsigned long ByteCount;
typedef unsigned long ByteOffset;
typedef SInt32 Duration;
typedef UnsignedWide AbsoluteTime;
typedef UInt32 OptionBits;
typedef unsigned long ItemCount;
typedef UInt32 PBVersion;
typedef SInt16 ScriptCode;
typedef SInt16 LangCode;
typedef SInt16 RegionCode;
typedef UInt32 FourCharCode;
typedef FourCharCode OSType;
typedef FourCharCode ResType;
typedef OSType * OSTypePtr;
typedef ResType * ResTypePtr;
typedef unsigned char Boolean;
typedef long ( * ProcPtr)(void);
typedef void ( * Register68kProcPtr)(void);




typedef ProcPtr UniversalProcPtr;


typedef ProcPtr * ProcHandle;
typedef UniversalProcPtr * UniversalProcHandle;
typedef void * PRefCon;

typedef void * URefCon;
typedef void * SRefCon;
enum {
  noErr = 0
};

enum {
  kNilOptions = 0
};


enum {
  kVariableLengthArray


  __attribute__((deprecated))


  = 1
};

enum {
  kUnknownType = 0x3F3F3F3F
};
typedef UInt32 UnicodeScalarValue;
typedef UInt32 UTF32Char;
typedef UInt16 UniChar;
typedef UInt16 UTF16Char;
typedef UInt8 UTF8Char;
typedef UniChar * UniCharPtr;
typedef unsigned long UniCharCount;
typedef UniCharCount * UniCharCountPtr;
typedef unsigned char Str255[256];
typedef unsigned char Str63[64];
typedef unsigned char Str32[33];
typedef unsigned char Str31[32];
typedef unsigned char Str27[28];
typedef unsigned char Str15[16];
typedef unsigned char Str32Field[34];
typedef Str63 StrFileName;
typedef unsigned char * StringPtr;
typedef StringPtr * StringHandle;
typedef const unsigned char * ConstStringPtr;
typedef const unsigned char * ConstStr255Param;
typedef const unsigned char * ConstStr63Param;
typedef const unsigned char * ConstStr32Param;
typedef const unsigned char * ConstStr31Param;
typedef const unsigned char * ConstStr27Param;
typedef const unsigned char * ConstStr15Param;
typedef ConstStr63Param ConstStrFileNameParam;

inline unsigned char StrLength(ConstStr255Param string) { return (*string); }
struct ProcessSerialNumber {
  UInt32 highLongOfPSN;
  UInt32 lowLongOfPSN;
};
typedef struct ProcessSerialNumber ProcessSerialNumber;
typedef ProcessSerialNumber * ProcessSerialNumberPtr;
struct Point {
  short v;
  short h;
};
typedef struct Point Point;
typedef Point * PointPtr;
struct Rect {
  short top;
  short left;
  short bottom;
  short right;
};
typedef struct Rect Rect;
typedef Rect * RectPtr;
struct FixedPoint {
  Fixed x;
  Fixed y;
};
typedef struct FixedPoint FixedPoint;
struct FixedRect {
  Fixed left;
  Fixed top;
  Fixed right;
  Fixed bottom;
};
typedef struct FixedRect FixedRect;

typedef short CharParameter;
enum {
  normal = 0,
  bold = 1,
  italic = 2,
  underline = 4,
  outline = 8,
  shadow = 0x10,
  condense = 0x20,
  extend = 0x40
};

typedef unsigned char Style;
typedef short StyleParameter;
typedef Style StyleField;
typedef SInt32 TimeValue;
typedef SInt32 TimeScale;
typedef wide CompTimeValue;
typedef SInt64 TimeValue64;
typedef struct TimeBaseRecord* TimeBase;
struct TimeRecord {
  CompTimeValue value;
  TimeScale scale;
  TimeBase base;
};
typedef struct TimeRecord TimeRecord;
struct NumVersion {

  UInt8 nonRelRev;
  UInt8 stage;
  UInt8 minorAndBugRev;
  UInt8 majorRev;
};
typedef struct NumVersion NumVersion;


enum {

  developStage = 0x20,
  alphaStage = 0x40,
  betaStage = 0x60,
  finalStage = 0x80
};

union NumVersionVariant {

  NumVersion parts;
  UInt32 whole;
};
typedef union NumVersionVariant NumVersionVariant;
typedef NumVersionVariant * NumVersionVariantPtr;
typedef NumVersionVariantPtr * NumVersionVariantHandle;
struct VersRec {

  NumVersion numericVersion;
  short countryCode;
  Str255 shortVersion;
  Str255 reserved;
};
typedef struct VersRec VersRec;
typedef VersRec * VersRecPtr;
typedef VersRecPtr * VersRecHndl;





typedef UInt8 Byte;
typedef SInt8 SignedByte;
typedef wide * WidePtr;
typedef UnsignedWide * UnsignedWidePtr;
typedef Float80 extended80;
typedef Float96 extended96;
typedef SInt8 VHSelect;
extern void
Debugger(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
DebugStr(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
SysBreak(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
SysBreakStr(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
SysBreakFunc(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
#pragma pack(pop)


}
extern "C" {
// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSAttributedString;
#ifndef _REWRITER_typedef_NSAttributedString
#define _REWRITER_typedef_NSAttributedString
typedef struct objc_object NSAttributedString;
typedef struct {} _objc_exc_NSAttributedString;
#endif

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSNull;
#ifndef _REWRITER_typedef_NSNull
#define _REWRITER_typedef_NSNull
typedef struct objc_object NSNull;
typedef struct {} _objc_exc_NSNull;
#endif

// @class NSCharacterSet;
#ifndef _REWRITER_typedef_NSCharacterSet
#define _REWRITER_typedef_NSCharacterSet
typedef struct objc_object NSCharacterSet;
typedef struct {} _objc_exc_NSCharacterSet;
#endif

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

// @class NSDate;
#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

// @class NSTimeZone;
#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
typedef struct objc_object NSTimeZone;
typedef struct {} _objc_exc_NSTimeZone;
#endif

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

// @class NSLocale;
#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif

// @class NSNumber;
#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

// @class NSSet;
#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

extern double kCFCoreFoundationVersionNumber;
typedef unsigned long CFTypeID;
typedef unsigned long CFOptionFlags;
typedef unsigned long CFHashCode;
typedef signed long CFIndex;



typedef const __attribute__((objc_bridge(id))) void * CFTypeRef;

typedef const struct __attribute__((objc_bridge(NSString))) __CFString * CFStringRef;
typedef struct __attribute__((objc_bridge_mutable(NSMutableString))) __CFString * CFMutableStringRef;






typedef __attribute__((objc_bridge(id))) CFTypeRef CFPropertyListRef;


typedef CFIndex CFComparisonResult; enum {
    kCFCompareLessThan = -1L,
    kCFCompareEqualTo = 0,
    kCFCompareGreaterThan = 1
};


typedef CFComparisonResult (*CFComparatorFunction)(const void *val1, const void *val2, void *context);


static const CFIndex kCFNotFound = -1;



typedef struct {
    CFIndex location;
    CFIndex length;
} CFRange;


static __inline__ __attribute__((always_inline)) CFRange CFRangeMake(CFIndex loc, CFIndex len) {
    CFRange range;
    range.location = loc;
    range.length = len;
    return range;
}





extern
CFRange __CFRangeMake(CFIndex loc, CFIndex len);




typedef const struct __attribute__((objc_bridge(NSNull))) __CFNull * CFNullRef;

extern
CFTypeID CFNullGetTypeID(void);

extern
const CFNullRef kCFNull;
typedef const struct __attribute__((objc_bridge(id))) __CFAllocator * CFAllocatorRef;


extern
const CFAllocatorRef kCFAllocatorDefault;


extern
const CFAllocatorRef kCFAllocatorSystemDefault;







extern
const CFAllocatorRef kCFAllocatorMalloc;





extern
const CFAllocatorRef kCFAllocatorMallocZone;





extern
const CFAllocatorRef kCFAllocatorNull;





extern
const CFAllocatorRef kCFAllocatorUseContext;

typedef const void * (*CFAllocatorRetainCallBack)(const void *info);
typedef void (*CFAllocatorReleaseCallBack)(const void *info);
typedef CFStringRef (*CFAllocatorCopyDescriptionCallBack)(const void *info);
typedef void * (*CFAllocatorAllocateCallBack)(CFIndex allocSize, CFOptionFlags hint, void *info);
typedef void * (*CFAllocatorReallocateCallBack)(void *ptr, CFIndex newsize, CFOptionFlags hint, void *info);
typedef void (*CFAllocatorDeallocateCallBack)(void *ptr, void *info);
typedef CFIndex (*CFAllocatorPreferredSizeCallBack)(CFIndex size, CFOptionFlags hint, void *info);
typedef struct {
    CFIndex version;
    void * info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
    CFAllocatorAllocateCallBack allocate;
    CFAllocatorReallocateCallBack reallocate;
    CFAllocatorDeallocateCallBack deallocate;
    CFAllocatorPreferredSizeCallBack preferredSize;
} CFAllocatorContext;

extern
CFTypeID CFAllocatorGetTypeID(void);
extern
void CFAllocatorSetDefault(CFAllocatorRef allocator);

extern
CFAllocatorRef CFAllocatorGetDefault(void);

extern
CFAllocatorRef CFAllocatorCreate(CFAllocatorRef allocator, CFAllocatorContext *context);

extern
void *CFAllocatorAllocate(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

extern
void *CFAllocatorReallocate(CFAllocatorRef allocator, void *ptr, CFIndex newsize, CFOptionFlags hint);

extern
void CFAllocatorDeallocate(CFAllocatorRef allocator, void *ptr);

extern
CFIndex CFAllocatorGetPreferredSizeForSize(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

extern
void CFAllocatorGetContext(CFAllocatorRef allocator, CFAllocatorContext *context);






extern
CFTypeID CFGetTypeID(CFTypeRef cf);

extern
CFStringRef CFCopyTypeIDDescription(CFTypeID type_id);

extern
CFTypeRef CFRetain(CFTypeRef cf);

extern
void CFRelease(CFTypeRef cf);



extern
CFTypeRef CFAutorelease(CFTypeRef __attribute__((cf_consumed)) arg) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
CFIndex CFGetRetainCount(CFTypeRef cf);


extern
Boolean CFEqual(CFTypeRef cf1, CFTypeRef cf2);

extern
CFHashCode CFHash(CFTypeRef cf);

extern
CFStringRef CFCopyDescription(CFTypeRef cf);

extern
CFAllocatorRef CFGetAllocator(CFTypeRef cf);




extern
CFTypeRef CFMakeCollectable(CFTypeRef cf) ;
typedef enum {
  ptrauth_key_asia = 0,
  ptrauth_key_asib = 1,
  ptrauth_key_asda = 2,
  ptrauth_key_asdb = 3,




  ptrauth_key_process_independent_code = ptrauth_key_asia,




  ptrauth_key_process_dependent_code = ptrauth_key_asib,




  ptrauth_key_process_independent_data = ptrauth_key_asda,




  ptrauth_key_process_dependent_data = ptrauth_key_asdb,



  ptrauth_key_function_pointer = ptrauth_key_process_independent_code,





  ptrauth_key_return_address = ptrauth_key_process_dependent_code,





  ptrauth_key_frame_pointer = ptrauth_key_process_dependent_data,
  ptrauth_key_block_function = ptrauth_key_asia,



  ptrauth_key_cxx_vtable_pointer = ptrauth_key_asda,


  ptrauth_key_method_list_pointer = ptrauth_key_asda,


  ptrauth_key_objc_isa_pointer = ptrauth_key_process_independent_data,
  ptrauth_key_objc_super_pointer = ptrauth_key_process_independent_data,


  ptrauth_key_block_descriptor_pointer = ptrauth_key_asda,



} ptrauth_key;


typedef long unsigned int ptrauth_extra_data_t;


typedef long unsigned int ptrauth_generic_signature_t;
}
extern "C" {
typedef const void * (*CFArrayRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void (*CFArrayReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef (*CFArrayCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFArrayEqualCallBack)(const void *value1, const void *value2);
typedef struct {
    CFIndex version;
    CFArrayRetainCallBack retain;
    CFArrayReleaseCallBack release;
    CFArrayCopyDescriptionCallBack copyDescription;
    CFArrayEqualCallBack equal;
} CFArrayCallBacks;






extern
const CFArrayCallBacks kCFTypeArrayCallBacks;
typedef void (*CFArrayApplierFunction)(const void *value, void *context);





typedef const struct __attribute__((objc_bridge(NSArray))) __CFArray * CFArrayRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableArray))) __CFArray * CFMutableArrayRef;





extern
CFTypeID CFArrayGetTypeID(void);
extern
CFArrayRef CFArrayCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFArrayCallBacks *callBacks);
extern
CFArrayRef CFArrayCreateCopy(CFAllocatorRef allocator, CFArrayRef theArray);
extern
CFMutableArrayRef CFArrayCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFArrayCallBacks *callBacks);
extern
CFMutableArrayRef CFArrayCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFArrayRef theArray);
extern
CFIndex CFArrayGetCount(CFArrayRef theArray);
extern
CFIndex CFArrayGetCountOfValue(CFArrayRef theArray, CFRange range, const void *value);
extern
Boolean CFArrayContainsValue(CFArrayRef theArray, CFRange range, const void *value);
extern
const void *CFArrayGetValueAtIndex(CFArrayRef theArray, CFIndex idx);
extern
void CFArrayGetValues(CFArrayRef theArray, CFRange range, const void **values);
extern
void CFArrayApplyFunction(CFArrayRef theArray, CFRange range, CFArrayApplierFunction __attribute__((noescape)) applier, void *context);
extern
CFIndex CFArrayGetFirstIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);
extern
CFIndex CFArrayGetLastIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);
extern
CFIndex CFArrayBSearchValues(CFArrayRef theArray, CFRange range, const void *value, CFComparatorFunction comparator, void *context);
extern
void CFArrayAppendValue(CFMutableArrayRef theArray, const void *value);
extern
void CFArrayInsertValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);
extern
void CFArraySetValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);
extern
void CFArrayRemoveValueAtIndex(CFMutableArrayRef theArray, CFIndex idx);
extern
void CFArrayRemoveAllValues(CFMutableArrayRef theArray);
extern
void CFArrayReplaceValues(CFMutableArrayRef theArray, CFRange range, const void **newValues, CFIndex newCount);
extern
void CFArrayExchangeValuesAtIndices(CFMutableArrayRef theArray, CFIndex idx1, CFIndex idx2);
extern
void CFArraySortValues(CFMutableArrayRef theArray, CFRange range, CFComparatorFunction comparator, void *context);
extern
void CFArrayAppendArray(CFMutableArrayRef theArray, CFArrayRef otherArray, CFRange otherRange);

}
extern "C" {

typedef const void * (*CFBagRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void (*CFBagReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef (*CFBagCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFBagEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode (*CFBagHashCallBack)(const void *value);
typedef struct {
    CFIndex version;
    CFBagRetainCallBack retain;
    CFBagReleaseCallBack release;
    CFBagCopyDescriptionCallBack copyDescription;
    CFBagEqualCallBack equal;
    CFBagHashCallBack hash;
} CFBagCallBacks;

extern
const CFBagCallBacks kCFTypeBagCallBacks;
extern
const CFBagCallBacks kCFCopyStringBagCallBacks;

typedef void (*CFBagApplierFunction)(const void *value, void *context);

typedef const struct __attribute__((objc_bridge(id))) __CFBag * CFBagRef;
typedef struct __attribute__((objc_bridge_mutable(id))) __CFBag * CFMutableBagRef;

extern
CFTypeID CFBagGetTypeID(void);

extern
CFBagRef CFBagCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFBagCallBacks *callBacks);

extern
CFBagRef CFBagCreateCopy(CFAllocatorRef allocator, CFBagRef theBag);

extern
CFMutableBagRef CFBagCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFBagCallBacks *callBacks);

extern
CFMutableBagRef CFBagCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFBagRef theBag);

extern
CFIndex CFBagGetCount(CFBagRef theBag);

extern
CFIndex CFBagGetCountOfValue(CFBagRef theBag, const void *value);

extern
Boolean CFBagContainsValue(CFBagRef theBag, const void *value);

extern
const void *CFBagGetValue(CFBagRef theBag, const void *value);

extern
Boolean CFBagGetValueIfPresent(CFBagRef theBag, const void *candidate, const void **value);

extern
void CFBagGetValues(CFBagRef theBag, const void **values);

extern
void CFBagApplyFunction(CFBagRef theBag, CFBagApplierFunction __attribute__((noescape)) applier, void *context);

extern
void CFBagAddValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagReplaceValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagSetValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagRemoveValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagRemoveAllValues(CFMutableBagRef theBag);

}
extern "C" {

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFBinaryHeapCompareContext;
typedef struct {
    CFIndex version;
    const void *(*retain)(CFAllocatorRef allocator, const void *ptr);
    void (*release)(CFAllocatorRef allocator, const void *ptr);
    CFStringRef (*copyDescription)(const void *ptr);
    CFComparisonResult (*compare)(const void *ptr1, const void *ptr2, void *context);
} CFBinaryHeapCallBacks;







extern const CFBinaryHeapCallBacks kCFStringBinaryHeapCallBacks;
typedef void (*CFBinaryHeapApplierFunction)(const void *val, void *context);





typedef struct __attribute__((objc_bridge_mutable(id))) __CFBinaryHeap * CFBinaryHeapRef;





extern CFTypeID CFBinaryHeapGetTypeID(void);
extern CFBinaryHeapRef CFBinaryHeapCreate(CFAllocatorRef allocator, CFIndex capacity, const CFBinaryHeapCallBacks *callBacks, const CFBinaryHeapCompareContext *compareContext);
extern CFBinaryHeapRef CFBinaryHeapCreateCopy(CFAllocatorRef allocator, CFIndex capacity, CFBinaryHeapRef heap);
extern CFIndex CFBinaryHeapGetCount(CFBinaryHeapRef heap);
extern CFIndex CFBinaryHeapGetCountOfValue(CFBinaryHeapRef heap, const void *value);
extern Boolean CFBinaryHeapContainsValue(CFBinaryHeapRef heap, const void *value);
extern const void * CFBinaryHeapGetMinimum(CFBinaryHeapRef heap);
extern Boolean CFBinaryHeapGetMinimumIfPresent(CFBinaryHeapRef heap, const void **value);
extern void CFBinaryHeapGetValues(CFBinaryHeapRef heap, const void **values);
extern void CFBinaryHeapApplyFunction(CFBinaryHeapRef heap, CFBinaryHeapApplierFunction __attribute__((noescape)) applier, void *context);
extern void CFBinaryHeapAddValue(CFBinaryHeapRef heap, const void *value);







extern void CFBinaryHeapRemoveMinimumValue(CFBinaryHeapRef heap);
extern void CFBinaryHeapRemoveAllValues(CFBinaryHeapRef heap);

}
extern "C" {

typedef UInt32 CFBit;

typedef const struct __attribute__((objc_bridge(id))) __CFBitVector * CFBitVectorRef;
typedef struct __attribute__((objc_bridge_mutable(id))) __CFBitVector * CFMutableBitVectorRef;

extern CFTypeID CFBitVectorGetTypeID(void);

extern CFBitVectorRef CFBitVectorCreate(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex numBits);
extern CFBitVectorRef CFBitVectorCreateCopy(CFAllocatorRef allocator, CFBitVectorRef bv);
extern CFMutableBitVectorRef CFBitVectorCreateMutable(CFAllocatorRef allocator, CFIndex capacity);
extern CFMutableBitVectorRef CFBitVectorCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFBitVectorRef bv);

extern CFIndex CFBitVectorGetCount(CFBitVectorRef bv);
extern CFIndex CFBitVectorGetCountOfBit(CFBitVectorRef bv, CFRange range, CFBit value);
extern Boolean CFBitVectorContainsBit(CFBitVectorRef bv, CFRange range, CFBit value);
extern CFBit CFBitVectorGetBitAtIndex(CFBitVectorRef bv, CFIndex idx);
extern void CFBitVectorGetBits(CFBitVectorRef bv, CFRange range, UInt8 *bytes);
extern CFIndex CFBitVectorGetFirstIndexOfBit(CFBitVectorRef bv, CFRange range, CFBit value);
extern CFIndex CFBitVectorGetLastIndexOfBit(CFBitVectorRef bv, CFRange range, CFBit value);

extern void CFBitVectorSetCount(CFMutableBitVectorRef bv, CFIndex count);
extern void CFBitVectorFlipBitAtIndex(CFMutableBitVectorRef bv, CFIndex idx);
extern void CFBitVectorFlipBits(CFMutableBitVectorRef bv, CFRange range);
extern void CFBitVectorSetBitAtIndex(CFMutableBitVectorRef bv, CFIndex idx, CFBit value);
extern void CFBitVectorSetBits(CFMutableBitVectorRef bv, CFRange range, CFBit value);
extern void CFBitVectorSetAllBits(CFMutableBitVectorRef bv, CFBit value);

}



static __inline__
uint16_t
OSReadSwapInt16(
 const volatile void * base,
 uintptr_t byteOffset
 )
{
 uint16_t result;

 result = *(volatile uint16_t *)((uintptr_t)base + byteOffset);
 return _OSSwapInt16(result);
}

static __inline__
uint32_t
OSReadSwapInt32(
 const volatile void * base,
 uintptr_t byteOffset
 )
{
 uint32_t result;

 result = *(volatile uint32_t *)((uintptr_t)base + byteOffset);
 return _OSSwapInt32(result);
}

static __inline__
uint64_t
OSReadSwapInt64(
 const volatile void * base,
 uintptr_t byteOffset
 )
{
 uint64_t result;

 result = *(volatile uint64_t *)((uintptr_t)base + byteOffset);
 return _OSSwapInt64(result);
}



static __inline__
void
OSWriteSwapInt16(
 volatile void * base,
 uintptr_t byteOffset,
 uint16_t data
 )
{
 *(volatile uint16_t *)((uintptr_t)base + byteOffset) = _OSSwapInt16(data);
}

static __inline__
void
OSWriteSwapInt32(
 volatile void * base,
 uintptr_t byteOffset,
 uint32_t data
 )
{
 *(volatile uint32_t *)((uintptr_t)base + byteOffset) = _OSSwapInt32(data);
}

static __inline__
void
OSWriteSwapInt64(
 volatile void * base,
 uintptr_t byteOffset,
 uint64_t data
 )
{
 *(volatile uint64_t *)((uintptr_t)base + byteOffset) = _OSSwapInt64(data);
}
enum {
 OSUnknownByteOrder,
 OSLittleEndian,
 OSBigEndian
};

static inline
int32_t
OSHostByteOrder(void)
{

 return OSLittleEndian;





}
static inline
uint16_t
_OSReadInt16(
 const volatile void * base,
 uintptr_t byteOffset
 )
{
 return *(volatile uint16_t *)((uintptr_t)base + byteOffset);
}

static inline
uint32_t
_OSReadInt32(
 const volatile void * base,
 uintptr_t byteOffset
 )
{
 return *(volatile uint32_t *)((uintptr_t)base + byteOffset);
}

static inline
uint64_t
_OSReadInt64(
 const volatile void * base,
 uintptr_t byteOffset
 )
{
 return *(volatile uint64_t *)((uintptr_t)base + byteOffset);
}



static inline
void
_OSWriteInt16(
 volatile void * base,
 uintptr_t byteOffset,
 uint16_t data
 )
{
 *(volatile uint16_t *)((uintptr_t)base + byteOffset) = data;
}

static inline
void
_OSWriteInt32(
 volatile void * base,
 uintptr_t byteOffset,
 uint32_t data
 )
{
 *(volatile uint32_t *)((uintptr_t)base + byteOffset) = data;
}

static inline
void
_OSWriteInt64(
 volatile void * base,
 uintptr_t byteOffset,
 uint64_t data
 )
{
 *(volatile uint64_t *)((uintptr_t)base + byteOffset) = data;
}



extern "C" {

enum __CFByteOrder {
    CFByteOrderUnknown,
    CFByteOrderLittleEndian,
    CFByteOrderBigEndian
};
typedef CFIndex CFByteOrder;

static __inline__ __attribute__((always_inline)) CFByteOrder CFByteOrderGetCurrent(void) {

    int32_t byteOrder = OSHostByteOrder();
    switch (byteOrder) {
    case OSLittleEndian: return CFByteOrderLittleEndian;
    case OSBigEndian: return CFByteOrderBigEndian;
    default: break;
    }
    return CFByteOrderUnknown;
}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16(uint16_t arg) {

    return ((__uint16_t)(__builtin_constant_p(arg) ? ((__uint16_t)((((__uint16_t)(arg) & 0xff00U) >> 8) | (((__uint16_t)(arg) & 0x00ffU) << 8))) : _OSSwapInt16(arg)));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32(uint32_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint32_t)((((__uint32_t)(arg) & 0xff000000U) >> 24) | (((__uint32_t)(arg) & 0x00ff0000U) >> 8) | (((__uint32_t)(arg) & 0x0000ff00U) << 8) | (((__uint32_t)(arg) & 0x000000ffU) << 24))) : _OSSwapInt32(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64(uint64_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint64_t)((((__uint64_t)(arg) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(arg) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(arg) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(arg) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(arg) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(arg) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(arg) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(arg) & 0x00000000000000ffULL) << 56))) : _OSSwapInt64(arg));
}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16BigToHost(uint16_t arg) {

    return ((__uint16_t)(__builtin_constant_p(arg) ? ((__uint16_t)((((__uint16_t)(arg) & 0xff00U) >> 8) | (((__uint16_t)(arg) & 0x00ffU) << 8))) : _OSSwapInt16(arg)));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32BigToHost(uint32_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint32_t)((((__uint32_t)(arg) & 0xff000000U) >> 24) | (((__uint32_t)(arg) & 0x00ff0000U) >> 8) | (((__uint32_t)(arg) & 0x0000ff00U) << 8) | (((__uint32_t)(arg) & 0x000000ffU) << 24))) : _OSSwapInt32(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64BigToHost(uint64_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint64_t)((((__uint64_t)(arg) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(arg) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(arg) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(arg) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(arg) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(arg) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(arg) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(arg) & 0x00000000000000ffULL) << 56))) : _OSSwapInt64(arg));





}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16HostToBig(uint16_t arg) {

    return ((__uint16_t)(__builtin_constant_p(arg) ? ((__uint16_t)((((__uint16_t)(arg) & 0xff00U) >> 8) | (((__uint16_t)(arg) & 0x00ffU) << 8))) : _OSSwapInt16(arg)));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32HostToBig(uint32_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint32_t)((((__uint32_t)(arg) & 0xff000000U) >> 24) | (((__uint32_t)(arg) & 0x00ff0000U) >> 8) | (((__uint32_t)(arg) & 0x0000ff00U) << 8) | (((__uint32_t)(arg) & 0x000000ffU) << 24))) : _OSSwapInt32(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64HostToBig(uint64_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint64_t)((((__uint64_t)(arg) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(arg) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(arg) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(arg) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(arg) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(arg) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(arg) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(arg) & 0x00000000000000ffULL) << 56))) : _OSSwapInt64(arg));





}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16LittleToHost(uint16_t arg) {

    return ((uint16_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32LittleToHost(uint32_t arg) {

    return ((uint32_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64LittleToHost(uint64_t arg) {

    return ((uint64_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16HostToLittle(uint16_t arg) {

    return ((uint16_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32HostToLittle(uint32_t arg) {

    return ((uint32_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64HostToLittle(uint64_t arg) {

    return ((uint64_t)(arg));





}

typedef struct {uint32_t v;} CFSwappedFloat32;
typedef struct {uint64_t v;} CFSwappedFloat64;

static __inline__ __attribute__((always_inline)) CFSwappedFloat32 CFConvertFloat32HostToSwapped(Float32 arg) {
    union CFSwap {
 Float32 v;
 CFSwappedFloat32 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) Float32 CFConvertFloat32SwappedToHost(CFSwappedFloat32 arg) {
    union CFSwap {
 Float32 v;
 CFSwappedFloat32 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.v;
}

static __inline__ __attribute__((always_inline)) CFSwappedFloat64 CFConvertFloat64HostToSwapped(Float64 arg) {
    union CFSwap {
 Float64 v;
 CFSwappedFloat64 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) Float64 CFConvertFloat64SwappedToHost(CFSwappedFloat64 arg) {
    union CFSwap {
 Float64 v;
 CFSwappedFloat64 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.v;
}

static __inline__ __attribute__((always_inline)) CFSwappedFloat32 CFConvertFloatHostToSwapped(float arg) {
    union CFSwap {
 float v;
 CFSwappedFloat32 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) float CFConvertFloatSwappedToHost(CFSwappedFloat32 arg) {
    union CFSwap {
 float v;
 CFSwappedFloat32 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.v;
}

static __inline__ __attribute__((always_inline)) CFSwappedFloat64 CFConvertDoubleHostToSwapped(double arg) {
    union CFSwap {
 double v;
 CFSwappedFloat64 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) double CFConvertDoubleSwappedToHost(CFSwappedFloat64 arg) {
    union CFSwap {
 double v;
 CFSwappedFloat64 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.v;
}

}
extern "C" {
typedef const void * (*CFDictionaryRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void (*CFDictionaryReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef (*CFDictionaryCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFDictionaryEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode (*CFDictionaryHashCallBack)(const void *value);
typedef struct {
    CFIndex version;
    CFDictionaryRetainCallBack retain;
    CFDictionaryReleaseCallBack release;
    CFDictionaryCopyDescriptionCallBack copyDescription;
    CFDictionaryEqualCallBack equal;
    CFDictionaryHashCallBack hash;
} CFDictionaryKeyCallBacks;







extern
const CFDictionaryKeyCallBacks kCFTypeDictionaryKeyCallBacks;
extern
const CFDictionaryKeyCallBacks kCFCopyStringDictionaryKeyCallBacks;
typedef struct {
    CFIndex version;
    CFDictionaryRetainCallBack retain;
    CFDictionaryReleaseCallBack release;
    CFDictionaryCopyDescriptionCallBack copyDescription;
    CFDictionaryEqualCallBack equal;
} CFDictionaryValueCallBacks;







extern
const CFDictionaryValueCallBacks kCFTypeDictionaryValueCallBacks;
typedef void (*CFDictionaryApplierFunction)(const void *key, const void *value, void *context);





typedef const struct __attribute__((objc_bridge(NSDictionary))) __CFDictionary * CFDictionaryRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableDictionary))) __CFDictionary * CFMutableDictionaryRef;





extern
CFTypeID CFDictionaryGetTypeID(void);
extern
CFDictionaryRef CFDictionaryCreate(CFAllocatorRef allocator, const void **keys, const void **values, CFIndex numValues, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
extern
CFDictionaryRef CFDictionaryCreateCopy(CFAllocatorRef allocator, CFDictionaryRef theDict);
extern
CFMutableDictionaryRef CFDictionaryCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
extern
CFMutableDictionaryRef CFDictionaryCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDictionaryRef theDict);
extern
CFIndex CFDictionaryGetCount(CFDictionaryRef theDict);
extern
CFIndex CFDictionaryGetCountOfKey(CFDictionaryRef theDict, const void *key);
extern
CFIndex CFDictionaryGetCountOfValue(CFDictionaryRef theDict, const void *value);
extern
Boolean CFDictionaryContainsKey(CFDictionaryRef theDict, const void *key);
extern
Boolean CFDictionaryContainsValue(CFDictionaryRef theDict, const void *value);
extern
const void *CFDictionaryGetValue(CFDictionaryRef theDict, const void *key);
extern
Boolean CFDictionaryGetValueIfPresent(CFDictionaryRef theDict, const void *key, const void **value);
extern
void CFDictionaryGetKeysAndValues(CFDictionaryRef theDict, const void **keys, const void **values);
extern
void CFDictionaryApplyFunction(CFDictionaryRef theDict, CFDictionaryApplierFunction __attribute__((noescape)) applier, void *context);
extern
void CFDictionaryAddValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
extern
void CFDictionarySetValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
extern
void CFDictionaryReplaceValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
extern
void CFDictionaryRemoveValue(CFMutableDictionaryRef theDict, const void *key);
extern
void CFDictionaryRemoveAllValues(CFMutableDictionaryRef theDict);

}
extern "C" {

typedef CFStringRef CFNotificationName __attribute__((swift_wrapper(struct)));

typedef struct __attribute__((objc_bridge_mutable(id))) __CFNotificationCenter * CFNotificationCenterRef;

typedef void (*CFNotificationCallback)(CFNotificationCenterRef center, void *observer, CFNotificationName name, const void *object, CFDictionaryRef userInfo);

typedef CFIndex CFNotificationSuspensionBehavior; enum {
    CFNotificationSuspensionBehaviorDrop = 1,

    CFNotificationSuspensionBehaviorCoalesce = 2,

    CFNotificationSuspensionBehaviorHold = 3,

    CFNotificationSuspensionBehaviorDeliverImmediately = 4

};

extern CFTypeID CFNotificationCenterGetTypeID(void);

extern CFNotificationCenterRef CFNotificationCenterGetLocalCenter(void);


extern CFNotificationCenterRef CFNotificationCenterGetDistributedCenter(void);


extern CFNotificationCenterRef CFNotificationCenterGetDarwinNotifyCenter(void);
extern void CFNotificationCenterAddObserver(CFNotificationCenterRef center, const void *observer, CFNotificationCallback callBack, CFStringRef name, const void *object, CFNotificationSuspensionBehavior suspensionBehavior);

extern void CFNotificationCenterRemoveObserver(CFNotificationCenterRef center, const void *observer, CFNotificationName name, const void *object);
extern void CFNotificationCenterRemoveEveryObserver(CFNotificationCenterRef center, const void *observer);

extern void CFNotificationCenterPostNotification(CFNotificationCenterRef center, CFNotificationName name, const void *object, CFDictionaryRef userInfo, Boolean deliverImmediately);

enum {
    kCFNotificationDeliverImmediately = (1UL << 0),
    kCFNotificationPostToAllSessions = (1UL << 1)
};

extern void CFNotificationCenterPostNotificationWithOptions(CFNotificationCenterRef center, CFNotificationName name, const void *object, CFDictionaryRef userInfo, CFOptionFlags options);


}


extern "C" {

typedef CFStringRef CFLocaleIdentifier __attribute__((swift_wrapper(struct)));
typedef CFStringRef CFLocaleKey __attribute__((swift_wrapper(enum)));

typedef const struct __attribute__((objc_bridge(NSLocale))) __CFLocale *CFLocaleRef;

extern
CFTypeID CFLocaleGetTypeID(void);

extern
CFLocaleRef CFLocaleGetSystem(void);


extern
CFLocaleRef CFLocaleCopyCurrent(void);
extern
CFArrayRef CFLocaleCopyAvailableLocaleIdentifiers(void);



extern
CFArrayRef CFLocaleCopyISOLanguageCodes(void);




extern
CFArrayRef CFLocaleCopyISOCountryCodes(void);




extern
CFArrayRef CFLocaleCopyISOCurrencyCodes(void);




extern
CFArrayRef CFLocaleCopyCommonISOCurrencyCodes(void) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFArrayRef CFLocaleCopyPreferredLanguages(void) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
CFLocaleIdentifier CFLocaleCreateCanonicalLanguageIdentifierFromString(CFAllocatorRef allocator, CFStringRef localeIdentifier);



extern
CFLocaleIdentifier CFLocaleCreateCanonicalLocaleIdentifierFromString(CFAllocatorRef allocator, CFStringRef localeIdentifier);



extern
CFLocaleIdentifier CFLocaleCreateCanonicalLocaleIdentifierFromScriptManagerCodes(CFAllocatorRef allocator, LangCode lcode, RegionCode rcode);


extern
CFLocaleIdentifier CFLocaleCreateLocaleIdentifierFromWindowsLocaleCode(CFAllocatorRef allocator, uint32_t lcid) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
uint32_t CFLocaleGetWindowsLocaleCodeFromLocaleIdentifier(CFLocaleIdentifier localeIdentifier) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


typedef CFIndex CFLocaleLanguageDirection; enum {
    kCFLocaleLanguageDirectionUnknown = 0,
    kCFLocaleLanguageDirectionLeftToRight = 1,
    kCFLocaleLanguageDirectionRightToLeft = 2,
    kCFLocaleLanguageDirectionTopToBottom = 3,
    kCFLocaleLanguageDirectionBottomToTop = 4
};

extern
CFLocaleLanguageDirection CFLocaleGetLanguageCharacterDirection(CFStringRef isoLangCode) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
CFLocaleLanguageDirection CFLocaleGetLanguageLineDirection(CFStringRef isoLangCode) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
CFDictionaryRef CFLocaleCreateComponentsFromLocaleIdentifier(CFAllocatorRef allocator, CFLocaleIdentifier localeID);
extern
CFLocaleIdentifier CFLocaleCreateLocaleIdentifierFromComponents(CFAllocatorRef allocator, CFDictionaryRef dictionary);






extern
CFLocaleRef CFLocaleCreate(CFAllocatorRef allocator, CFLocaleIdentifier localeIdentifier);


extern
CFLocaleRef CFLocaleCreateCopy(CFAllocatorRef allocator, CFLocaleRef locale);




extern
CFLocaleIdentifier CFLocaleGetIdentifier(CFLocaleRef locale);



extern
CFTypeRef CFLocaleGetValue(CFLocaleRef locale, CFLocaleKey key);



extern
CFStringRef CFLocaleCopyDisplayNameForPropertyValue(CFLocaleRef displayLocale, CFLocaleKey key, CFStringRef value);





extern const CFNotificationName kCFLocaleCurrentLocaleDidChangeNotification __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern const CFLocaleKey kCFLocaleIdentifier;
extern const CFLocaleKey kCFLocaleLanguageCode;
extern const CFLocaleKey kCFLocaleCountryCode;
extern const CFLocaleKey kCFLocaleScriptCode;
extern const CFLocaleKey kCFLocaleVariantCode;

extern const CFLocaleKey kCFLocaleExemplarCharacterSet;
extern const CFLocaleKey kCFLocaleCalendarIdentifier;
extern const CFLocaleKey kCFLocaleCalendar;
extern const CFLocaleKey kCFLocaleCollationIdentifier;
extern const CFLocaleKey kCFLocaleUsesMetricSystem;
extern const CFLocaleKey kCFLocaleMeasurementSystem;
extern const CFLocaleKey kCFLocaleDecimalSeparator;
extern const CFLocaleKey kCFLocaleGroupingSeparator;
extern const CFLocaleKey kCFLocaleCurrencySymbol;
extern const CFLocaleKey kCFLocaleCurrencyCode;
extern const CFLocaleKey kCFLocaleCollatorIdentifier __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFLocaleKey kCFLocaleQuotationBeginDelimiterKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFLocaleKey kCFLocaleQuotationEndDelimiterKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFLocaleKey kCFLocaleAlternateQuotationBeginDelimiterKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFLocaleKey kCFLocaleAlternateQuotationEndDelimiterKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


typedef CFStringRef CFCalendarIdentifier __attribute__((swift_wrapper(enum)));

extern const CFCalendarIdentifier kCFGregorianCalendar;
extern const CFCalendarIdentifier kCFBuddhistCalendar;
extern const CFCalendarIdentifier kCFChineseCalendar;
extern const CFCalendarIdentifier kCFHebrewCalendar;
extern const CFCalendarIdentifier kCFIslamicCalendar;
extern const CFCalendarIdentifier kCFIslamicCivilCalendar;
extern const CFCalendarIdentifier kCFJapaneseCalendar;
extern const CFCalendarIdentifier kCFRepublicOfChinaCalendar __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFCalendarIdentifier kCFPersianCalendar __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFCalendarIdentifier kCFIndianCalendar __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFCalendarIdentifier kCFISO8601Calendar __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFCalendarIdentifier kCFIslamicTabularCalendar __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFCalendarIdentifier kCFIslamicUmmAlQuraCalendar __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

}
extern "C" {

typedef double CFTimeInterval;
typedef CFTimeInterval CFAbsoluteTime;



extern
CFAbsoluteTime CFAbsoluteTimeGetCurrent(void);

extern
const CFTimeInterval kCFAbsoluteTimeIntervalSince1970;
extern
const CFTimeInterval kCFAbsoluteTimeIntervalSince1904;

typedef const struct __attribute__((objc_bridge(NSDate))) __CFDate * CFDateRef;

extern
CFTypeID CFDateGetTypeID(void);

extern
CFDateRef CFDateCreate(CFAllocatorRef allocator, CFAbsoluteTime at);

extern
CFAbsoluteTime CFDateGetAbsoluteTime(CFDateRef theDate);

extern
CFTimeInterval CFDateGetTimeIntervalSinceDate(CFDateRef theDate, CFDateRef otherDate);

extern
CFComparisonResult CFDateCompare(CFDateRef theDate, CFDateRef otherDate, void *context);



typedef const struct __attribute__((objc_bridge(NSTimeZone))) __CFTimeZone * CFTimeZoneRef;
typedef struct {
    SInt32 year;
    SInt8 month;
    SInt8 day;
    SInt8 hour;
    SInt8 minute;
    double second;
} CFGregorianDate __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

typedef struct {
    SInt32 years;
    SInt32 months;
    SInt32 days;
    SInt32 hours;
    SInt32 minutes;
    double seconds;
} CFGregorianUnits __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

typedef CFOptionFlags CFGregorianUnitFlags; enum {
    kCFGregorianUnitsYears __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead"))) = (1UL << 0),
    kCFGregorianUnitsMonths __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead"))) = (1UL << 1),
    kCFGregorianUnitsDays __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead"))) = (1UL << 2),
    kCFGregorianUnitsHours __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead"))) = (1UL << 3),
    kCFGregorianUnitsMinutes __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead"))) = (1UL << 4),
    kCFGregorianUnitsSeconds __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead"))) = (1UL << 5),
    kCFGregorianAllUnits __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead"))) = 0x00FFFFFF
};

extern
Boolean CFGregorianDateIsValid(CFGregorianDate gdate, CFOptionFlags unitFlags) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

extern
CFAbsoluteTime CFGregorianDateGetAbsoluteTime(CFGregorianDate gdate, CFTimeZoneRef tz) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

extern
CFGregorianDate CFAbsoluteTimeGetGregorianDate(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

extern
CFAbsoluteTime CFAbsoluteTimeAddGregorianUnits(CFAbsoluteTime at, CFTimeZoneRef tz, CFGregorianUnits units) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

extern
CFGregorianUnits CFAbsoluteTimeGetDifferenceAsGregorianUnits(CFAbsoluteTime at1, CFAbsoluteTime at2, CFTimeZoneRef tz, CFOptionFlags unitFlags) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

extern
SInt32 CFAbsoluteTimeGetDayOfWeek(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

extern
SInt32 CFAbsoluteTimeGetDayOfYear(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

extern
SInt32 CFAbsoluteTimeGetWeekOfYear(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFCalendar or NSCalendar API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFCalendar or NSCalendar API instead")));

}
extern "C" {

typedef const struct __attribute__((objc_bridge(NSData))) __CFData * CFDataRef;
typedef struct __attribute__((objc_bridge_mutable(NSMutableData))) __CFData * CFMutableDataRef;

extern
CFTypeID CFDataGetTypeID(void);

extern
CFDataRef CFDataCreate(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length);

extern
CFDataRef CFDataCreateWithBytesNoCopy(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length, CFAllocatorRef bytesDeallocator);


extern
CFDataRef CFDataCreateCopy(CFAllocatorRef allocator, CFDataRef theData);

extern
CFMutableDataRef CFDataCreateMutable(CFAllocatorRef allocator, CFIndex capacity);

extern
CFMutableDataRef CFDataCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDataRef theData);

extern
CFIndex CFDataGetLength(CFDataRef theData);

extern
const UInt8 *CFDataGetBytePtr(CFDataRef theData);

extern
UInt8 *CFDataGetMutableBytePtr(CFMutableDataRef theData);

extern
void CFDataGetBytes(CFDataRef theData, CFRange range, UInt8 *buffer);

extern
void CFDataSetLength(CFMutableDataRef theData, CFIndex length);

extern
void CFDataIncreaseLength(CFMutableDataRef theData, CFIndex extraLength);

extern
void CFDataAppendBytes(CFMutableDataRef theData, const UInt8 *bytes, CFIndex length);

extern
void CFDataReplaceBytes(CFMutableDataRef theData, CFRange range, const UInt8 *newBytes, CFIndex newLength);

extern
void CFDataDeleteBytes(CFMutableDataRef theData, CFRange range);

typedef CFOptionFlags CFDataSearchFlags; enum {
    kCFDataSearchBackwards = 1UL << 0,
    kCFDataSearchAnchored = 1UL << 1
} __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
CFRange CFDataFind(CFDataRef theData, CFDataRef dataToFind, CFRange searchRange, CFDataSearchFlags compareOptions) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

}


extern "C" {





typedef const struct __attribute__((objc_bridge(NSCharacterSet))) __CFCharacterSet * CFCharacterSetRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableCharacterSet))) __CFCharacterSet * CFMutableCharacterSetRef;






typedef CFIndex CFCharacterSetPredefinedSet; enum {
    kCFCharacterSetControl = 1,
    kCFCharacterSetWhitespace,
    kCFCharacterSetWhitespaceAndNewline,
    kCFCharacterSetDecimalDigit,
    kCFCharacterSetLetter,
    kCFCharacterSetLowercaseLetter,
    kCFCharacterSetUppercaseLetter,
    kCFCharacterSetNonBase,
    kCFCharacterSetDecomposable,
    kCFCharacterSetAlphaNumeric,
    kCFCharacterSetPunctuation,
    kCFCharacterSetCapitalizedLetter = 13,
    kCFCharacterSetSymbol = 14,
    kCFCharacterSetNewline __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 15,
    kCFCharacterSetIllegal = 12
};





extern
CFTypeID CFCharacterSetGetTypeID(void);
extern
CFCharacterSetRef CFCharacterSetGetPredefined(CFCharacterSetPredefinedSet theSetIdentifier);
extern
CFCharacterSetRef CFCharacterSetCreateWithCharactersInRange(CFAllocatorRef alloc, CFRange theRange);
extern
CFCharacterSetRef CFCharacterSetCreateWithCharactersInString(CFAllocatorRef alloc, CFStringRef theString);
extern
CFCharacterSetRef CFCharacterSetCreateWithBitmapRepresentation(CFAllocatorRef alloc, CFDataRef theData);
extern CFCharacterSetRef CFCharacterSetCreateInvertedSet(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern Boolean CFCharacterSetIsSupersetOfSet(CFCharacterSetRef theSet, CFCharacterSetRef theOtherset);
extern Boolean CFCharacterSetHasMemberInPlane(CFCharacterSetRef theSet, CFIndex thePlane);
extern
CFMutableCharacterSetRef CFCharacterSetCreateMutable(CFAllocatorRef alloc);
extern
CFCharacterSetRef CFCharacterSetCreateCopy(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern
CFMutableCharacterSetRef CFCharacterSetCreateMutableCopy(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern
Boolean CFCharacterSetIsCharacterMember(CFCharacterSetRef theSet, UniChar theChar);
extern Boolean CFCharacterSetIsLongCharacterMember(CFCharacterSetRef theSet, UTF32Char theChar);
extern
CFDataRef CFCharacterSetCreateBitmapRepresentation(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern
void CFCharacterSetAddCharactersInRange(CFMutableCharacterSetRef theSet, CFRange theRange);
extern
void CFCharacterSetRemoveCharactersInRange(CFMutableCharacterSetRef theSet, CFRange theRange);
extern
void CFCharacterSetAddCharactersInString(CFMutableCharacterSetRef theSet, CFStringRef theString);
extern
void CFCharacterSetRemoveCharactersInString(CFMutableCharacterSetRef theSet, CFStringRef theString);
extern
void CFCharacterSetUnion(CFMutableCharacterSetRef theSet, CFCharacterSetRef theOtherSet);
extern
void CFCharacterSetIntersect(CFMutableCharacterSetRef theSet, CFCharacterSetRef theOtherSet);
extern
void CFCharacterSetInvert(CFMutableCharacterSetRef theSet);

}




extern "C" {
typedef UInt32 CFStringEncoding;





typedef CFStringEncoding CFStringBuiltInEncodings; enum {
    kCFStringEncodingMacRoman = 0,
    kCFStringEncodingWindowsLatin1 = 0x0500,
    kCFStringEncodingISOLatin1 = 0x0201,
    kCFStringEncodingNextStepLatin = 0x0B01,
    kCFStringEncodingASCII = 0x0600,
    kCFStringEncodingUnicode = 0x0100,
    kCFStringEncodingUTF8 = 0x08000100,
    kCFStringEncodingNonLossyASCII = 0x0BFF,

    kCFStringEncodingUTF16 = 0x0100,
    kCFStringEncodingUTF16BE = 0x10000100,
    kCFStringEncodingUTF16LE = 0x14000100,

    kCFStringEncodingUTF32 = 0x0c000100,
    kCFStringEncodingUTF32BE = 0x18000100,
    kCFStringEncodingUTF32LE = 0x1c000100
};



extern
CFTypeID CFStringGetTypeID(void);
extern
CFStringRef CFStringCreateWithPascalString(CFAllocatorRef alloc, ConstStr255Param pStr, CFStringEncoding encoding);

extern
CFStringRef CFStringCreateWithCString(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding);



extern
CFStringRef CFStringCreateWithBytes(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex numBytes, CFStringEncoding encoding, Boolean isExternalRepresentation);

extern
CFStringRef CFStringCreateWithCharacters(CFAllocatorRef alloc, const UniChar *chars, CFIndex numChars);
extern
CFStringRef CFStringCreateWithPascalStringNoCopy(CFAllocatorRef alloc, ConstStr255Param pStr, CFStringEncoding encoding, CFAllocatorRef contentsDeallocator);

extern
CFStringRef CFStringCreateWithCStringNoCopy(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding, CFAllocatorRef contentsDeallocator);



extern
CFStringRef CFStringCreateWithBytesNoCopy(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex numBytes, CFStringEncoding encoding, Boolean isExternalRepresentation, CFAllocatorRef contentsDeallocator);

extern
CFStringRef CFStringCreateWithCharactersNoCopy(CFAllocatorRef alloc, const UniChar *chars, CFIndex numChars, CFAllocatorRef contentsDeallocator);



extern
CFStringRef CFStringCreateWithSubstring(CFAllocatorRef alloc, CFStringRef str, CFRange range);

extern
CFStringRef CFStringCreateCopy(CFAllocatorRef alloc, CFStringRef theString);



extern
CFStringRef CFStringCreateWithFormat(CFAllocatorRef alloc, CFDictionaryRef formatOptions, CFStringRef format, ...) __attribute__((format(CFString, 3, 4)));

extern
CFStringRef CFStringCreateWithFormatAndArguments(CFAllocatorRef alloc, CFDictionaryRef formatOptions, CFStringRef format, va_list arguments) __attribute__((format(CFString, 3, 0)));



extern
CFMutableStringRef CFStringCreateMutable(CFAllocatorRef alloc, CFIndex maxLength);

extern
CFMutableStringRef CFStringCreateMutableCopy(CFAllocatorRef alloc, CFIndex maxLength, CFStringRef theString);







extern
CFMutableStringRef CFStringCreateMutableWithExternalCharactersNoCopy(CFAllocatorRef alloc, UniChar *chars, CFIndex numChars, CFIndex capacity, CFAllocatorRef externalCharactersAllocator);





extern
CFIndex CFStringGetLength(CFStringRef theString);






extern
UniChar CFStringGetCharacterAtIndex(CFStringRef theString, CFIndex idx);

extern
void CFStringGetCharacters(CFStringRef theString, CFRange range, UniChar *buffer);
extern
Boolean CFStringGetPascalString(CFStringRef theString, StringPtr buffer, CFIndex bufferSize, CFStringEncoding encoding);

extern
Boolean CFStringGetCString(CFStringRef theString, char *buffer, CFIndex bufferSize, CFStringEncoding encoding);






extern
ConstStringPtr CFStringGetPascalStringPtr(CFStringRef theString, CFStringEncoding encoding);

extern
const char *CFStringGetCStringPtr(CFStringRef theString, CFStringEncoding encoding);

extern
const UniChar *CFStringGetCharactersPtr(CFStringRef theString);
extern
CFIndex CFStringGetBytes(CFStringRef theString, CFRange range, CFStringEncoding encoding, UInt8 lossByte, Boolean isExternalRepresentation, UInt8 *buffer, CFIndex maxBufLen, CFIndex *usedBufLen);







extern
CFStringRef CFStringCreateFromExternalRepresentation(CFAllocatorRef alloc, CFDataRef data, CFStringEncoding encoding);

extern
CFDataRef CFStringCreateExternalRepresentation(CFAllocatorRef alloc, CFStringRef theString, CFStringEncoding encoding, UInt8 lossByte);



extern
CFStringEncoding CFStringGetSmallestEncoding(CFStringRef theString);

extern
CFStringEncoding CFStringGetFastestEncoding(CFStringRef theString);



extern
CFStringEncoding CFStringGetSystemEncoding(void);

extern
CFIndex CFStringGetMaximumSizeForEncoding(CFIndex length, CFStringEncoding encoding);






extern
Boolean CFStringGetFileSystemRepresentation(CFStringRef string, char *buffer, CFIndex maxBufLen);



extern
CFIndex CFStringGetMaximumSizeOfFileSystemRepresentation(CFStringRef string);



extern
CFStringRef CFStringCreateWithFileSystemRepresentation(CFAllocatorRef alloc, const char *buffer);






typedef CFOptionFlags CFStringCompareFlags; enum {
    kCFCompareCaseInsensitive = 1,
    kCFCompareBackwards = 4,
    kCFCompareAnchored = 8,
    kCFCompareNonliteral = 16,
    kCFCompareLocalized = 32,
    kCFCompareNumerically = 64,
    kCFCompareDiacriticInsensitive __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 128,
    kCFCompareWidthInsensitive __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 256,
    kCFCompareForcedOrdering __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 512
};







extern
CFComparisonResult CFStringCompareWithOptionsAndLocale(CFStringRef theString1, CFStringRef theString2, CFRange rangeToCompare, CFStringCompareFlags compareOptions, CFLocaleRef locale) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFComparisonResult CFStringCompareWithOptions(CFStringRef theString1, CFStringRef theString2, CFRange rangeToCompare, CFStringCompareFlags compareOptions);





extern
CFComparisonResult CFStringCompare(CFStringRef theString1, CFStringRef theString2, CFStringCompareFlags compareOptions);







extern
Boolean CFStringFindWithOptionsAndLocale(CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFLocaleRef locale, CFRange *result) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
Boolean CFStringFindWithOptions(CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFRange *result);
extern
CFArrayRef CFStringCreateArrayWithFindResults(CFAllocatorRef alloc, CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags compareOptions);



extern
CFRange CFStringFind(CFStringRef theString, CFStringRef stringToFind, CFStringCompareFlags compareOptions);

extern
Boolean CFStringHasPrefix(CFStringRef theString, CFStringRef prefix);

extern
Boolean CFStringHasSuffix(CFStringRef theString, CFStringRef suffix);
extern CFRange CFStringGetRangeOfComposedCharactersAtIndex(CFStringRef theString, CFIndex theIndex);
extern Boolean CFStringFindCharacterFromSet(CFStringRef theString, CFCharacterSetRef theSet, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFRange *result);
extern
void CFStringGetLineBounds(CFStringRef theString, CFRange range, CFIndex *lineBeginIndex, CFIndex *lineEndIndex, CFIndex *contentsEndIndex);



extern
void CFStringGetParagraphBounds(CFStringRef string, CFRange range, CFIndex *parBeginIndex, CFIndex *parEndIndex, CFIndex *contentsEndIndex) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFIndex CFStringGetHyphenationLocationBeforeIndex(CFStringRef string, CFIndex location, CFRange limitRange, CFOptionFlags options, CFLocaleRef locale, UTF32Char *character) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.2))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
Boolean CFStringIsHyphenationAvailableForLocale(CFLocaleRef locale) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.3))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFStringRef CFStringCreateByCombiningStrings(CFAllocatorRef alloc, CFArrayRef theArray, CFStringRef separatorString);

extern
CFArrayRef CFStringCreateArrayBySeparatingStrings(CFAllocatorRef alloc, CFStringRef theString, CFStringRef separatorString);




extern
SInt32 CFStringGetIntValue(CFStringRef str);

extern
double CFStringGetDoubleValue(CFStringRef str);
extern
void CFStringAppend(CFMutableStringRef theString, CFStringRef appendedString);

extern
void CFStringAppendCharacters(CFMutableStringRef theString, const UniChar *chars, CFIndex numChars);

extern
void CFStringAppendPascalString(CFMutableStringRef theString, ConstStr255Param pStr, CFStringEncoding encoding);

extern
void CFStringAppendCString(CFMutableStringRef theString, const char *cStr, CFStringEncoding encoding);

extern
void CFStringAppendFormat(CFMutableStringRef theString, CFDictionaryRef formatOptions, CFStringRef format, ...) __attribute__((format(CFString, 3, 4)));

extern
void CFStringAppendFormatAndArguments(CFMutableStringRef theString, CFDictionaryRef formatOptions, CFStringRef format, va_list arguments) __attribute__((format(CFString, 3, 0)));

extern
void CFStringInsert(CFMutableStringRef str, CFIndex idx, CFStringRef insertedStr);

extern
void CFStringDelete(CFMutableStringRef theString, CFRange range);

extern
void CFStringReplace(CFMutableStringRef theString, CFRange range, CFStringRef replacement);

extern
void CFStringReplaceAll(CFMutableStringRef theString, CFStringRef replacement);
extern
CFIndex CFStringFindAndReplace(CFMutableStringRef theString, CFStringRef stringToFind, CFStringRef replacementString, CFRange rangeToSearch, CFStringCompareFlags compareOptions);
extern
void CFStringSetExternalCharactersNoCopy(CFMutableStringRef theString, UniChar *chars, CFIndex length, CFIndex capacity);
extern
void CFStringPad(CFMutableStringRef theString, CFStringRef padString, CFIndex length, CFIndex indexIntoPad);

extern
void CFStringTrim(CFMutableStringRef theString, CFStringRef trimString);

extern
void CFStringTrimWhitespace(CFMutableStringRef theString);

extern
void CFStringLowercase(CFMutableStringRef theString, CFLocaleRef locale);

extern
void CFStringUppercase(CFMutableStringRef theString, CFLocaleRef locale);

extern
void CFStringCapitalize(CFMutableStringRef theString, CFLocaleRef locale);







typedef CFIndex CFStringNormalizationForm; enum {
 kCFStringNormalizationFormD = 0,
 kCFStringNormalizationFormKD,
 kCFStringNormalizationFormC,
 kCFStringNormalizationFormKC
};
extern void CFStringNormalize(CFMutableStringRef theString, CFStringNormalizationForm theForm);
extern
void CFStringFold(CFMutableStringRef theString, CFStringCompareFlags theFlags, CFLocaleRef theLocale) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));





extern
Boolean CFStringTransform(CFMutableStringRef string, CFRange *range, CFStringRef transform, Boolean reverse);



extern const CFStringRef kCFStringTransformStripCombiningMarks;
extern const CFStringRef kCFStringTransformToLatin;
extern const CFStringRef kCFStringTransformFullwidthHalfwidth;
extern const CFStringRef kCFStringTransformLatinKatakana;
extern const CFStringRef kCFStringTransformLatinHiragana;
extern const CFStringRef kCFStringTransformHiraganaKatakana;
extern const CFStringRef kCFStringTransformMandarinLatin;
extern const CFStringRef kCFStringTransformLatinHangul;
extern const CFStringRef kCFStringTransformLatinArabic;
extern const CFStringRef kCFStringTransformLatinHebrew;
extern const CFStringRef kCFStringTransformLatinThai;
extern const CFStringRef kCFStringTransformLatinCyrillic;
extern const CFStringRef kCFStringTransformLatinGreek;
extern const CFStringRef kCFStringTransformToXMLHex;
extern const CFStringRef kCFStringTransformToUnicodeName;
extern const CFStringRef kCFStringTransformStripDiacritics __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));






extern
Boolean CFStringIsEncodingAvailable(CFStringEncoding encoding);



extern
const CFStringEncoding *CFStringGetListOfAvailableEncodings(void);



extern
CFStringRef CFStringGetNameOfEncoding(CFStringEncoding encoding);



extern
unsigned long CFStringConvertEncodingToNSStringEncoding(CFStringEncoding encoding);

extern
CFStringEncoding CFStringConvertNSStringEncodingToEncoding(unsigned long encoding);



extern
UInt32 CFStringConvertEncodingToWindowsCodepage(CFStringEncoding encoding);

extern
CFStringEncoding CFStringConvertWindowsCodepageToEncoding(UInt32 codepage);



extern
CFStringEncoding CFStringConvertIANACharSetNameToEncoding(CFStringRef theString);

extern
CFStringRef CFStringConvertEncodingToIANACharSetName(CFStringEncoding encoding);





extern
CFStringEncoding CFStringGetMostCompatibleMacStringEncoding(CFStringEncoding encoding);
typedef struct {
    UniChar buffer[64];
    CFStringRef theString;
    const UniChar *directUniCharBuffer;
    const char *directCStringBuffer;
    CFRange rangeToBuffer;
    CFIndex bufferedRangeStart;
    CFIndex bufferedRangeEnd;
} CFStringInlineBuffer;


static __inline__ __attribute__((always_inline)) void CFStringInitInlineBuffer(CFStringRef str, CFStringInlineBuffer *buf, CFRange range) {
    buf->theString = str;
    buf->rangeToBuffer = range;
    buf->directCStringBuffer = (buf->directUniCharBuffer = CFStringGetCharactersPtr(str)) ? __null : CFStringGetCStringPtr(str, kCFStringEncodingASCII);
    buf->bufferedRangeStart = buf->bufferedRangeEnd = 0;
}

static __inline__ __attribute__((always_inline)) UniChar CFStringGetCharacterFromInlineBuffer(CFStringInlineBuffer *buf, CFIndex idx) {
    if (idx < 0 || idx >= buf->rangeToBuffer.length) return 0;
    if (buf->directUniCharBuffer) return buf->directUniCharBuffer[idx + buf->rangeToBuffer.location];
    if (buf->directCStringBuffer) return (UniChar)(buf->directCStringBuffer[idx + buf->rangeToBuffer.location]);
    if (idx >= buf->bufferedRangeEnd || idx < buf->bufferedRangeStart) {
 if ((buf->bufferedRangeStart = idx - 4) < 0) buf->bufferedRangeStart = 0;
 buf->bufferedRangeEnd = buf->bufferedRangeStart + 64;
 if (buf->bufferedRangeEnd > buf->rangeToBuffer.length) buf->bufferedRangeEnd = buf->rangeToBuffer.length;
 CFStringGetCharacters(buf->theString, CFRangeMake(buf->rangeToBuffer.location + buf->bufferedRangeStart, buf->bufferedRangeEnd - buf->bufferedRangeStart), buf->buffer);
    }
    return buf->buffer[idx - buf->bufferedRangeStart];
}
static __inline__ __attribute__((always_inline)) Boolean CFStringIsSurrogateHighCharacter(UniChar character) {
    return ((character >= 0xD800UL) && (character <= 0xDBFFUL) ? true : false);
}

static __inline__ __attribute__((always_inline)) Boolean CFStringIsSurrogateLowCharacter(UniChar character) {
    return ((character >= 0xDC00UL) && (character <= 0xDFFFUL) ? true : false);
}

static __inline__ __attribute__((always_inline)) UTF32Char CFStringGetLongCharacterForSurrogatePair(UniChar surrogateHigh, UniChar surrogateLow) {
    return (UTF32Char)(((surrogateHigh - 0xD800UL) << 10) + (surrogateLow - 0xDC00UL) + 0x0010000UL);
}


static __inline__ __attribute__((always_inline)) Boolean CFStringGetSurrogatePairForLongCharacter(UTF32Char character, UniChar *surrogates) {
    if ((character > 0xFFFFUL) && (character < 0x110000UL)) {
        character -= 0x10000;
        if (__null != surrogates) {
            surrogates[0] = (UniChar)((character >> 10) + 0xD800UL);
            surrogates[1] = (UniChar)((character & 0x3FF) + 0xDC00UL);
        }
        return true;
    } else {
        if (__null != surrogates) *surrogates = (UniChar)character;
        return false;
    }
}







extern
void CFShow(CFTypeRef obj);

extern
void CFShowStr(CFStringRef str);


extern
CFStringRef __CFStringMakeConstantString(const char *cStr) __attribute__((format_arg(1)));

}




extern "C" {

extern
CFTypeID CFTimeZoneGetTypeID(void);

extern
CFTimeZoneRef CFTimeZoneCopySystem(void);

extern
void CFTimeZoneResetSystem(void);

extern
CFTimeZoneRef CFTimeZoneCopyDefault(void);

extern
void CFTimeZoneSetDefault(CFTimeZoneRef tz);

extern
CFArrayRef CFTimeZoneCopyKnownNames(void);

extern
CFDictionaryRef CFTimeZoneCopyAbbreviationDictionary(void);

extern
void CFTimeZoneSetAbbreviationDictionary(CFDictionaryRef dict);

extern
CFTimeZoneRef CFTimeZoneCreate(CFAllocatorRef allocator, CFStringRef name, CFDataRef data);

extern
CFTimeZoneRef CFTimeZoneCreateWithTimeIntervalFromGMT(CFAllocatorRef allocator, CFTimeInterval ti);

extern
CFTimeZoneRef CFTimeZoneCreateWithName(CFAllocatorRef allocator, CFStringRef name, Boolean tryAbbrev);

extern
CFStringRef CFTimeZoneGetName(CFTimeZoneRef tz);

extern
CFDataRef CFTimeZoneGetData(CFTimeZoneRef tz);

extern
CFTimeInterval CFTimeZoneGetSecondsFromGMT(CFTimeZoneRef tz, CFAbsoluteTime at);

extern
CFStringRef CFTimeZoneCopyAbbreviation(CFTimeZoneRef tz, CFAbsoluteTime at);

extern
Boolean CFTimeZoneIsDaylightSavingTime(CFTimeZoneRef tz, CFAbsoluteTime at);

extern
CFTimeInterval CFTimeZoneGetDaylightSavingTimeOffset(CFTimeZoneRef tz, CFAbsoluteTime at) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
CFAbsoluteTime CFTimeZoneGetNextDaylightSavingTimeTransition(CFTimeZoneRef tz, CFAbsoluteTime at) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

typedef CFIndex CFTimeZoneNameStyle; enum {
 kCFTimeZoneNameStyleStandard,
 kCFTimeZoneNameStyleShortStandard,
 kCFTimeZoneNameStyleDaylightSaving,
 kCFTimeZoneNameStyleShortDaylightSaving,
 kCFTimeZoneNameStyleGeneric,
 kCFTimeZoneNameStyleShortGeneric
} __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
CFStringRef CFTimeZoneCopyLocalizedName(CFTimeZoneRef tz, CFTimeZoneNameStyle style, CFLocaleRef locale) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
const CFNotificationName kCFTimeZoneSystemTimeZoneDidChangeNotification __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

}


extern "C" {

typedef struct __attribute__((objc_bridge_mutable(NSCalendar))) __CFCalendar * CFCalendarRef;

extern
CFTypeID CFCalendarGetTypeID(void);

extern
CFCalendarRef CFCalendarCopyCurrent(void);

extern
CFCalendarRef CFCalendarCreateWithIdentifier(CFAllocatorRef allocator, CFCalendarIdentifier identifier);



extern
CFCalendarIdentifier CFCalendarGetIdentifier(CFCalendarRef calendar);


extern
CFLocaleRef CFCalendarCopyLocale(CFCalendarRef calendar);

extern
void CFCalendarSetLocale(CFCalendarRef calendar, CFLocaleRef locale);

extern
CFTimeZoneRef CFCalendarCopyTimeZone(CFCalendarRef calendar);

extern
void CFCalendarSetTimeZone(CFCalendarRef calendar, CFTimeZoneRef tz);

extern
CFIndex CFCalendarGetFirstWeekday(CFCalendarRef calendar);

extern
void CFCalendarSetFirstWeekday(CFCalendarRef calendar, CFIndex wkdy);

extern
CFIndex CFCalendarGetMinimumDaysInFirstWeek(CFCalendarRef calendar);

extern
void CFCalendarSetMinimumDaysInFirstWeek(CFCalendarRef calendar, CFIndex mwd);


typedef CFOptionFlags CFCalendarUnit; enum {
 kCFCalendarUnitEra = (1UL << 1),
 kCFCalendarUnitYear = (1UL << 2),
 kCFCalendarUnitMonth = (1UL << 3),
 kCFCalendarUnitDay = (1UL << 4),
 kCFCalendarUnitHour = (1UL << 5),
 kCFCalendarUnitMinute = (1UL << 6),
 kCFCalendarUnitSecond = (1UL << 7),
 kCFCalendarUnitWeek __attribute__((availability(macos,introduced=10.4,deprecated=10.10,message="Use kCFCalendarUnitWeekOfYear or kCFCalendarUnitWeekOfMonth instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use kCFCalendarUnitWeekOfYear or kCFCalendarUnitWeekOfMonth instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use kCFCalendarUnitWeekOfYear or kCFCalendarUnitWeekOfMonth instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use kCFCalendarUnitWeekOfYear or kCFCalendarUnitWeekOfMonth instead"))) = (1UL << 8),
 kCFCalendarUnitWeekday = (1UL << 9),
 kCFCalendarUnitWeekdayOrdinal = (1UL << 10),
 kCFCalendarUnitQuarter __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = (1UL << 11),
 kCFCalendarUnitWeekOfMonth __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = (1UL << 12),
 kCFCalendarUnitWeekOfYear __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = (1UL << 13),
 kCFCalendarUnitYearForWeekOfYear __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = (1UL << 14),
};

extern
CFRange CFCalendarGetMinimumRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit);

extern
CFRange CFCalendarGetMaximumRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit);

extern
CFRange CFCalendarGetRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit smallerUnit, CFCalendarUnit biggerUnit, CFAbsoluteTime at);

extern
CFIndex CFCalendarGetOrdinalityOfUnit(CFCalendarRef calendar, CFCalendarUnit smallerUnit, CFCalendarUnit biggerUnit, CFAbsoluteTime at);

extern
Boolean CFCalendarGetTimeRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit, CFAbsoluteTime at, CFAbsoluteTime *startp, CFTimeInterval *tip) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
Boolean CFCalendarComposeAbsoluteTime(CFCalendarRef calendar, CFAbsoluteTime *at, const char *componentDesc, ...);

extern
Boolean CFCalendarDecomposeAbsoluteTime(CFCalendarRef calendar, CFAbsoluteTime at, const char *componentDesc, ...);


enum {
    kCFCalendarComponentsWrap = (1UL << 0)
};

extern
Boolean CFCalendarAddComponents(CFCalendarRef calendar, CFAbsoluteTime *at, CFOptionFlags options, const char *componentDesc, ...);

extern
Boolean CFCalendarGetComponentDifference(CFCalendarRef calendar, CFAbsoluteTime startingAT, CFAbsoluteTime resultAT, CFOptionFlags options, const char *componentDesc, ...);


}



extern "C" {

typedef CFStringRef CFDateFormatterKey __attribute__((swift_wrapper(enum)));

typedef struct __attribute__((objc_bridge_mutable(id))) __CFDateFormatter *CFDateFormatterRef;



extern
CFStringRef CFDateFormatterCreateDateFormatFromTemplate(CFAllocatorRef allocator, CFStringRef tmplate, CFOptionFlags options, CFLocaleRef locale) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
CFTypeID CFDateFormatterGetTypeID(void);
typedef CFIndex CFDateFormatterStyle; enum {
    kCFDateFormatterNoStyle = 0,
    kCFDateFormatterShortStyle = 1,
    kCFDateFormatterMediumStyle = 2,
    kCFDateFormatterLongStyle = 3,
    kCFDateFormatterFullStyle = 4
};

typedef CFOptionFlags CFISO8601DateFormatOptions; enum {




    kCFISO8601DateFormatWithYear __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 0),
    kCFISO8601DateFormatWithMonth __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 1),

    kCFISO8601DateFormatWithWeekOfYear __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 2),






    kCFISO8601DateFormatWithDay __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 4),

    kCFISO8601DateFormatWithTime __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 5),
    kCFISO8601DateFormatWithTimeZone __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 6),

    kCFISO8601DateFormatWithSpaceBetweenDateAndTime __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 7),
    kCFISO8601DateFormatWithDashSeparatorInDate __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 8),
    kCFISO8601DateFormatWithColonSeparatorInTime __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 9),
    kCFISO8601DateFormatWithColonSeparatorInTimeZone __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = (1UL << 10),
    kCFISO8601DateFormatWithFractionalSeconds __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0))) __attribute__((availability(tvos,introduced=11.0))) = (1UL << 11),

    kCFISO8601DateFormatWithFullDate __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = kCFISO8601DateFormatWithYear | kCFISO8601DateFormatWithMonth | kCFISO8601DateFormatWithDay | kCFISO8601DateFormatWithDashSeparatorInDate,
    kCFISO8601DateFormatWithFullTime __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = kCFISO8601DateFormatWithTime | kCFISO8601DateFormatWithColonSeparatorInTime | kCFISO8601DateFormatWithTimeZone | kCFISO8601DateFormatWithColonSeparatorInTimeZone,

    kCFISO8601DateFormatWithInternetDateTime __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0))) = kCFISO8601DateFormatWithFullDate | kCFISO8601DateFormatWithFullTime,
};

extern
CFDateFormatterRef CFDateFormatterCreateISO8601Formatter(CFAllocatorRef allocator, CFISO8601DateFormatOptions formatOptions) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));

extern
CFDateFormatterRef CFDateFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFDateFormatterStyle dateStyle, CFDateFormatterStyle timeStyle);



extern
CFLocaleRef CFDateFormatterGetLocale(CFDateFormatterRef formatter);

extern
CFDateFormatterStyle CFDateFormatterGetDateStyle(CFDateFormatterRef formatter);

extern
CFDateFormatterStyle CFDateFormatterGetTimeStyle(CFDateFormatterRef formatter);


extern
CFStringRef CFDateFormatterGetFormat(CFDateFormatterRef formatter);

extern
void CFDateFormatterSetFormat(CFDateFormatterRef formatter, CFStringRef formatString);







extern
CFStringRef CFDateFormatterCreateStringWithDate(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFDateRef date);

extern
CFStringRef CFDateFormatterCreateStringWithAbsoluteTime(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFAbsoluteTime at);




extern
CFDateRef CFDateFormatterCreateDateFromString(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep);

extern
Boolean CFDateFormatterGetAbsoluteTimeFromString(CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep, CFAbsoluteTime *atp);
extern
void CFDateFormatterSetProperty(CFDateFormatterRef formatter, CFStringRef key, CFTypeRef value);

extern
CFTypeRef CFDateFormatterCopyProperty(CFDateFormatterRef formatter, CFDateFormatterKey key);



extern const CFDateFormatterKey kCFDateFormatterIsLenient;
extern const CFDateFormatterKey kCFDateFormatterTimeZone;
extern const CFDateFormatterKey kCFDateFormatterCalendarName;
extern const CFDateFormatterKey kCFDateFormatterDefaultFormat;
extern const CFDateFormatterKey kCFDateFormatterTwoDigitStartDate;
extern const CFDateFormatterKey kCFDateFormatterDefaultDate;
extern const CFDateFormatterKey kCFDateFormatterCalendar;
extern const CFDateFormatterKey kCFDateFormatterEraSymbols;
extern const CFDateFormatterKey kCFDateFormatterMonthSymbols;
extern const CFDateFormatterKey kCFDateFormatterShortMonthSymbols;
extern const CFDateFormatterKey kCFDateFormatterWeekdaySymbols;
extern const CFDateFormatterKey kCFDateFormatterShortWeekdaySymbols;
extern const CFDateFormatterKey kCFDateFormatterAMSymbol;
extern const CFDateFormatterKey kCFDateFormatterPMSymbol;
extern const CFDateFormatterKey kCFDateFormatterLongEraSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterVeryShortMonthSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterStandaloneMonthSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterShortStandaloneMonthSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterVeryShortStandaloneMonthSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterVeryShortWeekdaySymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterStandaloneWeekdaySymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterShortStandaloneWeekdaySymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterVeryShortStandaloneWeekdaySymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterQuarterSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterShortQuarterSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterStandaloneQuarterSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterShortStandaloneQuarterSymbols __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterGregorianStartDate __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFDateFormatterKey kCFDateFormatterDoesRelativeDateFormattingKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
}

extern "C" {

typedef CFStringRef CFErrorDomain __attribute__((swift_wrapper(struct)));





typedef struct __attribute__((objc_bridge(NSError))) __CFError * CFErrorRef;





extern
CFTypeID CFErrorGetTypeID(void) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern const CFErrorDomain kCFErrorDomainPOSIX __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFErrorDomain kCFErrorDomainOSStatus __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFErrorDomain kCFErrorDomainMach __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFErrorDomain kCFErrorDomainCocoa __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern const CFStringRef kCFErrorLocalizedDescriptionKey __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFStringRef kCFErrorLocalizedFailureKey __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0))) __attribute__((availability(tvos,introduced=11.0)));
extern const CFStringRef kCFErrorLocalizedFailureReasonKey __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFStringRef kCFErrorLocalizedRecoverySuggestionKey __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern const CFStringRef kCFErrorDescriptionKey __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern const CFStringRef kCFErrorUnderlyingErrorKey __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFStringRef kCFErrorURLKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFStringRef kCFErrorFilePathKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFErrorRef CFErrorCreate(CFAllocatorRef allocator, CFErrorDomain domain, CFIndex code, CFDictionaryRef userInfo) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFErrorRef CFErrorCreateWithUserInfoKeysAndValues(CFAllocatorRef allocator, CFErrorDomain domain, CFIndex code, const void *const *userInfoKeys, const void *const *userInfoValues, CFIndex numUserInfoValues) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));







extern
CFErrorDomain CFErrorGetDomain(CFErrorRef err) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));







extern
CFIndex CFErrorGetCode(CFErrorRef err) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFDictionaryRef CFErrorCopyUserInfo(CFErrorRef err) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFStringRef CFErrorCopyDescription(CFErrorRef err) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFStringRef CFErrorCopyFailureReason(CFErrorRef err) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFStringRef CFErrorCopyRecoverySuggestion(CFErrorRef err) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



}

extern "C" {

typedef const struct __attribute__((objc_bridge(NSNumber))) __CFBoolean * CFBooleanRef;

extern
const CFBooleanRef kCFBooleanTrue;
extern
const CFBooleanRef kCFBooleanFalse;

extern
CFTypeID CFBooleanGetTypeID(void);

extern
Boolean CFBooleanGetValue(CFBooleanRef boolean);

typedef CFIndex CFNumberType; enum {

    kCFNumberSInt8Type = 1,
    kCFNumberSInt16Type = 2,
    kCFNumberSInt32Type = 3,
    kCFNumberSInt64Type = 4,
    kCFNumberFloat32Type = 5,
    kCFNumberFloat64Type = 6,

    kCFNumberCharType = 7,
    kCFNumberShortType = 8,
    kCFNumberIntType = 9,
    kCFNumberLongType = 10,
    kCFNumberLongLongType = 11,
    kCFNumberFloatType = 12,
    kCFNumberDoubleType = 13,

    kCFNumberCFIndexType = 14,
    kCFNumberNSIntegerType __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 15,
    kCFNumberCGFloatType __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 16,
    kCFNumberMaxType = 16
};

typedef const struct __attribute__((objc_bridge(NSNumber))) __CFNumber * CFNumberRef;

extern
const CFNumberRef kCFNumberPositiveInfinity;
extern
const CFNumberRef kCFNumberNegativeInfinity;
extern
const CFNumberRef kCFNumberNaN;

extern
CFTypeID CFNumberGetTypeID(void);
extern
CFNumberRef CFNumberCreate(CFAllocatorRef allocator, CFNumberType theType, const void *valuePtr);





extern
CFNumberType CFNumberGetType(CFNumberRef number);




extern
CFIndex CFNumberGetByteSize(CFNumberRef number);





extern
Boolean CFNumberIsFloatType(CFNumberRef number);
extern
Boolean CFNumberGetValue(CFNumberRef number, CFNumberType theType, void *valuePtr);
extern
CFComparisonResult CFNumberCompare(CFNumberRef number, CFNumberRef otherNumber, void *context);

}
extern "C" {

typedef CFStringRef CFNumberFormatterKey __attribute__((swift_wrapper(enum)));

typedef struct __attribute__((objc_bridge_mutable(id))) __CFNumberFormatter *CFNumberFormatterRef;



extern
CFTypeID CFNumberFormatterGetTypeID(void);

typedef CFIndex CFNumberFormatterStyle; enum {
 kCFNumberFormatterNoStyle = 0,
 kCFNumberFormatterDecimalStyle = 1,
 kCFNumberFormatterCurrencyStyle = 2,
 kCFNumberFormatterPercentStyle = 3,
 kCFNumberFormatterScientificStyle = 4,
 kCFNumberFormatterSpellOutStyle = 5,
 kCFNumberFormatterOrdinalStyle __attribute__((availability(macos,introduced=10.11))) __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 6,
 kCFNumberFormatterCurrencyISOCodeStyle __attribute__((availability(macos,introduced=10.11))) __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 8,
 kCFNumberFormatterCurrencyPluralStyle __attribute__((availability(macos,introduced=10.11))) __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 9,
 kCFNumberFormatterCurrencyAccountingStyle __attribute__((availability(macos,introduced=10.11))) __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 10,
};


extern
CFNumberFormatterRef CFNumberFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFNumberFormatterStyle style);



extern
CFLocaleRef CFNumberFormatterGetLocale(CFNumberFormatterRef formatter);

extern
CFNumberFormatterStyle CFNumberFormatterGetStyle(CFNumberFormatterRef formatter);


extern
CFStringRef CFNumberFormatterGetFormat(CFNumberFormatterRef formatter);

extern
void CFNumberFormatterSetFormat(CFNumberFormatterRef formatter, CFStringRef formatString);
extern
CFStringRef CFNumberFormatterCreateStringWithNumber(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFNumberRef number);

extern
CFStringRef CFNumberFormatterCreateStringWithValue(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFNumberType numberType, const void *valuePtr);




typedef CFOptionFlags CFNumberFormatterOptionFlags; enum {
    kCFNumberFormatterParseIntegersOnly = 1
};

extern
CFNumberRef CFNumberFormatterCreateNumberFromString(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFStringRef string, CFRange *rangep, CFOptionFlags options);

extern
Boolean CFNumberFormatterGetValueFromString(CFNumberFormatterRef formatter, CFStringRef string, CFRange *rangep, CFNumberType numberType, void *valuePtr);
extern
void CFNumberFormatterSetProperty(CFNumberFormatterRef formatter, CFNumberFormatterKey key, CFTypeRef value);

extern
CFTypeRef CFNumberFormatterCopyProperty(CFNumberFormatterRef formatter, CFNumberFormatterKey key);



extern const CFNumberFormatterKey kCFNumberFormatterCurrencyCode;
extern const CFNumberFormatterKey kCFNumberFormatterDecimalSeparator;
extern const CFNumberFormatterKey kCFNumberFormatterCurrencyDecimalSeparator;
extern const CFNumberFormatterKey kCFNumberFormatterAlwaysShowDecimalSeparator;
extern const CFNumberFormatterKey kCFNumberFormatterGroupingSeparator;
extern const CFNumberFormatterKey kCFNumberFormatterUseGroupingSeparator;
extern const CFNumberFormatterKey kCFNumberFormatterPercentSymbol;
extern const CFNumberFormatterKey kCFNumberFormatterZeroSymbol;
extern const CFNumberFormatterKey kCFNumberFormatterNaNSymbol;
extern const CFNumberFormatterKey kCFNumberFormatterInfinitySymbol;
extern const CFNumberFormatterKey kCFNumberFormatterMinusSign;
extern const CFNumberFormatterKey kCFNumberFormatterPlusSign;
extern const CFNumberFormatterKey kCFNumberFormatterCurrencySymbol;
extern const CFNumberFormatterKey kCFNumberFormatterExponentSymbol;
extern const CFNumberFormatterKey kCFNumberFormatterMinIntegerDigits;
extern const CFNumberFormatterKey kCFNumberFormatterMaxIntegerDigits;
extern const CFNumberFormatterKey kCFNumberFormatterMinFractionDigits;
extern const CFNumberFormatterKey kCFNumberFormatterMaxFractionDigits;
extern const CFNumberFormatterKey kCFNumberFormatterGroupingSize;
extern const CFNumberFormatterKey kCFNumberFormatterSecondaryGroupingSize;
extern const CFNumberFormatterKey kCFNumberFormatterRoundingMode;
extern const CFNumberFormatterKey kCFNumberFormatterRoundingIncrement;
extern const CFNumberFormatterKey kCFNumberFormatterFormatWidth;
extern const CFNumberFormatterKey kCFNumberFormatterPaddingPosition;
extern const CFNumberFormatterKey kCFNumberFormatterPaddingCharacter;
extern const CFNumberFormatterKey kCFNumberFormatterDefaultFormat;
extern const CFNumberFormatterKey kCFNumberFormatterMultiplier;
extern const CFNumberFormatterKey kCFNumberFormatterPositivePrefix;
extern const CFNumberFormatterKey kCFNumberFormatterPositiveSuffix;
extern const CFNumberFormatterKey kCFNumberFormatterNegativePrefix;
extern const CFNumberFormatterKey kCFNumberFormatterNegativeSuffix;
extern const CFNumberFormatterKey kCFNumberFormatterPerMillSymbol;
extern const CFNumberFormatterKey kCFNumberFormatterInternationalCurrencySymbol;
extern const CFNumberFormatterKey kCFNumberFormatterCurrencyGroupingSeparator __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFNumberFormatterKey kCFNumberFormatterIsLenient __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFNumberFormatterKey kCFNumberFormatterUseSignificantDigits __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFNumberFormatterKey kCFNumberFormatterMinSignificantDigits __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern const CFNumberFormatterKey kCFNumberFormatterMaxSignificantDigits __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

typedef CFIndex CFNumberFormatterRoundingMode; enum {
    kCFNumberFormatterRoundCeiling = 0,
    kCFNumberFormatterRoundFloor = 1,
    kCFNumberFormatterRoundDown = 2,
    kCFNumberFormatterRoundUp = 3,
    kCFNumberFormatterRoundHalfEven = 4,
    kCFNumberFormatterRoundHalfDown = 5,
    kCFNumberFormatterRoundHalfUp = 6
};

typedef CFIndex CFNumberFormatterPadPosition; enum {
    kCFNumberFormatterPadBeforePrefix = 0,
    kCFNumberFormatterPadAfterPrefix = 1,
    kCFNumberFormatterPadBeforeSuffix = 2,
    kCFNumberFormatterPadAfterSuffix = 3
};


extern
Boolean CFNumberFormatterGetDecimalInfoForCurrencyCode(CFStringRef currencyCode, int32_t *defaultFractionDigits, double *roundingIncrement);






}
#pragma clang assume_nonnull begin
extern "C" {

extern
const CFStringRef kCFPreferencesAnyApplication;
extern
const CFStringRef kCFPreferencesCurrentApplication;
extern
const CFStringRef kCFPreferencesAnyHost;
extern
const CFStringRef kCFPreferencesCurrentHost;
extern
const CFStringRef kCFPreferencesAnyUser;
extern
const CFStringRef kCFPreferencesCurrentUser;
extern
_Nullable CFPropertyListRef CFPreferencesCopyAppValue(CFStringRef key, CFStringRef applicationID);




extern
Boolean CFPreferencesGetAppBooleanValue(CFStringRef key, CFStringRef applicationID, Boolean * _Nullable keyExistsAndHasValidFormat);




extern
CFIndex CFPreferencesGetAppIntegerValue(CFStringRef key, CFStringRef applicationID, Boolean * _Nullable keyExistsAndHasValidFormat);




extern
void CFPreferencesSetAppValue(CFStringRef key, _Nullable CFPropertyListRef value, CFStringRef applicationID);





extern
void CFPreferencesAddSuitePreferencesToApp(CFStringRef applicationID, CFStringRef suiteID);

extern
void CFPreferencesRemoveSuitePreferencesFromApp(CFStringRef applicationID, CFStringRef suiteID);



extern
Boolean CFPreferencesAppSynchronize(CFStringRef applicationID);





extern
_Nullable CFPropertyListRef CFPreferencesCopyValue(CFStringRef key, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);





extern
CFDictionaryRef CFPreferencesCopyMultiple(_Nullable CFArrayRef keysToFetch, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);



extern
void CFPreferencesSetValue(CFStringRef key, _Nullable CFPropertyListRef value, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);



extern
void CFPreferencesSetMultiple(_Nullable CFDictionaryRef keysToSet, _Nullable CFArrayRef keysToRemove, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);

extern
Boolean CFPreferencesSynchronize(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);





extern
_Nullable CFArrayRef CFPreferencesCopyApplicationList(CFStringRef userName, CFStringRef hostName) __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Unsupported API"))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Unsupported API"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Unsupported API"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Unsupported API")));




extern
_Nullable CFArrayRef CFPreferencesCopyKeyList(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);







extern
Boolean CFPreferencesAppValueIsForced(CFStringRef key, CFStringRef applicationID);



}
#pragma clang assume_nonnull end
extern "C" {

typedef CFIndex CFURLPathStyle; enum {
    kCFURLPOSIXPathStyle = 0,
    kCFURLHFSPathStyle __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Carbon File Manager is deprecated, use kCFURLPOSIXPathStyle where possible"))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Carbon File Manager is deprecated, use kCFURLPOSIXPathStyle where possible"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Carbon File Manager is deprecated, use kCFURLPOSIXPathStyle where possible"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Carbon File Manager is deprecated, use kCFURLPOSIXPathStyle where possible"))),
    kCFURLWindowsPathStyle
};

typedef const struct __attribute__((objc_bridge(NSURL))) __CFURL * CFURLRef;
extern
CFTypeID CFURLGetTypeID(void);
extern
CFURLRef CFURLCreateWithBytes(CFAllocatorRef allocator, const UInt8 *URLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL);





extern
CFDataRef CFURLCreateData(CFAllocatorRef allocator, CFURLRef url, CFStringEncoding encoding, Boolean escapeWhitespace);


extern
CFURLRef CFURLCreateWithString(CFAllocatorRef allocator, CFStringRef URLString, CFURLRef baseURL);
extern
CFURLRef CFURLCreateAbsoluteURLWithBytes(CFAllocatorRef alloc, const UInt8 *relativeURLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL, Boolean useCompatibilityMode);







extern
CFURLRef CFURLCreateWithFileSystemPath(CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory);

extern
CFURLRef CFURLCreateFromFileSystemRepresentation(CFAllocatorRef allocator, const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory);







extern
CFURLRef CFURLCreateWithFileSystemPathRelativeToBase(CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory, CFURLRef baseURL);

extern
CFURLRef CFURLCreateFromFileSystemRepresentationRelativeToBase(CFAllocatorRef allocator, const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory, CFURLRef baseURL);
extern
Boolean CFURLGetFileSystemRepresentation(CFURLRef url, Boolean resolveAgainstBase, UInt8 *buffer, CFIndex maxBufLen);


extern
CFURLRef CFURLCopyAbsoluteURL(CFURLRef relativeURL);


extern
CFStringRef CFURLGetString(CFURLRef anURL);


extern
CFURLRef CFURLGetBaseURL(CFURLRef anURL);
extern
Boolean CFURLCanBeDecomposed(CFURLRef anURL);

extern
CFStringRef CFURLCopyScheme(CFURLRef anURL);


extern
CFStringRef CFURLCopyNetLocation(CFURLRef anURL);
extern
CFStringRef CFURLCopyPath(CFURLRef anURL);


extern
CFStringRef CFURLCopyStrictPath(CFURLRef anURL, Boolean *isAbsolute);




extern
CFStringRef CFURLCopyFileSystemPath(CFURLRef anURL, CFURLPathStyle pathStyle);



extern
Boolean CFURLHasDirectoryPath(CFURLRef anURL);




extern
CFStringRef CFURLCopyResourceSpecifier(CFURLRef anURL);


extern
CFStringRef CFURLCopyHostName(CFURLRef anURL);

extern
SInt32 CFURLGetPortNumber(CFURLRef anURL);


extern
CFStringRef CFURLCopyUserName(CFURLRef anURL);


extern
CFStringRef CFURLCopyPassword(CFURLRef anURL);







extern
CFStringRef CFURLCopyParameterString(CFURLRef anURL, CFStringRef charactersToLeaveEscaped) __attribute__((availability(macosx,introduced=10.2,deprecated=10.15,message="The CFURLCopyParameterString function is deprecated. Post deprecation for applications linked with or after the macOS 10.15, and for all iOS, watchOS, and tvOS applications, CFURLCopyParameterString will always return NULL, and the CFURLCopyPath(), CFURLCopyStrictPath(), and CFURLCopyFileSystemPath() functions will return the complete path including the semicolon separator and params component if the URL string contains them."))) __attribute__((availability(ios,introduced=2.0,deprecated=13.0,message="The CFURLCopyParameterString function is deprecated. Post deprecation for applications linked with or after the macOS 10.15, and for all iOS, watchOS, and tvOS applications, CFURLCopyParameterString will always return NULL, and the CFURLCopyPath(), CFURLCopyStrictPath(), and CFURLCopyFileSystemPath() functions will return the complete path including the semicolon separator and params component if the URL string contains them."))) __attribute__((availability(watchos,introduced=2.0,deprecated=6.0,message="The CFURLCopyParameterString function is deprecated. Post deprecation for applications linked with or after the macOS 10.15, and for all iOS, watchOS, and tvOS applications, CFURLCopyParameterString will always return NULL, and the CFURLCopyPath(), CFURLCopyStrictPath(), and CFURLCopyFileSystemPath() functions will return the complete path including the semicolon separator and params component if the URL string contains them."))) __attribute__((availability(tvos,introduced=9.0,deprecated=13.0,message="The CFURLCopyParameterString function is deprecated. Post deprecation for applications linked with or after the macOS 10.15, and for all iOS, watchOS, and tvOS applications, CFURLCopyParameterString will always return NULL, and the CFURLCopyPath(), CFURLCopyStrictPath(), and CFURLCopyFileSystemPath() functions will return the complete path including the semicolon separator and params component if the URL string contains them.")));
extern
CFStringRef CFURLCopyQueryString(CFURLRef anURL, CFStringRef charactersToLeaveEscaped);

extern
CFStringRef CFURLCopyFragment(CFURLRef anURL, CFStringRef charactersToLeaveEscaped);


extern
CFStringRef CFURLCopyLastPathComponent(CFURLRef url);


extern
CFStringRef CFURLCopyPathExtension(CFURLRef url);

extern
CFURLRef CFURLCreateCopyAppendingPathComponent(CFAllocatorRef allocator, CFURLRef url, CFStringRef pathComponent, Boolean isDirectory);

extern
CFURLRef CFURLCreateCopyDeletingLastPathComponent(CFAllocatorRef allocator, CFURLRef url);

extern
CFURLRef CFURLCreateCopyAppendingPathExtension(CFAllocatorRef allocator, CFURLRef url, CFStringRef extension);

extern
CFURLRef CFURLCreateCopyDeletingPathExtension(CFAllocatorRef allocator, CFURLRef url);
extern
CFIndex CFURLGetBytes(CFURLRef url, UInt8 *buffer, CFIndex bufferLength);

typedef CFIndex CFURLComponentType; enum {
 kCFURLComponentScheme = 1,
 kCFURLComponentNetLocation = 2,
 kCFURLComponentPath = 3,
 kCFURLComponentResourceSpecifier = 4,

 kCFURLComponentUser = 5,
 kCFURLComponentPassword = 6,
 kCFURLComponentUserInfo = 7,
 kCFURLComponentHost = 8,
 kCFURLComponentPort = 9,
 kCFURLComponentParameterString = 10,
 kCFURLComponentQuery = 11,
 kCFURLComponentFragment = 12
};
extern
CFRange CFURLGetByteRangeForComponent(CFURLRef url, CFURLComponentType component, CFRange *rangeIncludingSeparators);
extern
CFStringRef CFURLCreateStringByReplacingPercentEscapes(CFAllocatorRef allocator, CFStringRef originalString, CFStringRef charactersToLeaveEscaped);


extern
CFStringRef CFURLCreateStringByReplacingPercentEscapesUsingEncoding(CFAllocatorRef allocator, CFStringRef origString, CFStringRef charsToLeaveEscaped, CFStringEncoding encoding) __attribute__((availability(macos,introduced=10.0,deprecated=10.11,message="Use [NSString stringByRemovingPercentEncoding] or CFURLCreateStringByReplacingPercentEscapes() instead, which always uses the recommended UTF-8 encoding."))) __attribute__((availability(ios,introduced=2.0,deprecated=9.0,message="Use [NSString stringByRemovingPercentEncoding] or CFURLCreateStringByReplacingPercentEscapes() instead, which always uses the recommended UTF-8 encoding."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use [NSString stringByRemovingPercentEncoding] or CFURLCreateStringByReplacingPercentEscapes() instead, which always uses the recommended UTF-8 encoding."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use [NSString stringByRemovingPercentEncoding] or CFURLCreateStringByReplacingPercentEscapes() instead, which always uses the recommended UTF-8 encoding.")));
extern
CFStringRef CFURLCreateStringByAddingPercentEscapes(CFAllocatorRef allocator, CFStringRef originalString, CFStringRef charactersToLeaveUnescaped, CFStringRef legalURLCharactersToBeEscaped, CFStringEncoding encoding) __attribute__((availability(macos,introduced=10.0,deprecated=10.11,message="Use [NSString stringByAddingPercentEncodingWithAllowedCharacters:] instead, which always uses the recommended UTF-8 encoding, and which encodes for a specific URL component or subcomponent (since each URL component or subcomponent has different rules for what characters are valid)."))) __attribute__((availability(ios,introduced=2.0,deprecated=9.0,message="Use [NSString stringByAddingPercentEncodingWithAllowedCharacters:] instead, which always uses the recommended UTF-8 encoding, and which encodes for a specific URL component or subcomponent (since each URL component or subcomponent has different rules for what characters are valid)."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use [NSString stringByAddingPercentEncodingWithAllowedCharacters:] instead, which always uses the recommended UTF-8 encoding, and which encodes for a specific URL component or subcomponent (since each URL component or subcomponent has different rules for what characters are valid)."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use [NSString stringByAddingPercentEncodingWithAllowedCharacters:] instead, which always uses the recommended UTF-8 encoding, and which encodes for a specific URL component or subcomponent (since each URL component or subcomponent has different rules for what characters are valid).")));
extern
Boolean CFURLIsFileReferenceURL(CFURLRef url) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFURLRef CFURLCreateFileReferenceURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFURLRef CFURLCreateFilePathURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));







struct FSRef;



extern
CFURLRef CFURLCreateFromFSRef(CFAllocatorRef allocator, const struct FSRef *fsRef) __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Not supported"))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Not supported"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Not supported"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Not supported")));

extern
Boolean CFURLGetFSRef(CFURLRef url, struct FSRef *fsRef) __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Not supported"))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Not supported"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Not supported"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Not supported")));
extern
Boolean CFURLCopyResourcePropertyForKey(CFURLRef url, CFStringRef key, void *propertyValueTypeRefPtr, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFDictionaryRef CFURLCopyResourcePropertiesForKeys(CFURLRef url, CFArrayRef keys, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFURLSetResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFURLSetResourcePropertiesForKeys(CFURLRef url, CFDictionaryRef keyedPropertyValues, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLKeysOfUnsetValuesKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
void CFURLClearResourcePropertyCacheForKey(CFURLRef url, CFStringRef key) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
void CFURLClearResourcePropertyCache(CFURLRef url) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
void CFURLSetTemporaryResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFURLResourceIsReachable(CFURLRef url, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));






extern
const CFStringRef kCFURLNameKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLLocalizedNameKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsRegularFileKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsDirectoryKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsSymbolicLinkKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsVolumeKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsPackageKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsApplicationKey __attribute__((availability(macos,introduced=10.11))) __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLApplicationIsScriptableKey __attribute__((availability(macos,introduced=10.11))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));


extern
const CFStringRef kCFURLIsSystemImmutableKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsUserImmutableKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsHiddenKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLHasHiddenExtensionKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLCreationDateKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLContentAccessDateKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLContentModificationDateKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLAttributeModificationDateKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLFileContentIdentifierKey __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0))) __attribute__((availability(tvos,introduced=14.0)));


extern
const CFStringRef kCFURLMayShareFileContentKey __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0))) __attribute__((availability(tvos,introduced=14.0)));


extern
const CFStringRef kCFURLMayHaveExtendedAttributesKey __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0))) __attribute__((availability(tvos,introduced=14.0)));


extern
const CFStringRef kCFURLIsPurgeableKey __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0))) __attribute__((availability(tvos,introduced=14.0)));


extern
const CFStringRef kCFURLIsSparseKey __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0))) __attribute__((availability(tvos,introduced=14.0)));


extern
const CFStringRef kCFURLLinkCountKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLParentDirectoryURLKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeURLKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLTypeIdentifierKey __attribute__((availability(macos,introduced=10.6,deprecated=100000,message="Use NSURLContentTypeKey instead"))) __attribute__((availability(ios,introduced=4.0,deprecated=100000,message="Use NSURLContentTypeKey instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=100000,message="Use NSURLContentTypeKey instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=100000,message="Use NSURLContentTypeKey instead")));


extern
const CFStringRef kCFURLLocalizedTypeDescriptionKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLLabelNumberKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLLabelColorKey __attribute__((availability(macosx,introduced=10.6,deprecated=10.12,message="Use NSURLLabelColorKey"))) __attribute__((availability(ios,introduced=4.0,deprecated=10.0,message="Use NSURLLabelColorKey"))) __attribute__((availability(watchos,introduced=2.0,deprecated=3.0,message="Use NSURLLabelColorKey"))) __attribute__((availability(tvos,introduced=9.0,deprecated=10.0,message="Use NSURLLabelColorKey")));


extern
const CFStringRef kCFURLLocalizedLabelKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLEffectiveIconKey __attribute__((availability(macosx,introduced=10.6,deprecated=10.12,message="Use NSURLEffectiveIconKey"))) __attribute__((availability(ios,introduced=4.0,deprecated=10.0,message="Use NSURLEffectiveIconKey"))) __attribute__((availability(watchos,introduced=2.0,deprecated=3.0,message="Use NSURLEffectiveIconKey"))) __attribute__((availability(tvos,introduced=9.0,deprecated=10.0,message="Use NSURLEffectiveIconKey")));


extern
const CFStringRef kCFURLCustomIconKey __attribute__((availability(macosx,introduced=10.6,deprecated=10.12,message="Use NSURLCustomIconKey"))) __attribute__((availability(ios,introduced=4.0,deprecated=10.0,message="Use NSURLCustomIconKey"))) __attribute__((availability(watchos,introduced=2.0,deprecated=3.0,message="Use NSURLCustomIconKey"))) __attribute__((availability(tvos,introduced=9.0,deprecated=10.0,message="Use NSURLCustomIconKey")));


extern
const CFStringRef kCFURLFileResourceIdentifierKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIdentifierKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLPreferredIOBlockSizeKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsReadableKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsWritableKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsExecutableKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLFileSecurityKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsExcludedFromBackupKey __attribute__((availability(macos,introduced=10.8))) __attribute__((availability(ios,introduced=5.1))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLTagNamesKey __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));


extern
const CFStringRef kCFURLPathKey __attribute__((availability(macos,introduced=10.8))) __attribute__((availability(ios,introduced=6.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLCanonicalPathKey __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));


extern
const CFStringRef kCFURLIsMountTriggerKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLGenerationIdentifierKey __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLDocumentIdentifierKey __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLAddedToDirectoryDateKey __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLQuarantinePropertiesKey __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));


extern
const CFStringRef kCFURLFileResourceTypeKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
const CFStringRef kCFURLFileResourceTypeNamedPipe __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
const CFStringRef kCFURLFileResourceTypeCharacterSpecial __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
const CFStringRef kCFURLFileResourceTypeDirectory __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
const CFStringRef kCFURLFileResourceTypeBlockSpecial __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
const CFStringRef kCFURLFileResourceTypeRegular __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
const CFStringRef kCFURLFileResourceTypeSymbolicLink __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
const CFStringRef kCFURLFileResourceTypeSocket __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
const CFStringRef kCFURLFileResourceTypeUnknown __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
const CFStringRef kCFURLFileSizeKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLFileAllocatedSizeKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLTotalFileSizeKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLTotalFileAllocatedSizeKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLIsAliasFileKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLFileProtectionKey __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(macos,unavailable)));



extern
const CFStringRef kCFURLFileProtectionNone __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(macos,unavailable)));

extern
const CFStringRef kCFURLFileProtectionComplete __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(macos,unavailable)));

extern
const CFStringRef kCFURLFileProtectionCompleteUnlessOpen __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(macos,unavailable)));

extern
const CFStringRef kCFURLFileProtectionCompleteUntilFirstUserAuthentication __attribute__((availability(ios,introduced=9.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(macos,unavailable)));





extern
const CFStringRef kCFURLVolumeLocalizedFormatDescriptionKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeTotalCapacityKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeAvailableCapacityKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeAvailableCapacityForImportantUsageKey __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));






extern
const CFStringRef kCFURLVolumeAvailableCapacityForOpportunisticUsageKey __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));




extern
const CFStringRef kCFURLVolumeResourceCountKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsPersistentIDsKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsSymbolicLinksKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsHardLinksKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsJournalingKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsJournalingKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsSparseFilesKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsZeroRunsKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsCaseSensitiveNamesKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsCasePreservedNamesKey __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsRootDirectoryDatesKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsVolumeSizesKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsRenamingKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsAdvisoryFileLockingKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeSupportsExtendedSecurityKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsBrowsableKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeMaximumFileSizeKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsEjectableKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsRemovableKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsInternalKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsAutomountedKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsLocalKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsReadOnlyKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeCreationDateKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeURLForRemountingKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeUUIDStringKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeNameKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeLocalizedNameKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLVolumeIsEncryptedKey __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));


extern
const CFStringRef kCFURLVolumeIsRootFileSystemKey __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));


extern
const CFStringRef kCFURLVolumeSupportsCompressionKey __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));


extern
const CFStringRef kCFURLVolumeSupportsFileCloningKey __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));


extern
const CFStringRef kCFURLVolumeSupportsSwapRenamingKey __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));


extern
const CFStringRef kCFURLVolumeSupportsExclusiveRenamingKey __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) __attribute__((availability(tvos,introduced=10.0)));


extern
const CFStringRef kCFURLVolumeSupportsImmutableFilesKey __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0))) __attribute__((availability(tvos,introduced=11.0)));


extern
const CFStringRef kCFURLVolumeSupportsAccessPermissionsKey __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0))) __attribute__((availability(tvos,introduced=11.0)));


extern
const CFStringRef kCFURLVolumeSupportsFileProtectionKey __attribute__((availability(macosx,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0))) __attribute__((availability(tvos,introduced=14.0)));




extern
const CFStringRef kCFURLIsUbiquitousItemKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemHasUnresolvedConflictsKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemIsDownloadedKey __attribute__((availability(macos,introduced=10.7,deprecated=10.9,message="Use kCFURLUbiquitousItemDownloadingStatusKey instead"))) __attribute__((availability(ios,introduced=5.0,deprecated=7.0,message="Use kCFURLUbiquitousItemDownloadingStatusKey instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use kCFURLUbiquitousItemDownloadingStatusKey instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use kCFURLUbiquitousItemDownloadingStatusKey instead")));


extern
const CFStringRef kCFURLUbiquitousItemIsDownloadingKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemIsUploadedKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemIsUploadingKey __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemPercentDownloadedKey __attribute__((availability(macos,introduced=10.7,deprecated=10.8,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentDownloadedKey on NSMetadataItem instead"))) __attribute__((availability(ios,introduced=5.0,deprecated=6.0,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentDownloadedKey on NSMetadataItem instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentDownloadedKey on NSMetadataItem instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentDownloadedKey on NSMetadataItem instead")));


extern
const CFStringRef kCFURLUbiquitousItemPercentUploadedKey __attribute__((availability(macos,introduced=10.7,deprecated=10.8,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentUploadedKey on NSMetadataItem instead"))) __attribute__((availability(ios,introduced=5.0,deprecated=6.0,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentUploadedKey on NSMetadataItem instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentUploadedKey on NSMetadataItem instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use NSMetadataQuery and NSMetadataUbiquitousItemPercentUploadedKey on NSMetadataItem instead")));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusKey __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingErrorKey __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemUploadingErrorKey __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));




extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusNotDownloaded __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusDownloaded __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusCurrent __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));




typedef CFOptionFlags CFURLBookmarkCreationOptions; enum {
    kCFURLBookmarkCreationMinimalBookmarkMask = ( 1UL << 9 ),
    kCFURLBookmarkCreationSuitableForBookmarkFile = ( 1UL << 10 ),
    kCFURLBookmarkCreationWithSecurityScope __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(macCatalyst,introduced=13.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = ( 1UL << 11 ),
    kCFURLBookmarkCreationSecurityScopeAllowOnlyReadAccess __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(macCatalyst,introduced=13.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = ( 1UL << 12 ),


    kCFURLBookmarkCreationPreferFileIDResolutionMask
    __attribute__((availability(macos,introduced=10.6,deprecated=10.9,message="kCFURLBookmarkCreationPreferFileIDResolutionMask does nothing and has no effect on bookmark resolution"))) __attribute__((availability(ios,introduced=4.0,deprecated=7.0,message="kCFURLBookmarkCreationPreferFileIDResolutionMask does nothing and has no effect on bookmark resolution"))) = ( 1UL << 8 ),
} __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

typedef CFOptionFlags CFURLBookmarkResolutionOptions; enum {
    kCFURLBookmarkResolutionWithoutUIMask = ( 1UL << 8 ),
    kCFURLBookmarkResolutionWithoutMountingMask = ( 1UL << 9 ),
    kCFURLBookmarkResolutionWithSecurityScope __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(macCatalyst,introduced=13.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = ( 1UL << 10 ),

    kCFBookmarkResolutionWithoutUIMask = kCFURLBookmarkResolutionWithoutUIMask,
    kCFBookmarkResolutionWithoutMountingMask = kCFURLBookmarkResolutionWithoutMountingMask,
} __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

typedef CFOptionFlags CFURLBookmarkFileCreationOptions;





extern
CFDataRef CFURLCreateBookmarkData ( CFAllocatorRef allocator, CFURLRef url, CFURLBookmarkCreationOptions options, CFArrayRef resourcePropertiesToInclude, CFURLRef relativeToURL, CFErrorRef* error ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFURLRef CFURLCreateByResolvingBookmarkData ( CFAllocatorRef allocator, CFDataRef bookmark, CFURLBookmarkResolutionOptions options, CFURLRef relativeToURL, CFArrayRef resourcePropertiesToInclude, Boolean* isStale, CFErrorRef* error ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFDictionaryRef CFURLCreateResourcePropertiesForKeysFromBookmarkData ( CFAllocatorRef allocator, CFArrayRef resourcePropertiesToReturn, CFDataRef bookmark ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFTypeRef CFURLCreateResourcePropertyForKeyFromBookmarkData( CFAllocatorRef allocator, CFStringRef resourcePropertyKey, CFDataRef bookmark ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFDataRef CFURLCreateBookmarkDataFromFile(CFAllocatorRef allocator, CFURLRef fileURL, CFErrorRef *errorRef ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
Boolean CFURLWriteBookmarkDataToFile( CFDataRef bookmarkRef, CFURLRef fileURL, CFURLBookmarkFileCreationOptions options, CFErrorRef *errorRef ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFDataRef CFURLCreateBookmarkDataFromAliasRecord ( CFAllocatorRef allocatorRef, CFDataRef aliasRecordDataRef ) __attribute__((availability(macos,introduced=10.6,deprecated=11.0,message="The Carbon Alias Manager is deprecated. This function should only be used to convert Carbon AliasRecords to bookmark data."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));





extern
Boolean CFURLStartAccessingSecurityScopedResource(CFURLRef url) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=8.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
void CFURLStopAccessingSecurityScopedResource(CFURLRef url) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=8.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));




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



extern "C" {

typedef CFStringRef CFRunLoopMode __attribute__((swift_wrapper(struct)));

typedef struct __attribute__((objc_bridge_mutable(id))) __CFRunLoop * CFRunLoopRef;

typedef struct __attribute__((objc_bridge_mutable(id))) __CFRunLoopSource * CFRunLoopSourceRef;

typedef struct __attribute__((objc_bridge_mutable(id))) __CFRunLoopObserver * CFRunLoopObserverRef;

typedef struct __attribute__((objc_bridge_mutable(NSTimer))) __CFRunLoopTimer * CFRunLoopTimerRef;


typedef SInt32 CFRunLoopRunResult; enum {
    kCFRunLoopRunFinished = 1,
    kCFRunLoopRunStopped = 2,
    kCFRunLoopRunTimedOut = 3,
    kCFRunLoopRunHandledSource = 4
};


typedef CFOptionFlags CFRunLoopActivity; enum {
    kCFRunLoopEntry = (1UL << 0),
    kCFRunLoopBeforeTimers = (1UL << 1),
    kCFRunLoopBeforeSources = (1UL << 2),
    kCFRunLoopBeforeWaiting = (1UL << 5),
    kCFRunLoopAfterWaiting = (1UL << 6),
    kCFRunLoopExit = (1UL << 7),
    kCFRunLoopAllActivities = 0x0FFFFFFFU
};

extern const CFRunLoopMode kCFRunLoopDefaultMode;
extern const CFRunLoopMode kCFRunLoopCommonModes;

extern CFTypeID CFRunLoopGetTypeID(void);

extern CFRunLoopRef CFRunLoopGetCurrent(void);
extern CFRunLoopRef CFRunLoopGetMain(void);

extern CFRunLoopMode CFRunLoopCopyCurrentMode(CFRunLoopRef rl);

extern CFArrayRef CFRunLoopCopyAllModes(CFRunLoopRef rl);

extern void CFRunLoopAddCommonMode(CFRunLoopRef rl, CFRunLoopMode mode);

extern CFAbsoluteTime CFRunLoopGetNextTimerFireDate(CFRunLoopRef rl, CFRunLoopMode mode);

extern void CFRunLoopRun(void);
extern CFRunLoopRunResult CFRunLoopRunInMode(CFRunLoopMode mode, CFTimeInterval seconds, Boolean returnAfterSourceHandled);
extern Boolean CFRunLoopIsWaiting(CFRunLoopRef rl);
extern void CFRunLoopWakeUp(CFRunLoopRef rl);
extern void CFRunLoopStop(CFRunLoopRef rl);


extern void CFRunLoopPerformBlock(CFRunLoopRef rl, CFTypeRef mode, void (*block)(void)) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern Boolean CFRunLoopContainsSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFRunLoopMode mode);
extern void CFRunLoopAddSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFRunLoopMode mode);
extern void CFRunLoopRemoveSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFRunLoopMode mode);

extern Boolean CFRunLoopContainsObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFRunLoopMode mode);
extern void CFRunLoopAddObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFRunLoopMode mode);
extern void CFRunLoopRemoveObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFRunLoopMode mode);

extern Boolean CFRunLoopContainsTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFRunLoopMode mode);
extern void CFRunLoopAddTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFRunLoopMode mode);
extern void CFRunLoopRemoveTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFRunLoopMode mode);

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
    Boolean (*equal)(const void *info1, const void *info2);
    CFHashCode (*hash)(const void *info);
    void (*schedule)(void *info, CFRunLoopRef rl, CFRunLoopMode mode);
    void (*cancel)(void *info, CFRunLoopRef rl, CFRunLoopMode mode);
    void (*perform)(void *info);
} CFRunLoopSourceContext;

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
    Boolean (*equal)(const void *info1, const void *info2);
    CFHashCode (*hash)(const void *info);

    mach_port_t (*getPort)(void *info);
    void * (*perform)(void *msg, CFIndex size, CFAllocatorRef allocator, void *info);




} CFRunLoopSourceContext1;

extern CFTypeID CFRunLoopSourceGetTypeID(void);

extern CFRunLoopSourceRef CFRunLoopSourceCreate(CFAllocatorRef allocator, CFIndex order, CFRunLoopSourceContext *context);

extern CFIndex CFRunLoopSourceGetOrder(CFRunLoopSourceRef source);
extern void CFRunLoopSourceInvalidate(CFRunLoopSourceRef source);
extern Boolean CFRunLoopSourceIsValid(CFRunLoopSourceRef source);
extern void CFRunLoopSourceGetContext(CFRunLoopSourceRef source, CFRunLoopSourceContext *context);
extern void CFRunLoopSourceSignal(CFRunLoopSourceRef source);

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFRunLoopObserverContext;

typedef void (*CFRunLoopObserverCallBack)(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void *info);

extern CFTypeID CFRunLoopObserverGetTypeID(void);

extern CFRunLoopObserverRef CFRunLoopObserverCreate(CFAllocatorRef allocator, CFOptionFlags activities, Boolean repeats, CFIndex order, CFRunLoopObserverCallBack callout, CFRunLoopObserverContext *context);

extern CFRunLoopObserverRef CFRunLoopObserverCreateWithHandler(CFAllocatorRef allocator, CFOptionFlags activities, Boolean repeats, CFIndex order, void (*block) (CFRunLoopObserverRef observer, CFRunLoopActivity activity)) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern CFOptionFlags CFRunLoopObserverGetActivities(CFRunLoopObserverRef observer);
extern Boolean CFRunLoopObserverDoesRepeat(CFRunLoopObserverRef observer);
extern CFIndex CFRunLoopObserverGetOrder(CFRunLoopObserverRef observer);
extern void CFRunLoopObserverInvalidate(CFRunLoopObserverRef observer);
extern Boolean CFRunLoopObserverIsValid(CFRunLoopObserverRef observer);
extern void CFRunLoopObserverGetContext(CFRunLoopObserverRef observer, CFRunLoopObserverContext *context);

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFRunLoopTimerContext;

typedef void (*CFRunLoopTimerCallBack)(CFRunLoopTimerRef timer, void *info);

extern CFTypeID CFRunLoopTimerGetTypeID(void);

extern CFRunLoopTimerRef CFRunLoopTimerCreate(CFAllocatorRef allocator, CFAbsoluteTime fireDate, CFTimeInterval interval, CFOptionFlags flags, CFIndex order, CFRunLoopTimerCallBack callout, CFRunLoopTimerContext *context);

extern CFRunLoopTimerRef CFRunLoopTimerCreateWithHandler(CFAllocatorRef allocator, CFAbsoluteTime fireDate, CFTimeInterval interval, CFOptionFlags flags, CFIndex order, void (*block) (CFRunLoopTimerRef timer)) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


extern CFAbsoluteTime CFRunLoopTimerGetNextFireDate(CFRunLoopTimerRef timer);
extern void CFRunLoopTimerSetNextFireDate(CFRunLoopTimerRef timer, CFAbsoluteTime fireDate);
extern CFTimeInterval CFRunLoopTimerGetInterval(CFRunLoopTimerRef timer);
extern Boolean CFRunLoopTimerDoesRepeat(CFRunLoopTimerRef timer);
extern CFIndex CFRunLoopTimerGetOrder(CFRunLoopTimerRef timer);
extern void CFRunLoopTimerInvalidate(CFRunLoopTimerRef timer);
extern Boolean CFRunLoopTimerIsValid(CFRunLoopTimerRef timer);
extern void CFRunLoopTimerGetContext(CFRunLoopTimerRef timer, CFRunLoopTimerContext *context);



extern CFTimeInterval CFRunLoopTimerGetTolerance(CFRunLoopTimerRef timer) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern void CFRunLoopTimerSetTolerance(CFRunLoopTimerRef timer, CFTimeInterval tolerance) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

}
extern "C" {

typedef struct __attribute__((objc_bridge_mutable(id))) __CFSocket * CFSocketRef;
typedef CFIndex CFSocketError; enum {
    kCFSocketSuccess = 0,
    kCFSocketError = -1L,
    kCFSocketTimeout = -2L
};

typedef struct {
    SInt32 protocolFamily;
    SInt32 socketType;
    SInt32 protocol;
    CFDataRef address;
} CFSocketSignature;


typedef CFOptionFlags CFSocketCallBackType; enum {
    kCFSocketNoCallBack = 0,
    kCFSocketReadCallBack = 1,
    kCFSocketAcceptCallBack = 2,
    kCFSocketDataCallBack = 3,
    kCFSocketConnectCallBack = 4,
    kCFSocketWriteCallBack = 8
};


enum {
    kCFSocketAutomaticallyReenableReadCallBack = 1,
    kCFSocketAutomaticallyReenableAcceptCallBack = 2,
    kCFSocketAutomaticallyReenableDataCallBack = 3,
    kCFSocketAutomaticallyReenableWriteCallBack = 8,
    kCFSocketLeaveErrors __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 64,
    kCFSocketCloseOnInvalidate = 128
};

typedef void (*CFSocketCallBack)(CFSocketRef s, CFSocketCallBackType type, CFDataRef address, const void *data, void *info);


typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFSocketContext;


typedef int CFSocketNativeHandle;


extern CFTypeID CFSocketGetTypeID(void);

extern CFSocketRef CFSocketCreate(CFAllocatorRef allocator, SInt32 protocolFamily, SInt32 socketType, SInt32 protocol, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);
extern CFSocketRef CFSocketCreateWithNative(CFAllocatorRef allocator, CFSocketNativeHandle sock, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);
extern CFSocketRef CFSocketCreateWithSocketSignature(CFAllocatorRef allocator, const CFSocketSignature *signature, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);

extern CFSocketRef CFSocketCreateConnectedToSocketSignature(CFAllocatorRef allocator, const CFSocketSignature *signature, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context, CFTimeInterval timeout);


extern CFSocketError CFSocketSetAddress(CFSocketRef s, CFDataRef address);
extern CFSocketError CFSocketConnectToAddress(CFSocketRef s, CFDataRef address, CFTimeInterval timeout);
extern void CFSocketInvalidate(CFSocketRef s);

extern Boolean CFSocketIsValid(CFSocketRef s);
extern CFDataRef CFSocketCopyAddress(CFSocketRef s);
extern CFDataRef CFSocketCopyPeerAddress(CFSocketRef s);
extern void CFSocketGetContext(CFSocketRef s, CFSocketContext *context);
extern CFSocketNativeHandle CFSocketGetNative(CFSocketRef s);

extern CFRunLoopSourceRef CFSocketCreateRunLoopSource(CFAllocatorRef allocator, CFSocketRef s, CFIndex order);

extern CFOptionFlags CFSocketGetSocketFlags(CFSocketRef s);
extern void CFSocketSetSocketFlags(CFSocketRef s, CFOptionFlags flags);
extern void CFSocketDisableCallBacks(CFSocketRef s, CFOptionFlags callBackTypes);
extern void CFSocketEnableCallBacks(CFSocketRef s, CFOptionFlags callBackTypes);



extern CFSocketError CFSocketSendData(CFSocketRef s, CFDataRef address, CFDataRef data, CFTimeInterval timeout);
extern CFSocketError CFSocketRegisterValue(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFPropertyListRef value);
extern CFSocketError CFSocketCopyRegisteredValue(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFPropertyListRef *value, CFDataRef *nameServerAddress);

extern CFSocketError CFSocketRegisterSocketSignature(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, const CFSocketSignature *signature);
extern CFSocketError CFSocketCopyRegisteredSocketSignature(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFSocketSignature *signature, CFDataRef *nameServerAddress);

extern CFSocketError CFSocketUnregister(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name);

extern void CFSocketSetDefaultNameRegistryPortNumber(UInt16 port);
extern UInt16 CFSocketGetDefaultNameRegistryPortNumber(void);


extern const CFStringRef kCFSocketCommandKey;
extern const CFStringRef kCFSocketNameKey;
extern const CFStringRef kCFSocketValueKey;
extern const CFStringRef kCFSocketResultKey;
extern const CFStringRef kCFSocketErrorKey;
extern const CFStringRef kCFSocketRegisterCommand;
extern const CFStringRef kCFSocketRetrieveCommand;

}

typedef void (*os_function_t)(void *_Nullable);
typedef void (*os_block_t)(void);












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

typedef struct {
    CFIndex domain;
    SInt32 error;
} CFStreamError;

typedef CFStringRef CFStreamPropertyKey __attribute__((swift_wrapper(struct)));

typedef CFIndex CFStreamStatus; enum {
    kCFStreamStatusNotOpen = 0,
    kCFStreamStatusOpening,
    kCFStreamStatusOpen,
    kCFStreamStatusReading,
    kCFStreamStatusWriting,
    kCFStreamStatusAtEnd,
    kCFStreamStatusClosed,
    kCFStreamStatusError
};

typedef CFOptionFlags CFStreamEventType; enum {
    kCFStreamEventNone = 0,
    kCFStreamEventOpenCompleted = 1,
    kCFStreamEventHasBytesAvailable = 2,
    kCFStreamEventCanAcceptBytes = 4,
    kCFStreamEventErrorOccurred = 8,
    kCFStreamEventEndEncountered = 16
};

typedef struct {
    CFIndex version;
    void * _Null_unspecified info;
    void *_Null_unspecified(* _Null_unspecified retain)(void * _Null_unspecified info);
    void (* _Null_unspecified release)(void * _Null_unspecified info);
    CFStringRef _Null_unspecified (* _Null_unspecified copyDescription)(void * _Null_unspecified info);
} CFStreamClientContext;

typedef struct __attribute__((objc_bridge_mutable(NSInputStream))) __CFReadStream * CFReadStreamRef;
typedef struct __attribute__((objc_bridge_mutable(NSOutputStream))) __CFWriteStream * CFWriteStreamRef;

typedef void (*CFReadStreamClientCallBack)(CFReadStreamRef _Null_unspecified stream, CFStreamEventType type, void * _Null_unspecified clientCallBackInfo);
typedef void (*CFWriteStreamClientCallBack)(CFWriteStreamRef _Null_unspecified stream, CFStreamEventType type, void * _Null_unspecified clientCallBackInfo);

extern
CFTypeID CFReadStreamGetTypeID(void);
extern
CFTypeID CFWriteStreamGetTypeID(void);




extern
const CFStreamPropertyKey _Null_unspecified kCFStreamPropertyDataWritten;


extern
CFReadStreamRef _Null_unspecified CFReadStreamCreateWithBytesNoCopy(CFAllocatorRef _Null_unspecified alloc, const UInt8 * _Null_unspecified bytes, CFIndex length, CFAllocatorRef _Null_unspecified bytesDeallocator);


extern
CFWriteStreamRef _Null_unspecified CFWriteStreamCreateWithBuffer(CFAllocatorRef _Null_unspecified alloc, UInt8 * _Null_unspecified buffer, CFIndex bufferCapacity);


extern
CFWriteStreamRef _Null_unspecified CFWriteStreamCreateWithAllocatedBuffers(CFAllocatorRef _Null_unspecified alloc, CFAllocatorRef _Null_unspecified bufferAllocator);


extern
CFReadStreamRef _Null_unspecified CFReadStreamCreateWithFile(CFAllocatorRef _Null_unspecified alloc, CFURLRef _Null_unspecified fileURL);
extern
CFWriteStreamRef _Null_unspecified CFWriteStreamCreateWithFile(CFAllocatorRef _Null_unspecified alloc, CFURLRef _Null_unspecified fileURL);

extern
void CFStreamCreateBoundPair(CFAllocatorRef _Null_unspecified alloc, CFReadStreamRef _Null_unspecified * _Null_unspecified readStream, CFWriteStreamRef _Null_unspecified * _Null_unspecified writeStream, CFIndex transferBufferSize);



extern
const CFStreamPropertyKey _Null_unspecified kCFStreamPropertyAppendToFile;

extern
const CFStreamPropertyKey _Null_unspecified kCFStreamPropertyFileCurrentOffset;





extern
const CFStreamPropertyKey _Null_unspecified kCFStreamPropertySocketNativeHandle;


extern
const CFStreamPropertyKey _Null_unspecified kCFStreamPropertySocketRemoteHostName;


extern
const CFStreamPropertyKey _Null_unspecified kCFStreamPropertySocketRemotePortNumber;







extern const int kCFStreamErrorDomainSOCKS __attribute__((availability(macosx,introduced=10_0)));
extern const CFStringRef _Nonnull kCFStreamPropertySOCKSProxy __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamPropertySOCKSProxyHost __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamPropertySOCKSProxyPort __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamPropertySOCKSVersion __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamSocketSOCKSVersion4 __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamSocketSOCKSVersion5 __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamPropertySOCKSUser __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamPropertySOCKSPassword __attribute__((availability(macosx,introduced=10_2)));
extern const int kCFStreamErrorDomainSSL __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamPropertySocketSecurityLevel __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamSocketSecurityLevelNone __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamSocketSecurityLevelSSLv2 __attribute__((availability(macosx,introduced=10_2,deprecated=10_12,message="" )));
extern const CFStringRef _Nonnull kCFStreamSocketSecurityLevelSSLv3 __attribute__((availability(macosx,introduced=10_2,deprecated=10_12,message="" )));
extern const CFStringRef _Nonnull kCFStreamSocketSecurityLevelTLSv1 __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamSocketSecurityLevelNegotiatedSSL __attribute__((availability(macosx,introduced=10_2)));
extern const CFStringRef _Nonnull kCFStreamPropertyShouldCloseNativeSocket __attribute__((availability(macosx,introduced=10_2)));



extern
void CFStreamCreatePairWithSocket(CFAllocatorRef _Null_unspecified alloc, CFSocketNativeHandle sock, CFReadStreamRef _Null_unspecified * _Null_unspecified readStream, CFWriteStreamRef _Null_unspecified * _Null_unspecified writeStream);
extern
void CFStreamCreatePairWithSocketToHost(CFAllocatorRef _Null_unspecified alloc, CFStringRef _Null_unspecified host, UInt32 port, CFReadStreamRef _Null_unspecified * _Null_unspecified readStream, CFWriteStreamRef _Null_unspecified * _Null_unspecified writeStream);
extern
void CFStreamCreatePairWithPeerSocketSignature(CFAllocatorRef _Null_unspecified alloc, const CFSocketSignature * _Null_unspecified signature, CFReadStreamRef _Null_unspecified * _Null_unspecified readStream, CFWriteStreamRef _Null_unspecified * _Null_unspecified writeStream);




extern
CFStreamStatus CFReadStreamGetStatus(CFReadStreamRef _Null_unspecified stream);
extern
CFStreamStatus CFWriteStreamGetStatus(CFWriteStreamRef _Null_unspecified stream);


extern
CFErrorRef _Null_unspecified CFReadStreamCopyError(CFReadStreamRef _Null_unspecified stream) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFErrorRef _Null_unspecified CFWriteStreamCopyError(CFWriteStreamRef _Null_unspecified stream) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));






extern
Boolean CFReadStreamOpen(CFReadStreamRef _Null_unspecified stream);
extern
Boolean CFWriteStreamOpen(CFWriteStreamRef _Null_unspecified stream);




extern
void CFReadStreamClose(CFReadStreamRef _Null_unspecified stream);
extern
void CFWriteStreamClose(CFWriteStreamRef _Null_unspecified stream);



extern
Boolean CFReadStreamHasBytesAvailable(CFReadStreamRef _Null_unspecified stream);
extern
CFIndex CFReadStreamRead(CFReadStreamRef _Null_unspecified stream, UInt8 * _Null_unspecified buffer, CFIndex bufferLength);
extern
const UInt8 * _Null_unspecified CFReadStreamGetBuffer(CFReadStreamRef _Null_unspecified stream, CFIndex maxBytesToRead, CFIndex * _Null_unspecified numBytesRead);



extern
Boolean CFWriteStreamCanAcceptBytes(CFWriteStreamRef _Null_unspecified stream);






extern
CFIndex CFWriteStreamWrite(CFWriteStreamRef _Null_unspecified stream, const UInt8 * _Null_unspecified buffer, CFIndex bufferLength);
extern
CFTypeRef _Null_unspecified CFReadStreamCopyProperty(CFReadStreamRef _Null_unspecified stream, CFStreamPropertyKey _Null_unspecified propertyName);
extern
CFTypeRef _Null_unspecified CFWriteStreamCopyProperty(CFWriteStreamRef _Null_unspecified stream, CFStreamPropertyKey _Null_unspecified propertyName);



extern
Boolean CFReadStreamSetProperty(CFReadStreamRef _Null_unspecified stream, CFStreamPropertyKey _Null_unspecified propertyName, CFTypeRef _Null_unspecified propertyValue);
extern
Boolean CFWriteStreamSetProperty(CFWriteStreamRef _Null_unspecified stream, CFStreamPropertyKey _Null_unspecified propertyName, CFTypeRef _Null_unspecified propertyValue);
extern
Boolean CFReadStreamSetClient(CFReadStreamRef _Null_unspecified stream, CFOptionFlags streamEvents, CFReadStreamClientCallBack _Null_unspecified clientCB, CFStreamClientContext * _Null_unspecified clientContext);
extern
Boolean CFWriteStreamSetClient(CFWriteStreamRef _Null_unspecified stream, CFOptionFlags streamEvents, CFWriteStreamClientCallBack _Null_unspecified clientCB, CFStreamClientContext * _Null_unspecified clientContext);

extern
void CFReadStreamScheduleWithRunLoop(CFReadStreamRef _Null_unspecified stream, CFRunLoopRef _Null_unspecified runLoop, CFRunLoopMode _Null_unspecified runLoopMode);
extern
void CFWriteStreamScheduleWithRunLoop(CFWriteStreamRef _Null_unspecified stream, CFRunLoopRef _Null_unspecified runLoop, _Null_unspecified CFRunLoopMode runLoopMode);

extern
void CFReadStreamUnscheduleFromRunLoop(CFReadStreamRef _Null_unspecified stream, CFRunLoopRef _Null_unspecified runLoop, CFRunLoopMode _Null_unspecified runLoopMode);
extern
void CFWriteStreamUnscheduleFromRunLoop(CFWriteStreamRef _Null_unspecified stream, CFRunLoopRef _Null_unspecified runLoop, CFRunLoopMode _Null_unspecified runLoopMode);
extern
void CFReadStreamSetDispatchQueue(CFReadStreamRef _Null_unspecified stream, dispatch_queue_t _Null_unspecified q) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
void CFWriteStreamSetDispatchQueue(CFWriteStreamRef _Null_unspecified stream, dispatch_queue_t _Null_unspecified q) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));






extern
dispatch_queue_t _Null_unspecified CFReadStreamCopyDispatchQueue(CFReadStreamRef _Null_unspecified stream) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
dispatch_queue_t _Null_unspecified CFWriteStreamCopyDispatchQueue(CFWriteStreamRef _Null_unspecified stream) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



typedef CFIndex CFStreamErrorDomain; enum {
    kCFStreamErrorDomainCustom = -1L,
    kCFStreamErrorDomainPOSIX = 1,
    kCFStreamErrorDomainMacOSStatus
};

extern
CFStreamError CFReadStreamGetError(CFReadStreamRef _Null_unspecified stream);
extern
CFStreamError CFWriteStreamGetError(CFWriteStreamRef _Null_unspecified stream);


}


extern "C" {

typedef CFOptionFlags CFPropertyListMutabilityOptions; enum {
    kCFPropertyListImmutable = 0,
    kCFPropertyListMutableContainers = 1 << 0,
    kCFPropertyListMutableContainersAndLeaves = 1 << 1,
};
extern
CFPropertyListRef CFPropertyListCreateFromXMLData(CFAllocatorRef allocator, CFDataRef xmlData, CFOptionFlags mutabilityOption, CFStringRef *errorString) __attribute__((availability(macos,introduced=10.0,deprecated=10.10,message="Use CFPropertyListCreateWithData instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFPropertyListCreateWithData instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFPropertyListCreateWithData instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFPropertyListCreateWithData instead.")));
extern
CFDataRef CFPropertyListCreateXMLData(CFAllocatorRef allocator, CFPropertyListRef propertyList) __attribute__((availability(macos,introduced=10.0,deprecated=10.10,message="Use CFPropertyListCreateData instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFPropertyListCreateData instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFPropertyListCreateData instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFPropertyListCreateData instead.")));
extern
CFPropertyListRef CFPropertyListCreateDeepCopy(CFAllocatorRef allocator, CFPropertyListRef propertyList, CFOptionFlags mutabilityOption);

typedef CFIndex CFPropertyListFormat; enum {
    kCFPropertyListOpenStepFormat = 1,
    kCFPropertyListXMLFormat_v1_0 = 100,
    kCFPropertyListBinaryFormat_v1_0 = 200
};






extern
Boolean CFPropertyListIsValid(CFPropertyListRef plist, CFPropertyListFormat format);
extern
CFIndex CFPropertyListWriteToStream(CFPropertyListRef propertyList, CFWriteStreamRef stream, CFPropertyListFormat format, CFStringRef *errorString) __attribute__((availability(macos,introduced=10.2,deprecated=10.10,message="Use CFPropertyListWrite instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFPropertyListWrite instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFPropertyListWrite instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFPropertyListWrite instead.")));
extern
CFPropertyListRef CFPropertyListCreateFromStream(CFAllocatorRef allocator, CFReadStreamRef stream, CFIndex streamLength, CFOptionFlags mutabilityOption, CFPropertyListFormat *format, CFStringRef *errorString) __attribute__((availability(macos,introduced=10.2,deprecated=10.10,message="Use CFPropertyListCreateWithStream instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message="Use CFPropertyListCreateWithStream instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFPropertyListCreateWithStream instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFPropertyListCreateWithStream instead.")));





enum {
    kCFPropertyListReadCorruptError = 3840,
    kCFPropertyListReadUnknownVersionError = 3841,
    kCFPropertyListReadStreamError = 3842,
    kCFPropertyListWriteStreamError = 3851,
} __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFPropertyListRef CFPropertyListCreateWithData(CFAllocatorRef allocator, CFDataRef data, CFOptionFlags options, CFPropertyListFormat *format, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFPropertyListRef CFPropertyListCreateWithStream(CFAllocatorRef allocator, CFReadStreamRef stream, CFIndex streamLength, CFOptionFlags options, CFPropertyListFormat *format, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFIndex CFPropertyListWrite(CFPropertyListRef propertyList, CFWriteStreamRef stream, CFPropertyListFormat format, CFOptionFlags options, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



extern
CFDataRef CFPropertyListCreateData(CFAllocatorRef allocator, CFPropertyListRef propertyList, CFPropertyListFormat format, CFOptionFlags options, CFErrorRef *error) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



}
extern "C" {
typedef const void * (*CFSetRetainCallBack)(CFAllocatorRef allocator, const void *value);







typedef void (*CFSetReleaseCallBack)(CFAllocatorRef allocator, const void *value);







typedef CFStringRef (*CFSetCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFSetEqualCallBack)(const void *value1, const void *value2);







typedef CFHashCode (*CFSetHashCallBack)(const void *value);
typedef struct {
    CFIndex version;
    CFSetRetainCallBack retain;
    CFSetReleaseCallBack release;
    CFSetCopyDescriptionCallBack copyDescription;
    CFSetEqualCallBack equal;
    CFSetHashCallBack hash;
} CFSetCallBacks;






extern
const CFSetCallBacks kCFTypeSetCallBacks;







extern
const CFSetCallBacks kCFCopyStringSetCallBacks;
typedef void (*CFSetApplierFunction)(const void *value, void *context);





typedef const struct __attribute__((objc_bridge(NSSet))) __CFSet * CFSetRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableSet))) __CFSet * CFMutableSetRef;





extern
CFTypeID CFSetGetTypeID(void);
extern
CFSetRef CFSetCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFSetCallBacks *callBacks);
extern
CFSetRef CFSetCreateCopy(CFAllocatorRef allocator, CFSetRef theSet);
extern
CFMutableSetRef CFSetCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFSetCallBacks *callBacks);
extern
CFMutableSetRef CFSetCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFSetRef theSet);
extern
CFIndex CFSetGetCount(CFSetRef theSet);
extern
CFIndex CFSetGetCountOfValue(CFSetRef theSet, const void *value);
extern
Boolean CFSetContainsValue(CFSetRef theSet, const void *value);
extern
const void *CFSetGetValue(CFSetRef theSet, const void *value);
extern
Boolean CFSetGetValueIfPresent(CFSetRef theSet, const void *candidate, const void **value);
extern
void CFSetGetValues(CFSetRef theSet, const void **values);
extern
void CFSetApplyFunction(CFSetRef theSet, CFSetApplierFunction __attribute__((noescape)) applier, void *context);
extern
void CFSetAddValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetReplaceValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetSetValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetRemoveValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetRemoveAllValues(CFMutableSetRef theSet);

}

extern "C" {

typedef CFIndex CFStringEncodings; enum {

    kCFStringEncodingMacJapanese = 1,
    kCFStringEncodingMacChineseTrad = 2,
    kCFStringEncodingMacKorean = 3,
    kCFStringEncodingMacArabic = 4,
    kCFStringEncodingMacHebrew = 5,
    kCFStringEncodingMacGreek = 6,
    kCFStringEncodingMacCyrillic = 7,
    kCFStringEncodingMacDevanagari = 9,
    kCFStringEncodingMacGurmukhi = 10,
    kCFStringEncodingMacGujarati = 11,
    kCFStringEncodingMacOriya = 12,
    kCFStringEncodingMacBengali = 13,
    kCFStringEncodingMacTamil = 14,
    kCFStringEncodingMacTelugu = 15,
    kCFStringEncodingMacKannada = 16,
    kCFStringEncodingMacMalayalam = 17,
    kCFStringEncodingMacSinhalese = 18,
    kCFStringEncodingMacBurmese = 19,
    kCFStringEncodingMacKhmer = 20,
    kCFStringEncodingMacThai = 21,
    kCFStringEncodingMacLaotian = 22,
    kCFStringEncodingMacGeorgian = 23,
    kCFStringEncodingMacArmenian = 24,
    kCFStringEncodingMacChineseSimp = 25,
    kCFStringEncodingMacTibetan = 26,
    kCFStringEncodingMacMongolian = 27,
    kCFStringEncodingMacEthiopic = 28,
    kCFStringEncodingMacCentralEurRoman = 29,
    kCFStringEncodingMacVietnamese = 30,
    kCFStringEncodingMacExtArabic = 31,

    kCFStringEncodingMacSymbol = 33,
    kCFStringEncodingMacDingbats = 34,
    kCFStringEncodingMacTurkish = 35,
    kCFStringEncodingMacCroatian = 36,
    kCFStringEncodingMacIcelandic = 37,
    kCFStringEncodingMacRomanian = 38,
    kCFStringEncodingMacCeltic = 39,
    kCFStringEncodingMacGaelic = 40,

    kCFStringEncodingMacFarsi = 0x8C,

    kCFStringEncodingMacUkrainian = 0x98,

    kCFStringEncodingMacInuit = 0xEC,
    kCFStringEncodingMacVT100 = 0xFC,

    kCFStringEncodingMacHFS = 0xFF,






    kCFStringEncodingISOLatin2 = 0x0202,
    kCFStringEncodingISOLatin3 = 0x0203,
    kCFStringEncodingISOLatin4 = 0x0204,
    kCFStringEncodingISOLatinCyrillic = 0x0205,
    kCFStringEncodingISOLatinArabic = 0x0206,
    kCFStringEncodingISOLatinGreek = 0x0207,
    kCFStringEncodingISOLatinHebrew = 0x0208,
    kCFStringEncodingISOLatin5 = 0x0209,
    kCFStringEncodingISOLatin6 = 0x020A,
    kCFStringEncodingISOLatinThai = 0x020B,
    kCFStringEncodingISOLatin7 = 0x020D,
    kCFStringEncodingISOLatin8 = 0x020E,
    kCFStringEncodingISOLatin9 = 0x020F,
    kCFStringEncodingISOLatin10 = 0x0210,


    kCFStringEncodingDOSLatinUS = 0x0400,
    kCFStringEncodingDOSGreek = 0x0405,
    kCFStringEncodingDOSBalticRim = 0x0406,
    kCFStringEncodingDOSLatin1 = 0x0410,
    kCFStringEncodingDOSGreek1 = 0x0411,
    kCFStringEncodingDOSLatin2 = 0x0412,
    kCFStringEncodingDOSCyrillic = 0x0413,
    kCFStringEncodingDOSTurkish = 0x0414,
    kCFStringEncodingDOSPortuguese = 0x0415,
    kCFStringEncodingDOSIcelandic = 0x0416,
    kCFStringEncodingDOSHebrew = 0x0417,
    kCFStringEncodingDOSCanadianFrench = 0x0418,
    kCFStringEncodingDOSArabic = 0x0419,
    kCFStringEncodingDOSNordic = 0x041A,
    kCFStringEncodingDOSRussian = 0x041B,
    kCFStringEncodingDOSGreek2 = 0x041C,
    kCFStringEncodingDOSThai = 0x041D,
    kCFStringEncodingDOSJapanese = 0x0420,
    kCFStringEncodingDOSChineseSimplif = 0x0421,
    kCFStringEncodingDOSKorean = 0x0422,
    kCFStringEncodingDOSChineseTrad = 0x0423,

    kCFStringEncodingWindowsLatin2 = 0x0501,
    kCFStringEncodingWindowsCyrillic = 0x0502,
    kCFStringEncodingWindowsGreek = 0x0503,
    kCFStringEncodingWindowsLatin5 = 0x0504,
    kCFStringEncodingWindowsHebrew = 0x0505,
    kCFStringEncodingWindowsArabic = 0x0506,
    kCFStringEncodingWindowsBalticRim = 0x0507,
    kCFStringEncodingWindowsVietnamese = 0x0508,
    kCFStringEncodingWindowsKoreanJohab = 0x0510,



    kCFStringEncodingANSEL = 0x0601,
    kCFStringEncodingJIS_X0201_76 = 0x0620,
    kCFStringEncodingJIS_X0208_83 = 0x0621,
    kCFStringEncodingJIS_X0208_90 = 0x0622,
    kCFStringEncodingJIS_X0212_90 = 0x0623,
    kCFStringEncodingJIS_C6226_78 = 0x0624,
    kCFStringEncodingShiftJIS_X0213 __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 0x0628,
    kCFStringEncodingShiftJIS_X0213_MenKuTen = 0x0629,
    kCFStringEncodingGB_2312_80 = 0x0630,
    kCFStringEncodingGBK_95 = 0x0631,
    kCFStringEncodingGB_18030_2000 = 0x0632,
    kCFStringEncodingKSC_5601_87 = 0x0640,
    kCFStringEncodingKSC_5601_92_Johab = 0x0641,
    kCFStringEncodingCNS_11643_92_P1 = 0x0651,
    kCFStringEncodingCNS_11643_92_P2 = 0x0652,
    kCFStringEncodingCNS_11643_92_P3 = 0x0653,


    kCFStringEncodingISO_2022_JP = 0x0820,
    kCFStringEncodingISO_2022_JP_2 = 0x0821,
    kCFStringEncodingISO_2022_JP_1 = 0x0822,
    kCFStringEncodingISO_2022_JP_3 = 0x0823,
    kCFStringEncodingISO_2022_CN = 0x0830,
    kCFStringEncodingISO_2022_CN_EXT = 0x0831,
    kCFStringEncodingISO_2022_KR = 0x0840,


    kCFStringEncodingEUC_JP = 0x0920,
    kCFStringEncodingEUC_CN = 0x0930,
    kCFStringEncodingEUC_TW = 0x0931,
    kCFStringEncodingEUC_KR = 0x0940,


    kCFStringEncodingShiftJIS = 0x0A01,
    kCFStringEncodingKOI8_R = 0x0A02,
    kCFStringEncodingBig5 = 0x0A03,
    kCFStringEncodingMacRomanLatin1 = 0x0A04,
    kCFStringEncodingHZ_GB_2312 = 0x0A05,
    kCFStringEncodingBig5_HKSCS_1999 = 0x0A06,
    kCFStringEncodingVISCII = 0x0A07,
    kCFStringEncodingKOI8_U = 0x0A08,
    kCFStringEncodingBig5_E = 0x0A09,



    kCFStringEncodingNextStepJapanese = 0x0B02,


    kCFStringEncodingEBCDIC_US = 0x0C01,
    kCFStringEncodingEBCDIC_CP037 = 0x0C02,

    kCFStringEncodingUTF7 __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 0x04000100,
    kCFStringEncodingUTF7_IMAP __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) = 0x0A10,


    kCFStringEncodingShiftJIS_X0213_00 = 0x0628
};

}

extern "C" {
typedef const void * (*CFTreeRetainCallBack)(const void *info);







typedef void (*CFTreeReleaseCallBack)(const void *info);
typedef CFStringRef (*CFTreeCopyDescriptionCallBack)(const void *info);
typedef struct {
    CFIndex version;
    void * info;
    CFTreeRetainCallBack retain;
    CFTreeReleaseCallBack release;
    CFTreeCopyDescriptionCallBack copyDescription;
} CFTreeContext;
typedef void (*CFTreeApplierFunction)(const void *value, void *context);





typedef struct __attribute__((objc_bridge_mutable(id))) __CFTree * CFTreeRef;





extern
CFTypeID CFTreeGetTypeID(void);
extern
CFTreeRef CFTreeCreate(CFAllocatorRef allocator, const CFTreeContext *context);
extern
CFTreeRef CFTreeGetParent(CFTreeRef tree);
extern
CFTreeRef CFTreeGetNextSibling(CFTreeRef tree);
extern
CFTreeRef CFTreeGetFirstChild(CFTreeRef tree);
extern
void CFTreeGetContext(CFTreeRef tree, CFTreeContext *context);
extern
CFIndex CFTreeGetChildCount(CFTreeRef tree);
extern
CFTreeRef CFTreeGetChildAtIndex(CFTreeRef tree, CFIndex idx);
extern
void CFTreeGetChildren(CFTreeRef tree, CFTreeRef *children);
extern
void CFTreeApplyFunctionToChildren(CFTreeRef tree, CFTreeApplierFunction __attribute__((noescape)) applier, void *context);
extern
CFTreeRef CFTreeFindRoot(CFTreeRef tree);
extern
void CFTreeSetContext(CFTreeRef tree, const CFTreeContext *context);
extern
void CFTreePrependChild(CFTreeRef tree, CFTreeRef newChild);
extern
void CFTreeAppendChild(CFTreeRef tree, CFTreeRef newChild);
extern
void CFTreeInsertSibling(CFTreeRef tree, CFTreeRef newSibling);







extern
void CFTreeRemove(CFTreeRef tree);







extern
void CFTreeRemoveAllChildren(CFTreeRef tree);
extern
void CFTreeSortChildren(CFTreeRef tree, CFComparatorFunction comparator, void *context);

}

extern "C" {
extern
Boolean CFURLCreateDataAndPropertiesFromResource(CFAllocatorRef alloc, CFURLRef url, CFDataRef *resourceData, CFDictionaryRef *properties, CFArrayRef desiredProperties, SInt32 *errorCode) __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="For resource data, use the CFReadStream API. For file resource properties, use CFURLCopyResourcePropertiesForKeys."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="For resource data, use the CFReadStream API. For file resource properties, use CFURLCopyResourcePropertiesForKeys."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="For resource data, use the CFReadStream API. For file resource properties, use CFURLCopyResourcePropertiesForKeys."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="For resource data, use the CFReadStream API. For file resource properties, use CFURLCopyResourcePropertiesForKeys.")));
extern
Boolean CFURLWriteDataAndPropertiesToResource(CFURLRef url, CFDataRef dataToWrite, CFDictionaryRef propertiesToWrite, SInt32 *errorCode) __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="For resource data, use the CFWriteStream API. For file resource properties, use CFURLSetResourcePropertiesForKeys."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="For resource data, use the CFWriteStream API. For file resource properties, use CFURLSetResourcePropertiesForKeys."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="For resource data, use the CFWriteStream API. For file resource properties, use CFURLSetResourcePropertiesForKeys."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="For resource data, use the CFWriteStream API. For file resource properties, use CFURLSetResourcePropertiesForKeys.")));





extern
Boolean CFURLDestroyResource(CFURLRef url, SInt32 *errorCode) __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use CFURLGetFileSystemRepresentation and removefile(3) instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use CFURLGetFileSystemRepresentation and removefile(3) instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFURLGetFileSystemRepresentation and removefile(3) instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFURLGetFileSystemRepresentation and removefile(3) instead.")));





extern
CFTypeRef CFURLCreatePropertyFromResource(CFAllocatorRef alloc, CFURLRef url, CFStringRef property, SInt32 *errorCode) __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="For file resource properties, use CFURLCopyResourcePropertyForKey."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="For file resource properties, use CFURLCopyResourcePropertyForKey."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="For file resource properties, use CFURLCopyResourcePropertyForKey."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="For file resource properties, use CFURLCopyResourcePropertyForKey.")));



typedef CFIndex CFURLError; enum {
    kCFURLUnknownError = -10L,
    kCFURLUnknownSchemeError = -11L,
    kCFURLResourceNotFoundError = -12L,
    kCFURLResourceAccessViolationError = -13L,
    kCFURLRemoteHostUnavailableError = -14L,
    kCFURLImproperArgumentsError = -15L,
    kCFURLUnknownPropertyKeyError = -16L,
    kCFURLPropertyKeyUnavailableError = -17L,
    kCFURLTimeoutError = -18L
} __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use CFError codes instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use CFError codes instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFError codes instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFError codes instead")));



extern
const CFStringRef kCFURLFileExists __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use CFURLResourceIsReachable instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use CFURLResourceIsReachable instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFURLResourceIsReachable instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFURLResourceIsReachable instead.")));
extern
const CFStringRef kCFURLFileDirectoryContents __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use the CFURLEnumerator API instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use the CFURLEnumerator API instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use the CFURLEnumerator API instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use the CFURLEnumerator API instead.")));
extern
const CFStringRef kCFURLFileLength __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSizeKey instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSizeKey instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSizeKey instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSizeKey instead.")));
extern
const CFStringRef kCFURLFileLastModificationTime __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use CFURLCopyResourcePropertyForKey with kCFURLContentModificationDateKey instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLContentModificationDateKey instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLContentModificationDateKey instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLContentModificationDateKey instead.")));
extern
const CFStringRef kCFURLFilePOSIXMode __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead.")));
extern
const CFStringRef kCFURLFileOwnerID __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead.")));
extern
const CFStringRef kCFURLHTTPStatusCode __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use NSHTTPURLResponse methods instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use NSHTTPURLResponse methods instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use NSHTTPURLResponse methods instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use NSHTTPURLResponse methods instead.")));
extern
const CFStringRef kCFURLHTTPStatusLine __attribute__((availability(macos,introduced=10.0,deprecated=10.9,message="Use NSHTTPURLResponse methods instead."))) __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message="Use NSHTTPURLResponse methods instead."))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use NSHTTPURLResponse methods instead."))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use NSHTTPURLResponse methods instead.")));
}
extern "C" {

typedef const struct __attribute__((objc_bridge(id))) __CFUUID * CFUUIDRef;

typedef struct {
    UInt8 byte0;
    UInt8 byte1;
    UInt8 byte2;
    UInt8 byte3;
    UInt8 byte4;
    UInt8 byte5;
    UInt8 byte6;
    UInt8 byte7;
    UInt8 byte8;
    UInt8 byte9;
    UInt8 byte10;
    UInt8 byte11;
    UInt8 byte12;
    UInt8 byte13;
    UInt8 byte14;
    UInt8 byte15;
} CFUUIDBytes;






extern
CFTypeID CFUUIDGetTypeID(void);

extern
CFUUIDRef CFUUIDCreate(CFAllocatorRef alloc);


extern
CFUUIDRef CFUUIDCreateWithBytes(CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1, UInt8 byte2, UInt8 byte3, UInt8 byte4, UInt8 byte5, UInt8 byte6, UInt8 byte7, UInt8 byte8, UInt8 byte9, UInt8 byte10, UInt8 byte11, UInt8 byte12, UInt8 byte13, UInt8 byte14, UInt8 byte15);


extern
CFUUIDRef CFUUIDCreateFromString(CFAllocatorRef alloc, CFStringRef uuidStr);


extern
CFStringRef CFUUIDCreateString(CFAllocatorRef alloc, CFUUIDRef uuid);


extern
CFUUIDRef CFUUIDGetConstantUUIDWithBytes(CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1, UInt8 byte2, UInt8 byte3, UInt8 byte4, UInt8 byte5, UInt8 byte6, UInt8 byte7, UInt8 byte8, UInt8 byte9, UInt8 byte10, UInt8 byte11, UInt8 byte12, UInt8 byte13, UInt8 byte14, UInt8 byte15);


extern
CFUUIDBytes CFUUIDGetUUIDBytes(CFUUIDRef uuid);

extern
CFUUIDRef CFUUIDCreateFromUUIDBytes(CFAllocatorRef alloc, CFUUIDBytes bytes);

}
extern "C" {

extern
CFURLRef CFCopyHomeDirectoryURL(void) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0))) __attribute__((availability(macos,unavailable)));

}
typedef integer_t cpu_type_t;
typedef integer_t cpu_subtype_t;
typedef integer_t cpu_threadtype_t;



extern "C" {

typedef struct __attribute__((objc_bridge(id))) __CFBundle *CFBundleRef;
typedef struct __attribute__((objc_bridge(id))) __CFBundle *CFPlugInRef;


extern
const CFStringRef kCFBundleInfoDictionaryVersionKey;

extern
const CFStringRef kCFBundleExecutableKey;

extern
const CFStringRef kCFBundleIdentifierKey;

extern
const CFStringRef kCFBundleVersionKey;



extern
const CFStringRef kCFBundleDevelopmentRegionKey;

extern
const CFStringRef kCFBundleNameKey;

extern
const CFStringRef kCFBundleLocalizationsKey;




extern
CFBundleRef CFBundleGetMainBundle(void);

extern
CFBundleRef CFBundleGetBundleWithIdentifier(CFStringRef bundleID);







extern
CFArrayRef CFBundleGetAllBundles(void);





extern
CFTypeID CFBundleGetTypeID(void);

extern
CFBundleRef CFBundleCreate(CFAllocatorRef allocator, CFURLRef bundleURL);


extern
CFArrayRef CFBundleCreateBundlesFromDirectory(CFAllocatorRef allocator, CFURLRef directoryURL, CFStringRef bundleType);





extern
CFURLRef CFBundleCopyBundleURL(CFBundleRef bundle);

extern
CFTypeRef CFBundleGetValueForInfoDictionaryKey(CFBundleRef bundle, CFStringRef key);



extern
CFDictionaryRef CFBundleGetInfoDictionary(CFBundleRef bundle);



extern
CFDictionaryRef CFBundleGetLocalInfoDictionary(CFBundleRef bundle);


extern
void CFBundleGetPackageInfo(CFBundleRef bundle, UInt32 *packageType, UInt32 *packageCreator);

extern
CFStringRef CFBundleGetIdentifier(CFBundleRef bundle);

extern
UInt32 CFBundleGetVersionNumber(CFBundleRef bundle);

extern
CFStringRef CFBundleGetDevelopmentRegion(CFBundleRef bundle);

extern
CFURLRef CFBundleCopySupportFilesDirectoryURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopyResourcesDirectoryURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopyPrivateFrameworksURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopySharedFrameworksURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopySharedSupportURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopyBuiltInPlugInsURL(CFBundleRef bundle);






extern
CFDictionaryRef CFBundleCopyInfoDictionaryInDirectory(CFURLRef bundleURL);

extern
Boolean CFBundleGetPackageInfoInDirectory(CFURLRef url, UInt32 *packageType, UInt32 *packageCreator);



extern
CFURLRef CFBundleCopyResourceURL(CFBundleRef bundle, CFStringRef resourceName, CFStringRef resourceType, CFStringRef subDirName);

extern
CFArrayRef CFBundleCopyResourceURLsOfType(CFBundleRef bundle, CFStringRef resourceType, CFStringRef subDirName);

extern
CFStringRef CFBundleCopyLocalizedString(CFBundleRef bundle, CFStringRef key, CFStringRef value, CFStringRef tableName) __attribute__((format_arg(2)));
extern
CFURLRef CFBundleCopyResourceURLInDirectory(CFURLRef bundleURL, CFStringRef resourceName, CFStringRef resourceType, CFStringRef subDirName);

extern
CFArrayRef CFBundleCopyResourceURLsOfTypeInDirectory(CFURLRef bundleURL, CFStringRef resourceType, CFStringRef subDirName);






extern
CFArrayRef CFBundleCopyBundleLocalizations(CFBundleRef bundle);


extern
CFArrayRef CFBundleCopyPreferredLocalizationsFromArray(CFArrayRef locArray);






extern
CFArrayRef CFBundleCopyLocalizationsForPreferences(CFArrayRef locArray, CFArrayRef prefArray);
extern
CFURLRef CFBundleCopyResourceURLForLocalization(CFBundleRef bundle, CFStringRef resourceName, CFStringRef resourceType, CFStringRef subDirName, CFStringRef localizationName);

extern
CFArrayRef CFBundleCopyResourceURLsOfTypeForLocalization(CFBundleRef bundle, CFStringRef resourceType, CFStringRef subDirName, CFStringRef localizationName);
extern
CFDictionaryRef CFBundleCopyInfoDictionaryForURL(CFURLRef url);




extern
CFArrayRef CFBundleCopyLocalizationsForURL(CFURLRef url);





extern
CFArrayRef CFBundleCopyExecutableArchitecturesForURL(CFURLRef url) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFURLRef CFBundleCopyExecutableURL(CFBundleRef bundle);

enum {
    kCFBundleExecutableArchitectureI386 = 0x00000007,
    kCFBundleExecutableArchitecturePPC = 0x00000012,
    kCFBundleExecutableArchitectureX86_64 = 0x01000007,
    kCFBundleExecutableArchitecturePPC64 = 0x01000012,
    kCFBundleExecutableArchitectureARM64 __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0))) __attribute__((availability(tvos,introduced=14.0))) = 0x0100000c,
} __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern
CFArrayRef CFBundleCopyExecutableArchitectures(CFBundleRef bundle) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));





extern
Boolean CFBundlePreflightExecutable(CFBundleRef bundle, CFErrorRef *error) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));






extern
Boolean CFBundleLoadExecutableAndReturnError(CFBundleRef bundle, CFErrorRef *error) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));





extern
Boolean CFBundleLoadExecutable(CFBundleRef bundle);

extern
Boolean CFBundleIsExecutableLoaded(CFBundleRef bundle);

extern
void CFBundleUnloadExecutable(CFBundleRef bundle);

extern
void *CFBundleGetFunctionPointerForName(CFBundleRef bundle, CFStringRef functionName);

extern
void CFBundleGetFunctionPointersForNames(CFBundleRef bundle, CFArrayRef functionNames, void *ftbl[]);

extern
void *CFBundleGetDataPointerForName(CFBundleRef bundle, CFStringRef symbolName);

extern
void CFBundleGetDataPointersForNames(CFBundleRef bundle, CFArrayRef symbolNames, void *stbl[]);

extern
CFURLRef CFBundleCopyAuxiliaryExecutableURL(CFBundleRef bundle, CFStringRef executableName);
extern
Boolean CFBundleIsExecutableLoadable(CFBundleRef bundle) __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
Boolean CFBundleIsExecutableLoadableForURL(CFURLRef url) __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
Boolean CFBundleIsArchitectureLoadable(cpu_type_t arch) __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));




extern
CFPlugInRef CFBundleGetPlugIn(CFBundleRef bundle);




typedef int CFBundleRefNum;




extern
CFBundleRefNum CFBundleOpenBundleResourceMap(CFBundleRef bundle) __attribute__((availability(macosx,introduced=10.0,deprecated=10.15,message="The Carbon Resource Manager is deprecated. This should only be used to access Resource Manager-style resources in old bundles."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));






extern
SInt32 CFBundleOpenBundleResourceFiles(CFBundleRef bundle, CFBundleRefNum *refNum, CFBundleRefNum *localizedRefNum) __attribute__((availability(macosx,introduced=10.0,deprecated=10.15,message="The Carbon Resource Manager is deprecated. This should only be used to access Resource Manager-style resources in old bundles."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));



extern
void CFBundleCloseBundleResourceMap(CFBundleRef bundle, CFBundleRefNum refNum) __attribute__((availability(macosx,introduced=10.0,deprecated=10.15,message="The Carbon Resource Manager is deprecated. This should only be used to access Resource Manager-style resources in old bundles."))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

}


extern "C" {

typedef struct __attribute__((objc_bridge_mutable(NSMessagePort))) __CFMessagePort * CFMessagePortRef;

enum {
    kCFMessagePortSuccess = 0,
    kCFMessagePortSendTimeout = -1,
    kCFMessagePortReceiveTimeout = -2,
    kCFMessagePortIsInvalid = -3,
    kCFMessagePortTransportError = -4,
    kCFMessagePortBecameInvalidError = -5
};

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFMessagePortContext;

typedef CFDataRef (*CFMessagePortCallBack)(CFMessagePortRef local, SInt32 msgid, CFDataRef data, void *info);

typedef void (*CFMessagePortInvalidationCallBack)(CFMessagePortRef ms, void *info);

extern CFTypeID CFMessagePortGetTypeID(void);

extern CFMessagePortRef CFMessagePortCreateLocal(CFAllocatorRef allocator, CFStringRef name, CFMessagePortCallBack callout, CFMessagePortContext *context, Boolean *shouldFreeInfo);
extern CFMessagePortRef CFMessagePortCreateRemote(CFAllocatorRef allocator, CFStringRef name);

extern Boolean CFMessagePortIsRemote(CFMessagePortRef ms);
extern CFStringRef CFMessagePortGetName(CFMessagePortRef ms);
extern Boolean CFMessagePortSetName(CFMessagePortRef ms, CFStringRef newName);
extern void CFMessagePortGetContext(CFMessagePortRef ms, CFMessagePortContext *context);
extern void CFMessagePortInvalidate(CFMessagePortRef ms);
extern Boolean CFMessagePortIsValid(CFMessagePortRef ms);
extern CFMessagePortInvalidationCallBack CFMessagePortGetInvalidationCallBack(CFMessagePortRef ms);
extern void CFMessagePortSetInvalidationCallBack(CFMessagePortRef ms, CFMessagePortInvalidationCallBack callout);


extern SInt32 CFMessagePortSendRequest(CFMessagePortRef remote, SInt32 msgid, CFDataRef data, CFTimeInterval sendTimeout, CFTimeInterval rcvTimeout, CFStringRef replyMode, CFDataRef *returnData);

extern CFRunLoopSourceRef CFMessagePortCreateRunLoopSource(CFAllocatorRef allocator, CFMessagePortRef local, CFIndex order);

extern void CFMessagePortSetDispatchQueue(CFMessagePortRef ms, dispatch_queue_t queue) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

}
extern "C" {



extern const CFStringRef kCFPlugInDynamicRegistrationKey;
extern const CFStringRef kCFPlugInDynamicRegisterFunctionKey;
extern const CFStringRef kCFPlugInUnloadFunctionKey;
extern const CFStringRef kCFPlugInFactoriesKey;
extern const CFStringRef kCFPlugInTypesKey;




typedef void (*CFPlugInDynamicRegisterFunction)(CFPlugInRef plugIn);
typedef void (*CFPlugInUnloadFunction)(CFPlugInRef plugIn);
typedef void *(*CFPlugInFactoryFunction)(CFAllocatorRef allocator, CFUUIDRef typeUUID);



extern CFTypeID CFPlugInGetTypeID(void);

extern CFPlugInRef CFPlugInCreate(CFAllocatorRef allocator, CFURLRef plugInURL);


extern CFBundleRef CFPlugInGetBundle(CFPlugInRef plugIn);







extern void CFPlugInSetLoadOnDemand(CFPlugInRef plugIn, Boolean flag);

extern Boolean CFPlugInIsLoadOnDemand(CFPlugInRef plugIn);






extern CFArrayRef CFPlugInFindFactoriesForPlugInType(CFUUIDRef typeUUID) __attribute__((cf_returns_retained));



extern CFArrayRef CFPlugInFindFactoriesForPlugInTypeInPlugIn(CFUUIDRef typeUUID, CFPlugInRef plugIn) __attribute__((cf_returns_retained));


extern void *CFPlugInInstanceCreate(CFAllocatorRef allocator, CFUUIDRef factoryUUID, CFUUIDRef typeUUID);





extern Boolean CFPlugInRegisterFactoryFunction(CFUUIDRef factoryUUID, CFPlugInFactoryFunction func);

extern Boolean CFPlugInRegisterFactoryFunctionByName(CFUUIDRef factoryUUID, CFPlugInRef plugIn, CFStringRef functionName);

extern Boolean CFPlugInUnregisterFactory(CFUUIDRef factoryUUID);

extern Boolean CFPlugInRegisterPlugInType(CFUUIDRef factoryUUID, CFUUIDRef typeUUID);

extern Boolean CFPlugInUnregisterPlugInType(CFUUIDRef factoryUUID, CFUUIDRef typeUUID);





extern void CFPlugInAddInstanceForFactory(CFUUIDRef factoryID);

extern void CFPlugInRemoveInstanceForFactory(CFUUIDRef factoryID);




typedef struct __attribute__((objc_bridge(id))) __CFPlugInInstance *CFPlugInInstanceRef;

typedef Boolean (*CFPlugInInstanceGetInterfaceFunction)(CFPlugInInstanceRef instance, CFStringRef interfaceName, void **ftbl);
typedef void (*CFPlugInInstanceDeallocateInstanceDataFunction)(void *instanceData);

extern Boolean CFPlugInInstanceGetInterfaceFunctionTable(CFPlugInInstanceRef instance, CFStringRef interfaceName, void **ftbl);


extern CFStringRef CFPlugInInstanceGetFactoryName(CFPlugInInstanceRef instance) __attribute__((cf_returns_retained));

extern void *CFPlugInInstanceGetInstanceData(CFPlugInInstanceRef instance);

extern CFTypeID CFPlugInInstanceGetTypeID(void);

extern CFPlugInInstanceRef CFPlugInInstanceCreateWithInstanceDataSize(CFAllocatorRef allocator, CFIndex instanceDataSize, CFPlugInInstanceDeallocateInstanceDataFunction deallocateInstanceFunction, CFStringRef factoryName, CFPlugInInstanceGetInterfaceFunction getInterfaceFunction);

}



extern "C" {

typedef struct __attribute__((objc_bridge_mutable(NSMachPort))) __CFMachPort * CFMachPortRef;

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFMachPortContext;

typedef void (*CFMachPortCallBack)(CFMachPortRef port, void *msg, CFIndex size, void *info);
typedef void (*CFMachPortInvalidationCallBack)(CFMachPortRef port, void *info);

extern CFTypeID CFMachPortGetTypeID(void);

extern CFMachPortRef CFMachPortCreate(CFAllocatorRef allocator, CFMachPortCallBack callout, CFMachPortContext *context, Boolean *shouldFreeInfo);
extern CFMachPortRef CFMachPortCreateWithPort(CFAllocatorRef allocator, mach_port_t portNum, CFMachPortCallBack callout, CFMachPortContext *context, Boolean *shouldFreeInfo);

extern mach_port_t CFMachPortGetPort(CFMachPortRef port);
extern void CFMachPortGetContext(CFMachPortRef port, CFMachPortContext *context);
extern void CFMachPortInvalidate(CFMachPortRef port);
extern Boolean CFMachPortIsValid(CFMachPortRef port);
extern CFMachPortInvalidationCallBack CFMachPortGetInvalidationCallBack(CFMachPortRef port);
extern void CFMachPortSetInvalidationCallBack(CFMachPortRef port, CFMachPortInvalidationCallBack callout);

extern CFRunLoopSourceRef CFMachPortCreateRunLoopSource(CFAllocatorRef allocator, CFMachPortRef port, CFIndex order);

}

extern "C" {




typedef const struct __attribute__((objc_bridge(NSAttributedString))) __CFAttributedString *CFAttributedStringRef;
typedef struct __attribute__((objc_bridge_mutable(NSMutableAttributedString))) __CFAttributedString *CFMutableAttributedStringRef;




extern CFTypeID CFAttributedStringGetTypeID(void);
extern CFAttributedStringRef CFAttributedStringCreate(CFAllocatorRef alloc, CFStringRef str, CFDictionaryRef attributes);




extern CFAttributedStringRef CFAttributedStringCreateWithSubstring(CFAllocatorRef alloc, CFAttributedStringRef aStr, CFRange range);




extern CFAttributedStringRef CFAttributedStringCreateCopy(CFAllocatorRef alloc, CFAttributedStringRef aStr);




extern CFStringRef CFAttributedStringGetString(CFAttributedStringRef aStr);




extern CFIndex CFAttributedStringGetLength(CFAttributedStringRef aStr);






extern CFDictionaryRef CFAttributedStringGetAttributes(CFAttributedStringRef aStr, CFIndex loc, CFRange *effectiveRange);




extern CFTypeRef CFAttributedStringGetAttribute(CFAttributedStringRef aStr, CFIndex loc, CFStringRef attrName, CFRange *effectiveRange);




extern CFDictionaryRef CFAttributedStringGetAttributesAndLongestEffectiveRange(CFAttributedStringRef aStr, CFIndex loc, CFRange inRange, CFRange *longestEffectiveRange);




extern CFTypeRef CFAttributedStringGetAttributeAndLongestEffectiveRange(CFAttributedStringRef aStr, CFIndex loc, CFStringRef attrName, CFRange inRange, CFRange *longestEffectiveRange);
extern CFMutableAttributedStringRef CFAttributedStringCreateMutableCopy(CFAllocatorRef alloc, CFIndex maxLength, CFAttributedStringRef aStr);




extern CFMutableAttributedStringRef CFAttributedStringCreateMutable(CFAllocatorRef alloc, CFIndex maxLength);






extern void CFAttributedStringReplaceString(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef replacement);






extern CFMutableStringRef CFAttributedStringGetMutableString(CFMutableAttributedStringRef aStr);




extern void CFAttributedStringSetAttributes(CFMutableAttributedStringRef aStr, CFRange range, CFDictionaryRef replacement, Boolean clearOtherAttributes);




extern void CFAttributedStringSetAttribute(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef attrName, CFTypeRef value);




extern void CFAttributedStringRemoveAttribute(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef attrName);




extern void CFAttributedStringReplaceAttributedString(CFMutableAttributedStringRef aStr, CFRange range, CFAttributedStringRef replacement);




extern void CFAttributedStringBeginEditing(CFMutableAttributedStringRef aStr);




extern void CFAttributedStringEndEditing(CFMutableAttributedStringRef aStr);


}


extern "C" {


typedef const struct __attribute__((objc_bridge_mutable(id))) __CFURLEnumerator *CFURLEnumeratorRef;


extern
CFTypeID CFURLEnumeratorGetTypeID( void ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



typedef CFOptionFlags CFURLEnumeratorOptions; enum {
    kCFURLEnumeratorDefaultBehavior = 0,
    kCFURLEnumeratorDescendRecursively = 1UL << 0,
    kCFURLEnumeratorSkipInvisibles = 1UL << 1,
    kCFURLEnumeratorGenerateFileReferenceURLs = 1UL << 2,
    kCFURLEnumeratorSkipPackageContents = 1UL << 3,
    kCFURLEnumeratorIncludeDirectoriesPreOrder = 1UL << 4,
    kCFURLEnumeratorIncludeDirectoriesPostOrder = 1UL << 5,

    kCFURLEnumeratorGenerateRelativePathURLs __attribute__((availability(macos,introduced=10.15))) __attribute__((availability(ios,introduced=13.0))) __attribute__((availability(watchos,introduced=6.0))) __attribute__((availability(tvos,introduced=13.0))) = 1UL << 6,
};







extern
CFURLEnumeratorRef CFURLEnumeratorCreateForDirectoryURL( CFAllocatorRef alloc, CFURLRef directoryURL, CFURLEnumeratorOptions option, CFArrayRef propertyKeys ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFURLEnumeratorRef CFURLEnumeratorCreateForMountedVolumes( CFAllocatorRef alloc, CFURLEnumeratorOptions option, CFArrayRef propertyKeys ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



typedef CFIndex CFURLEnumeratorResult; enum {
    kCFURLEnumeratorSuccess = 1,
    kCFURLEnumeratorEnd = 2,
    kCFURLEnumeratorError = 3,
    kCFURLEnumeratorDirectoryPostOrderSuccess = 4,
};





extern
CFURLEnumeratorResult CFURLEnumeratorGetNextURL( CFURLEnumeratorRef enumerator, CFURLRef *url, CFErrorRef *error ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
void CFURLEnumeratorSkipDescendents( CFURLEnumeratorRef enumerator ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));




extern
CFIndex CFURLEnumeratorGetDescendentLevel( CFURLEnumeratorRef enumerator ) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=4.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));






extern
Boolean CFURLEnumeratorGetSourceDidChange( CFURLEnumeratorRef enumerator ) __attribute__((availability(macos,introduced=10.6,deprecated=10.7,message="Use File System Events API instead"))) __attribute__((availability(ios,introduced=4.0,deprecated=5.0,message="Use File System Events API instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="Use File System Events API instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="Use File System Events API instead")));


}






typedef union {

 unsigned char g_guid[16];
 unsigned int g_guid_asint[16 / sizeof(unsigned int)];
} guid_t;


#pragma pack(1)
typedef struct {
 u_int8_t sid_kind;
 u_int8_t sid_authcount;
 u_int8_t sid_authority[6];

 u_int32_t sid_authorities[16];
} ntsid_t;
#pragma pack()
struct kauth_identity_extlookup {
 u_int32_t el_seqno;
 u_int32_t el_result;





 u_int32_t el_flags;
 __darwin_pid_t el_info_pid;
 u_int64_t el_extend;
 u_int32_t el_info_reserved_1;

 uid_t el_uid;
 guid_t el_uguid;
 u_int32_t el_uguid_valid;
 ntsid_t el_usid;
 u_int32_t el_usid_valid;
 gid_t el_gid;
 guid_t el_gguid;
 u_int32_t el_gguid_valid;
 ntsid_t el_gsid;
 u_int32_t el_gsid_valid;
 u_int32_t el_member_valid;
 u_int32_t el_sup_grp_cnt;
 gid_t el_sup_groups[16];
};

struct kauth_cache_sizes {
 u_int32_t kcs_group_size;
 u_int32_t kcs_id_size;
};
typedef u_int32_t kauth_ace_rights_t;


struct kauth_ace {
 guid_t ace_applicable;
 u_int32_t ace_flags;
 kauth_ace_rights_t ace_rights;





};



typedef struct kauth_ace *kauth_ace_t;




struct kauth_acl {
 u_int32_t acl_entrycount;
 u_int32_t acl_flags;

 struct kauth_ace acl_ace[1];
};
typedef struct kauth_acl *kauth_acl_t;
struct kauth_filesec {
 u_int32_t fsec_magic;

 guid_t fsec_owner;
 guid_t fsec_group;

 struct kauth_acl fsec_acl;
};
typedef struct kauth_filesec *kauth_filesec_t;
typedef enum {
 ACL_READ_DATA = (1<<1),
 ACL_LIST_DIRECTORY = (1<<1),
 ACL_WRITE_DATA = (1<<2),
 ACL_ADD_FILE = (1<<2),
 ACL_EXECUTE = (1<<3),
 ACL_SEARCH = (1<<3),
 ACL_DELETE = (1<<4),
 ACL_APPEND_DATA = (1<<5),
 ACL_ADD_SUBDIRECTORY = (1<<5),
 ACL_DELETE_CHILD = (1<<6),
 ACL_READ_ATTRIBUTES = (1<<7),
 ACL_WRITE_ATTRIBUTES = (1<<8),
 ACL_READ_EXTATTRIBUTES = (1<<9),
 ACL_WRITE_EXTATTRIBUTES = (1<<10),
 ACL_READ_SECURITY = (1<<11),
 ACL_WRITE_SECURITY = (1<<12),
 ACL_CHANGE_OWNER = (1<<13),
 ACL_SYNCHRONIZE = (1<<20),
} acl_perm_t;


typedef enum {
 ACL_UNDEFINED_TAG = 0,
 ACL_EXTENDED_ALLOW = 1,
 ACL_EXTENDED_DENY = 2
} acl_tag_t;


typedef enum {
 ACL_TYPE_EXTENDED = 0x00000100,

 ACL_TYPE_ACCESS = 0x00000000,
 ACL_TYPE_DEFAULT = 0x00000001,

 ACL_TYPE_AFS = 0x00000002,
 ACL_TYPE_CODA = 0x00000003,
 ACL_TYPE_NTFS = 0x00000004,
 ACL_TYPE_NWFS = 0x00000005
} acl_type_t;






typedef enum {
 ACL_FIRST_ENTRY = 0,
 ACL_NEXT_ENTRY = -1,
 ACL_LAST_ENTRY = -2
} acl_entry_id_t;


typedef enum {
 ACL_FLAG_DEFER_INHERIT = (1 << 0),
 ACL_FLAG_NO_INHERIT = (1<<17),
 ACL_ENTRY_INHERITED = (1<<4),
 ACL_ENTRY_FILE_INHERIT = (1<<5),
 ACL_ENTRY_DIRECTORY_INHERIT = (1<<6),
 ACL_ENTRY_LIMIT_INHERIT = (1<<7),
 ACL_ENTRY_ONLY_INHERIT = (1<<8)
} acl_flag_t;



struct _acl;
struct _acl_entry;
struct _acl_permset;
struct _acl_flagset;

typedef struct _acl *acl_t;
typedef struct _acl_entry *acl_entry_t;
typedef struct _acl_permset *acl_permset_t;
typedef struct _acl_flagset *acl_flagset_t;

typedef u_int64_t acl_permset_mask_t;

extern "C" {

extern acl_t acl_dup(acl_t acl);
extern int acl_free(void *obj_p);
extern acl_t acl_init(int count);


extern int acl_copy_entry(acl_entry_t dest_d, acl_entry_t src_d);
extern int acl_create_entry(acl_t *acl_p, acl_entry_t *entry_p);
extern int acl_create_entry_np(acl_t *acl_p, acl_entry_t *entry_p, int entry_index);
extern int acl_delete_entry(acl_t acl, acl_entry_t entry_d);
extern int acl_get_entry(acl_t acl, int entry_id, acl_entry_t *entry_p);
extern int acl_valid(acl_t acl);
extern int acl_valid_fd_np(int fd, acl_type_t type, acl_t acl);
extern int acl_valid_file_np(const char *path, acl_type_t type, acl_t acl);
extern int acl_valid_link_np(const char *path, acl_type_t type, acl_t acl);


extern int acl_add_perm(acl_permset_t permset_d, acl_perm_t perm);
extern int acl_calc_mask(acl_t *acl_p);
extern int acl_clear_perms(acl_permset_t permset_d);
extern int acl_delete_perm(acl_permset_t permset_d, acl_perm_t perm);
extern int acl_get_perm_np(acl_permset_t permset_d, acl_perm_t perm);
extern int acl_get_permset(acl_entry_t entry_d, acl_permset_t *permset_p);
extern int acl_set_permset(acl_entry_t entry_d, acl_permset_t permset_d);


extern int acl_maximal_permset_mask_np(acl_permset_mask_t * mask_p) __attribute__((availability(macosx,introduced=10.7)));
extern int acl_get_permset_mask_np(acl_entry_t entry_d, acl_permset_mask_t * mask_p) __attribute__((availability(macosx,introduced=10.7)));
extern int acl_set_permset_mask_np(acl_entry_t entry_d, acl_permset_mask_t mask) __attribute__((availability(macosx,introduced=10.7)));


extern int acl_add_flag_np(acl_flagset_t flagset_d, acl_flag_t flag);
extern int acl_clear_flags_np(acl_flagset_t flagset_d);
extern int acl_delete_flag_np(acl_flagset_t flagset_d, acl_flag_t flag);
extern int acl_get_flag_np(acl_flagset_t flagset_d, acl_flag_t flag);
extern int acl_get_flagset_np(void *obj_p, acl_flagset_t *flagset_p);
extern int acl_set_flagset_np(void *obj_p, acl_flagset_t flagset_d);


extern void *acl_get_qualifier(acl_entry_t entry_d);
extern int acl_get_tag_type(acl_entry_t entry_d, acl_tag_t *tag_type_p);
extern int acl_set_qualifier(acl_entry_t entry_d, const void *tag_qualifier_p);
extern int acl_set_tag_type(acl_entry_t entry_d, acl_tag_t tag_type);


extern int acl_delete_def_file(const char *path_p);
extern acl_t acl_get_fd(int fd);
extern acl_t acl_get_fd_np(int fd, acl_type_t type);
extern acl_t acl_get_file(const char *path_p, acl_type_t type);
extern acl_t acl_get_link_np(const char *path_p, acl_type_t type);
extern int acl_set_fd(int fd, acl_t acl);
extern int acl_set_fd_np(int fd, acl_t acl, acl_type_t acl_type);
extern int acl_set_file(const char *path_p, acl_type_t type, acl_t acl);
extern int acl_set_link_np(const char *path_p, acl_type_t type, acl_t acl);


extern ssize_t acl_copy_ext(void *buf_p, acl_t acl, ssize_t size);
extern ssize_t acl_copy_ext_native(void *buf_p, acl_t acl, ssize_t size);
extern acl_t acl_copy_int(const void *buf_p);
extern acl_t acl_copy_int_native(const void *buf_p);
extern acl_t acl_from_text(const char *buf_p);
extern ssize_t acl_size(acl_t acl);
extern char *acl_to_text(acl_t acl, ssize_t *len_p);
}




extern "C" {





typedef struct __attribute__((objc_bridge_mutable(NSFileSecurity))) __CFFileSecurity* CFFileSecurityRef;







extern
CFTypeID CFFileSecurityGetTypeID(void) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFFileSecurityRef CFFileSecurityCreate(CFAllocatorRef allocator) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFFileSecurityRef CFFileSecurityCreateCopy(CFAllocatorRef allocator, CFFileSecurityRef fileSec) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecurityCopyOwnerUUID(CFFileSecurityRef fileSec, CFUUIDRef *ownerUUID) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecuritySetOwnerUUID(CFFileSecurityRef fileSec, CFUUIDRef ownerUUID) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecurityCopyGroupUUID(CFFileSecurityRef fileSec, CFUUIDRef *groupUUID) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecuritySetGroupUUID(CFFileSecurityRef fileSec, CFUUIDRef groupUUID) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecurityCopyAccessControlList(CFFileSecurityRef fileSec, acl_t *accessControlList) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecuritySetAccessControlList(CFFileSecurityRef fileSec, acl_t accessControlList) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecurityGetOwner(CFFileSecurityRef fileSec, uid_t *owner) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecuritySetOwner(CFFileSecurityRef fileSec, uid_t owner) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecurityGetGroup(CFFileSecurityRef fileSec, gid_t *group) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecuritySetGroup(CFFileSecurityRef fileSec, gid_t group) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecurityGetMode(CFFileSecurityRef fileSec, mode_t *mode) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecuritySetMode(CFFileSecurityRef fileSec, mode_t mode) __attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));



typedef CFOptionFlags CFFileSecurityClearOptions; enum {
    kCFFileSecurityClearOwner = 1UL << 0,
    kCFFileSecurityClearGroup = 1UL << 1,
    kCFFileSecurityClearMode = 1UL << 2,
    kCFFileSecurityClearOwnerUUID = 1UL << 3,
    kCFFileSecurityClearGroupUUID = 1UL << 4,
    kCFFileSecurityClearAccessControlList = 1UL << 5
} __attribute__((availability(macos,introduced=10.8))) __attribute__((availability(ios,introduced=6.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
Boolean CFFileSecurityClearProperties(CFFileSecurityRef fileSec, CFFileSecurityClearOptions clearPropertyMask) __attribute__((availability(macos,introduced=10.8))) __attribute__((availability(ios,introduced=6.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


}
extern "C" {
extern
CFStringRef CFStringTokenizerCopyBestStringLanguage(CFStringRef string, CFRange range) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));







typedef struct __attribute__((objc_bridge_mutable(id))) __CFStringTokenizer * CFStringTokenizerRef;




enum {






    kCFStringTokenizerUnitWord = 0,
    kCFStringTokenizerUnitSentence = 1,
    kCFStringTokenizerUnitParagraph = 2,
    kCFStringTokenizerUnitLineBreak = 3,




    kCFStringTokenizerUnitWordBoundary = 4,
    kCFStringTokenizerAttributeLatinTranscription = 1UL << 16,


    kCFStringTokenizerAttributeLanguage = 1UL << 17,
};






typedef CFOptionFlags CFStringTokenizerTokenType; enum {

    kCFStringTokenizerTokenNone = 0,


    kCFStringTokenizerTokenNormal = 1UL << 0,





    kCFStringTokenizerTokenHasSubTokensMask = 1UL << 1,






    kCFStringTokenizerTokenHasDerivedSubTokensMask = 1UL << 2,

    kCFStringTokenizerTokenHasHasNumbersMask = 1UL << 3,
    kCFStringTokenizerTokenHasNonLettersMask = 1UL << 4,
    kCFStringTokenizerTokenIsCJWordMask = 1UL << 5
};






extern
CFTypeID CFStringTokenizerGetTypeID(void) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFStringTokenizerRef CFStringTokenizerCreate(CFAllocatorRef alloc, CFStringRef string, CFRange range, CFOptionFlags options, CFLocaleRef locale) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
void CFStringTokenizerSetString(CFStringTokenizerRef tokenizer, CFStringRef string, CFRange range) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFStringTokenizerTokenType CFStringTokenizerGoToTokenAtIndex(CFStringTokenizerRef tokenizer, CFIndex index) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFStringTokenizerTokenType CFStringTokenizerAdvanceToNextToken(CFStringTokenizerRef tokenizer) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFRange CFStringTokenizerGetCurrentTokenRange(CFStringTokenizerRef tokenizer) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFTypeRef CFStringTokenizerCopyCurrentTokenAttribute(CFStringTokenizerRef tokenizer, CFOptionFlags attribute) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern
CFIndex CFStringTokenizerGetCurrentSubTokens(CFStringTokenizerRef tokenizer, CFRange *ranges, CFIndex maxRangeLength, CFMutableArrayRef derivedSubTokens) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=3.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

}
extern "C" {

typedef int CFFileDescriptorNativeDescriptor;

typedef struct __attribute__((objc_bridge_mutable(id))) __CFFileDescriptor * CFFileDescriptorRef;


enum {
    kCFFileDescriptorReadCallBack = 1UL << 0,
    kCFFileDescriptorWriteCallBack = 1UL << 1
};

typedef void (*CFFileDescriptorCallBack)(CFFileDescriptorRef f, CFOptionFlags callBackTypes, void *info);

typedef struct {
    CFIndex version;
    void * info;
    void * (*retain)(void *info);
    void (*release)(void *info);
    CFStringRef (*copyDescription)(void *info);
} CFFileDescriptorContext;

extern CFTypeID CFFileDescriptorGetTypeID(void) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern CFFileDescriptorRef CFFileDescriptorCreate(CFAllocatorRef allocator, CFFileDescriptorNativeDescriptor fd, Boolean closeOnInvalidate, CFFileDescriptorCallBack callout, const CFFileDescriptorContext *context) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern CFFileDescriptorNativeDescriptor CFFileDescriptorGetNativeDescriptor(CFFileDescriptorRef f) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern void CFFileDescriptorGetContext(CFFileDescriptorRef f, CFFileDescriptorContext *context) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern void CFFileDescriptorEnableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern void CFFileDescriptorDisableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern void CFFileDescriptorInvalidate(CFFileDescriptorRef f) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));
extern Boolean CFFileDescriptorIsValid(CFFileDescriptorRef f) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));

extern CFRunLoopSourceRef CFFileDescriptorCreateRunLoopSource(CFAllocatorRef allocator, CFFileDescriptorRef f, CFIndex order) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(tvos,introduced=9.0)));


}



extern "C" {

typedef struct __attribute__((objc_bridge_mutable(id))) __CFUserNotification * CFUserNotificationRef;
typedef void (*CFUserNotificationCallBack)(CFUserNotificationRef userNotification, CFOptionFlags responseFlags);

extern
CFTypeID CFUserNotificationGetTypeID(void) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
CFUserNotificationRef CFUserNotificationCreate(CFAllocatorRef allocator, CFTimeInterval timeout, CFOptionFlags flags, SInt32 *error, CFDictionaryRef dictionary) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
SInt32 CFUserNotificationReceiveResponse(CFUserNotificationRef userNotification, CFTimeInterval timeout, CFOptionFlags *responseFlags) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
CFStringRef CFUserNotificationGetResponseValue(CFUserNotificationRef userNotification, CFStringRef key, CFIndex idx) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
CFDictionaryRef CFUserNotificationGetResponseDictionary(CFUserNotificationRef userNotification) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
SInt32 CFUserNotificationUpdate(CFUserNotificationRef userNotification, CFTimeInterval timeout, CFOptionFlags flags, CFDictionaryRef dictionary) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
SInt32 CFUserNotificationCancel(CFUserNotificationRef userNotification) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
CFRunLoopSourceRef CFUserNotificationCreateRunLoopSource(CFAllocatorRef allocator, CFUserNotificationRef userNotification, CFUserNotificationCallBack callout, CFIndex order) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));




extern
SInt32 CFUserNotificationDisplayNotice(CFTimeInterval timeout, CFOptionFlags flags, CFURLRef iconURL, CFURLRef soundURL, CFURLRef localizationURL, CFStringRef alertHeader, CFStringRef alertMessage, CFStringRef defaultButtonTitle) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
SInt32 CFUserNotificationDisplayAlert(CFTimeInterval timeout, CFOptionFlags flags, CFURLRef iconURL, CFURLRef soundURL, CFURLRef localizationURL, CFStringRef alertHeader, CFStringRef alertMessage, CFStringRef defaultButtonTitle, CFStringRef alternateButtonTitle, CFStringRef otherButtonTitle, CFOptionFlags *responseFlags) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));




enum {
    kCFUserNotificationStopAlertLevel __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 0,
    kCFUserNotificationNoteAlertLevel __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 1,
    kCFUserNotificationCautionAlertLevel __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 2,
    kCFUserNotificationPlainAlertLevel __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 3
};

enum {
    kCFUserNotificationDefaultResponse __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 0,
    kCFUserNotificationAlternateResponse __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 1,
    kCFUserNotificationOtherResponse __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 2,
    kCFUserNotificationCancelResponse __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = 3
};

enum {
    kCFUserNotificationNoDefaultButtonFlag __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = (1UL << 5),
    kCFUserNotificationUseRadioButtonsFlag __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) = (1UL << 6)
};

static __inline__ __attribute__((always_inline)) CFOptionFlags CFUserNotificationCheckBoxChecked(CFIndex i) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) {return ((CFOptionFlags)(1UL << (8 + i)));}
static __inline__ __attribute__((always_inline)) CFOptionFlags CFUserNotificationSecureTextField(CFIndex i) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) {return ((CFOptionFlags)(1UL << (16 + i)));}
static __inline__ __attribute__((always_inline)) CFOptionFlags CFUserNotificationPopUpSelection(CFIndex n) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable))) {return ((CFOptionFlags)(n << 24));}




extern
const CFStringRef kCFUserNotificationIconURLKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationSoundURLKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationLocalizationURLKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationAlertHeaderKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationAlertMessageKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationDefaultButtonTitleKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationAlternateButtonTitleKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationOtherButtonTitleKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationProgressIndicatorValueKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationPopUpTitlesKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationTextFieldTitlesKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationCheckBoxTitlesKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationTextFieldValuesKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationPopUpSelectionKey __attribute__((availability(macos,introduced=10.3))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationAlertTopMostKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

extern
const CFStringRef kCFUserNotificationKeyboardTypesKey __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));

}
extern "C" {



enum {
 kCFXMLNodeCurrentVersion = 1
};

typedef const struct __CFXMLNode * CFXMLNodeRef;
typedef CFTreeRef CFXMLTreeRef;
typedef CFIndex CFXMLNodeTypeCode; enum {
    kCFXMLNodeTypeDocument = 1,
    kCFXMLNodeTypeElement = 2,
    kCFXMLNodeTypeAttribute = 3,
    kCFXMLNodeTypeProcessingInstruction = 4,
    kCFXMLNodeTypeComment = 5,
    kCFXMLNodeTypeText = 6,
    kCFXMLNodeTypeCDATASection = 7,
    kCFXMLNodeTypeDocumentFragment = 8,
    kCFXMLNodeTypeEntity = 9,
    kCFXMLNodeTypeEntityReference = 10,
    kCFXMLNodeTypeDocumentType = 11,
    kCFXMLNodeTypeWhitespace = 12,
    kCFXMLNodeTypeNotation = 13,
    kCFXMLNodeTypeElementTypeDeclaration = 14,
    kCFXMLNodeTypeAttributeListDeclaration = 15
};

typedef struct {
    CFDictionaryRef attributes;
    CFArrayRef attributeOrder;
    Boolean isEmpty;
    char _reserved[3];
} CFXMLElementInfo;

typedef struct {
    CFStringRef dataString;
} CFXMLProcessingInstructionInfo;

typedef struct {
    CFURLRef sourceURL;
    CFStringEncoding encoding;
} CFXMLDocumentInfo;

typedef struct {
    CFURLRef systemID;
    CFStringRef publicID;
} CFXMLExternalID;

typedef struct {
    CFXMLExternalID externalID;
} CFXMLDocumentTypeInfo;

typedef struct {
    CFXMLExternalID externalID;
} CFXMLNotationInfo;

typedef struct {

    CFStringRef contentDescription;
} CFXMLElementTypeDeclarationInfo;

typedef struct {

    CFStringRef attributeName;
    CFStringRef typeString;
    CFStringRef defaultString;
} CFXMLAttributeDeclarationInfo;

typedef struct {
    CFIndex numberOfAttributes;
    CFXMLAttributeDeclarationInfo *attributes;
} CFXMLAttributeListDeclarationInfo;

typedef CFIndex CFXMLEntityTypeCode; enum {
    kCFXMLEntityTypeParameter,
    kCFXMLEntityTypeParsedInternal,
    kCFXMLEntityTypeParsedExternal,
    kCFXMLEntityTypeUnparsed,
    kCFXMLEntityTypeCharacter
};

typedef struct {
    CFXMLEntityTypeCode entityType;
    CFStringRef replacementText;
    CFXMLExternalID entityID;
    CFStringRef notationName;
} CFXMLEntityInfo;

typedef struct {
    CFXMLEntityTypeCode entityType;
} CFXMLEntityReferenceInfo;
extern
CFTypeID CFXMLNodeGetTypeID(void) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));


extern
CFXMLNodeRef CFXMLNodeCreate(CFAllocatorRef alloc, CFXMLNodeTypeCode xmlType, CFStringRef dataString, const void *additionalInfoPtr, CFIndex version) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));


extern
CFXMLNodeRef CFXMLNodeCreateCopy(CFAllocatorRef alloc, CFXMLNodeRef origNode) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
CFXMLNodeTypeCode CFXMLNodeGetTypeCode(CFXMLNodeRef node) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
CFStringRef CFXMLNodeGetString(CFXMLNodeRef node) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
const void *CFXMLNodeGetInfoPtr(CFXMLNodeRef node) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
CFIndex CFXMLNodeGetVersion(CFXMLNodeRef node) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));




extern
CFXMLTreeRef CFXMLTreeCreateWithNode(CFAllocatorRef allocator, CFXMLNodeRef node) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));


extern
CFXMLNodeRef CFXMLTreeGetNode(CFXMLTreeRef xmlTree) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLNode is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));



}


extern "C" {



typedef struct __CFXMLParser * CFXMLParserRef;
typedef CFOptionFlags CFXMLParserOptions; enum {
    kCFXMLParserValidateDocument = (1UL << 0),
    kCFXMLParserSkipMetaData = (1UL << 1),
    kCFXMLParserReplacePhysicalEntities = (1UL << 2),
    kCFXMLParserSkipWhitespace = (1UL << 3),
    kCFXMLParserResolveExternalEntities = (1UL << 4),
    kCFXMLParserAddImpliedAttributes = (1UL << 5),
    kCFXMLParserAllOptions = 0x00FFFFFF,
    kCFXMLParserNoOptions = 0
};


typedef CFIndex CFXMLParserStatusCode; enum {
    kCFXMLStatusParseNotBegun = -2,
    kCFXMLStatusParseInProgress = -1,
    kCFXMLStatusParseSuccessful = 0,
    kCFXMLErrorUnexpectedEOF = 1,
    kCFXMLErrorUnknownEncoding,
    kCFXMLErrorEncodingConversionFailure,
    kCFXMLErrorMalformedProcessingInstruction,
    kCFXMLErrorMalformedDTD,
    kCFXMLErrorMalformedName,
    kCFXMLErrorMalformedCDSect,
    kCFXMLErrorMalformedCloseTag,
    kCFXMLErrorMalformedStartTag,
    kCFXMLErrorMalformedDocument,
    kCFXMLErrorElementlessDocument,
    kCFXMLErrorMalformedComment,
    kCFXMLErrorMalformedCharacterReference,
    kCFXMLErrorMalformedParsedCharacterData,
    kCFXMLErrorNoData
};
typedef void * (*CFXMLParserCreateXMLStructureCallBack)(CFXMLParserRef parser, CFXMLNodeRef nodeDesc, void *info);
typedef void (*CFXMLParserAddChildCallBack)(CFXMLParserRef parser, void *parent, void *child, void *info);
typedef void (*CFXMLParserEndXMLStructureCallBack)(CFXMLParserRef parser, void *xmlType, void *info);
typedef CFDataRef (*CFXMLParserResolveExternalEntityCallBack)(CFXMLParserRef parser, CFXMLExternalID *extID, void *info);
typedef Boolean (*CFXMLParserHandleErrorCallBack)(CFXMLParserRef parser, CFXMLParserStatusCode error, void *info);
typedef struct {
    CFIndex version;
    CFXMLParserCreateXMLStructureCallBack createXMLStructure;
    CFXMLParserAddChildCallBack addChild;
    CFXMLParserEndXMLStructureCallBack endXMLStructure;
    CFXMLParserResolveExternalEntityCallBack resolveExternalEntity;
    CFXMLParserHandleErrorCallBack handleError;
} CFXMLParserCallBacks;

typedef const void * (*CFXMLParserRetainCallBack)(const void *info);
typedef void (*CFXMLParserReleaseCallBack)(const void *info);
typedef CFStringRef (*CFXMLParserCopyDescriptionCallBack)(const void *info);
typedef struct {
    CFIndex version;
    void * info;
    CFXMLParserRetainCallBack retain;
    CFXMLParserReleaseCallBack release;
    CFXMLParserCopyDescriptionCallBack copyDescription;
} CFXMLParserContext;

extern
CFTypeID CFXMLParserGetTypeID(void) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));
extern
CFXMLParserRef CFXMLParserCreate(CFAllocatorRef allocator, CFDataRef xmlData, CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes, CFXMLParserCallBacks *callBacks, CFXMLParserContext *context) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));



extern
CFXMLParserRef CFXMLParserCreateWithDataFromURL(CFAllocatorRef allocator, CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes, CFXMLParserCallBacks *callBacks, CFXMLParserContext *context) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
void CFXMLParserGetContext(CFXMLParserRef parser, CFXMLParserContext *context) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
void CFXMLParserGetCallBacks(CFXMLParserRef parser, CFXMLParserCallBacks *callBacks) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
CFURLRef CFXMLParserGetSourceURL(CFXMLParserRef parser) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));


extern
CFIndex CFXMLParserGetLocation(CFXMLParserRef parser) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));


extern
CFIndex CFXMLParserGetLineNumber(CFXMLParserRef parser) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));


extern
void *CFXMLParserGetDocument(CFXMLParserRef parser) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));




extern
CFXMLParserStatusCode CFXMLParserGetStatusCode(CFXMLParserRef parser) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));

extern
CFStringRef CFXMLParserCopyErrorDescription(CFXMLParserRef parser) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));




extern
void CFXMLParserAbort(CFXMLParserRef parser, CFXMLParserStatusCode errorCode, CFStringRef errorDescription) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));






extern
Boolean CFXMLParserParse(CFXMLParserRef parser) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));







extern
CFXMLTreeRef CFXMLTreeCreateFromData(CFAllocatorRef allocator, CFDataRef xmlData, CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));




extern
CFXMLTreeRef CFXMLTreeCreateFromDataWithError(CFAllocatorRef allocator, CFDataRef xmlData, CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes, CFDictionaryRef *errorDict) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));


extern
CFXMLTreeRef CFXMLTreeCreateWithDataFromURL(CFAllocatorRef allocator, CFURLRef dataSource, CFOptionFlags parseOptions, CFIndex versionOfNodes) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));






extern
CFDataRef CFXMLTreeCreateXMLData(CFAllocatorRef allocator, CFXMLTreeRef xmlTree) __attribute__((availability(macos,introduced=10.0,deprecated=10.8,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(watchos,introduced=2.0,deprecated=2.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead"))) __attribute__((availability(tvos,introduced=9.0,deprecated=9.0,message="CFXMLParser is deprecated, use NSXMLParser, NSXMLDocument or libxml2 library instead")));







extern
CFStringRef CFXMLCreateStringByEscapingEntities(CFAllocatorRef allocator, CFStringRef string, CFDictionaryRef entitiesDictionary);

extern
CFStringRef CFXMLCreateStringByUnescapingEntities(CFAllocatorRef allocator, CFStringRef string, CFDictionaryRef entitiesDictionary);


extern const CFStringRef kCFXMLTreeErrorDescription;


extern const CFStringRef kCFXMLTreeErrorLineNumber;


extern const CFStringRef kCFXMLTreeErrorLocation;


extern const CFStringRef kCFXMLTreeErrorStatusCode;


}







const char* whoami = "nobody";

struct __Block_byref_counter_0 {
  void *__isa;
__Block_byref_counter_0 *__forwarding;
 int __flags;
 int __size;
 CFIndex counter;
};

struct __EnqueueStuff_block_impl_0 {
  struct __block_impl impl;
  struct __EnqueueStuff_block_desc_0* Desc;
  __Block_byref_counter_0 *counter; // by ref
  __EnqueueStuff_block_impl_0(void *fp, struct __EnqueueStuff_block_desc_0 *desc, __Block_byref_counter_0 *_counter, int flags=0) : counter(_counter->__forwarding) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __EnqueueStuff_block_func_0(struct __EnqueueStuff_block_impl_0 *__cself) {
  __Block_byref_counter_0 *counter = __cself->counter; // bound by ref

    (counter->__forwarding->counter) = 0;
  }
static void __EnqueueStuff_block_copy_0(struct __EnqueueStuff_block_impl_0*dst, struct __EnqueueStuff_block_impl_0*src) {_Block_object_assign((void*)&dst->counter, (void*)src->counter, 8/*BLOCK_FIELD_IS_BYREF*/);}

static void __EnqueueStuff_block_dispose_0(struct __EnqueueStuff_block_impl_0*src) {_Block_object_dispose((void*)src->counter, 8/*BLOCK_FIELD_IS_BYREF*/);}

static struct __EnqueueStuff_block_desc_0 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __EnqueueStuff_block_impl_0*, struct __EnqueueStuff_block_impl_0*);
  void (*dispose)(struct __EnqueueStuff_block_impl_0*);
} __EnqueueStuff_block_desc_0_DATA = { 0, sizeof(struct __EnqueueStuff_block_impl_0), __EnqueueStuff_block_copy_0, __EnqueueStuff_block_dispose_0};

struct __EnqueueStuff_block_impl_1 {
  struct __block_impl impl;
  struct __EnqueueStuff_block_desc_1* Desc;
  __Block_byref_counter_0 *counter; // by ref
  __EnqueueStuff_block_impl_1(void *fp, struct __EnqueueStuff_block_desc_1 *desc, __Block_byref_counter_0 *_counter, int flags=0) : counter(_counter->__forwarding) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __EnqueueStuff_block_func_1(struct __EnqueueStuff_block_impl_1 *__cself) {
  __Block_byref_counter_0 *counter = __cself->counter; // bound by ref


      (counter->__forwarding->counter)--;
      if ((counter->__forwarding->counter) == 0) {
        printf("%s: success\n", whoami);
        exit(0);
      }
    }
static void __EnqueueStuff_block_copy_1(struct __EnqueueStuff_block_impl_1*dst, struct __EnqueueStuff_block_impl_1*src) {_Block_object_assign((void*)&dst->counter, (void*)src->counter, 8/*BLOCK_FIELD_IS_BYREF*/);}

static void __EnqueueStuff_block_dispose_1(struct __EnqueueStuff_block_impl_1*src) {_Block_object_dispose((void*)src->counter, 8/*BLOCK_FIELD_IS_BYREF*/);}

static struct __EnqueueStuff_block_desc_1 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __EnqueueStuff_block_impl_1*, struct __EnqueueStuff_block_impl_1*);
  void (*dispose)(struct __EnqueueStuff_block_impl_1*);
} __EnqueueStuff_block_desc_1_DATA = { 0, sizeof(struct __EnqueueStuff_block_impl_1), __EnqueueStuff_block_copy_1, __EnqueueStuff_block_dispose_1};

struct __EnqueueStuff_block_impl_2 {
  struct __block_impl impl;
  struct __EnqueueStuff_block_desc_2* Desc;
  dispatch_queue_t q;
  __Block_byref_counter_0 *counter; // by ref
  __EnqueueStuff_block_impl_2(void *fp, struct __EnqueueStuff_block_desc_2 *desc, dispatch_queue_t _q, __Block_byref_counter_0 *_counter, int flags=0) : q(_q), counter(_counter->__forwarding) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __EnqueueStuff_block_func_2(struct __EnqueueStuff_block_impl_2 *__cself) {
  __Block_byref_counter_0 *counter = __cself->counter; // bound by ref
  dispatch_queue_t q = __cself->q; // bound by copy


    (counter->__forwarding->counter)++;
    dispatch_async(q, ((void (*)())&__EnqueueStuff_block_impl_1((void *)__EnqueueStuff_block_func_1, &__EnqueueStuff_block_desc_1_DATA, (__Block_byref_counter_0 *)counter, 570425344)));
    if ((counter->__forwarding->counter) == 0) {
      printf("already done? inconceivable!\n");
      exit(1);
    }
  }
static void __EnqueueStuff_block_copy_2(struct __EnqueueStuff_block_impl_2*dst, struct __EnqueueStuff_block_impl_2*src) {_Block_object_assign((void*)&dst->counter, (void*)src->counter, 8/*BLOCK_FIELD_IS_BYREF*/);_Block_object_assign((void*)&dst->q, (void*)src->q, 3/*BLOCK_FIELD_IS_OBJECT*/);}

static void __EnqueueStuff_block_dispose_2(struct __EnqueueStuff_block_impl_2*src) {_Block_object_dispose((void*)src->counter, 8/*BLOCK_FIELD_IS_BYREF*/);_Block_object_dispose((void*)src->q, 3/*BLOCK_FIELD_IS_OBJECT*/);}

static struct __EnqueueStuff_block_desc_2 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __EnqueueStuff_block_impl_2*, struct __EnqueueStuff_block_impl_2*);
  void (*dispose)(struct __EnqueueStuff_block_impl_2*);
} __EnqueueStuff_block_desc_2_DATA = { 0, sizeof(struct __EnqueueStuff_block_impl_2), __EnqueueStuff_block_copy_2, __EnqueueStuff_block_dispose_2};
void EnqueueStuff(dispatch_queue_t q) {
  __attribute__((__blocks__(byref))) __Block_byref_counter_0 counter = {(void*)0,(__Block_byref_counter_0 *)&counter, 0, sizeof(__Block_byref_counter_0)};
;




  dispatch_async(q, ((void (*)())&__EnqueueStuff_block_impl_0((void *)__EnqueueStuff_block_func_0, &__EnqueueStuff_block_desc_0_DATA, (__Block_byref_counter_0 *)&counter, 570425344)));

  dispatch_async(q, ((void (*)())&__EnqueueStuff_block_impl_2((void *)__EnqueueStuff_block_func_2, &__EnqueueStuff_block_desc_2_DATA, q, (__Block_byref_counter_0 *)&counter, 570425344)));
}

int main(int argc, const char* argv[]) {
  dispatch_queue_t q = dispatch_queue_create("queue", __null);

  whoami = argv[0];

  EnqueueStuff(q);

  dispatch_main();
  printf("shouldn't get here\n");
  return 1;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };
