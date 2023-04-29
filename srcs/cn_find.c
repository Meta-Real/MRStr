/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_cn_find(mrstr_pc, mrstr_size, mrstr_chr)
 * Returns the index of the first matched character within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_cn_find(mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    mrstr_str ptr;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_NF;

    ptr = memchr(MRSTR_DATA(str), chr, len);
    return ptr ? (mrstr_size)(ptr - MRSTR_DATA(str)) : MRSTR_NF;
}
