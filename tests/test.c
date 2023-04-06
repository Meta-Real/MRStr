#include <mrstr.h>
#include <time.h>

int main()
{
    mrstr_t a, b;
    mrstr_inits(a, b, NULL);

    clock_t l = 0;

    for (int i = 0; i < 100; i++)
    {
        mrstr_set_str(a, "H");

        clock_t s = clock();

        mrstr_repeat(b, a, 1000000);

        l += clock() - s;

        mrstr_clears(a, b, NULL);
    }

    printf("%lf miliseconds\n", l / 100.0);

    return 0;
}
