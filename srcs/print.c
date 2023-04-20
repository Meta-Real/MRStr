/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_print(mrstr_cstr, ...)
 * Prints out the formatted string into the stdout
 *
 * input reqs:
 *  (format) pointer must be valid
/*/

#include <mrstr.h>
#include <stdarg.h>

void mrstr_print(mrstr_cstr format, ...)
{
    if (!format)
        return;

    va_list ap;
    va_start(ap, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format++);
            continue;
        }

        format++;
        if (!*format)
            break;

        switch (*format)
        {
        case 'S':
            fputs(MRSTR_DATA(va_arg(ap, mrstr_p)), stdout);
            break;
        case 'R':
            mrstr_p s = va_arg(ap, mrstr_p);
            printf("{data = \"%s\", len = %llu, offset = %llu}",
                  MRSTR_DATA(s), MRSTR_LEN(s), MRSTR_OFFSET(s));
            break;
        case 'd':
        case 'i':
            printf("%d", va_arg(ap, int));
            break;
        case 'o':
            printf("%o", va_arg(ap, int));
            break;
        case 'u':
            printf("%u", va_arg(ap, unsigned));
            break;
        case 'x':
            printf("%x", va_arg(ap, int));
            break;
        case 'X':
            printf("%X", va_arg(ap, int));
            break;
        case 'f':
            printf("%f", va_arg(ap, double));
            break;
        case 'F':
            printf("%F", va_arg(ap, double));
            break;
        case 'e':
            printf("%e", va_arg(ap, double));
            break;
        case 'E':
            printf("%E", va_arg(ap, double));
            break;
        case 'g':
            printf("%g", va_arg(ap, double));
            break;
        case 'G':
            printf("%G", va_arg(ap, double));
            break;
        case 'a':
            printf("%a", va_arg(ap, double));
            break;
        case 'A':
            printf("%A", va_arg(ap, double));
            break;
        case 'c':
            putchar(va_arg(ap, int));
            break;
        case 's':
            fputs(va_arg(ap, mrstr_cstr), stdout);
            break;
        case 'p':
            printf("%p", va_arg(ap, void*));
            break;
        case '%':
            putchar('%');
            break;
        case 'l':
            format++;
            if (!format)
            {
                va_end(ap);
                return;
            }

            switch (*format)
            {
            case 'd':
            case 'i':
                printf("%ld", va_arg(ap, long int));
                break;
            case 'u':
                printf("%lu", va_arg(ap, unsigned long));
                break;
            case 'f':
                printf("%lf", va_arg(ap, double));
                break;
            case 'R':
                mrstr_p s = va_arg(ap, mrstr_p);
                printf("{ptr = %p, sptr = %p, eptr = %p, "
                       "data = \"%s\", "
                       "alloc = %llu, len = %llu, "
                       "offset = %llu}",
                       MRSTR_DATA(s), MRSTR_DATA(s) - MRSTR_OFFSET(s), MRSTR_DATA(s) + MRSTR_LEN(s),
                       MRSTR_DATA(s),
                       MRSTR_LEN(s) + MRSTR_OFFSET(s), MRSTR_LEN(s),
                       MRSTR_OFFSET(s));
                break;
            case 'l':
                format++;
                if (!format)
                {
                    va_end(ap);
                    return;
                }

                switch (*format)
                {
                case 'd':
                case 'i':
                    printf("%lld", va_arg(ap, long long int));
                    break;
                case 'u':
                    printf("%llu", va_arg(ap, unsigned long long));
                    break;
                }
                break;
            }
            break;
        }

        format++;
    }

    va_end(ap);
}
