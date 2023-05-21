/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_concat function
/*/

#include <utest.h>
#include <string.h>

int main()
{
    mrstr_str s1, s2;
    mrstr_t a, b, c, d;

    s1 = malloc(7);
    strcpy(s1, "Hello ");

    s2 = malloc(6);
    strcpy(s2, "World");

    mrstr_init2(a, s1);
    mrstr_init2(b, s2);
    mrstr_inits(c, d, NULL);

    mrstr_concat(c, a, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello World"), "mrstr_concat",
                 "test1: 'c' data must be \"Hello World\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 11, "mrstr_concat",
                 "test1: 'c' length must be 11 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_concat",
                 "test1: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_concat(c, a, d);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello "), "mrstr_concat",
                 "test2: 'c' data must be \"Hello \" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 6, "mrstr_concat",
                 "test2: 'c' length must be 6 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_concat",
                 "test2: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_concat(c, d, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "World"), "mrstr_concat",
                 "test3: 'c' data must be \"World\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 5, "mrstr_concat",
                 "test3: 'c' length must be 5 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_concat",
                 "test3: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_concat(c, d, d);

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_concat",
                 "test4: 'c' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_concat",
                 "test4: 'c' length must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_concat",
                 "test4: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_concat(a, a, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello World"), "mrstr_concat",
                 "test5: 'a' data must be \"Hello World\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 11, "mrstr_concat",
                 "test5: 'a' length must be 11 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_concat",
                 "test5: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_concat(a, a, d);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello World"), "mrstr_concat",
                 "test6: 'a' data must be \"Hello World\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 11, "mrstr_concat",
                 "test6: 'a' length must be 11 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_concat",
                 "test6: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_concat(a, a, a);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello WorldHello World"), "mrstr_concat",
                 "test7: 'a' data must be \"Hello WorldHello World\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 22, "mrstr_concat",
                 "test7: 'a' length must be 22 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_concat",
                 "test7: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_concat(b, a, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello WorldHello WorldWorld"), "mrstr_concat",
                 "test8: 'b' data must be \"Hello WorldHello WorldWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 27, "mrstr_concat",
                 "test8: 'b' length must be 27 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_concat",
                 "test8: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_concat(b, d, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello WorldHello WorldWorld"), "mrstr_concat",
                 "test9: 'b' data must be \"Hello WorldHello WorldWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 27, "mrstr_concat",
                 "test9: 'b' length must be 27 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_concat",
                 "test9: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_clears(a, b, c, NULL);

    UTEST_SUCCESS("mrstr_concat");
    return 0;
}
