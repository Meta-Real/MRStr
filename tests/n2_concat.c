/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_n2_concat function
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

    mrstr_n2_concat(c, a, b, 3);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello Wor"), "mrstr_n2_concat",
                 "test1: 'c' data must be \"Hello Wor\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 9, "mrstr_n2_concat",
                 "test1: 'c' length must be 9 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n2_concat",
                 "test1: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n2_concat(c, a, b, 100);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello World"), "mrstr_n2_concat",
                 "test2: 'c' data must be \"Hello World\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 11, "mrstr_n2_concat",
                 "test2: 'c' length must be 11 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n2_concat",
                 "test2: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n2_concat(c, a, b, 0);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello "), "mrstr_n2_concat",
                 "test3: 'c' data must be \"World\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 6, "mrstr_n2_concat",
                 "test3: 'c' length must be 6 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n2_concat",
                 "test3: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n2_concat(c, d, a, 2);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "He"), "mrstr_n2_concat",
                 "test4: 'c' data must be \"He\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 2, "mrstr_n2_concat",
                 "test4: 'c' length must be 2 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n2_concat",
                 "test4: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n2_concat(c, d, a, 0);

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_n2_concat",
                 "test5: 'c' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_n2_concat",
                 "test5: 'c' length must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n2_concat",
                 "test5: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_n2_concat(c, a, d, 10);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello "), "mrstr_n2_concat",
                 "test6: 'c' data must be \"Hello \" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 6, "mrstr_n2_concat",
                 "test6: 'c' length must be 6 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n2_concat",
                 "test6: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n2_concat(c, d, d, 58);

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_n2_concat",
                 "test7: 'c' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_n2_concat",
                 "test7: 'c' length must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n2_concat",
                 "test7: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_n2_concat(a, a, b, 2);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello Wo"), "mrstr_n2_concat",
                 "test8: 'a' data must be \"Hello Wo\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 8, "mrstr_n2_concat",
                 "test8: 'a' length must be 8 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n2_concat",
                 "test8: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n2_concat(a, a, b, 200);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello WoWorld"), "mrstr_n2_concat",
                 "test9: 'a' data must be \"Hello WoWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 13, "mrstr_n2_concat",
                 "test9: 'a' length must be 13 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n2_concat",
                 "test9: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n2_concat(a, a, b, 0);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello WoWorld"), "mrstr_n2_concat",
                 "test10: 'a' data must be \"World\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 13, "mrstr_n2_concat",
                 "test10: 'a' length must be 13 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n2_concat",
                 "test10: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n2_concat(a, a, d, 3);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello WoWorld"), "mrstr_n2_concat",
                 "test11: 'a' data must be \"Wor\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 13, "mrstr_n2_concat",
                 "test11: 'a' length must be 13 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n2_concat",
                 "test11: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n2_concat(a, a, a, 2);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello WoWorldHe"), "mrstr_n2_concat",
                 "test12: 'a' data must be \"Hello WoWorldHe\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 15, "mrstr_n2_concat",
                 "test12: 'a' length must be 15 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n2_concat",
                 "test12: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n2_concat(a, a, a, 20);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello WoWorldHeHello WoWorldHe"), "mrstr_n2_concat",
                 "test13: 'a' data must be \"Hello WoWorldHeHello WoWorldHe\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 30, "mrstr_n2_concat",
                 "test13: 'a' length must be 30 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n2_concat",
                 "test13: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n2_concat(a, a, a, 0);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Hello WoWorldHeHello WoWorldHe"), "mrstr_n2_concat",
                 "test14: 'a' data must be \"Hello WoWorldHeHello WoWorldHe\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 30, "mrstr_n2_concat",
                 "test14: 'a' length must be 30 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n2_concat",
                 "test14: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n2_concat(b, a, b, 1);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello WoWorldHeHello WoWorldHeW"), "mrstr_n2_concat",
                 "test15: 'b' data must be \"Hello WoWorldHeHello WoWorldHeW\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 31, "mrstr_n2_concat",
                 "test15: 'b' length must be 31 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n2_concat",
                 "test15: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_n2_concat(b, a, b, 40);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello WoWorldHeHello WoWorldHeHello WoWorldHeHello WoWorldHeW"), "mrstr_n2_concat",
                 "test16: 'b' data must be \"Hello WoWorldHeHello WoWorldHeHello WoWorldHeHello WoWorldHeW\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 61, "mrstr_n2_concat",
                 "test16: 'b' length must be 61 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n2_concat",
                 "test16: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_n2_concat(b, a, b, 0);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello WoWorldHeHello WoWorldHe"), "mrstr_n2_concat",
                 "test17: 'b' data must be \"Hello WoWorldHeHello WoWorldHe\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 30, "mrstr_n2_concat",
                 "test17: 'b' length must be 30 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n2_concat",
                 "test17: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_n2_concat(b, d, b, 30);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "Hello WoWorldHeHello WoWorldHe"), "mrstr_n2_concat",
                 "test18: 'b' data must be \"Hello WoWorldHeHello WoWorldHe\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 30, "mrstr_n2_concat",
                 "test18: 'b' length must be 30 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n2_concat",
                 "test18: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_clears(a, b, c, NULL);

    UTEST_SUCCESS("mrstr_n2_concat");
    return 0;
}
