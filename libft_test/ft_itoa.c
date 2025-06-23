/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:06:25 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 14:14:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*handle_special(char *output, int n)
{
	if (n == -2147483648)
	{
		ft_strlcpy(output, "-2147483648", 12);
		return (output);
	}
	if (n == 0)
	{
		output[0] = '0';
		return (output);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		len;

	len = str_len(n);
	output = ft_calloc(len + 1, sizeof(char));
	if (!output)
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (handle_special(output, n));
	if (n < 0)
	{
		output[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		output[--len] = n % 10 + '0';
		n /= 10;
	}
	return (output);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa(-123));
    printf("%s\n", ft_itoa(-2147483648));
    printf("%s\n", ft_itoa(2));
    printf("%s\n", ft_itoa(100000000));
    printf("%s\n", ft_itoa(101030010));
}
*/