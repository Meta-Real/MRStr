/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_rout(FILE*, mrstr_pc, mrstr_size)
 * Writes the content of the source string in the destination file in raw form up to the length
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_n_rout(FILE* dst, mrstr_pc src, mrstr_size len)
{
    mrstr_size i;

    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    if (!len)
        return;

    if (!dst)
        dst = stdout;

    for (i = 0; i < len; i++)
        switch (MRSTR_DATA(src)[i])
        {
        case '\0':
            fputs("\\0", dst);
            break;
        case '\a':
            fputs("\\a", dst);
            break;
        case '\b':
            fputs("\\b", dst);
            break;
        case '\e':
            fputs("\\e", dst);
            break;
        case '\f':
            fputs("\\f", dst);
            break;
        case '\n':
            fputs("\\n", dst);
            break;
        case '\r':
            fputs("\\r", dst);
            break;
        case '\t':
            fputs("\\t", dst);
            break;
        case '\v':
            fputs("\\v", dst);
            break;
        case '\\':
            fputs("\\\\", dst);
            break;
        default:
            fputc(MRSTR_DATA(src)[i], dst);
            break;
        }
}
