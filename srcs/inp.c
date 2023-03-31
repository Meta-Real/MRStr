/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_inp(mrstr_p, FILE*)
 * Sets the destination data with the source file
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_inp(mrstr_p restrict dst, FILE* restrict src)
{
    if (src == stdin || !src)
    {
        MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_DEF_SIZE);

        if (!MRSTR_DATA(dst))
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_inp function: can not allocate %llu bytes from memory\n",
                MRSTR_DEF_SIZE);
            abort();
#else
            err_code = ALOC_ERR;
            return;
#endif
        }

        mrstr_size alloc = MRSTR_DEF_SIZE;
        mrstr_str t_data;

        mrstr_chr c;
        while ((c = fgetc(stdin)) != '\n')
        {
            if (MRSTR_LEN(dst) == alloc)
            {
                t_data = __mrstr_das_realloc(MRSTR_DATA(dst), alloc += MRSTR_DEF_SIZE);

                if (!t_data)
                {
#ifdef __MRSTR_DBG__
                    fprintf(stderr,
                        "(MRSTR_ERR) mrstr_inp function: can not allocate %llu bytes from memory\n",
                        alloc);
                    abort();
#else
                    err_code = ALOC_ERR;
                    return;
#endif
                }

                MRSTR_DATA(dst) = t_data;
            }

            MRSTR_DATA(dst)[MRSTR_LEN(dst)++] = c;
        }

        if (!MRSTR_LEN(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst));
            return;
        }

        t_data = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);

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

        MRSTR_DATA(dst) = t_data;
        MRSTR_DATA(dst)[MRSTR_LEN(dst)] = '\0';

        return;
    }

    fseeko64(src, 0, SEEK_END);
    MRSTR_LEN(dst) = ftello64(src);
    fseeko64(src, 0, SEEK_SET);

    if (!MRSTR_LEN(dst))
        return;

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
