/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_n_find_chr(mrstr_pc, mrstr_size, mrstr_chr)
 * Returns the index of the character within the string up to the length (MRSTR_NF if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_idx mrstr_n_find_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (!MRSTR_LEN(str) || !len)
        return MRSTR_NF;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_str ptr = memchr(MRSTR_DATA(str), chr, len);
    return ptr ? (mrstr_idx)(ptr - MRSTR_DATA(str)) : MRSTR_NF;
}
