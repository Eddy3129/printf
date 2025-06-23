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

int	print_uint(unsigned int num)
{
	int				count;
	unsigned int	n;

	n = num;
	put_uint(n);
	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	print_hex_format(unsigned long num, char format)
{
	char	*s;
	int		count;

	count = 0;
	if (format == 'X')
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	if (num >= 16)
		count += print_hex_format(num / 16, format);
	write(1, &s[num % 16], 1);
	return (count + 1);
}

int	print_ptr(void *ptr)
{
	int					count;
	unsigned long		addr;
	unsigned long		temp;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	print_hex_format(addr, 'x');
	count = 2;
	temp = addr;
	if (temp == 0)
		count++;
	while (temp > 0)
	{
		temp /= 16;
		count++;
	}
	return (count);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += print_char(va_arg(args, int));
	if (format == 's')
		print_length += print_str(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		print_length += print_int(va_arg(args, int));
	if (format == 'p')
		print_length += print_ptr(va_arg(args, void *));
	if (format == 'u')
		print_length += print_uint(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		print_length += print_hex_format(va_arg(args, unsigned int), format);
	if (format == '%')
		print_length += print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

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
