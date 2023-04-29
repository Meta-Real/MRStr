/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_count(mrstr_pc, mrstr_size, mrstr_pc)
 * Returns the number of matched substrings within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_count(mrstr_pc str, mrstr_size len, mrstr_pc sub)
{
    mrstr_size i, c;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!MRSTR_LEN(sub) || len < MRSTR_LEN(sub))
        return 0;

    if (len == MRSTR_LEN(sub))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(sub), len) ? 0 : 1;

    c = 0;
    for (i = 0; i <= len - MRSTR_LEN(sub); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            c++;

    return c;
}
