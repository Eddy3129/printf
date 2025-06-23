/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:44:05 by marvin            #+#    #+#             */
/*   Updated: 2025/06/23 17:44:05 by marvin           ###   ########.fr       */
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
    write(1, "%", 1);
    return (1);
}

void put_uint(unsigned int num)
{
    char    n;
    if (num >= 10)
        put_uint(num / 10);
    n = num % 10 + '0';
    write(1, &n, 1);
}