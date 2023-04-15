/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_init function
/*/

#include <utest.h>

int main()
{
    mrstr_t a;
    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    mrstr_init(a);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_init",
                 "test1: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_init",
                 "test1: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_init",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_init");
    return 0;
}
