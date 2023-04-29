/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_s_end_with(mrstr_pc, mrstr_cstr)
 * Checks whether the string ends with the substring
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_s_end_with(mrstr_pc str, mrstr_cstr sub)
{
    mrstr_size slen;
    if (!(sub && (slen = strlen(sub))))
        return MRSTR_TRUE;

    if (slen > MRSTR_LEN(str))
        return MRSTR_FALSE;

    return memcmp(MRSTR_DATA(str) + MRSTR_LEN(str) - slen, sub, slen) ? MRSTR_FALSE : MRSTR_TRUE;
}
