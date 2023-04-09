/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_start_with_str(mrstr_pc, mrstr_cstr)
 * Checks whether the string starts with the substring
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_start_with_str(mrstr_pc str, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!substr || !(slen = strlen(substr)))
        return MRSTR_TRUE;

    if (slen > MRSTR_LEN(str))
        return MRSTR_FALSE;

    return memcmp(MRSTR_DATA(str), substr, slen) ? MRSTR_FALSE : MRSTR_TRUE;
}
