/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:06:37 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/31 13:03:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *) b;
	while (len > 0)
	{
		*s++ = c;
		len--;
	}
	return (b);
}
/*#include <unistd.h>
int	main(void)
{
	char	s[10];
	int	i = 0;
	while (i < 10)
	{
		s[i] = 'X';
		i++;
	}
	ft_memset(s, 'A', 5);
	i = 0;
	while (i < 10)
	{
		write(1, &s[i], 1);
		i++;
	}		
}*/
