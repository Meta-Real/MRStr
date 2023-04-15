/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n2_count(mrstr_pc, mrstr_pc, mrstr_size)
 * Returns the number of matched substrings up to the length within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n2_count(mrstr_pc str, mrstr_pc substr, mrstr_size len)
{
    if (len > MRSTR_LEN(substr))
        len = MRSTR_LEN(substr);

    if (!len || MRSTR_LEN(str) < MRSTR_LEN(substr))
        return 0;

    if (len == MRSTR_LEN(str))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), len) ? 0 : 1;

    mrstr_size i, c = 0;
    for (i = 0; i <= MRSTR_LEN(str) - len; i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(substr), len))
            c++;

    return c;
}
