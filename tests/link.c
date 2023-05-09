/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_link function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s;
    mrstr_t a, b;

    s = malloc(6);
    strcpy(s, "Hello");

    mrstr_init2(b, s);

    mrstr_link(a, b);

    UTEST_EXPECT(MRSTR_DATA(a) == s, "mrstr_link",
                 "test1: 'a' data pointer must be %p but it is %p\n",
                 s, MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 5, "mrstr_link",
                 "test1: 'a' length must be 5 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_link",
                 "test1: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    UTEST_SUCCESS("mrstr_link");
    return 0;
}
