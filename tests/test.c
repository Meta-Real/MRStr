#include <stdio.h>
#include <mrstr.h>

int main()
{
    mrstr_t a, b;
    mrstr_inits(a, b, NULL);

    mrstr_set_str(a, "Hello World!");
    mrstr_onset(b, a, 5, 2);
    mrstr_onset(a, a, 5, 2);

    printf("%s\n%s\n", MRSTR_DATA(a), MRSTR_DATA(b));

    mrstr_clears(a, b, NULL);
    return 0;
}
