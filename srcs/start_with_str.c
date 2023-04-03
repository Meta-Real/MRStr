/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_start_with_str(mrstr_pc, mrstr_cstr)
 * Checks if the string starts with the substring
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_start_with_str(mrstr_pc str, mrstr_cstr substr)
{
    if (!substr)
        return MRSTR_TRUE;

    mrstr_size len = strlen(substr);

    if (!len)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (!memcmp(MRSTR_DATA(str), substr, len))
        return MRSTR_TRUE;
    return MRSTR_FALSE;
}
