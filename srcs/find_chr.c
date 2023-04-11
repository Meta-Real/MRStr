/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_find_chr(mrstr_pc, mrstr_chr)
 * Returns the index of the character within the string (MRSTR_NF if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_idx mrstr_find_chr(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return MRSTR_NF;

    mrstr_str ptr = memchr(MRSTR_DATA(str), chr, MRSTR_LEN(str));
    return ptr ? (mrstr_idx)(ptr - MRSTR_DATA(str)) : MRSTR_NF;
}
