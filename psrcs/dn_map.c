/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_dn_map(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr (*)(mrstr_chr, mrstr_chr_data_pc))
 * Replaces all the characters of the string up to the length by their alternative
 * The function parameter must return the alternative of each character of the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
/*/

#include <intern.h>
