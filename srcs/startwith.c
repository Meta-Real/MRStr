/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_startwith(mrstr_pc, mrstr_pc)
 * Checks whether the string starts with the substring
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_startwith(mrstr_pc str, mrstr_pc substr)
{
    if (str == substr || !MRSTR_LEN(substr))
        return MRSTR_TRUE;

    if (MRSTR_LEN(str) < MRSTR_LEN(substr))
        return MRSTR_FALSE;

    return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), MRSTR_LEN(substr)) ? MRSTR_FALSE : MRSTR_TRUE;
}
