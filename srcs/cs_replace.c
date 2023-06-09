/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_cs_replace(mrstr_p, mrstr_pc, mrstr_cstr, mrstr_chr)
 * Replaces all the old characters from the string with the new character
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
 *  (olds) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_cs_replace(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_chr new)
{
    mrstr_size olen;

    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_size i;

        if (!(olds && (olen = strlen(olds))))
            return;

        for (i = 0; i < MRSTR_LEN(res); i++)
            if (memchr(olds, MRSTR_DATA(res)[i], olen))
            {
                MRSTR_DATA(res)[i] = new;
                break;
            }

        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_cs_replace", MRSTR_LEN(str) + 1, );

    if (!(olds && (olen = strlen(olds))))
    {
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
    {
        if (memchr(olds, MRSTR_DATA(res)[MRSTR_LEN(res)], olen))
        {
            MRSTR_DATA(res)[MRSTR_LEN(res)] = new;
            break;
        }
        else
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
