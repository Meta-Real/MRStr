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

    mrstr_init2(a, s);

    UTEST_EXPECT(MRSTR_DATA(a) == s, "mrstr_init2",
                 "MRSTR_DATA must be %p but it is %p\n",
                 s, MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 5, "mrstr_init2",
                 "MRSTR_LEN must be 5 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_init2",
                 "MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_init2(a, NULL);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_init2",
                 "MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_init2",
                 "MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_init2",
                 "MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    free(s);

    UTEST_SUCCESS("mrstr_init2");
    return 0;
}
