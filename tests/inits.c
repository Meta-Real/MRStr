/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_inits function
/*/

#include <utest.h>

int main()
{
    mrstr_t a, b, c;

    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    MRSTR_DATA(b) = (mrstr_str)0xbadbeef;
    MRSTR_LEN(b) = 600;
    MRSTR_OFFSET(b) = 24;

    MRSTR_DATA(c) = (mrstr_str)0xdeadbee;
    MRSTR_LEN(c) = 900;
    MRSTR_OFFSET(c) = 36;

    mrstr_inits(a, b, c, NULL);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_inits",
                 "test1: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_inits",
                 "test1: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_inits",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_EXPECT(!MRSTR_DATA(b), "mrstr_inits",
                 "test1: 'b' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(!MRSTR_LEN(b), "mrstr_inits",
                 "test1: 'b' length must be 0 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_inits",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_inits",
                 "test1: 'c' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_inits",
                 "test1: 'c' length must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_inits",
                 "test1: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    UTEST_SUCCESS("mrstr_inits");
    return 0;
}
