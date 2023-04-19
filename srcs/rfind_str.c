/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_rfind_str(mrstr_pc, mrstr_cstr)
 * Returns the index of the last matched substring within the string
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_rfind_str(mrstr_pc str, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!(substr && (slen = strlen(substr))))
        return MRSTR_LEN(str);

    if (slen > MRSTR_LEN(str))
        return MRSTR_NF;

    if (slen == MRSTR_LEN(str))
        return memcmp(MRSTR_DATA(str), substr, slen) ? MRSTR_NF : 0;

    mrstr_size i;
    for (i = MRSTR_LEN(str) - slen + 1; i;)
        if (!memcmp(MRSTR_DATA(str) + --i, substr, slen))
            return i;

    return MRSTR_NF;
}
