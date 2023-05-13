/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_rput(mrstr_pc)
 * Writes the content of the source string in stdout in raw form
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_rput(mrstr_pc src)
{
    mrstr_size i;

    if (!MRSTR_LEN(src))
        return;

    for (i = 0; i < MRSTR_LEN(src); i++)
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
