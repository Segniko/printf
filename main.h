#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;
    char *s;

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, char *);
                    while (*s) {
                        putchar(*s);
                        count++;
                        s++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    int num = 65;
    char str[] = "Hello, World!";

    int characters_printed = _printf("Printing a character: %c\nPrinting a string: %s\nPrinting a percent sign: %%\nPrinting an integer: %c\n", 'A', str, num);

    printf("\nTotal characters printed: %d\n", characters_printed);

    return 0;
}
