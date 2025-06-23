/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:03:18 by marvin            #+#    #+#             */
/*   Updated: 2025/05/25 22:29:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = ft_calloc((len + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h> 

int main(void)
{
	char *s1 = "Hello, world!";
	char *s2 = "abcdef";
	char *s3 = ""; // Empty string
	char *sub;

	printf("Testing ft_substr:\n");
	printf("----------------------------------------\n");

	// Test Case 1: Basic substring
	printf("Test 1: s=\"%s\", start=7, len=5\n", s1);
	sub = ft_substr(s1, 7, 5); // Should be "world"
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		// Optional: Compare with expected output
		printf("Expected: \"world\"\n");
		// printf("Match: %d\n", strcmp(sub, "world") == 0);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");

	// Test Case 2: Substring from the beginning
	printf("Test 2: s=\"%s\", start=0, len=5\n", s1);
	sub = ft_substr(s1, 0, 5); // Should be "Hello"
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");

	// Test Case 3: Substring to the end
	printf("Test 3: s=\"%s\", start=7, len=20 (longer than remaining)\n", s1);
	sub = ft_substr(s1, 7, 20); // Should be "world!"
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");

	// Test Case 4: start is exactly string length
	printf("Test 4: s=\"%s\", start=%zu, len=5\n", s2, strlen(s2));
	sub = ft_substr(s2, strlen(s2), 5); // Should be "" (empty string)
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");

	// Test Case 5: start is beyond string length
	printf("Test 5: s=\"%s\", start=%zu, len=5\n", s2, strlen(s2) + 1);
	sub = ft_substr(s2, strlen(s2) + 1, 5); // Should be NULL
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");

	// Test Case 6: len is 0
	printf("Test 6: s=\"%s\", start=2, len=0\n", s1);
	sub = ft_substr(s1, 2, 0); // Should be "" (empty string)
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");

	// Test Case 7: Empty string, start=0, len=5
	printf("Test 7: s=\"%s\", start=0, len=5\n", s3);
	sub = ft_substr(s3, 0, 5); // Should be "" (empty string)
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");

	// Test Case 8: Empty string, start=1, len=5
	printf("Test 8: s=\"%s\", start=1, len=5\n", s3);
	sub = ft_substr(s3, 1, 5); // Should be NULL
	if (sub)
	{
		printf("Result: \"%s\"\n", sub);
		free(sub);
	}
	else
		printf("Result: NULL\n");
	printf("----------------------------------------\n");
	return (0);
}
	*/