/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:41:48 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/30 16:27:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last = s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return ((char *)last);
}
/*
#include <stdio.h>
int     main(void)
{
	char c[6] = "hello";
	printf("%s",ft_strrchr(c,'x'));
}*/
