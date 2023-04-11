/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_remove(mrstr_p, mrstr_pc, mrstr_idx)
 * Removes the character from the string at the index
 * Throws ORNG_ERR if the index exceeds the length of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_remove(mrstr_p res, mrstr_pc str, mrstr_idx idx)
{
    if (idx >= MRSTR_LEN(str))
        mrstr_dbg_orng_err("mrstr_remove", idx, MRSTR_LEN(str), );

    if (res == str)
    {
        if (MRSTR_LEN(res) == 1)
        {
            MRSTR_LEN(res) = 0;

            if (!MRSTR_OFFSET(res))
            {
                __mrstr_das_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = NULL;
                return;
            }

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_remove", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        memmove(MRSTR_DATA(res) + idx, MRSTR_DATA(res) + idx + 1, MRSTR_LEN(res) - idx);

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res));
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_remove", MRSTR_LEN(res) + MRSTR_OFFSET(res), );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_LEN(res)--;
        return;
    }

    if (MRSTR_LEN(str) == 1)
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str));
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_remove", MRSTR_LEN(res), );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), idx);
    memcpy(MRSTR_DATA(res) + idx, MRSTR_DATA(str) + idx + 1, MRSTR_LEN(str) - idx);
    MRSTR_LEN(res) = MRSTR_LEN(str) - 1;
}
