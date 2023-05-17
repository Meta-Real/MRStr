/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_replace(mrstr_p, mrstr_pc, mrstr_pc, mrstr_pc)
 * Replaces all the old substrings from the string with the new substring
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
 *  (old) pointer must be valid
 *  (new) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_replace(mrstr_p res, mrstr_pc str, mrstr_pc old, mrstr_pc new)
{
    mrstr_str tdata, data;
    mrstr_size len, i, j, diff;

    if (!MRSTR_LEN(str))
    {
        if (res == old || res == new)
        {
            MRSTR_LEN(res) = 0;

            if (!MRSTR_OFFSET(res))
            {
                __mrstr_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = NULL;
                return;
            }

            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_replace", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        return;
    }

    if (old == new || MRSTR_LEN(str) < MRSTR_LEN(old))
    {
        if (res == str)
            return;

        MRSTR_LEN(res) = MRSTR_LEN(str);

        if (res == old || res == new)
        {
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_replace", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(res) + 1);
            return;
        }

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_replace", MRSTR_LEN(res) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(res) + 1);
        return;
    }

    if (!MRSTR_LEN(old))
    {
        if (!MRSTR_LEN(new))
        {
            if (res == str)
                return;

            MRSTR_LEN(res) = MRSTR_LEN(str);

            if (res == old || res == new)
            {
                tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
                if (!tdata)
                    mrstr_dbg_aloc_err("mrstr_replace", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
                memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(res) + 1);
                return;
            }

            MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
            if (!MRSTR_DATA(res))
                mrstr_dbg_aloc_err("mrstr_replace", MRSTR_LEN(res) + 1, );

            memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(res) + 1);
            return;
        }

        len = MRSTR_LEN(str) * (MRSTR_LEN(new) + 1);
        data = __mrstr_alloc(len + 1);
        if (!data)
            mrstr_dbg_aloc_err("mrstr_replace", len + 1, );

        for (i = 0, j = 0; i < len; i += MRSTR_LEN(new), j++)
        {
            data[i++] = MRSTR_DATA(str)[j];
            memcpy(data + i, MRSTR_DATA(new), MRSTR_LEN(new));
        }

        data[i] = '\0';

        if (res == str || res == old || res == new)
        {
            if (!MRSTR_OFFSET(res))
            {
                __mrstr_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = data;
                MRSTR_LEN(res) = i;
                return;
            }

            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), i + MRSTR_OFFSET(res) + 1);
            if (!tdata)
            {
                __mrstr_free(data);
                mrstr_dbg_aloc_err("mrstr_replace", i + MRSTR_OFFSET(res) + 1, );
            }

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), data, i + 1);
            MRSTR_LEN(res) = i;
            return;
        }

        MRSTR_DATA(res) = data;
        MRSTR_LEN(res) = len;
        return;
    }

    len = MRSTR_LEN(str) + 1;
    diff = MRSTR_LEN(new) - MRSTR_LEN(old);

    data = __mrstr_alloc(len);
    if (!data)
        mrstr_dbg_aloc_err("mrstr_replace", len, );

    if (diff)
        for (i = 0, j = 0; j < MRSTR_LEN(str) - MRSTR_LEN(old);)
        {
            if (memcmp(MRSTR_DATA(str) + j, MRSTR_DATA(old), MRSTR_LEN(old)))
            {
                data[i++] = MRSTR_DATA(str)[j++];
                continue;
            }

            tdata = __mrstr_realloc(data, len += diff);
            if (!tdata)
            {
                __mrstr_free(data);
                mrstr_dbg_aloc_err("mrstr_replace", len, );
            }

            data = tdata;
            memcpy(data + i, MRSTR_DATA(new), MRSTR_LEN(new));

            i += MRSTR_LEN(new);
            j += MRSTR_LEN(old);
        }
    else
        for (i = 0, j = 0; j < MRSTR_LEN(str) - MRSTR_LEN(old);)
        {
            if (memcmp(MRSTR_DATA(str) + j, MRSTR_DATA(old), MRSTR_LEN(old)))
            {
                data[i++] = MRSTR_DATA(str)[j++];
                continue;
            }

            memcpy(data + i, MRSTR_DATA(new), MRSTR_LEN(new));

            i += MRSTR_LEN(new);
            j += MRSTR_LEN(old);
        }

    memcpy(data + i, MRSTR_DATA(str) + j, MRSTR_LEN(str) - j + 1);

    if (res == str || res == old || res == new)
    {
        if (!MRSTR_OFFSET(res))
        {
            __mrstr_free(MRSTR_DATA(res));
            MRSTR_DATA(res) = data;
            MRSTR_LEN(res) = len - 1;
            return;
        }

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res));
        if (!tdata)
        {
            __mrstr_free(data);
            mrstr_dbg_aloc_err("mrstr_replace", len + MRSTR_OFFSET(res), );
        }

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res), data, len);
        MRSTR_LEN(res) = len - 1;
        return;
    }

    MRSTR_DATA(res) = data;
    MRSTR_LEN(res) = len - 1;
}
