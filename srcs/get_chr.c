/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_chr mrstr_get_chr(mrstr_pc, mrstr_idx)
 * Returns the character in the specified index from the source data
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <intern.h>

mrstr_chr mrstr_get_chr(mrstr_pc src, mrstr_idx idx)
{
    if (idx >= MRSTR_LEN(src))
        mrstr_dbg_orng_err("mrstr_get_chr", idx, MRSTR_LEN(src), '\0');

    return MRSTR_DATA(src)[idx];
}
