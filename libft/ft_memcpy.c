/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:41:24 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 16:41:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dest == 0 && src == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src1[] = "Hello, World!";
    char dest1[20];
    char src2[] = "abcdefgh";
    char dest2[10];
    char src3[] = "12345";
    char dest3[10] = "xxxxxxxxx"; 
    char buffer[20] = "This is a test"; 

    printf("Testing ft_memcpy:\n");
    printf("----------------------------------------\n");

    // Test Case 1: Copying a string
    printf("Test 1: Copying a string\n");
    ft_memcpy(dest1, src1, strlen(src1) + 1); 
    printf("Source: \"%s\"\n", src1);
    printf("Destination: \"%s\"\n", dest1);
    printf("----------------------------------------\n");

    // Test Case 2: Copying a specific number of bytes
    printf("Test 2: Copying 5 bytes\n");
    ft_memcpy(dest2, src2, 5);
    dest2[5] = '\0'; // Manually null-terminate for printing
    printf("Source: \"%s\"\n", src2);
    printf("Destination (first 5 bytes): \"%s\"\n", dest2);
    printf("----------------------------------------\n");

    // Test Case 3: Copying zero bytes
    printf("Test 3: Copying 0 bytes\n");
    ft_memcpy(dest3, src3, 0);
    printf("Source: \"%s\"\n", src3);
    printf("Destination (after copying 0 bytes): \"%s\"\n", dest3); 
    printf("----------------------------------------\n");

    // Test Case 4: Copying to a destination with existing data
    printf("Test 4: Copying 3 bytes to existing buffer\n");
    ft_memcpy(dest3, src3, 3); // Copy "123" over "xxx"
    printf("Source: \"%s\"\n", src3);
    printf("Destination (after copying 3 bytes): \"%s\"\n", dest3); 
    printf("----------------------------------------\n");

    // Test Case 5: Overlapping regions (memcpy behavior is undefined)
    // Copy 5 bytes from buffer[5] ("is a ") to buffer[0] ("This ")
    // Expected (standard memmove behavior): "is a is a test"
    // memcpy might produce different results due to copy direction
    printf("Test 5: Overlapping regions (memcpy behavior undefined)\n");
    printf("Original buffer: \"%s\"\n", buffer);
    ft_memcpy(buffer, buffer + 5, 5);
    printf("Buffer after ft_memcpy(buffer, buffer + 5, 5): \"%s\"\n", buffer);
    printf("----------------------------------------\n");

    // Test Case 6: Another overlapping case
    // Copy 5 bytes from buffer[0] ("is a ") to buffer[5] ("is a ")
    // Expected (standard memmove behavior): "is a is a test"
    printf("Test 6: Another overlapping regions (memcpy behavior undefined)\n");
    // Reset buffer for this test
    strcpy(buffer, "This is a test");
    printf("Original buffer: \"%s\"\n", buffer);
    ft_memcpy(buffer + 5, buffer, 5);
    printf("Buffer after ft_memcpy(buffer + 5, buffer, 5): \"%s\"\n", buffer);
    printf("----------------------------------------\n");


    return (0);
}
*/
