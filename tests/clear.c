#include <utest.h>
#include <string.h>

int main()
{
    char* s = malloc(6);
    strcpy(s, "Hello");

    mrstr_t a;
    mrstr_init2(a, s);

    mrstr_clear(a);

    UTEST_EXPECT(!MRSTR_DATA(a), "mrstr_clear",
                 "MRSTR_DATA must be NULL but it is %p\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(!MRSTR_LEN(a), "mrstr_clear",
                 "MRSTR_LEN must be 0 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_clear",
                 "MRSTR_OFFSET must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_clear");
    return 0;
}
