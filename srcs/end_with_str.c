/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_end_with_str(mrstr_pc restrict, mrstr_cstr restrict)
 * Checks that the string ends with the substring
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_end_with_str(mrstr_pc restrict str, mrstr_cstr restrict substr)
{
    if (!substr)
        return MRSTR_TRUE;

    mrstr_size len = strlen(substr);

    if (!len)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (!memcmp(MRSTR_DATA(str) + MRSTR_LEN(str) - len, substr, len))
        return MRSTR_TRUE;
    return MRSTR_FALSE;
}
