/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_ninp(mrstr_p, FILE*, mrstr_size)
 * Sets the destination data with the source file (up to the specified size)
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_ninp(mrstr_p restrict dst, FILE* restrict src, mrstr_size size)
{
    if (!size)
        return;

    if (src == stdin || !src)
    {
        MRSTR_DATA(dst) = __mrstr_das_alloc(++size);

        if (!MRSTR_DATA(dst))
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_ninp function: can not allocate %llu bytes from memory\n",
                size);
            abort();
#else
            err_code = ALOC_ERR;
            return;
#endif
        }

        fgets(MRSTR_DATA(dst), size, stdin);
        MRSTR_LEN(dst) = strlen(MRSTR_DATA(dst));

        if (!MRSTR_LEN(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst));
            return;
        }

        if (MRSTR_LEN(dst) + 1 != size)
            MRSTR_DATA(dst)[--MRSTR_LEN(dst)] = '\0';

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);

        if (!t_data)
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_ninp function: can not allocate %llu bytes from memory\n",
                MRSTR_LEN(dst) + 1);
            abort();
#else
            err_code = ALOC_ERR;
            return;
#endif
        }

        MRSTR_DATA(dst) = t_data;

        return;
    }

    fseeko64(src, 0, SEEK_END);
    MRSTR_LEN(dst) = ftello64(src);
    fseeko64(src, 0, SEEK_SET);

    if (!MRSTR_LEN(dst))
        return;

    if (MRSTR_LEN(dst) > size)
        MRSTR_LEN(dst) = size;

    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_LEN(dst) + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_inp function: can not allocate %llu bytes from memory\n",
            MRSTR_LEN(src) + 1);
        abort();
#else
        err_code = ALOC_ERR;
        return;
#endif
    }

    fread(MRSTR_DATA(dst), 1, MRSTR_LEN(dst), src);
    MRSTR_DATA(dst)[MRSTR_LEN(dst)] = '\0';
}
