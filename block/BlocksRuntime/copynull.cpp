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
extern "C" {





extern "C" __attribute__((__visibility__("default"))) void *_Block_copy(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) void _Block_release(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) void _Block_object_assign(void *, const void *, const int);


extern "C" __attribute__((__visibility__("default"))) void _Block_object_dispose(const void *, const int);






extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteGlobalBlock[32];
extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteStackBlock[32];



}
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

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
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;


typedef int64_t register_t;





typedef unsigned long uintptr_t;



typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;

typedef __darwin_intptr_t intptr_t;




typedef long int intmax_t;
typedef long unsigned int uintmax_t;

typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;



typedef __darwin_va_list va_list;
typedef __darwin_size_t size_t;

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
typedef __darwin_off_t off_t;

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
typedef __darwin_ssize_t ssize_t;

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




enum {
    BLOCK_DEALLOCATING = (0x0001),
    BLOCK_REFCOUNT_MASK = (0xfffe),
    BLOCK_NEEDS_FREE = (1 << 24),
    BLOCK_HAS_COPY_DISPOSE = (1 << 25),
    BLOCK_HAS_CTOR = (1 << 26),
    BLOCK_IS_GC = (1 << 27),
    BLOCK_IS_GLOBAL = (1 << 28),
    BLOCK_USE_STRET = (1 << 29),
    BLOCK_HAS_SIGNATURE = (1 << 30),
    BLOCK_HAS_EXTENDED_LAYOUT=(1 << 31)
};


struct Block_descriptor_1 {
    unsigned long int reserved;
    unsigned long int size;
};


struct Block_descriptor_2 {

    void (*copy)(void *dst, const void *src);
    void (*dispose)(const void *);
};


struct Block_descriptor_3 {

    const char *signature;
    const char *layout;
};

struct Block_layout {
    void *isa;
    volatile int32_t flags;
    int32_t reserved;
    void (*invoke)(void *, ...);
    struct Block_descriptor_1 *descriptor;

};



enum {




    BLOCK_BYREF_LAYOUT_MASK = (0xf << 28),
    BLOCK_BYREF_LAYOUT_EXTENDED = ( 1 << 28),
    BLOCK_BYREF_LAYOUT_NON_OBJECT = ( 2 << 28),
    BLOCK_BYREF_LAYOUT_STRONG = ( 3 << 28),
    BLOCK_BYREF_LAYOUT_WEAK = ( 4 << 28),
    BLOCK_BYREF_LAYOUT_UNRETAINED = ( 5 << 28),

    BLOCK_BYREF_IS_GC = ( 1 << 27),

    BLOCK_BYREF_HAS_COPY_DISPOSE = ( 1 << 25),
    BLOCK_BYREF_NEEDS_FREE = ( 1 << 24),
};

struct Block_byref {
    void *isa;
    struct Block_byref *forwarding;
    volatile int32_t flags;
    uint32_t size;
};

struct Block_byref_2 {

    void (*byref_keep)(struct Block_byref *dst, struct Block_byref *src);
    void (*byref_destroy)(struct Block_byref *);
};

struct Block_byref_3 {

    const char *layout;
};
enum {
    BLOCK_LAYOUT_ESCAPE = 0,
    BLOCK_LAYOUT_NON_OBJECT_BYTES = 1,
    BLOCK_LAYOUT_NON_OBJECT_WORDS = 2,
    BLOCK_LAYOUT_STRONG = 3,
    BLOCK_LAYOUT_BYREF = 4,
    BLOCK_LAYOUT_WEAK = 5,
    BLOCK_LAYOUT_UNRETAINED = 6,
    BLOCK_LAYOUT_UNKNOWN_WORDS_7 = 7,
    BLOCK_LAYOUT_UNKNOWN_WORDS_8 = 8,
    BLOCK_LAYOUT_UNKNOWN_WORDS_9 = 9,
    BLOCK_LAYOUT_UNKNOWN_WORDS_A = 0xA,
    BLOCK_LAYOUT_UNUSED_B = 0xB,
    BLOCK_LAYOUT_UNUSED_C = 0xC,
    BLOCK_LAYOUT_UNUSED_D = 0xD,
    BLOCK_LAYOUT_UNUSED_E = 0xE,
    BLOCK_LAYOUT_UNUSED_F = 0xF,
};





enum {

    BLOCK_FIELD_IS_OBJECT = 3,
    BLOCK_FIELD_IS_BLOCK = 7,
    BLOCK_FIELD_IS_BYREF = 8,
    BLOCK_FIELD_IS_WEAK = 16,
    BLOCK_BYREF_CALLER = 128,
};

enum {
    BLOCK_ALL_COPY_DISPOSE_FLAGS =
        BLOCK_FIELD_IS_OBJECT | BLOCK_FIELD_IS_BLOCK | BLOCK_FIELD_IS_BYREF |
        BLOCK_FIELD_IS_WEAK | BLOCK_BYREF_CALLER
};


extern "C" __attribute__((__visibility__("default"))) void _Block_object_assign(void *destAddr, const void *object, const int flags);




extern "C" __attribute__((__visibility__("default"))) void _Block_object_dispose(const void *object, const int flags);





extern "C" __attribute__((__visibility__("default"))) size_t Block_size(void *aBlock);


extern "C" __attribute__((__visibility__("default"))) bool _Block_has_signature(void *aBlock);


extern "C" __attribute__((__visibility__("default"))) bool _Block_use_stret(void *aBlock);




extern "C" __attribute__((__visibility__("default"))) const char * _Block_signature(void *aBlock);




extern "C" __attribute__((__visibility__("default"))) const char * _Block_layout(void *aBlock);




extern "C" __attribute__((__visibility__("default"))) const char * _Block_extended_layout(void *aBlock);


extern "C" __attribute__((__visibility__("default"))) bool _Block_tryRetain(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) bool _Block_isDeallocating(const void *aBlock);




extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteMallocBlock[32];
extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteAutoBlock[32];
extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteFinalizingBlock[32];
extern "C" __attribute__((__visibility__("default"))) void * _NSConcreteWeakBlockVariable[32];






extern "C" __attribute__((__visibility__("default"))) void _Block_use_GC( void *(*alloc)(const unsigned long, const bool isOne, const bool isObject),
                                  void (*setHasRefcount)(const void *, const bool),
                                  void (*gc_assign_strong)(void *, void **),
                                  void (*gc_assign_weak)(const void *, void *),
                                  void (*gc_memmove)(void *, void *, unsigned long));


extern "C" __attribute__((__visibility__("default"))) void _Block_use_GC5( void *(*alloc)(const unsigned long, const bool isOne, const bool isObject),
                                  void (*setHasRefcount)(const void *, const bool),
                                  void (*gc_assign_strong)(void *, void **),
                                  void (*gc_assign_weak)(const void *, void *));

extern "C" __attribute__((__visibility__("default"))) void _Block_use_RR( void (*retain)(const void *),
                                 void (*release)(const void *));

struct Block_callbacks_RR {
    size_t size;
    void (*retain)(const void *);
    void (*release)(const void *);
    void (*destructInstance)(const void *);
};
typedef struct Block_callbacks_RR Block_callbacks_RR;

extern "C" __attribute__((__visibility__("default"))) void _Block_use_RR2(const Block_callbacks_RR *callbacks);


extern "C" __attribute__((__visibility__("default"))) void *_Block_copy_collectable(const void *aBlock);


extern "C" __attribute__((__visibility__("default"))) const char *_Block_dump(const void *block);





struct Block_basic {
    void *isa;
    int Block_flags;
    int Block_size;
    void (*Block_invoke)(void *);
    void (*Block_copy)(void *dst, void *src);
    void (*Block_dispose)(void *);

} __attribute__((deprecated));



}




int main(int argc, char* argv[]) {
  void (*block)(void) = (void (*)(void))0;
  void (*blockcopy)(void) = ((void (*)())_Block_copy((const void *)(block)));

  if (blockcopy != (void (*)(void))0) {
    printf("whoops, somehow we copied NULL!\n");
    return 1;
  }

  _Block_release((const void *)(blockcopy));



  printf("%s: success\n", argv[0]);
  return 0;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };
