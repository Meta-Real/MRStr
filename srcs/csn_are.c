/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_csn_are(mrstr_pc, mrstr_size, mrstr_cstr)
 * Checks whether the string consists of only the specified characters up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_csn_are(mrstr_pc str, mrstr_size len, mrstr_cstr chrs)
{
    mrstr_size clen, i;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!(len && chrs && (clen = strlen(chrs))))
        return MRSTR_TRUE;

    for (i = 0; i < len; i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
