/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_get_chr function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    char* s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_t a;
    mrstr_init2(a, s);

    char r = mrstr_get_chr(a, 0);

    UTEST_EXPECT(r == 'H', "mrstr_get_chr",
                 "test1: 'r' must be 'H' but it is '%c'\n",
                 r);

    mrstr_clear(a);

    UTEST_SUCCESS("mrstr_get_str");
    return 0;
}
