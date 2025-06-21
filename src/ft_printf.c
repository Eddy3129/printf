/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:18:59 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 17:18:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(int c)
{
    write(1, &c, 1);
    return (1);
}

int print_str(char *str)
{
    ft_putstr_fd(str, 1);
    return ft_strlen(str);
}

int print_int(int num)
{
    ft_putnbr_fd(num, 1);
    return ft_strlen(ft_itoa(num));
}

int print_percent(void)
{
    write(1, '%', 1);
    return (1);
}

int ft_formats(va_list args, const char format)
{
    int print_length;

    print_length = 0;
    if (format == 'c')
        print_length += print_char(va_arg(args, int));
    if (format == 's')
        print_length += print_str(va_arg(args, char *));
    if (format == 'd')
        print_length += print_int(va_arg(args, int));
    if (format == '%')
        print_length += print_percent();
    return (print_length);
}

int ft_printf(const char *str, ...)
{
    int     i;
    va_list args;
    int     print_length;

    i = 0;
    print_length = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            print_length += ft_formats(args, str[i + 1]);
            i++;
        }
        else
            print_length += print_char(str[i]);
        i++;
    }
    va_end(args);
    return (print_length);
}
