/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_unmask_t mrstr_mask(mrstr_p, mrstr_size)
 * Masks the string by the specified size and returns the unmask structure for later unmasking
 * The length of the string must not change between masking and unmasking
 * The unmask structure must not change (at least the length component)
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_unmask_t mrstr_mask(mrstr_p str, mrstr_size len)
{
    mrstr_unmask_t unmask;
    unmask.olen = MRSTR_LEN(str);

    if (len >= MRSTR_LEN(str))
        return unmask;

    unmask.ochr = MRSTR_DATA(str)[len];

    MRSTR_DATA(str)[len] = '\0';
    MRSTR_LEN(str) = len;

    return unmask;
}
