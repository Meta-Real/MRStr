/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_s_iniset function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_t a;
    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    mrstr_s_iniset(a, "Quick sentence");

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Quick sentence"), "mrstr_s_iniset",
                 "test1: 'a' data must be \"Quick sentence\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 14, "mrstr_s_iniset",
                 "test1: 'a' length must be 14 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_s_iniset",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_clear(a);

    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    mrstr_s_iniset(a, NULL);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_s_iniset",
                 "test2: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_s_iniset",
                 "test2: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_s_iniset",
                 "test2: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    mrstr_s_iniset(a, "");

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_s_iniset",
                 "test3: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_s_iniset",
                 "test3: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_s_iniset",
                 "test3: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_s_iniset");
    return 0;
}
