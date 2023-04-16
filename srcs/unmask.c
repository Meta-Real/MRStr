/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_unmask(mrstr_p, mrstr_unmask_t)
 * Unmasks the string according to the unmask structure
 * The length of the string must not change between masking and unmasking
 * The unmask structure must not change (at least the length component)
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_unmask(mrstr_p str, mrstr_unmask_t unmask)
{
    if (unmask.olen == MRSTR_LEN(str))
        return;

    MRSTR_DATA(str)[MRSTR_LEN(str)] = unmask.ochr;
    MRSTR_LEN(str) = unmask.olen;
}
