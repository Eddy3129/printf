/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:46:17 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/30 18:41:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_trim(const char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	find_start(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && is_trim(set, s1[i]))
		i++;
	return (i);
}

size_t	find_end(const char *s1, const char *set)
{
	size_t	j;

	j = 0;
	while (s1[j])
		j++;
	if (j == 0)
		return (0);
	j--;
	while (s1[j] && is_trim(set, s1[j]))
		j--;
	return (j);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*dest;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	len = end - start + 1;
	dest = (char *)ft_calloc((len + 1), sizeof(char));
	if (!dest)
		return (NULL);
	ft_memmove(dest, &s1[start], len);
	return (dest);
}
