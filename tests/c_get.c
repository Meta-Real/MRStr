/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_c_get function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s;
    mrstr_t a;
    mrstr_chr r;

    s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_init2(a, s);

    r = mrstr_c_get(a, 0);

    UTEST_EXPECT(r == 'H', "mrstr_c_get",
                 "test1: 'r' must be 'H' but it is '%c'\n",
                 r);

    mrstr_clear(a);

    UTEST_SUCCESS("mrstr_c_get");
    return 0;
}
