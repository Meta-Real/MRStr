#include <mrstr.h>
#include <time.h>

int main()
{
    mrstr_t a, b, c;
    mrstr_inits(a, b, c, NULL);

    mrstr_set_str(a, "Hello World");
    mrstr_rremove(c, a, 4, 6);

    printf("%s\n", c->_data);

    mrstr_clears(a, b, c, NULL);
    return 0;
}
