/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_rfind_chr(mrstr_pc, mrstr_size, mrstr_chr)
 * Returns the index of the last matched character within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_rfind_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_NF;

    mrstr_size sidx = MRSTR_LEN(str) - len;
    mrstr_size i;
    for (i = MRSTR_LEN(str); i != sidx;)
        if (MRSTR_DATA(str)[--i] == chr)
            return i;

    return MRSTR_NF;
}
