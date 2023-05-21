/*/
 * MetaReal String Library version 1.0.0
 *
 * Testing mrstr_n_concat function
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

    mrstr_n_concat(c, a, 4, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "HellWorld"), "mrstr_n_concat",
                 "test1: 'c' data must be \"HellWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 9, "mrstr_n_concat",
                 "test1: 'c' length must be 9 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n_concat",
                 "test1: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n_concat(c, a, 100, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello World"), "mrstr_n_concat",
                 "test2: 'c' data must be \"Hello World\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 11, "mrstr_n_concat",
                 "test2: 'c' length must be 11 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n_concat",
                 "test2: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n_concat(c, a, 0, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "World"), "mrstr_n_concat",
                 "test3: 'c' data must be \"World\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 5, "mrstr_n_concat",
                 "test3: 'c' length must be 5 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n_concat",
                 "test3: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n_concat(c, a, 2, d);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "He"), "mrstr_n_concat",
                 "test4: 'c' data must be \"He\" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 2, "mrstr_n_concat",
                 "test4: 'c' length must be 2 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n_concat",
                 "test4: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n_concat(c, a, 0, d);

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_n_concat",
                 "test5: 'c' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_n_concat",
                 "test5: 'c' length must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n_concat",
                 "test5: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_n_concat(c, d, 10, a);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(c), "Hello "), "mrstr_n_concat",
                 "test6: 'c' data must be \"Hello \" but it is \"%s\"\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(MRSTR_LEN(c) == 6, "mrstr_n_concat",
                 "test6: 'c' length must be 6 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n_concat",
                 "test6: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_clear(c);
    mrstr_n_concat(c, d, 58, d);

    UTEST_EXPECT(!MRSTR_DATA(c), "mrstr_n_concat",
                 "test7: 'c' data pointer must be NULL but it is %p\n",
                 MRSTR_DATA(c));
    UTEST_EXPECT(!MRSTR_LEN(c), "mrstr_n_concat",
                 "test7: 'c' length must be 0 but it is %llu\n",
                 MRSTR_LEN(c));
    UTEST_EXPECT(!MRSTR_OFFSET(c), "mrstr_n_concat",
                 "test7: 'c' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(c));

    mrstr_n_concat(a, a, 2, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "HeWorld"), "mrstr_n_concat",
                 "test8: 'a' data must be \"HeWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 7, "mrstr_n_concat",
                 "test8: 'a' length must be 7 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_concat",
                 "test8: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_concat(a, a, 200, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "HeWorldWorld"), "mrstr_n_concat",
                 "test9: 'a' data must be \"HeWorldWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 12, "mrstr_n_concat",
                 "test9: 'a' length must be 12 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_concat",
                 "test9: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_concat(a, a, 0, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "World"), "mrstr_n_concat",
                 "test10: 'a' data must be \"World\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 5, "mrstr_n_concat",
                 "test10: 'a' length must be 5 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_concat",
                 "test10: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_concat(a, a, 3, d);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "Wor"), "mrstr_n_concat",
                 "test11: 'a' data must be \"Wor\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 3, "mrstr_n_concat",
                 "test11: 'a' length must be 3 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_concat",
                 "test11: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_concat(a, a, 2, a);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "WoWor"), "mrstr_n_concat",
                 "test12: 'a' data must be \"WoWor\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 5, "mrstr_n_concat",
                 "test12: 'a' length must be 5 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_concat",
                 "test12: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_concat(a, a, 20, a);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "WoWorWoWor"), "mrstr_n_concat",
                 "test13: 'a' data must be \"WoWorWoWor\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 10, "mrstr_n_concat",
                 "test13: 'a' length must be 10 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_concat",
                 "test13: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_concat(a, a, 0, a);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(a), "WoWorWoWor"), "mrstr_n_concat",
                 "test14: 'a' data must be \"WoWorWoWor\" but it is \"%s\"\n",
                 MRSTR_DATA(a));
    UTEST_EXPECT(MRSTR_LEN(a) == 10, "mrstr_n_concat",
                 "test14: 'a' length must be 10 but it is %llu\n",
                 MRSTR_LEN(a));
    UTEST_EXPECT(!MRSTR_OFFSET(a), "mrstr_n_concat",
                 "test14: 'a' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(a));

    mrstr_n_concat(b, a, 1, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "WWorld"), "mrstr_n_concat",
                 "test15: 'b' data must be \"WWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 6, "mrstr_n_concat",
                 "test15: 'b' length must be 6 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n_concat",
                 "test15: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_n_concat(b, a, 40, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "WoWorWoWorWWorld"), "mrstr_n_concat",
                 "test16: 'b' data must be \"WoWorWoWorWWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 16, "mrstr_n_concat",
                 "test16: 'b' length must be 16 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n_concat",
                 "test16: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_n_concat(b, a, 0, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "WoWorWoWorWWorld"), "mrstr_n_concat",
                 "test17: 'b' data must be \"WoWorWoWorWWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 16, "mrstr_n_concat",
                 "test17: 'b' length must be 16 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n_concat",
                 "test17: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_n_concat(b, d, 30, b);

    UTEST_EXPECT(!strcmp(MRSTR_DATA(b), "WoWorWoWorWWorld"), "mrstr_n_concat",
                 "test18: 'b' data must be \"WoWorWoWorWWorld\" but it is \"%s\"\n",
                 MRSTR_DATA(b));
    UTEST_EXPECT(MRSTR_LEN(b) == 16, "mrstr_n_concat",
                 "test18: 'b' length must be 16 but it is %llu\n",
                 MRSTR_LEN(b));
    UTEST_EXPECT(!MRSTR_OFFSET(b), "mrstr_n_concat",
                 "test18: 'b' offset must be 0 but it is %llu\n",
                 MRSTR_OFFSET(b));

    mrstr_clears(a, b, c, NULL);

    UTEST_SUCCESS("mrstr_n_concat");
    return 0;
}
