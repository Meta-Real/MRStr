/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_clear function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s = malloc(6);
    strcpy(s, "Hello");

    mrstr_t a;
    mrstr_init2(a, s);

    mrstr_clear(a);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_clear",
                 "test1: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_clear",
                 "test1: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_clear",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_clear");
    return 0;
}
