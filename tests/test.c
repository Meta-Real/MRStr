#include <mrstr.h>

int main()
{
    mrstr_t a;
    mrstr_init(a);

    mrstr_n_inp(a, stdin, 5);
    printf_s("'%s'\n", a->_data);

    mrstr_clear(a);
    return 0;
}
