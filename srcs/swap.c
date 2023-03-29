/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_swap(mrstr_p, mrstr_p)
 * Swaps the values of str1 and str2
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_swap(mrstr_p str1, mrstr_p str2)
{
    char* t_data = MRSTR_DATA(str1);
    MRSTR_DATA(str1) = MRSTR_DATA(str2);
    MRSTR_DATA(str2) = t_data;

    size_t t_size = MRSTR_SIZE(str1);
    MRSTR_SIZE(str1) = MRSTR_SIZE(str2);
    MRSTR_SIZE(str2) = t_size;

    t_size = MRSTR_LEN(str1);
    MRSTR_LEN(str1) = MRSTR_LEN(str2);
    MRSTR_LEN(str2) = t_size;

    t_size = MRSTR_OFFSET(str1);
    MRSTR_OFFSET(str1) = MRSTR_OFFSET(str2);
    MRSTR_OFFSET(str2) = t_size;
}
