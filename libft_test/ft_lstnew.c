/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:15:02 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 22:15:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
#include <stdio.h>

int main(void)
{
    // Test case 1: Create a node with string content
    char *str_content = "Hello, Libft!";
    t_list *node1 = ft_lstnew(str_content);

    printf("Test Case 1: String Content\n");
    if (node1)
    {
        printf("Node created successfully.\n");
        printf("Content: %s\n", (char *)node1->content);
        if (node1->next == NULL)
            printf("Next pointer is NULL (correct).\n");
        else
            printf("Next pointer is NOT NULL (incorrect).\n");

        // Verify content
        if (strcmp((char *)node1->content, str_content) == 0)
            printf("Content matches original string (correct).\n");
        else
            printf("Content does not match original string (incorrect).\n");

        // Free the node
        free(node1);
        printf("Node freed.\n");
    }
    else
    {
        printf("Failed to create node.\n");
    }

    printf("\n");

    // Test case 2: Create a node with integer content (requires casting)
    int int_val = 42;
    t_list *node2 = ft_lstnew(&int_val); // Pass the address of the integer

    printf("Test Case 2: Integer Content\n");
    if (node2)
    {
        printf("Node created successfully.\n");
        // Need to cast back to int pointer and dereference to print the value
        printf("Content: %d\n", *(int *)node2->content);
        if (node2->next == NULL)
            printf("Next pointer is NULL (correct).\n");
        else
            printf("Next pointer is NOT NULL (incorrect).\n");

        // Verify content
        if (*(int *)node2->content == int_val)
             printf("Content matches original integer (correct).\n");
        else
             printf("Content does not match original integer (incorrect).\n");

        // Free the node
        free(node2);
        printf("Node freed.\n");
    }
    else
    {
        printf("Failed to create node.\n");
    }

    return (0);
}
    */