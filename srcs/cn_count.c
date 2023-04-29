/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_cn_count(mrstr_pc, mrstr_size, mrstr_chr)
 * Returns the number of matched characters within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_size mrstr_cn_count(mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    mrstr_size i, c;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return 0;

    c = 0;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] == chr)
            c++;

    return c;
}
