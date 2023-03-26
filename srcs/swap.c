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
    if (MRSTR_DATA(str1) == MRSTR_DATA(str2))
        return;

    char* t_data = MRSTR_DATA(str1);
    MRSTR_DATA(str1) = MRSTR_DATA(str2);
    MRSTR_DATA(str2) = t_data;

    if (MRSTR_SIZE(str1) == MRSTR_SIZE(str2))
        return;

    size_t t_size = MRSTR_SIZE(str1);
    MRSTR_SIZE(str1) = MRSTR_SIZE(str2);
    MRSTR_SIZE(str2) = t_size;
}
