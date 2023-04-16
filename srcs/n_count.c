/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_count(mrstr_pc, mrstr_size, mrstr_pc)
 * Returns the number of matched substrings within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_count(mrstr_pc str, mrstr_size len, mrstr_pc substr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!MRSTR_LEN(substr) || len < MRSTR_LEN(substr))
        return 0;

    if (len == MRSTR_LEN(substr))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), len) ? 0 : 1;

    mrstr_size i, c = 0;
    for (i = 0; i <= len - MRSTR_LEN(substr); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(substr), MRSTR_LEN(substr)))
            c++;

    return c;
}
