/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_n_get_str function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    char* s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_t a;
    mrstr_init2(a, s);

    char* r = mrstr_n_get_str(a, 100);

    UTEST_EXPECT(!strcmp(r, "Hello World"), "mrstr_n_get_str",
                 "test1: 'r' must be \"Hello World\" but it is \"%s\"\n",
                 r);

    free(r);
    r = mrstr_n_get_str(a, 5);

    UTEST_EXPECT(!strcmp(r, "Hello"), "mrstr_n_get_str",
                 "test1: 'r' must be \"Hello\" but it is \"%s\"\n",
                 r);

    free(r);
    r = mrstr_n_get_str(a, 0);

    UTEST_EXPECT(!r, "mrstr_n_get_str",
                 "test1: 'r' pointer must be NULL but it is %p\n",
                 r);

    mrstr_clear(a);
    r = mrstr_n_get_str(a, 5);

    UTEST_EXPECT(!r, "mrstr_n_get_str",
                 "test2: 'r' pointer must be NULL but it is %p\n",
                 r);

    UTEST_SUCCESS("mrstr_n_get_str");
    return 0;
}
