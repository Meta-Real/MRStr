/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_swap function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s1 = malloc(6);
    strcpy(s1, "Hello");

    mrstr_str s2 = malloc(12);
    strcpy(s2, "Hello Again");

    mrstr_t a, b;
    mrstr_init2(a, s1);
    mrstr_init3(b, s2, 11, 3);

    mrstr_swap(a, b);

    UTEST_EXPECT(MRSTR_DATA(a) == s2 + 3, "mrstr_swap",
                 "test1: 'a' data pointer must be %p but it is %p\n",
                 s2, MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 8, "mrstr_swap",
                 "test1: 'a' length must be 8 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(MRSTR_OFFSET(a) == 3, "mrstr_swap",
                 "test1: 'a' offset must be 3 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_EXPECT(MRSTR_DATA(b) == s1, "mrstr_swap",
                 "test1: 'b' data pointer must be %p but it is %p\n",
                 s1, MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 5, "mrstr_swap",
                 "test1: 'b' length must be 5 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_swap",
                 "test1: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    UTEST_SUCCESS("mrstr_swap");
    return 0;
}
