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

/* type definitions */

typedef char mrstr_chr;

typedef mrstr_chr *mrstr_str;
typedef const mrstr_chr *mrstr_cstr;

typedef uint64_t mrstr_size;

typedef uint8_t mrstr_bool;
typedef int8_t mrstr_cmpr;

#define MRSTR_NF ((mrstr_size)-1)

#define MRSTR_TRUE ((mrstr_bool)1)
#define MRSTR_FALSE ((mrstr_bool)0)

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

#define MRSTR_DIGIT "0123456789"
#define MRSTR_ODIGIT "01234567"
#define MRSTR_XDIGIT "0123456789abcdefABCDEF"

#define MRSTR_ALPHA_LOW "abcdefghijklmnopqrstuvwxyz"
#define MRSTR_ALPHA_UP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MRSTR_ALPHA (MRSTR_ALPHA_LOW MRSTR_ALPHA_UP)

#define MRSTR_SPACE " \f\n\r\t\v"

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

void mrstr_s_set(mrstr_p dst, mrstr_cstr src);
void mrstr_sn_set(mrstr_p dst, mrstr_cstr src, mrstr_size len);

void mrstr_c_set(mrstr_p dst, mrstr_chr src);
void mrstr_cn_set(mrstr_p dst, mrstr_chr src, mrstr_size cnt);

void mrstr_link(mrstr_p dst, mrstr_p src);
void mrstr_swap(mrstr_p str1, mrstr_p str2);

/* iniset functions */

void mrstr_iniset(mrstr_p dst, mrstr_pc src);
void mrstr_n_iniset(mrstr_p dst, mrstr_pc src, mrstr_size len);

void mrstr_s_iniset(mrstr_p dst, mrstr_cstr src);
void mrstr_sn_iniset(mrstr_p dst, mrstr_cstr src, mrstr_size len);

void mrstr_c_iniset(mrstr_p dst, mrstr_chr src);
void mrstr_cn_iniset(mrstr_p dst, mrstr_chr src, mrstr_size cnt);

/* get functions */

mrstr_str mrstr_s_get(mrstr_pc src);
mrstr_str mrstr_sn_get(mrstr_pc src, mrstr_size len);

mrstr_chr mrstr_c_get(mrstr_pc src, mrstr_size idx);

/* concat functions */

void mrstr_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2);
void mrstr_n_concat(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_pc str2);
void mrstr_n2_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2, mrstr_size len);
void mrstr_nn_concat(mrstr_p res, mrstr_pc str1, mrstr_size len1, mrstr_pc str2, mrstr_size len2);

void mrstr_s_concat(mrstr_p res, mrstr_pc str1, mrstr_cstr str2);
void mrstr_sn_concat(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_cstr str2);

void mrstr_c_concat(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_cn_concat(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr);

/* join functions */

void mrstr_join(mrstr_p res, mrstr_pc sep, ...);
void mrstr_s_join(mrstr_p res, mrstr_cstr sep, ...);
void mrstr_c_join(mrstr_p res, mrstr_chr sep, ...);

/* remove functions */

void mrstr_remove(mrstr_p res, mrstr_pc str, mrstr_size idx);
void mrstr_n_remove(mrstr_p res, mrstr_pc str, mrstr_size idx, mrstr_size len);
void mrstr_r_remove(mrstr_p res, mrstr_pc str, mrstr_size sidx, mrstr_size eidx);

/* erase functions */

void mrstr_erase(mrstr_p res, mrstr_pc str, mrstr_pc sub);
void mrstr_n_erase(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_pc sub);

void mrstr_s_erase(mrstr_p res, mrstr_pc str, mrstr_cstr sub);
void mrstr_sn_erase(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr sub);

void mrstr_c_erase(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_cn_erase(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr);

void mrstr_cs_erase(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_csn_erase(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr chrs);

/* repeat functions */

void mrstr_repeat(mrstr_p res, mrstr_pc str, mrstr_size cnt);
void mrstr_n_repeat(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_size cnt);

/* trim functions */

void mrstr_trim(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_trim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr);
void mrstr_nn_trim(mrstr_p res, mrstr_pc str, mrstr_size llen, mrstr_size rlen, mrstr_chr chr);

void mrstr_cs_trim(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_csn_trim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr chrs);
void mrstr_csnn_trim(mrstr_p res, mrstr_pc str, mrstr_size llen, mrstr_size rlen, mrstr_cstr chrs);

void mrstr_ltrim(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_ltrim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr);

void mrstr_cs_ltrim(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_csn_ltrim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr chrs);

void mrstr_rtrim(mrstr_p res, mrstr_pc str, mrstr_chr chr);
void mrstr_n_rtrim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr);

void mrstr_cs_rtrim(mrstr_p res, mrstr_pc str, mrstr_cstr chrs);
void mrstr_csn_rtrim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr chrs);

/* replace functions */

void mrstr_replace(mrstr_p res, mrstr_pc str, mrstr_pc old, mrstr_pc new);
void mrstr_n_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_pc old, mrstr_pc new);

void mrstr_s_replace(mrstr_p res, mrstr_pc str, mrstr_cstr old, mrstr_cstr new);
void mrstr_sn_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr old, mrstr_cstr new);

void mrstr_c_replace(mrstr_p res, mrstr_pc str, mrstr_chr old, mrstr_chr new);
void mrstr_cn_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr old, mrstr_chr new);

void mrstr_cs_replace(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_chr new);
void mrstr_csn_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_chr new);

void mrstr_cs_replace2(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_cstr news);
void mrstr_csn_replace2(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_cstr news);

/* split functions */

mrstr_t *mrstr_split(mrstr_size *cnt, mrstr_pc str, mrstr_chr chr);
mrstr_t *mrstr_n_split(mrstr_size *cnt, mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_t *mrstr_cs_split(mrstr_size *cnt, mrstr_pc str, mrstr_cstr chrs);
mrstr_t *mrstr_csn_split(mrstr_size *cnt, mrstr_pc str, mrstr_size len, mrstr_cstr chrs);

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

mrstr_bool mrstr_s_equal(mrstr_pc str1, mrstr_cstr str2);
mrstr_bool mrstr_sn_equal(mrstr_pc str1, mrstr_cstr str2, mrstr_size len);

mrstr_bool mrstr_c_equal(mrstr_pc str, mrstr_chr chr);

mrstr_cmpr mrstr_cmp(mrstr_pc str1, mrstr_pc str2);
mrstr_cmpr mrstr_n_cmp(mrstr_pc str1, mrstr_pc str2, mrstr_size len);

mrstr_cmpr mrstr_s_cmp(mrstr_pc str1, mrstr_cstr str2);
mrstr_cmpr mrstr_sn_cmp(mrstr_pc str1, mrstr_cstr str2, mrstr_size len);

mrstr_cmpr mrstr_c_cmp(mrstr_pc str, mrstr_chr chr);

/* contains functions */

mrstr_bool mrstr_contains(mrstr_pc str, mrstr_pc sub);
mrstr_bool mrstr_n_contains(mrstr_pc str, mrstr_size len, mrstr_pc sub);

mrstr_bool mrstr_s_contains(mrstr_pc str, mrstr_cstr sub);
mrstr_bool mrstr_sn_contains(mrstr_pc str, mrstr_size len, mrstr_cstr sub);

mrstr_bool mrstr_c_contains(mrstr_pc str, mrstr_chr chr);
mrstr_bool mrstr_cn_contains(mrstr_pc str, mrstr_size len, mrstr_chr chr);

/* find functions */

mrstr_size mrstr_find(mrstr_pc str, mrstr_pc sub);
mrstr_size mrstr_n_find(mrstr_pc str, mrstr_size len, mrstr_pc sub);

mrstr_size mrstr_s_find(mrstr_pc str, mrstr_cstr sub);
mrstr_size mrstr_sn_find(mrstr_pc str, mrstr_size len, mrstr_cstr sub);

mrstr_size mrstr_c_find(mrstr_pc str, mrstr_chr chr);
mrstr_size mrstr_cn_find(mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_size mrstr_rfind(mrstr_pc str, mrstr_pc sub);
mrstr_size mrstr_n_rfind(mrstr_pc str, mrstr_size len, mrstr_pc sub);

mrstr_size mrstr_s_rfind(mrstr_pc str, mrstr_cstr sub);
mrstr_size mrstr_sn_rfind(mrstr_pc str, mrstr_size len, mrstr_cstr sub);

mrstr_size mrstr_c_rfind(mrstr_pc str, mrstr_chr chr);
mrstr_size mrstr_cn_rfind(mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_size *mrstr_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_pc sub);
mrstr_size *mrstr_n_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_size len, mrstr_pc sub);

mrstr_size *mrstr_s_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_cstr sub);
mrstr_size *mrstr_sn_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_size len, mrstr_cstr sub);

mrstr_size *mrstr_c_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_chr chr);
mrstr_size *mrstr_cn_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_size len, mrstr_chr chr);

/* count functions */

mrstr_size mrstr_count(mrstr_pc str, mrstr_pc sub);
mrstr_size mrstr_n_count(mrstr_pc str, mrstr_size len, mrstr_pc sub);

mrstr_size mrstr_s_count(mrstr_pc str, mrstr_cstr sub);
mrstr_size mrstr_sn_count(mrstr_pc str, mrstr_size len, mrstr_cstr sub);

mrstr_size mrstr_c_count(mrstr_pc str, mrstr_chr chr);
mrstr_size mrstr_cn_count(mrstr_pc str, mrstr_size len, mrstr_chr chr);

/* check functions */

mrstr_bool mrstr_startwith(mrstr_pc str, mrstr_pc sub);
mrstr_bool mrstr_s_startwith(mrstr_pc str, mrstr_cstr sub);
mrstr_bool mrstr_c_startwith(mrstr_pc str, mrstr_chr chr);

mrstr_bool mrstr_endwith(mrstr_pc str, mrstr_pc sub);
mrstr_bool mrstr_s_endwith(mrstr_pc str, mrstr_cstr sub);
mrstr_bool mrstr_c_endwith(mrstr_pc str, mrstr_chr chr);

mrstr_bool mrstr_isdigit(mrstr_pc str);
mrstr_bool mrstr_n_isdigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isbdigit(mrstr_pc str);
mrstr_bool mrstr_n_isbdigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isodigit(mrstr_pc str);
mrstr_bool mrstr_n_isodigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isxdigit(mrstr_pc str);
mrstr_bool mrstr_n_isxdigit(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isint(mrstr_pc str);
mrstr_bool mrstr_n_isint(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isfloat(mrstr_pc str);
mrstr_bool mrstr_n_isfloat(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isalpha(mrstr_pc str);
mrstr_bool mrstr_n_isalpha(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isalnum(mrstr_pc str);
mrstr_bool mrstr_n_isalnum(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isidentifier(mrstr_pc str);
mrstr_bool mrstr_n_isidentifier(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isspace(mrstr_pc str);
mrstr_bool mrstr_n_isspace(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isblank(mrstr_pc str);
mrstr_bool mrstr_n_isblank(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_isupper(mrstr_pc str);
mrstr_bool mrstr_n_isupper(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_islower(mrstr_pc str);
mrstr_bool mrstr_n_islower(mrstr_pc str, mrstr_size len);

mrstr_bool mrstr_are(mrstr_pc str, mrstr_chr chr);
mrstr_bool mrstr_n_are(mrstr_pc str, mrstr_size len, mrstr_chr chr);

mrstr_bool mrstr_cs_are(mrstr_pc str, mrstr_cstr chrs);
mrstr_bool mrstr_csn_are(mrstr_pc str, mrstr_size len, mrstr_cstr chrs);

/* customizable functions */

void mrstr_map(mrstr_p res, mrstr_pc str,
               mrstr_chr (*func)(mrstr_chr));
void mrstr_n_map(mrstr_p res, mrstr_pc str, mrstr_size len,
                 mrstr_chr (*func)(mrstr_chr));
void mrstr_d_map(mrstr_p res, mrstr_pc str,
                 mrstr_chr (*func)(mrstr_chr, mrstr_cdata_t));
void mrstr_dn_map(mrstr_p res, mrstr_pc str, mrstr_size len,
                  mrstr_chr (*func)(mrstr_chr, mrstr_cdata_t));

mrstr_bool mrstr_all(mrstr_pc str,
                     mrstr_bool (*func)(mrstr_chr));
mrstr_bool mrstr_n_all(mrstr_pc str, mrstr_size len,
                       mrstr_bool (*func)(mrstr_chr));
mrstr_bool mrstr_d_all(mrstr_pc str,
                       mrstr_bool (*func)(mrstr_chr, mrstr_cdata_t));
mrstr_bool mrstr_dn_all(mrstr_pc str, mrstr_size len,
                        mrstr_bool (*func)(mrstr_chr, mrstr_cdata_t));

mrstr_bool mrstr_similar(mrstr_pc str1, mrstr_pc str2,
                         mrstr_bool (*func)(mrstr_chr, mrstr_chr));
mrstr_bool mrstr_n_similar(mrstr_pc str1, mrstr_pc str2, mrstr_size len,
                           mrstr_bool (*func)(mrstr_chr, mrstr_chr));
mrstr_bool mrstr_d_similar(mrstr_pc str1, mrstr_pc str2,
                           mrstr_bool (*func)(mrstr_chr, mrstr_cdata_t, mrstr_chr, mrstr_cdata_t));
mrstr_bool mrstr_dn_similar(mrstr_pc str1, mrstr_pc str2, mrstr_size len,
                            mrstr_bool (*func)(mrstr_chr, mrstr_cdata_t, mrstr_chr, mrstr_cdata_t));

/* print functions */

void mrstr_print(mrstr_cstr format, ...);
void mrstr_v_print(mrstr_cstr format, va_list args); //
void mrstr_f_print(FILE* stream, mrstr_cstr format, ...); //
void mrstr_vf_print(FILE* stream, mrstr_cstr format, va_list args); //

mrstr_str mrstr_s_print(mrstr_cstr format, ...); //
mrstr_str mrstr_sv_print(mrstr_cstr format, va_list args); //

/* io functions */

void mrstr_inp(mrstr_p dst, FILE *src);
void mrstr_n_inp(mrstr_p dst, FILE *src, mrstr_size len);

void mrstr_out(FILE *dst, mrstr_pc src);
void mrstr_n_out(FILE *dst, mrstr_pc src, mrstr_size len);

void mrstr_rout(FILE* dst, mrstr_pc src);
void mrstr_n_rout(FILE* dst, mrstr_pc src, mrstr_size len);

/* stdio functions */

void mrstr_get(mrstr_p dst);
void mrstr_n_get(mrstr_p dst, mrstr_size len);

void mrstr_put(mrstr_pc src);
void mrstr_n_put(mrstr_pc src, mrstr_size len);

void mrstr_rput(mrstr_pc src);
void mrstr_n_rput(mrstr_pc src, mrstr_size len);

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

enum _mrstr_err_codes_
{
    NONE_ERR, // nothing
    ALOC_ERR, // allocation error
    MOVF_ERR, // memory overflow error
    ORNG_ERR, // out of range error
    LMCH_ERR, // length match error
};

typedef uint8_t mrstr_err_code_t;

extern mrstr_err_code_t mrstr_err_code;

#endif

/* alloc system */

extern void *(*__mrstr_alloc)(mrstr_size);
extern void *(*__mrstr_realloc)(void*, mrstr_size);
extern void (*__mrstr_free)(void*);

void mrstr_set_alloc_sys(
    void *(*mrstr_alloc)(mrstr_size),
    void *(*mrstr_realloc)(void*, mrstr_size),
    void (*mrstr_free)(void*));

void *mrstr_def_alloc(mrstr_size size);
void *mrstr_def_realloc(void *block, mrstr_size size);
void mrstr_def_free(void *block);

#endif /* __MRSTR__ */
