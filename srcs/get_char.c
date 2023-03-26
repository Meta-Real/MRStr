/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_get_char(mrstr_pc, size_t)
 * Returns the character in the specified index from the source data
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

char mrstr_get_char(mrstr_pc src, size_t idx)
{
    if (idx >= MRSTR_SIZE(src))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_get_char function: index out of range (%llu out of %llu range)\n",
            idx, MRSTR_SIZE(src));
        abort();
#else
        err_code = ORNG_ERR;
        return '\0';
#endif
    }

    return MRSTR_DATA(src)[idx];
}
