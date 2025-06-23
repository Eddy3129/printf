/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:46:21 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 17:46:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	char			*result;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	return (result);
}
/*
#include <stdio.h>
#include <string.h>

char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char add_index(unsigned int i, char c)
{
    return (c + i);
}

char alternating_case(unsigned int i, char c)
{
    if (i % 2 == 0)
    {
        if (c >= 'a' && c <= 'z')
            return (c - 32);
    }
    else
    {
        if (c >= 'A' && c <= 'Z')
            return (c + 32);
    }
    return (c);
}

char index_to_digit(unsigned int i, char c)
{
    (void)c;
    return ('0' + (i % 10));
}

int main()
{
    char *result;
    
    printf("=== Testing ft_strmapi ===\n\n");
    
    // Test 1: NULL string
    printf("Test 1: NULL string\n");
    result = ft_strmapi(NULL, to_upper);
    if (result == NULL)
        printf("NULL input handled correctly\n\n");
    else
        printf("Failed - should return NULL\n\n");
    
    // Test 2: Empty string
    printf("Test 2: Empty string\n");
    result = ft_strmapi("", to_upper);
    if (result && strcmp(result, "") == 0)
        printf("Empty string handled correctly\n");
    else
        printf("Failed - empty string not handled\n");
    if (result) free(result);
    printf("\n");
    
    // Test 3: Convert to uppercase
    printf("Test 3: Convert to uppercase\n");
    result = ft_strmapi("hello world", to_upper);
    printf("Input: 'hello world'\n");
    printf("Output: '%s'\n", result ? result : "NULL");
    if (result && strcmp(result, "HELLO WORLD") == 0)
        printf("Test passed\n");
    else
        printf("Test failed\n");
    if (result) free(result);
    printf("\n");
    
    // Test 4: Add index to each character
    printf("Test 4: Add index to each character\n");
    result = ft_strmapi("abc", add_index);
    printf("Input: 'abc'\n");
    printf("Output: '%s'\n", result ? result : "NULL");
    printf("Expected: a+0=a, b+1=c, c+2=e\n");
    if (result) free(result);
    printf("\n");
    
    // Test 5: Alternating case
    printf("Test 5: Alternating case (even=upper, odd=lower)\n");
    result = ft_strmapi("hello", alternating_case);
    printf("Input: 'hello'\n");
    printf("Output: '%s'\n", result ? result : "NULL");
    printf("Expected: HeLlO\n");
    if (result) free(result);
    printf("\n");
    
    // Test 6: Replace with index digits
    printf("Test 6: Replace with index digits\n");
    result = ft_strmapi("abcdefghij", index_to_digit);
    printf("Input: 'abcdefghij'\n");
    printf("Output: '%s'\n", result ? result : "NULL");
    printf("Expected: 0123456789\n");
    if (result) free(result);
    printf("\n");
    
    // Test 7: Single character
    printf("Test 7: Single character\n");
    result = ft_strmapi("x", to_upper);
    printf("Input: 'x'\n");
    printf("Output: '%s'\n", result ? result : "NULL");
    if (result) free(result);
    printf("\n");
    
    // Test 8: Mixed characters
    printf("Test 8: Mixed characters\n");
    result = ft_strmapi("Hello123!@#", to_upper);
    printf("Input: 'Hello123!@#'\n");
    printf("Output: '%s'\n", result ? result : "NULL");
    if (result) free(result);
    printf("\n");
    
    printf("=== All tests completed ===\n");
    
    return (0);
}
	*/