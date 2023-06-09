/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_s_set function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_t a;
    mrstr_init(a);

    mrstr_s_set(a, "Quick sentence");

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Quick sentence"), "mrstr_s_set",
                 "test1: 'a' data must be \"Quick sentence\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 14, "mrstr_s_set",
                 "test1: 'a' length must be 14 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_s_set",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_clear(a);
    mrstr_s_set(a, NULL);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_s_set",
                 "test2: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_s_set",
                 "test2: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_s_set",
                 "test2: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_s_set(a, "");

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_s_set",
                 "test3: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_s_set",
                 "test3: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_s_set",
                 "test3: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_s_set");
    return 0;
}
