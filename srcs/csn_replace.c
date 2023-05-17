/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_csn_replace(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr, mrstr_chr)
 * Replaces all the old characters from the string with the new character up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
 *  (olds) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_csn_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_chr new)
{
    mrstr_size olen;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (res == str)
    {
        mrstr_size i;

        if (!(len && olds && (olen = strlen(olds))))
            return;

        for (i = 0; i < len; i++)
            if (memchr(olds, MRSTR_DATA(res)[i], olen))
            {
                MRSTR_DATA(res)[i] = new;
                break;
            }

        return;
    }

    if (!MRSTR_LEN(str))
        return;

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_csn_replace", MRSTR_LEN(str) + 1, );

    if (!(olds && (olen = strlen(olds))))
    {
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    for (; MRSTR_LEN(res) < len; MRSTR_LEN(res)++)
    {
        if (memchr(olds, MRSTR_DATA(res)[MRSTR_LEN(res)], olen))
        {
            MRSTR_DATA(res)[MRSTR_LEN(res)] = new;
            break;
        }
        else
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str) + len, MRSTR_LEN(str) - len + 1);
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
