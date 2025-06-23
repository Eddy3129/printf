/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:45:38 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 20:45:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h> 

int main(void)
{
	char *original1 = "Hello, World!";
	char *original2 = ""; // Empty string
	char *duplicate1;
	char *duplicate2;

	printf("Testing ft_strdup:\n");
	printf("----------------------------------------\n");

	// Test Case 1: Duplicating a standard string
	printf("Test 1: Duplicating \"%s\"\n", original1);
	duplicate1 = ft_strdup(original1);
	if (duplicate1 != NULL)
	{
		printf("Original: \"%s\"\n", original1);
		printf("Duplicate: \"%s\"\n", duplicate1);
		// Optional: Compare with standard strdup
		// char *std_duplicate1 = strdup(original1);
		// printf("Standard strdup: \"%s\"\n", std_duplicate1);
		// printf("Comparison result: %d\n", strcmp(duplicate1, std_duplicate1));
		// free(std_duplicate1);
		free(duplicate1); // Free allocated memory
	}
	else
	{
		printf("ft_strdup returned NULL (allocation failed?)\n");
	}
	printf("----------------------------------------\n");

	// Test Case 2: Duplicating an empty string
	printf("Test 2: Duplicating empty string \"%s\"\n", original2);
	duplicate2 = ft_strdup(original2);
	if (duplicate2 != NULL)
	{
		printf("Original: \"%s\"\n", original2);
		printf("Duplicate: \"%s\"\n", duplicate2);
		// Optional: Compare with standard strdup
		// char *std_duplicate2 = strdup(original2);
		// printf("Standard strdup: \"%s\"\n", std_duplicate2);
		// printf("Comparison result: %d\n", strcmp(duplicate2, std_duplicate2));
		// free(std_duplicate2);
		free(duplicate2); // Free allocated memory
	}
	else
	{
		printf("ft_strdup returned NULL (allocation failed?)\n");
	}
	printf("----------------------------------------\n");

	// Note: Testing malloc failure directly is difficult without
	// specific system calls or mocking libraries.

	return (0);
}
*/