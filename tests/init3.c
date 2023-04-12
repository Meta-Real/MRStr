#include <utest.h>
#include <string.h>

int main()
{
    mrstr_t a;
    MRSTR_DATA(a) = (mrstr_str)0xdeadbeef;
    MRSTR_LEN(a) = 300;
    MRSTR_OFFSET(a) = 12;

    char* s = malloc(6);
    strcpy(s, "Hello");

    mrstr_init3(a, s, 5, 0);

    UTEST_EXPECT(MRSTR_DATA(a) == s, "mrstr_init3",
                 "test1: 'a' data pointer must be %p but it is %p\n",
                 s, MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 5, "mrstr_init3",
                 "test1: 'a' length must be 5 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_init3",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_init3(a, s, 5, 2);

    UTEST_EXPECT(MRSTR_DATA(a) == s + 2, "mrstr_init3",
                 "test2: 'a' data pointer must be %p but it is %p\n",
                 s + 2, MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 3, "mrstr_init3",
                 "test2: 'a' length must be 3 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(MRSTR_OFFSET(a) == 2, "mrstr_init3",
                 "test2: 'a' offset must be 2 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_init3(a, s, 5, 8);

    UTEST_EXPECT(MRSTR_DATA(a) == s + 5, "mrstr_init3",
                 "test3: 'a' data pointer must be %p but it is %p\n",
                 s + 2, MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_init3",
                 "test3: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(MRSTR_OFFSET(a) == 5, "mrstr_init3",
                 "test3: 'a' offset must be 5 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_init3(a, NULL, 0, 4);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_init3",
                 "test4: 'a' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_init3",
                 "test4: 'a' length must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_init3",
                 "test4: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    free(s);

    UTEST_SUCCESS("mrstr_init3");
    return 0;
}
