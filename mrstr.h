/*/
 * MetaReal String Library version 1.0.0
 *
 * Main header file
/*/

#ifndef __MRSTR__
#define __MRSTR__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* type defines */

typedef char mrstr_chr;

typedef mrstr_chr *mrstr_str;
typedef const mrstr_str mrstr_cstr;

typedef uint64_t mrstr_size;

typedef uint8_t mrstr_bool;
typedef int8_t mrstr_cmpr;

#define MRSTR_NF ((mrstr_size)-1)

#define MRSTR_TRUE ((mrstr_bool)1)
#define MRSTR_FALSE ((mrstr_bool)0)

#define MRSTR_LEFT ((mrstr_cmpr)-1)
#define MRSTR_EQUAL ((mrstr_cmpr)0)
#define MRSTR_RIGHT ((mrstr_cmpr)1)

struct __mrstr__
{
    mrstr_str _data;
    mrstr_size _len;

    mrstr_size _offset;
};

typedef struct __mrstr__ mrstr_t[1];
typedef struct __mrstr__ *mrstr_p;
typedef const mrstr_p mrstr_pc;

#define MRSTR_DATA(x) ((x)->_data)
#define MRSTR_LEN(x) ((x)->_len)
#define MRSTR_OFFSET(x) ((x)->_offset)

struct __mrstr_unmask__
{
    mrstr_size olen;
    mrstr_chr ochr;
};

typedef struct __mrstr_unmask__ mrstr_unmask_t;

struct __mrstr_cdata__
{
    mrstr_p str;
    mrstr_size idx;

    mrstr_chr prev;
    mrstr_chr next;
};

typedef struct __mrstr_cdata__ mrstr_cdata_t;

#define MRSTR_ALPHA_LOWER "abcdefghijklmnopqrstuvwxyz"
#define MRSTR_ALPHA_UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MRSTR_ALPHA (MRSTR_ALPHA_LOWER MRSTR_ALPHA_UPPER)

#define MRSTR_DIGIT "0123456789"
#define MRSTR_ODIGIT "01234567"
#define MRSTR_XDIGIT "0123456789abcdefABCDEF"

/* init functions */

void mrstr_init(mrstr_p str);
void mrstr_init2(mrstr_p str, mrstr_str data);
void mrstr_init3(mrstr_p str, mrstr_str data, mrstr_size len, mrstr_size offset);
void mrstr_inits(mrstr_p str, ...);

void mrstr_clear(mrstr_p str);
void mrstr_clears(mrstr_p str, ...);

/* set functions */

void mrstr_set(mrstr_p dst, mrstr_pc src);
void mrstr_n_set(mrstr_p dst, mrstr_pc src, mrstr_size len);

void mrstr_set_str(mrstr_p dst, mrstr_cstr src);
void mrstr_n_set_str(mrstr_p dst, mrstr_cstr src, mrstr_size len);

void mrstr_set_chr(mrstr_p dst, mrstr_chr src);

void mrstr_link(mrstr_p dst, mrstr_p src);
void mrstr_swap(mrstr_p str1, mrstr_p str2);

/* get functions */

mrstr_str mrstr_get_str(mrstr_pc src);
mrstr_str mrstr_n_get_str(mrstr_pc src, mrstr_size len);

mrstr_chr mrstr_get_chr(mrstr_pc src, mrstr_size idx);

/* io functions */

void mrstr_inp(mrstr_p dst, FILE *src);
void mrstr_n_inp(mrstr_p dst, FILE *src, mrstr_size len);

void mrstr_out(FILE *dst, mrstr_pc src);
void mrstr_n_out(FILE *dst, mrstr_pc src, mrstr_size len);

/* concat */

void mrstr_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2);
void mrstr_n_concat(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_pc str2);

void mrstr_concat_str(mrstr_p res, mrstr_pc str1, mrstr_cstr str2);
void mrstr_n_concat_str(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_cstr str2);

void mrstr_concat_chr(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_concat_chr(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr);

/* remove */

void mrstr_remove(mrstr_p res, mrstr_pc str, mrstr_size idx);
void mrstr_r_remove(mrstr_p res, mrstr_p str, mrstr_size sidx, mrstr_size eidx);
void mrstr_n_remove(mrstr_p res, mrstr_p str, mrstr_size idx, mrstr_size len);

void mrstr_remove_chr(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_remove_chr(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr);

void mrstr_remove_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_n_remove_chrs(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr chrs);

/* repeat */

void mrstr_repeat(mrstr_p res, mrstr_pc str, mrstr_size count);
void mrstr_n_repeat(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_size count);

/* trim */

void mrstr_trim(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_trim(mrstr_p res, mrstr_pc str, mrstr_chr chr, mrstr_size len);
void mrstr_nn_trim(mrstr_p res, mrstr_pc str, mrstr_chr chr, mrstr_size len1, mrstr_size len2);

void mrstr_trim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_n_trim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs, mrstr_size len);
void mrstr_nn_trim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs, mrstr_size len1, mrstr_size len2);

void mrstr_ltrim(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_ltrim(mrstr_p res, mrstr_pc str, mrstr_chr chr, mrstr_size len);

void mrstr_ltrim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_n_ltrim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs, mrstr_size len);

void mrstr_rtrim(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_rtrim(mrstr_p res, mrstr_pc str, mrstr_chr chr, mrstr_size len);

void mrstr_rtrim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_n_rtrim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs, mrstr_size len);

/* replace */

void mrstr_replace(mrstr_p res, mrstr_pc str, mrstr_chr old, mrstr_chr new);
void mrstr_n_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr old, mrstr_chr new);

void mrstr_replace_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_chr new);
void mrstr_n_replace_chrs(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_chr new);

void mrstr_replace_chrs2(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_cstr news);
void mrstr_n_replace_chrs2(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_cstr news);

/* split */

mrstr_t* mrstr_split(mrstr_pc str, mrstr_chr chr); //
mrstr_t* mrstr_n_split(mrstr_pc str, mrstr_size len, mrstr_chr chr); //

/* unary operation functions */

void mrstr_reverse(mrstr_p res, mrstr_pc str);
void mrstr_n_reverse(mrstr_p res, mrstr_pc str, mrstr_size len);

void mrstr_lower(mrstr_p res, mrstr_pc str);
void mrstr_n_lower(mrstr_p res, mrstr_pc str, mrstr_size len);

void mrstr_upper(mrstr_p res, mrstr_pc str);
void mrstr_n_upper(mrstr_p res, mrstr_pc str, mrstr_size len);

/* comparison functions */

mrstr_bool mrstr_equal(mrstr_pc str1, mrstr_pc str2);
mrstr_bool mrstr_n_equal(mrstr_pc str1, mrstr_pc str2, mrstr_size len);

mrstr_bool mrstr_equal_str(mrstr_pc str1, mrstr_cstr str2);
mrstr_bool mrstr_n_equal_str(mrstr_pc str1, mrstr_cstr str2, mrstr_size len);

mrstr_bool mrstr_equal_chr(mrstr_pc str, mrstr_chr chr);

/* contains */

mrstr_bool mrstr_contains(mrstr_pc str, mrstr_pc substr);
mrstr_bool mrstr_n_contains(mrstr_pc str, mrstr_size len, mrstr_pc substr);

mrstr_bool mrstr_contains_str(mrstr_pc str, mrstr_cstr substr);
mrstr_bool mrstr_n_contains_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr);

mrstr_bool mrstr_contains_chr(mrstr_pc str, mrstr_chr chr);
mrstr_bool mrstr_n_contains_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr);

/* find */

mrstr_size mrstr_find(mrstr_pc str, mrstr_pc substr);
mrstr_size mrstr_n_find(mrstr_pc str, mrstr_size len, mrstr_pc substr);

mrstr_size mrstr_find_str(mrstr_pc str, mrstr_cstr substr);
mrstr_size mrstr_n_find_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr);

mrstr_size mrstr_find_chr(mrstr_pc str, mrstr_chr chr);
mrstr_size mrstr_n_find_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_size mrstr_rfind(mrstr_pc str, mrstr_pc substr);
mrstr_size mrstr_n_rfind(mrstr_pc str, mrstr_size len, mrstr_pc substr);

mrstr_size mrstr_rfind_str(mrstr_pc str, mrstr_cstr substr);
mrstr_size mrstr_n_rfind_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr);

mrstr_size mrstr_rfind_chr(mrstr_pc str, mrstr_chr chr);
mrstr_size mrstr_n_rfind_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_size* mrstr_find_all(mrstr_pc str, mrstr_pc substr); //
mrstr_size* mrstr_n_find_all(mrstr_pc str, mrstr_size len, mrstr_pc substr); //

mrstr_size* mrstr_find_all_str(mrstr_pc str, mrstr_cstr substr); //
mrstr_size* mrstr_n_find_all_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr); //

mrstr_size* mrstr_find_all_chr(mrstr_pc str, mrstr_chr chr); //
mrstr_size* mrstr_n_find_all_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr); //

/* count */

mrstr_size mrstr_count(mrstr_pc str, mrstr_pc substr);
mrstr_size mrstr_n_count(mrstr_pc str, mrstr_size len, mrstr_pc substr);

mrstr_size mrstr_count_str(mrstr_pc str, mrstr_cstr substr);
mrstr_size mrstr_n_count_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr);

mrstr_size mrstr_count_chr(mrstr_pc str, mrstr_chr chr);
mrstr_size mrstr_n_count_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr);

/* check functions */

mrstr_bool mrstr_start_with(mrstr_pc str, mrstr_pc substr);
mrstr_bool mrstr_start_with_str(mrstr_pc str, mrstr_cstr substr);
mrstr_bool mrstr_start_with_chr(mrstr_pc str, mrstr_chr chr);

mrstr_bool mrstr_end_with(mrstr_pc str, mrstr_pc substr);
mrstr_bool mrstr_end_with_str(mrstr_pc str, mrstr_cstr substr);
mrstr_bool mrstr_end_with_chr(mrstr_pc str, mrstr_chr chr);

mrstr_bool mrstr_isdigit(mrstr_pc str);
mrstr_bool mrstr_n_isdigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isbdigit(mrstr_pc str);
mrstr_bool mrstr_n_isbdigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isodigit(mrstr_pc str);
mrstr_bool mrstr_n_isodigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isxdigit(mrstr_pc str);
mrstr_bool mrstr_n_isxdigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isalpha(mrstr_pc str);
mrstr_bool mrstr_n_isalpha(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isalnum(mrstr_pc str);
mrstr_bool mrstr_n_isalnum(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isspace(mrstr_pc str);
mrstr_bool mrstr_n_isspace(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isblank(mrstr_pc str);
mrstr_bool mrstr_n_isblank(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isupper(mrstr_pc str);
mrstr_bool mrstr_n_isupper(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_islower(mrstr_pc str);
mrstr_bool mrstr_n_islower(mrstr_pc str, mrstr_size len);

/* customizable functions */

mrstr_bool mrstr_all(mrstr_pc str, mrstr_bool (*func)(mrstr_chr chr));
mrstr_bool mrstr_n_all(mrstr_pc str, mrstr_size len, mrstr_bool (*func)(mrstr_chr chr));
mrstr_bool mrstr_d_all(mrstr_pc str, mrstr_bool (*func)(mrstr_chr chr, mrstr_cdata_t data));
mrstr_bool mrstr_dn_all(mrstr_pc str, mrstr_size len,
                        mrstr_bool (*func)(mrstr_chr chr, mrstr_cdata_t data));

void mrstr_map(mrstr_p res, mrstr_pc str, mrstr_chr (*func)(mrstr_chr chr));
void mrstr_n_map(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr (*func)(mrstr_chr chr));
void mrstr_d_map(mrstr_p res, mrstr_pc str, mrstr_chr (*func)(mrstr_chr chr, mrstr_cdata_t data));
void mrstr_dn_map(mrstr_p res, mrstr_pc str, mrstr_size len,
                  mrstr_chr (*func)(mrstr_chr chr, mrstr_cdata_t data));

/* property functions */

void mrstr_set_offset(mrstr_p str, mrstr_size offset);
void mrstr_reset_offset(mrstr_p str);

mrstr_unmask_t mrstr_mask(mrstr_p str, mrstr_size len);
void mrstr_unmask(mrstr_p str, mrstr_unmask_t unmask);

static inline mrstr_str mrstr_data(mrstr_pc str)
{
    return MRSTR_DATA(str);
}

static inline mrstr_str mrstr_start(mrstr_pc str)
{
    return MRSTR_DATA(str) - MRSTR_OFFSET(str);
}

static inline mrstr_str mrstr_end(mrstr_pc str)
{
    return MRSTR_DATA(str) + MRSTR_LEN(str);
}

static inline mrstr_size mrstr_len(mrstr_pc str)
{
    return MRSTR_LEN(str);
}

static inline mrstr_size mrstr_offset(mrstr_pc str)
{
    return MRSTR_OFFSET(str);
}

static inline mrstr_size mrstr_alloc(mrstr_pc str)
{
    return MRSTR_LEN(str) + MRSTR_OFFSET(str);
}

static inline mrstr_bool mrstr_isempty(mrstr_pc str)
{
    return MRSTR_LEN(str) ? MRSTR_FALSE : MRSTR_TRUE;
}

static inline mrstr_bool mrstr_ischr(mrstr_pc str)
{
    return MRSTR_LEN(str) == 1 ? MRSTR_FALSE : MRSTR_TRUE;
}

/* manual debugging system */

#define __MRSTR_DBG__

#ifndef __MRSTR_DBG__

enum _err_codes_
{
    NONE_ERR, // nothing
    ALOC_ERR, // allocation error
    MOVF_ERR, // memory overflow error
    ORNG_ERR, // out of range error
    LMCH_ERR, // length match error
};

typedef char err_code_t;

extern err_code_t err_code;

#endif

/* alloc system */

extern void *(*__mrstr_das_alloc)(mrstr_size size);
extern void *(*__mrstr_das_realloc)(void *block, mrstr_size size);
extern void (*__mrstr_das_free)(void *block);

void mrstr_set_def_alloc_sys(
    void *(*mrstr_alloc)(mrstr_size size),
    void *(*mrstr_realloc)(void *block, mrstr_size size),
    void (*mrstr_free)(void *block));

void *mrstr_def_alloc(mrstr_size size);
void *mrstr_def_realloc(void *block, mrstr_size size);
void mrstr_def_free(void *block);

#endif /* __MRSTR__ */
