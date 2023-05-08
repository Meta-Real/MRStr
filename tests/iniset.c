/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_iniset function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s = malloc(12);
    strcpy(s, "Hello World");

    mrstr_t a, b;
    mrstr_init2(a, s);

    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    mrstr_iniset(b, a);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello World"), "mrstr_iniset",
                 "test1: 'b' data must be \"Hello World\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 11, "mrstr_iniset",
                 "test1: 'b' length must be 11 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_iniset",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_clears(a, b, NULL);

    MRSTR_DATA(b) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    mrstr_iniset(b, a);

    UTEST_EXPECT(!MRSTR_DATA(b), "mrstr_iniset",
                 "test1: 'b' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(!MRSTR_LEN(b), "mrstr_iniset",
                 "test1: 'b' length must be 0 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_iniset",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    UTEST_SUCCESS("mrstr_iniset");
    return 0;
}
