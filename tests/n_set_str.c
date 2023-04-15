/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_n_set_str function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_t a;
    mrstr_init(a);

    mrstr_n_set_str(a, "Hello World!", 5);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello"), "mrstr_n_set_str",
                 "test1: 'a' data must be \"Hello\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 5, "mrstr_n_set_str",
                 "test1: 'a' length must be 5 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_set_str",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_clear(a);
    mrstr_n_set_str(a, "Hello World!", 100);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello World!"), "mrstr_n_set_str",
                 "test2: 'a' data must be \"Hello World!\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 12, "mrstr_n_set_str",
                 "test2: 'a' length must be 12 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_set_str",
                 "test2: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_clear(a);
    mrstr_n_set_str(a, "Hello World!", 0);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_n_set_str",
                 "test3: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_n_set_str",
                 "test3: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_set_str",
                 "test3: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_set_str(a, "", 5);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_n_set_str",
                 "test4: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_n_set_str",
                 "test4: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_set_str",
                 "test4: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_set_str(a, NULL, 9);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_n_set_str",
                 "test5: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_n_set_str",
                 "test5: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_set_str",
                 "test5: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_n_set_str");
    return 0;
}
