/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_swap(mrstr_p, mrstr_p)
 * Swaps the values of the first string and the second string
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_swap(mrstr_p str1, mrstr_p str2)
{
#ifndef __MRSTR_ADV__
    if (str1 == str2)
        return;
#endif

    mrstr_str t_data = MRSTR_DATA(str1);
    MRSTR_DATA(str1) = MRSTR_DATA(str2);
    MRSTR_DATA(str2) = t_data;

    mrstr_size t_len = MRSTR_LEN(str1);
    MRSTR_LEN(str1) = MRSTR_LEN(str2);
    MRSTR_LEN(str2) = t_len;

    mrstr_idx t_offset = MRSTR_OFFSET(str1);
    MRSTR_OFFSET(str1) = MRSTR_OFFSET(str2);
    MRSTR_OFFSET(str2) = t_offset;
}
