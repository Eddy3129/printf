#include <stdio.h>
#include "include/ft_printf.h"

int main(void)
{
    int i;
    char *s;

    s = "fucking";
    i = ft_printf("Hello to the %s %d %% world\n", s, 99);
    printf("%d\n", i);
    return (0);
}