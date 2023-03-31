#include <mrstr.h>

int main()
{
    mrstr_t a, b;

    mrstr_inits(a, b, NULL);

    mrstr_set_str(a, "Hello World");
    mrstr_set(b, a);
    mrstr_nset(a, a, 5);

    printf("%s\n%s\n", a->_data, b->_data);

    mrstr_clears(b, a, NULL);
    return 0;
}
