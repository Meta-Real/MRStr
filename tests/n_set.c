/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_n_set function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s = malloc(22);
    strcpy(s, "Some Interesting TEXT");

    mrstr_t a, b;
    mrstr_init2(a, s);
    mrstr_init(b);

    mrstr_n_set(b, a, 16);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Some Interesting"), "mrstr_n_set",
                 "test1: 'b' data must be \"Some Interesting\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 16, "mrstr_n_set",
                 "test1: 'b' length must be 16 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n_set",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_clear(b);
    mrstr_n_set(b, a, 30);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Some Interesting TEXT"), "mrstr_n_set",
                 "test2: 'b' data must be \"Some Interesting TEXT\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 21, "mrstr_n_set",
                 "test2: 'b' length must be 21 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n_set",
                 "test2: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_clear(b);
    mrstr_n_set(b, a, 0);

    UTEST_EXPECT(!MRSTR_DATA(b), "mrstr_n_set",
                 "test3: 'b' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(!MRSTR_LEN(b), "mrstr_n_set",
                 "test3: 'b' length must be 0 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n_set",
                 "test3: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_n_set(a, a, 4);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Some"), "mrstr_n_set",
                 "test4: 'a' data must be \"Some\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 4, "mrstr_n_set",
                 "test4: 'a' length must be 4 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_set",
                 "test4: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_set(a, a, 0);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_n_set",
                 "test5: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_n_set",
                 "test5: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_set",
                 "test5: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_n_set");
    return 0;
}
