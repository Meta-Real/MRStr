/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_sn_get function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s, r;
    mrstr_t a;

    s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_init2(a, s);

    r = mrstr_sn_get(a, 100);

    UTEST_EXPECT(!strcmp(r, "Hello World"), "mrstr_sn_get",
                 "test1: 'r' must be \"Hello World\" but it is \"%s\"\n",
                 r);

    free(r);
    r = mrstr_sn_get(a, 5);

    UTEST_EXPECT(!strcmp(r, "Hello"), "mrstr_sn_get",
                 "test1: 'r' must be \"Hello\" but it is \"%s\"\n",
                 r);

    free(r);
    r = mrstr_sn_get(a, 0);

    UTEST_EXPECT(!r, "mrstr_sn_get",
                 "test1: 'r' pointer must be NULL but it is %p\n",
                 r);

    mrstr_clear(a);
    r = mrstr_sn_get(a, 5);

    UTEST_EXPECT(!r, "mrstr_sn_get",
                 "test2: 'r' pointer must be NULL but it is %p\n",
                 r);

    UTEST_SUCCESS("mrstr_sn_get");
    return 0;
}
