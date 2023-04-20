/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_are_chrs(mrstr_pc, mrstr_cstr)
 * Checks whether the string consists of only the specified characters
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_are_chrs(mrstr_pc str, mrstr_cstr chrs)
{
    mrstr_size clen;
    if (!(MRSTR_LEN(str) && chrs && (clen = strlen(chrs))))
        return MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
