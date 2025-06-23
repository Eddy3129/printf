/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:47:32 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 16:47:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == 0 && src == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst < src)
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h> 

int main(void)
{
    char buffer[50];
    char src[] = "abcdefghijklmnopqrstuvwxyz";
    char dst[50];

    printf("Testing ft_memmove:\n");
    printf("----------------------------------------\n");

    // Test Case 1: Non-overlapping copy
    printf("Test 1: Non-overlapping copy\n");
    strcpy(buffer, src); // Reset buffer
    ft_memmove(dst, buffer, strlen(buffer) + 1); // Copy entire string
    printf("Source: \"%s\"\n", buffer);
    printf("dstination: \"%s\"\n", dst);
    printf("----------------------------------------\n");

    // Test Case 2: Overlapping copy (dst < src)
    // Copy "cdefg" (5 bytes from index 2) to index 0
    printf("Test 2: Overlapping copy (dst < src)\n");
    strcpy(buffer, src); // Reset buffer to "abcdefghijklmnopqrstuvwxyz"
    printf("Original buffer: \"%s\"\n", buffer);
    ft_memmove(buffer, buffer + 2, 5);
    buffer[5] = '\0'; // Null-terminate for printing
    printf("Buffer after ft_memmove(buffer, buffer + 2, 5): \"%s\"\n", buffer); 
    printf("----------------------------------------\n");

    // Test Case 3: Overlapping copy (dst > src)
    // Copy "abcde" (5 bytes from index 0) to index 2
    printf("Test 3: Overlapping copy (dst > src)\n");
    strcpy(buffer, src); // Reset buffer to "abcdefghijklmnopqrstuvwxyz"
    printf("Original buffer: \"%s\"\n", buffer);
    ft_memmove(buffer + 2, buffer, 5); 
    buffer[7] = '\0'; // Null-terminate for printing (original length + 2)
    printf("Buffer after ft_memmove(buffer + 2, buffer, 5): \"%s\"\n", buffer); 
    printf("----------------------------------------\n");

    // Test Case 4: Copying zero bytes
    printf("Test 4: Copying 0 bytes\n");
    strcpy(buffer, src); // Reset buffer
    ft_memmove(buffer, buffer + 5, 0); // Copy 0 bytes
    printf("Buffer after ft_memmove(buffer, buffer + 5, 0): \"%s\"\n", buffer); 
    printf("----------------------------------------\n");

    // Test Case 5: Copying to self (should be safe)
    printf("Test 5: Copying to self\n");
    strcpy(buffer, src); // Reset buffer
    ft_memmove(buffer, buffer, strlen(buffer) + 1); // Copy buffer to itself
    printf("Buffer after ft_memmove(buffer, buffer, len): \"%s\"\n", buffer); 
    printf("----------------------------------------\n");

    // Test Case 6: Overlapping copy (dst < src), larger size
    // Copy "fghijklm" (8 bytes from index 5) to index 2
    printf("Test 6: Overlapping copy (dst < src), larger size\n");
    strcpy(buffer, src); // Reset buffer
    printf("Original buffer: \"%s\"\n", buffer);
    ft_memmove(buffer + 2, buffer + 5, 8);
    buffer[10] = '\0'; // Null-terminate for printing
    printf("ft_memmove(buffer + 2, buffer + 5, 8): \"%s\"\n", buffer); 
    printf("----------------------------------------\n");

    // Test Case 7: Overlapping copy (dst > src), larger size
    // Copy "abcdefgh" (8 bytes from index 0) to index 3
    printf("Test 7: Overlapping copy (dst > src), larger size\n");
    strcpy(buffer, src); // Reset buffer
    printf("Original buffer: \"%s\"\n", buffer);
    ft_memmove(buffer + 3, buffer, 8);
    buffer[11] = '\0'; // Null-terminate for printing
    printf("Buffer after ft_memmove(buffer + 3, buffer, 8): \"%s\"\n", buffer); 
    printf("----------------------------------------\n");

    // Test Case 8: NULL pointers with n=0 (should return dst)
    printf("Test 8: NULL pointers with n=0\n");
    char *null_result = ft_memmove(NULL, NULL, 0);
    printf("ft_memmove(NULL, NULL, 0) returned: %p\n", (void*)null_result);
    printf("----------------------------------------\n");

    // Note: Testing NULL pointers with n > 0 results in undefined behavior
    // according to the C standard, so we won't explicitly test those here
    // as they might cause crashes.

    return (0);
}
*/