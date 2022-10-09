#include "libftprintf.h"
#include <stdio.h>

void    go(va_list arg, int n)
{
        while (n--)
        {
                printf("%s\n", va_arg(arg, char *));
        }
}
void    test(int n, ...)
{
        va_list arg;
        va_start(arg, n);
	go(arg, 3);
        va_end(arg);
}
int     main()
{
        int a = printf("%%%%%Z", 221);
	printf("%.10i", 12);
}
