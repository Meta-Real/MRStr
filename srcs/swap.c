/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_swap(mrstr_p restrict, mrstr_p restrict)
 * Swaps the values of str1 and str2
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str1) and (str2) must be distinct pointers
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_swap(mrstr_p restrict str1, mrstr_p restrict str2)
{
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
