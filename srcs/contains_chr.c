/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_contains_chr(mrstr_pc, mrstr_chr)
 * Checks the existence of the character within the string
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_contains_chr(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return MRSTR_FALSE;

    return memchr(MRSTR_DATA(str), chr, MRSTR_LEN(str)) ? MRSTR_TRUE : MRSTR_FALSE;
}
