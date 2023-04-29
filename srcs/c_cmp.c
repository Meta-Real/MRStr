/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_cmpr mrstr_c_cmp(mrstr_pc, mrstr_chr)
 * Compares the string with the character and returns their signed difference
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_cmpr mrstr_c_cmp(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return chr;

    if (MRSTR_LEN(str) != 1)
        return -MRSTR_DATA(str)[1];

    return chr - *MRSTR_DATA(str);
}
