/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_rfind(mrstr_pc, mrstr_pc)
 * Returns the index of the last matched substring within the string
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_rfind(mrstr_pc str, mrstr_pc sub)
{
    mrstr_size i;

    if (str == sub)
        return 0;

    if (!MRSTR_LEN(sub))
        return MRSTR_LEN(str);

    if (MRSTR_LEN(str) < MRSTR_LEN(sub))
        return MRSTR_NF;

    if (MRSTR_LEN(str) == MRSTR_LEN(sub))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(sub), MRSTR_LEN(str)) ? MRSTR_NF : 0;

    for (i = MRSTR_LEN(str) - MRSTR_LEN(sub) + 1; i;)
        if (!memcmp(MRSTR_DATA(str) + --i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            return i;

    return MRSTR_NF;
}
