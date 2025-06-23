/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:25:30 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 13:25:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	parse_sign(const char *str, int *i)
{
	int	sign;
	int	count;

	sign = 1;
	count = 0;
	while (str[*i] == '+' || str[*i] == '-')
	{
		count++;
		if (count > 1)
			return (0);
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	sign = parse_sign(str, &i);
	if (sign == 0)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str = "  -123456+789";
	int		num = ft_atoi(str);
	printf("%d\n", num);
	int		num2 = atoi(str);
	printf("%d\n", num2);
}*/