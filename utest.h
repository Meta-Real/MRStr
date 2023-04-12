/*/
 * MetaReal String Library version 1.0.0
 *
 * Internal MRSTR library unit testing helper
/*/

#ifndef __MRSTR_UTEST__
#define __MRSTR_UTEST__

#include <mrstr.h>

#define UTEST_EXPECT(x, f, msg, ...)                                             \
    do                                                                           \
    {                                                                            \
        if (!(x))                                                                \
        {                                                                        \
            fprintf(stderr,                                                      \
                    "\033[38;2;180;0;0m(UTEST_ERR)\033[0m " f " function: " msg, \
                    __VA_ARGS__);                                                \
            abort();                                                             \
        }                                                                        \
    } while (0)

#define UTEST_SUCCESS(f) printf("\033[38;2;0;180;0m(UTEST_SCS)\033[0m %s function: test succeeded\n", f)

#endif /* __MRSTR_UTEST__ */
