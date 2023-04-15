/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_set function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    char* s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_t a, b;
    mrstr_init2(a, s);
    mrstr_init(b);

    mrstr_set(b, a);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello World"), "mrstr_set",
                 "test1: 'b' data must be \"Hello World\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 11, "mrstr_set",
                 "test1: 'b' length must be 11 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_set",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_clears(a, b, NULL);
    mrstr_set(b, a);

    UTEST_EXPECT(!MRSTR_DATA(b), "mrstr_set",
                 "test1: 'b' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(!MRSTR_LEN(b), "mrstr_set",
                 "test1: 'b' length must be 0 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_set",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    UTEST_SUCCESS("mrstr_set");
    return 0;
}
