/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_clears function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    char* s1 = malloc(6);
    strcpy(s1, "Hello");

    char* s2 = malloc(12);
    strcpy(s2, "Hello World");

    mrstr_t a, b, c;
    mrstr_init2(a, s1);
    mrstr_init2(b, s2);
    mrstr_init2(c, NULL);

    mrstr_clears(a, b, c, NULL);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_clears",
                 "test1: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_clears",
                 "test1: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_clears",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_EXPECT(!MRSTR_DATA(b), "mrstr_clears",
                 "test1: 'b' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(!MRSTR_LEN(b), "mrstr_clears",
                 "test1: 'b' length must be 0 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_clears",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_clears",
                 "test1: 'c' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_clears",
                 "test1: 'c' length must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_clears",
                 "test1: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    UTEST_SUCCESS("mrstr_clears");
    return 0;
}
