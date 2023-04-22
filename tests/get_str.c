/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_get_str function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    char* s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_t a;
    mrstr_init2(a, s);

    char* r = mrstr_get_str(a);

    UTEST_EXPECT(!strcmp(r, "Hello World"), "mrstr_get_str",
                 "test1: 'r' must be \"Hello World\" but it is \"%s\"\n",
                 r);

    mrstr_clear(a);
    free(r);
    r = mrstr_get_str(a);

    UTEST_EXPECT(!r, "mrstr_get_str",
                 "test2: 'r' pointer must be NULL but it is %p\n",
                 r);

    UTEST_SUCCESS("mrstr_get_str");
    return 0;
}
