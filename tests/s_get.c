/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_s_get function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_t a;
    mrstr_init2(a, s);

    mrstr_str r = mrstr_s_get(a);

    UTEST_EXPECT(!strcmp(r, "Hello World"), "mrstr_s_get",
                 "test1: 'r' must be \"Hello World\" but it is \"%s\"\n",
                 r);

    mrstr_clear(a);
    free(r);
    r = mrstr_s_get(a);

    UTEST_EXPECT(!r, "mrstr_s_get",
                 "test2: 'r' pointer must be NULL but it is %p\n",
                 r);

    UTEST_SUCCESS("mrstr_s_get");
    return 0;
}
