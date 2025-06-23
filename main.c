#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    unsigned int i;
    char *s;

    s = "42KL";
    i = 4294967295;
    printf("%X",i);
    return (0);
}