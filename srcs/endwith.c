/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_endwith(mrstr_pc, mrstr_pc)
 * Checks whether the string ends with the substring
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_endwith(mrstr_pc str, mrstr_pc sub)
{
    if (str == sub || !MRSTR_LEN(sub))
        return MRSTR_TRUE;

    if (MRSTR_LEN(str) < MRSTR_LEN(sub))
        return MRSTR_FALSE;

    return memcmp(MRSTR_DATA(str) + MRSTR_LEN(str) - MRSTR_LEN(sub),
                  MRSTR_DATA(sub), MRSTR_LEN(sub)) ? MRSTR_FALSE : MRSTR_TRUE;
}
