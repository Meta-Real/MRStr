/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_remove_chrs(mrstr_p, mrstr_pc, mrstr_cstr)
 * Removes the matched characters from the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_remove_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs)
{
    if (!MRSTR_LEN(str))
        return;

    mrstr_size clen;
    if (!(chrs && (clen = strlen(chrs))))
        return;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str) && !memchr(chrs, MRSTR_DATA(str)[i], clen); i++);

    if (res == str)
    {
        if (i == MRSTR_LEN(res))
            return;

        mrstr_size j;
        for (j = i++; i < MRSTR_LEN(res); i++)
            if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
                MRSTR_DATA(res)[j++] = MRSTR_DATA(res)[i];

        if (!j)
            mrstr_data_free("mrstr_remove_chrs");

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               j + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_remove_chrs", j + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[j] = '\0';
        MRSTR_LEN(res) = j;
        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_remove_chrs", MRSTR_LEN(str) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), i);

    if (i == MRSTR_LEN(str))
    {
        MRSTR_DATA(res)[i] = '\0';
        MRSTR_LEN(res) = i;
        return;
    }

    mrstr_size j;
    for (j = i++; i < MRSTR_LEN(str); i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            MRSTR_DATA(res)[j++] = MRSTR_DATA(str)[i];

    if (!j)
    {
        __mrstr_das_free(MRSTR_DATA(res));
        MRSTR_DATA(res) = NULL;
        return;
    }

    mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res), j + 1);
    if (!t_data)
        mrstr_dbg_aloc_err("mrstr_remove_chrs", j + 1, );

    MRSTR_DATA(res) = t_data;
    MRSTR_DATA(res)[j] = '\0';
    MRSTR_LEN(res) = j;
    return;
}
