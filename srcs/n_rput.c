/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_rput(mrstr_pc, mrstr_size)
 * Writes the content of the source string in stdout in raw form up to the length
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_n_rput(mrstr_pc src, mrstr_size len)
{
    mrstr_size i;

    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    if (!len)
        return;

    for (i = 0; i < len; i++)
        switch (MRSTR_DATA(src)[i])
        {
        case '\0':
            fputs("\\0", stdout);
            break;
        case '\a':
            fputs("\\a", stdout);
            break;
        case '\b':
            fputs("\\b", stdout);
            break;
        case '\e':
            fputs("\\e", stdout);
            break;
        case '\f':
            fputs("\\f", stdout);
            break;
        case '\n':
            fputs("\\n", stdout);
            break;
        case '\r':
            fputs("\\r", stdout);
            break;
        case '\t':
            fputs("\\t", stdout);
            break;
        case '\v':
            fputs("\\v", stdout);
            break;
        case '\\':
            fputs("\\\\", stdout);
            break;
        default:
            putchar(MRSTR_DATA(src)[i]);
            break;
        }
}
