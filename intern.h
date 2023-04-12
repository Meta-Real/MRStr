/*/
 * MetaReal String Library version 1.0.0
 *
 * Internal MRSTR library header file
/*/

#ifndef __MRSTR_INTERN__
#define __MRSTR_INTERN__

#include <mrstr.h>

#define MRSTR_DEF_LEN 128ULL
#define MRSTR_DIFF_CHR 'a' - 'A'

#ifdef __MRSTR_DBG__

#define mrstr_dbg_aloc_err(f, s, r)                                                   \
    do                                                                                \
    {                                                                                 \
        fprintf(stderr,                                                               \
                "(MRSTR_ERR) %s function: can not allocate %llu bytes from memory\n", \
                f, s);                                                                \
        abort();                                                                      \
    } while (0)

#define mrstr_dbg_movf_err(f, r)                                               \
    do                                                                         \
    {                                                                          \
        fprintf(stderr,                                                        \
                "(MRSTR_ERR) %s function: memory overflow while allocating\n", \
                f);                                                            \
        abort();                                                               \
    } while (0)

#define mrstr_dbg_orng_err(f, i, s, r)                                                  \
    do                                                                                  \
    {                                                                                   \
        fprintf(stderr,                                                                 \
                "(MRSTR_ERR) %s function: index out of range (idx: %llu, len: %llu)\n", \
                f, i, s);                                                               \
        abort();                                                                        \
    } while (0)

#define mrstr_dbg_lmch_err(f, s1, s2, r)                                                  \
    do                                                                                    \
    {                                                                                     \
        fprintf(stderr,                                                                   \
                "(MRSTR_ERR) %s function: string lengths do not match (%llu and %llu)\n", \
                f, s1, s2);                                                               \
        abort();                                                                          \
    } while (0)

#else

#define mrstr_dbg_aloc_err(f, s, r) \
    do                              \
    {                               \
        err_code = ALOC_ERR;        \
        return r;                   \
    } while (0)

#define mrstr_dbg_movf_err(f, r) \
    do                           \
    {                            \
        err_code = MOVF_ERR;     \
        return r;                \
    } while (0)

#define mrstr_dbg_orng_err(f, i, s, r) \
    do                                 \
    {                                  \
        err_code = ORNG_ERR;           \
        return r;                      \
    } while (0)

#define mrstr_dbg_lmch_err(f, i, s, r) \
    do                                 \
    {                                  \
        err_code = LMCH_ERR;           \
        return r;                      \
    } while (0)

#endif

#endif /* __MRSTR_INTERN__ */
