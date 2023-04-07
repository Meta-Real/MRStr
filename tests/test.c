#include <mrstr.h>

int main()
{
    mrstr_t a;
    mrstr_init(a);

    mrstr_set_str(a, "Hello World");

    mrstr_rtrim(a, a, 'd');

    mrstr_out(stdout, a);

    mrstr_clear(a);
    return 0;
}
