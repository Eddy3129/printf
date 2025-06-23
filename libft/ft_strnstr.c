/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:15:59 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 15:15:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] && needle[j]
			&& needle[j] == haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*result;
	const char *haystack;
	const char *needle;
	unsigned int len;

	printf("Testing ft_strnstr:\n");
	printf("-----------------------------------------------------\n");

	// Basic cases
	haystack = "Hello World!"; needle = "World"; len = 12;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "Hello World!"; needle = "o W"; len = 12;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "Hello World!"; needle = "xyz"; len = 12;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// Empty needle
	haystack = "Hello World!"; needle = ""; len = 12;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "Hello World!"; needle = ""; len = 0;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = ""; needle = ""; len = 0;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "abc"; needle = ""; len = 3;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// Empty haystack
	haystack = ""; needle = "abc"; len = 3;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// len constraints
	haystack = "Hello World!"; needle = "World"; len = 5;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "Hello World!"; needle = "World"; len = 6;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "Hello World!"; needle = "World"; len = 10;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "Hello World!"; needle = "World"; len = 11;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "Hello World!"; needle = "Hello"; len = 0;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "abc"; needle = "a"; len = 0;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// Needle longer than haystack
	haystack = "hi"; needle = "hello"; len = 5;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// Needle at various positions
	haystack = "abcabcabc"; needle = "abc"; len = 9;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "xyzabcxyz"; needle = "abc"; len = 9;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "xyzxyzabc"; needle = "abc"; len = 9;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// Haystack and Needle are the same
	haystack = "test"; needle = "test"; len = 4;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "test"; needle = "test"; len = 3;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// Partial matches before full match
	haystack = "abababc"; needle = "abc"; len = 7;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "aaabc"; needle = "abc"; len = 5;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// More len edge cases
	haystack = "lorem ipsum dolor sit amet"; needle = "ipsum"; len = 10;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "lorem ipsum dolor sit amet"; needle = "ipsum"; len = 11;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "lorem ipsum dolor sit amet"; needle = "ipsum"; len = 15;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "aaa"; needle = "a"; len = 1;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "aaab"; needle = "aab"; len = 3;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// From a common test set
	haystack = "ozoner"; needle = "ozo"; len = 3;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "lorelorelore"; needle = "lore"; len = 10;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	haystack = "MZIRIBMZIRIBMZE123"; needle = "MZIRIBMZE"; len = 15;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	// Case where first char of needle appears multiple times
	haystack = "atatatt"; needle = "att"; len = 7;
	result = ft_strnstr((char *)haystack, (char *)needle, len);
	printf("Haystack: \"%s\", Needle: \"%s\", len: %u\n", haystack, needle, len);
	printf("Result: %s\n", result ? result : "NULL");
	printf("-----------------------------------------------------\n");

	return (0);
}
	*/