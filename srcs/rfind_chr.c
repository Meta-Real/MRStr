/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_rfind_chr(mrstr_pc, mrstr_chr)
 * Returns the index of the last matched character within the string
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_rfind_chr(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return MRSTR_NF;

    mrstr_size i;
    for (i = MRSTR_LEN(str) - 1; i; i--)
        if (MRSTR_DATA(str)[i] == chr)
            return i;

    return MRSTR_NF;
}
