/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:16:14 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/31 13:08:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n > 0)
	{
		*temp++ = 0;
		n--;
	}
}
/*
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	char	s[6] = "XXXXX";
	ft_bzero(s, 3);
	printf("%s", s);
   	int	i = 0;
	while (i < 10)
	{
		write(1, &s[i], 1);
		 i++;
	}     	
}*/
