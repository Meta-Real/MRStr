/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_rfind(mrstr_pc, mrstr_pc)
 * Returns the index of the last matched substring within the string
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_rfind(mrstr_pc str, mrstr_pc substr)
{
    if (str == substr)
        return 0;

    if (!MRSTR_LEN(substr))
        return MRSTR_LEN(str);

    if (MRSTR_LEN(str) < MRSTR_LEN(substr))
        return MRSTR_NF;

    if (MRSTR_LEN(str) == MRSTR_LEN(substr))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), MRSTR_LEN(str)) ? MRSTR_NF : 0;

    mrstr_size i;
    for (i = MRSTR_LEN(str) - MRSTR_LEN(substr); i; i--)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(substr), MRSTR_LEN(substr)))
            return i;

    return MRSTR_NF;
}