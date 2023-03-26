#include <stdio.h>
#include <mrstr.h>

int main()
{
    mrstr_t a;
    mrstr_set_str(a, "Hello World Full of Monsters!");

    printf("%s\n", mrstr_get_str(a));
    printf("%s\n", mrstr_nget_str(a, 10));
    printf("%s\n", mrstr_oget_str(a, 7));
    printf("%s\n", mrstr_noget_str(a, 12, 4));

    mrstr_clear(a);
    return 0;
}
