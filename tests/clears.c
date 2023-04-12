#include <utest.h>
#include <string.h>

int main()
{
    char* s1 = malloc(6);
    strcpy(s1, "Hello");

    char* s2 = malloc(12);
    strcpy(s2, "Hello World");

    mrstr_t a, b, c;
    mrstr_init2(a, s1);
    mrstr_init2(b, s2);
    mrstr_init2(c, NULL);

    mrstr_clears(a, b, c, NULL);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_clears",
                 "'a' MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_clears",
                 "'a' MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_clears",
                 "'a' MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_EXPECT(!MRSTR_DATA(b), "mrstr_clears",
                 "'b' MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(!MRSTR_LEN(b), "mrstr_clears",
                 "'b' MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_clears",
                 "'b' MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_clears",
                 "'c' MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_clears",
                 "'c' MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_clears",
                 "'c' MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    UTEST_SUCCESS("mrstr_clears");
    return 0;
}
