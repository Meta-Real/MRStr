/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_s_count(mrstr_pc, mrstr_cstr)
 * Returns the number of matched substrings within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_s_count(mrstr_pc str, mrstr_cstr sub)
{
    mrstr_size slen, i, c;

    if (!(sub && (slen = strlen(sub))) || slen > MRSTR_LEN(str))
        return 0;

    if (slen == MRSTR_LEN(str))
        return memcmp(MRSTR_DATA(str), sub, slen) ? 0 : 1;

    c = 0;
    for (i = 0; i <= MRSTR_LEN(str) - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, sub, slen))
            c++;

    return c;
}
