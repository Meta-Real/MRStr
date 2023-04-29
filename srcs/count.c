/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_count(mrstr_pc, mrstr_pc)
 * Returns the number of matched substrings within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_count(mrstr_pc str, mrstr_pc sub)
{
    mrstr_size i, c;

    if (str == sub)
        return 1;

    if (!MRSTR_LEN(sub) || MRSTR_LEN(str) < MRSTR_LEN(sub))
        return 0;

    if (MRSTR_LEN(str) == MRSTR_LEN(sub))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(sub), MRSTR_LEN(str)) ? 0 : 1;

    c = 0;
    for (i = 0; i <= MRSTR_LEN(str) - MRSTR_LEN(sub); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            c++;

    return c;
}
