/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_c_find(mrstr_pc, mrstr_chr)
 * Returns the index of the first matched character within the string
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_c_find(mrstr_pc str, mrstr_chr chr)
{
    mrstr_str ptr;

    if (!MRSTR_LEN(str))
        return MRSTR_NF;

    ptr = memchr(MRSTR_DATA(str), chr, MRSTR_LEN(str));
    return ptr ? (mrstr_size)(ptr - MRSTR_DATA(str)) : MRSTR_NF;
}
