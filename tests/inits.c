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
                 "'a' MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_inits",
                 "'a' MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_inits",
                 "'a' MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_EXPECT(!MRSTR_DATA(b), "mrstr_inits",
                 "'b' MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(!MRSTR_LEN(b), "mrstr_inits",
                 "'b' MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_inits",
                 "'b' MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_inits",
                 "'c' MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_inits",
                 "'c' MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_inits",
                 "'c' MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    UTEST_SUCCESS("mrstr_inits");
    return 0;
}
