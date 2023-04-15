/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_count(mrstr_pc, mrstr_pc)
 * Returns the number of matched substrings within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_count(mrstr_pc str, mrstr_pc substr)
{
    if (str == substr)
        return 1;

    if (!MRSTR_LEN(substr) || MRSTR_LEN(str) < MRSTR_LEN(substr))
        return 0;

    if (MRSTR_LEN(str) == MRSTR_LEN(substr))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), MRSTR_LEN(str)) ? 0 : 1;

    mrstr_size i, c = 0;
    for (i = 0; i <= MRSTR_LEN(str) - MRSTR_LEN(substr); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(substr), MRSTR_LEN(substr)))
            c++;

    return c;
}
