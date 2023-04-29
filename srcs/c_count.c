/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_c_count(mrstr_pc, mrstr_chr)
 * Returns the number of matched characters within the string
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_size mrstr_c_count(mrstr_pc str, mrstr_chr chr)
{
    mrstr_size i, c;

    if (!MRSTR_LEN(str))
        return 0;

    c = 0;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] == chr)
            c++;

    return c;
}
