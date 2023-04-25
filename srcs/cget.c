/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_chr mrstr_cget(mrstr_pc, mrstr_size)
 * Returns the character at the index from the source string
 * Throws ORNG_ERR if the index exceeds the length of the source string
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <intern.h>

mrstr_chr mrstr_cget(mrstr_pc src, mrstr_size idx)
{
    if (idx >= MRSTR_LEN(src))
        mrstr_dbg_orng_err("mrstr_cget", idx, MRSTR_LEN(src), '\0');

    return MRSTR_DATA(src)[idx];
}
