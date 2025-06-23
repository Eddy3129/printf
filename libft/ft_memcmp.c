/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:42:47 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 18:42:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*d != *s)
			return (*d - *s);
		d++;
		s++;
		n--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[20];
	char s2[20];
	int result;
	int expected;
	unsigned int n;

	printf("Testing ft_memcmp:\n");
	printf("----------------------------------------\n");

	// Test Case 1: Identical strings
	strcpy(s1, "Hello");
	strcpy(s2, "Hello");
	n = 5;
	result = ft_memcmp(s1, s2, n);
	expected = memcmp(s1, s2, n);
	printf("Test 1: Identical strings \"%s\" vs \"%s\", n=%u\n", s1, s2, n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 2: Different strings, difference early
	strcpy(s1, "Hello");
	strcpy(s2, "Hallo");
	n = 5;
	result = ft_memcmp(s1, s2, n);
	expected = memcmp(s1, s2, n);
	printf("Test 2: Different strings \"%s\" vs \"%s\", n=%u\n", s1, s2, n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 3: Different strings, difference at the end of n
	strcpy(s1, "HelloX");
	strcpy(s2, "HelloY");
	n = 6;
	result = ft_memcmp(s1, s2, n);
	expected = memcmp(s1, s2, n);
	printf("Test 3: Different strings \"%s\" vs \"%s\", n=%u\n", s1, s2, n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 4: Different strings, difference after n
	strcpy(s1, "HelloX");
	strcpy(s2, "HelloY");
	n = 5;
	result = ft_memcmp(s1, s2, n);
	expected = memcmp(s1, s2, n);
	printf("Test 4: Different strings \"%s\" vs \"%s\", n=%u\n", s1, s2, n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 5: Comparing with n = 0
	strcpy(s1, "Hello");
	strcpy(s2, "World");
	n = 0;
	result = ft_memcmp(s1, s2, n);
	expected = memcmp(s1, s2, n);
	printf("Test 5: Comparing with n=0 \"%s\" vs \"%s\", n=%u\n", s1, s2, n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 6: Comparing with null bytes within the first n bytes
	char s3[] = "abc\0def";
	char s4[] = "abc\0ghi";
	n = 6; // Compare up to 'f' vs 'h'
	result = ft_memcmp(s3, s4, n);
	expected = memcmp(s3, s4, n);
	printf("Test 6: With null bytes \"abc\\0def\" vs \"abc\\0ghi\", n=%u\n", n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 7: Comparing with null bytes, difference after null
	char s5[] = "abc\0def";
	char s6[] = "abc\0def";
	n = 7; // Compare entire strings including null
	result = ft_memcmp(s5, s6, n);
	expected = memcmp(s5, s6, n);
	printf("Test 7: With null bytes \"abc\\0def\" vs \"abc\\0def\", n=%u\n", n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 8: Comparing with null bytes, difference before null
	char s7[] = "abX\0def";
	char s8[] = "abY\0def";
	n = 4; // Compare up to null
	result = ft_memcmp(s7, s8, n);
	expected = memcmp(s7, s8, n);
	printf("Test 8: With null bytes \"abX\\0def\" vs \"abY\\0def\", n=%u\n", n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	// Test Case 9: Comparing different lengths
	char s9[] = "short";
	char s10[] = "longer";
	n = 5;
	result = ft_memcmp(s9, s10, n);
	expected = memcmp(s9, s10, n);
	printf("Test 9: Different lengths \"%s\" vs \"%s\", n=%u\n", s9, s10, n);
	printf("ft_memcmp result: %d, Expected (memcmp): %d\n", result, expected);
	printf("----------------------------------------\n");

	return (0);
}
*/