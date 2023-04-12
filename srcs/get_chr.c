/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_chr mrstr_get_chr(mrstr_pc, mrstr_idx)
 * Returns the character at the index from the source string
 * Throws ORNG_ERR if the index exceeds the length of the source string
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <intern.h>

mrstr_chr mrstr_get_chr(mrstr_pc src, mrstr_idx idx)
{
#ifndef __MRSTR_ADV__
    if (idx >= MRSTR_LEN(src))
        mrstr_dbg_orng_err("mrstr_get_chr", idx, MRSTR_LEN(src), '\0');
#endif

    return MRSTR_DATA(src)[idx];
}
