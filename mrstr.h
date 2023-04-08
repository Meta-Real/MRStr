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
typedef const mrstr_chr *mrstr_cstr;

typedef uint64_t mrstr_size;
typedef uint64_t mrstr_idx;

#define MRSTR_NF ((mrstr_idx)-1)

typedef uint8_t mrstr_bool;

#define MRSTR_TRUE ((mrstr_bool)1)
#define MRSTR_FALSE ((mrstr_bool)0)

typedef int8_t mrstr_cmpr;

#define MRSTR_LEFT ((mrstr_cmpr)-1)
#define MRSTR_EQUAL ((mrstr_cmpr)0)
#define MRSTR_RIGHT ((mrstr_cmpr)1)

struct __mrstr__
{
    mrstr_str _data;
    mrstr_size _len;

    mrstr_idx _offset;
};

typedef struct __mrstr__ mrstr_t[1];
typedef struct __mrstr__ *mrstr_p;
typedef const struct __mrstr__ *mrstr_pc;

typedef mrstr_t* mrstr_lst;

#define MRSTR_DATA(x) ((x)->_data)
#define MRSTR_LEN(x) ((x)->_len)
#define MRSTR_OFFSET(x) ((x)->_offset)

struct __mrstr_chr_data__
{
    mrstr_p str;

    mrstr_idx idx;

    mrstr_chr prev;
    mrstr_chr next;
};

#define MRSTR_ALPHA_LOW "abcdefghijklmnopqrstuvwxyz"
#define MRSTR_ALPHA_HIGH "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MRSTR_ALPHA (MRSTR_ALPHA_LOW MRSTR_ALPHA_HIGH)

#define MRSTR_DIGIT "0123456789"
#define MRSTR_ODIGIT "01234567"
#define MRSTR_XDIGIT "0123456789abcdefABCDEF"

/* init functions */

void mrstr_init(mrstr_p str);
void mrstr_inits(mrstr_p str, ...);

void mrstr_init2(mrstr_p str, mrstr_str data);
void mrstr_init3(mrstr_p str, mrstr_str data, mrstr_size len, mrstr_idx offset);

void mrstr_clear(mrstr_p str);
void mrstr_clears(mrstr_p str, ...);

/* set functions */

void mrstr_set(mrstr_p dst, mrstr_pc src);
void mrstr_set_str(mrstr_p dst, mrstr_cstr src);
void mrstr_set_chr(mrstr_p dst, mrstr_chr src);

void mrstr_n_set(mrstr_p dst, mrstr_pc src, mrstr_size len);
void mrstr_n_set_str(mrstr_p dst, mrstr_cstr src, mrstr_size len);

void mrstr_link(mrstr_p dst, mrstr_p src);
void mrstr_swap(mrstr_p str1, mrstr_p str2);

/* get functions */

mrstr_str mrstr_get_str(mrstr_pc src);
mrstr_chr mrstr_get_chr(mrstr_pc src, mrstr_idx idx);

mrstr_str mrstr_n_get_str(mrstr_pc src, mrstr_size len);

/* io functions */

void mrstr_inp(mrstr_p dst, FILE *src);
void mrstr_n_inp(mrstr_p dst, FILE *src, mrstr_size len);

void mrstr_out(FILE *dst, mrstr_pc src);
void mrstr_n_out(FILE *dst, mrstr_pc src, mrstr_size len);

/* binary operation functions */

void mrstr_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2);
void mrstr_concat_str(mrstr_p res, mrstr_pc str1, mrstr_cstr str2);
void mrstr_concat_chr(mrstr_p res, mrstr_pc str, mrstr_chr chr);

void mrstr_n_concat(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_pc str2);
void mrstr_n_concat_str(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_cstr str2); //
void mrstr_n_concat_chr(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr); //

void mrstr_n2_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2, mrstr_size len);
void mrstr_n2_concat_str(mrstr_p res, mrstr_pc str1, mrstr_cstr str2, mrstr_size len); //

void mrstr_nn_concat(mrstr_p res, mrstr_pc str1, mrstr_size len1, mrstr_pc str2, mrstr_size len2);
void mrstr_nn_concat_str(mrstr_p res, mrstr_pc str1, mrstr_size len1, mrstr_cstr str2, mrstr_size len2); //

void mrstr_remove(mrstr_p res, mrstr_pc str, mrstr_idx idx);
void mrstr_r_remove(mrstr_p res, mrstr_p str, mrstr_idx sidx, mrstr_idx eidx);
void mrstr_n_remove(mrstr_p res, mrstr_p str, mrstr_idx idx, mrstr_size len);

void mrstr_repeat(mrstr_p res, mrstr_pc str, mrstr_size count);
void mrstr_n_repeat(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_size count);

void mrstr_trim(mrstr_p res, mrstr_pc str, mrstr_chr chr); //
void mrstr_n_trim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr); //

void mrstr_ltrim(mrstr_p res, mrstr_pc str, mrstr_chr chr); //
void mrstr_n_ltrim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr); //

void mrstr_rtrim(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_rtrim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr); //

void mrstr_replace(mrstr_p res, mrstr_pc str, mrstr_chr old, mrstr_chr new);
void mrstr_n_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr old, mrstr_chr new);

void mrstr_replace_all(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_chr new);
void mrstr_n_replace_all(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_chr new); //

void mrstr_replace_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_cstr news);
void mrstr_n_replace_chrs(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_cstr news); //

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
mrstr_bool mrstr_equal_str(mrstr_pc str1, mrstr_cstr str2);
mrstr_bool mrstr_equal_chr(mrstr_pc str, mrstr_chr chr);

mrstr_bool mrstr_n_equal(mrstr_pc str1, mrstr_pc str2, mrstr_size len);
mrstr_bool mrstr_n_equal_str(mrstr_pc str1, mrstr_cstr str2, mrstr_size len);

/* find functions */

mrstr_bool mrstr_contains(mrstr_pc str, mrstr_pc substr);
mrstr_bool mrstr_contains_str(mrstr_pc str, mrstr_cstr substr);
mrstr_bool mrstr_contains_chr(mrstr_pc str, mrstr_chr chr);

mrstr_bool mrstr_n_contains(mrstr_pc str, mrstr_size len, mrstr_pc substr);
mrstr_bool mrstr_n_contains_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr);
mrstr_bool mrstr_n_contains_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_bool mrstr_n2_contains(mrstr_pc str, mrstr_pc substr, mrstr_size len); //
mrstr_bool mrstr_n2_contains_str(mrstr_pc str, mrstr_cstr substr, mrstr_size len); //

mrstr_bool mrstr_nn_contains(mrstr_pc str, mrstr_size len1, mrstr_pc substr, mrstr_size len2); //
mrstr_bool mrstr_nn_contains_str(mrstr_pc str, mrstr_size len1, mrstr_cstr substr, mrstr_size len2); //

mrstr_idx mrstr_find(mrstr_pc str, mrstr_pc substr);
mrstr_idx mrstr_find_str(mrstr_pc str, mrstr_cstr substr);
mrstr_idx mrstr_find_chr(mrstr_pc str, mrstr_chr chr);

mrstr_idx mrstr_n_find(mrstr_pc str, mrstr_size len, mrstr_pc substr);
mrstr_idx mrstr_n_find_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr);
mrstr_idx mrstr_n_find_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_idx mrstr_n2_find(mrstr_pc str, mrstr_pc substr, mrstr_size len); //
mrstr_idx mrstr_n2_find_str(mrstr_pc str, mrstr_cstr substr, mrstr_size len); //

mrstr_idx mrstr_nn_find(mrstr_pc str, mrstr_size len1, mrstr_pc substr, mrstr_size len2); //
mrstr_idx mrstr_nn_find_str(mrstr_pc str, mrstr_size len1, mrstr_cstr substr, mrstr_size len2); //

mrstr_idx mrstr_rfind(mrstr_pc str, mrstr_pc substr); //
mrstr_idx mrstr_rfind_str(mrstr_pc str, mrstr_cstr substr); //
mrstr_idx mrstr_rfind_chr(mrstr_pc str, mrstr_chr chr); //

mrstr_idx mrstr_n_rfind(mrstr_pc str, mrstr_size len, mrstr_pc substr); //
mrstr_idx mrstr_n_rfind_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr); //
mrstr_idx mrstr_n_rfind_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr); //

mrstr_idx mrstr_n2_rfind(mrstr_pc str, mrstr_pc substr, mrstr_size len); //
mrstr_idx mrstr_n2_rfind_str(mrstr_pc str, mrstr_cstr substr, mrstr_size len); //

mrstr_idx mrstr_nn_rfind(mrstr_pc str, mrstr_size len1, mrstr_pc substr, mrstr_size len2); //
mrstr_idx mrstr_nn_rfind_str(mrstr_pc str, mrstr_size len1, mrstr_cstr substr, mrstr_size len2); //

mrstr_idx* mrstr_find_all(mrstr_pc str, mrstr_pc substr); //
mrstr_idx* mrstr_find_all_str(mrstr_pc str, mrstr_cstr substr); //
mrstr_idx* mrstr_find_all_chr(mrstr_pc str, mrstr_chr chr); //

mrstr_idx* mrstr_n_find_all(mrstr_pc str, mrstr_size len, mrstr_pc substr); //
mrstr_idx* mrstr_n_find_all_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr); //
mrstr_idx* mrstr_n_find_all_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr); //

mrstr_idx* mrstr_n2_find_all(mrstr_pc str, mrstr_pc substr, mrstr_size len); //
mrstr_idx* mrstr_n2_find_all_str(mrstr_pc str, mrstr_cstr substr, mrstr_size len); //

mrstr_idx* mrstr_nn_find_all(mrstr_pc str, mrstr_size len1, mrstr_pc substr, mrstr_size len2); //
mrstr_idx* mrstr_nn_find_all_str(mrstr_pc str, mrstr_size len1, mrstr_cstr substr, mrstr_size len2); //

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

void mrstr_map(mrstr_p res, mrstr_pc str, mrstr_chr (*func)(mrstr_chr chr));
void mrstr_n_map(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr (*func)(mrstr_chr chr));

/* property functions */

void mrstr_set_offset(mrstr_p str, mrstr_idx offset);

static inline mrstr_str mrstr_data(mrstr_pc str)
{
    return MRSTR_DATA(str);
}

static inline mrstr_str mrstr_end(mrstr_pc str)
{
    return MRSTR_DATA(str) + MRSTR_LEN(str);
}

static inline mrstr_size mrstr_len(mrstr_pc str)
{
    return MRSTR_LEN(str);
}

static inline mrstr_idx mrstr_offset(mrstr_pc str)
{
    return MRSTR_OFFSET(str);
}

static inline mrstr_bool mrstr_isempty(mrstr_pc str)
{
    return MRSTR_LEN(str) ? MRSTR_FALSE : MRSTR_TRUE;
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
