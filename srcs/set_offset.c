/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_set_offset(mrstr_p, mrstr_size)
 * Offsets the string by the specified offset
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_set_offset(mrstr_p str, mrstr_size offset)
{
    mrstr_size diff;

    if (MRSTR_OFFSET(str) == offset)
        return;

    if (offset < MRSTR_OFFSET(str))
    {
        diff = MRSTR_OFFSET(str) - offset;

        MRSTR_DATA(str) -= diff;
        MRSTR_LEN(str) += diff;
        MRSTR_OFFSET(str) = offset;
        return;
    }

    diff = offset - MRSTR_OFFSET(str);

    if (diff > MRSTR_LEN(str))
        diff = MRSTR_LEN(str);

    MRSTR_DATA(str) += diff;
    MRSTR_LEN(str) -= diff;
    MRSTR_OFFSET(str) = offset;
}
