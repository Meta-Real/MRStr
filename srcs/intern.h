/*/
 * MetaReal String Library version 1.0.0
 *
 * Internal MRSTR library header file
/*/

#include <mrstr.h>

#define MRSTR_DEF_LEN 128ULL

#ifdef __MRSTR_DBG__

#define mrstr_dbg_aloc_err(f, s, r)                                               \
    do                                                                            \
    {                                                                             \
        fprintf(stderr,                                                           \
            "(MRSTR_ERR) %s function: can not allocate %llu bytes from memory\n", \
            f, s                                                                  \
        );                                                                        \
        abort();                                                                  \
    } while (0)

#define mrstr_dbg_orng_err(f, i, s, r)                                              \
    do                                                                              \
    {                                                                               \
        fprintf(stderr,                                                             \
            "(MRSTR_ERR) %s function: index out of range (idx: %llu, len: %llu)\n", \
            f, i, s);                                                               \
        abort();                                                                    \
    } while (0)

#else

#define mrstr_dbg_aloc_err(f, s, r) \
    do                              \
    {                               \
        err_code = ALOC_ERR;        \
        return r;                   \
    } while (0)

#define mrstr_dbg_orng_err(f, i, s, r) \
    do                                 \
    {                                  \
        err_code = ORNG_ERR;           \
        return r;                      \
    } while (0)

#endif
