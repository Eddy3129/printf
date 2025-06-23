/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:10:30 by marvin            #+#    #+#             */
/*   Updated: 2025/05/28 23:10:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s)
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

void	*ft_free(char **str, int i)
{
	while (i-- > 0)
		free(str[i]);
	free(str);
	return (NULL);
}

int	word_len(char const **s_ptr, char c)
{
	int	j;

	j = 0;
	while (**s_ptr && **s_ptr == c)
		(*s_ptr)++;
	while ((*s_ptr)[j] && (*s_ptr)[j] != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		total_wc;
	int		j;
	int		n;

	if (!s)
		return (NULL);
	total_wc = word_count(s, c);
	str_array = ft_calloc((total_wc + 1), sizeof(char *));
	if (!str_array)
		return (NULL);
	n = 0;
	while (n < total_wc)
	{
		j = word_len(&s, c);
		str_array[n] = ft_calloc((j + 1), sizeof(char));
		if (!str_array[n])
			return (ft_free(str_array, n));
		ft_memmove(str_array[n], s, j);
		s += j;
		n++;
	}
	return (str_array);
}
