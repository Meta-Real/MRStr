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
    if (str1 == str2)
        return;

    mrstr_str data = MRSTR_DATA(str1);
    MRSTR_DATA(str1) = MRSTR_DATA(str2);
    MRSTR_DATA(str2) = data;

    mrstr_size len = MRSTR_LEN(str1);
    MRSTR_LEN(str1) = MRSTR_LEN(str2);
    MRSTR_LEN(str2) = len;

    mrstr_size offset = MRSTR_OFFSET(str1);
    MRSTR_OFFSET(str1) = MRSTR_OFFSET(str2);
    MRSTR_OFFSET(str2) = offset;
}
