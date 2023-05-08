/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_c_iniset function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_t a;
    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    mrstr_c_iniset(a, 'M');

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "M"), "mrstr_c_iniset",
                 "test1: 'a' data must be \"M\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 1, "mrstr_c_iniset",
                 "test1: 'a' length must be 1 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_c_iniset",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_clear(a);

    UTEST_SUCCESS("mrstr_c_iniset");
    return 0;
}
