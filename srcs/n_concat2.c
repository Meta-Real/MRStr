/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_concat2(mrstr_p, mrstr_pc, mrstr_pc, mrstr_size)
 * Concatenates the first string up to the specified size and the second string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str1) pointer) (memory leak)
 *  (res) pointer must not be equal to (str2) pointer
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include "intern.h"
#include <string.h>

void mrstr_n_concat2(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_pc str2)
{
}
