/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_cn_set function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_t a;
    mrstr_init(a);

    mrstr_cn_set(a, 'R', 5);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "RRRRR"), "mrstr_cn_set",
                 "test1: 'a' data must be \"RRRRR\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 5, "mrstr_cn_set",
                 "test1: 'a' length must be 5 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_cn_set",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_clear(a);
    mrstr_cn_set(a, 'U', 0);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_cn_set",
                 "test2: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_cn_set",
                 "test2: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_cn_set",
                 "test2: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_cn_set");
    return 0;
}
