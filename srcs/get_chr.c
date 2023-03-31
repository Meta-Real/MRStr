/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_get_chr(mrstr_pc, mrstr_idx)
 * Returns the character in the specified index from the source data
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

mrstr_chr mrstr_get_chr(mrstr_pc src, mrstr_idx idx)
{
    if (idx >= MRSTR_LEN(src))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_get_chr function: index out of range (idx: %llu, len: %llu)\n",
            idx, MRSTR_LEN(src));
        abort();
#else
        err_code = ORNG_ERR;
        return '\0';
#endif
    }

    return MRSTR_DATA(src)[idx];
}
