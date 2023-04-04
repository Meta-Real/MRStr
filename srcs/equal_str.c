/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_equal_str(mrstr_pc, mrstr_cstr)
 * Compares str1 and str2
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_equal_str(mrstr_pc str1, mrstr_cstr str2)
{
    if (!str2)
        return MRSTR_LEN(str1) ? MRSTR_TRUE : MRSTR_FALSE;

    mrstr_size len = strlen(str2);

    if (MRSTR_LEN(str1) != len)
        return MRSTR_FALSE;

    if (!len)
        return MRSTR_TRUE;

    return memcmp(MRSTR_DATA(str1), str2, len) ? MRSTR_TRUE : MRSTR_FALSE;
}
