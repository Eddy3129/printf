/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:57:29 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 23:05:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main(void)
{
    t_list *head = NULL;
    t_list *new_node;
    int size;

    printf("--- Testing ft_lstsize ---\n\n");

    // Test 1: Empty list
    size = ft_lstsize(head);
    printf("Size of empty list: %d\n", size);
    printf("\n");

    // Test 2: Add nodes and check size
    new_node = ft_lstnew(strdup("Node 1"));
    if (!new_node)
        return (1);
    ft_lstadd_front(&head, new_node);

    new_node = ft_lstnew(strdup("Node 2"));
    ft_lstadd_front(&head, new_node);

    new_node = ft_lstnew(strdup("Node 3"));
    ft_lstadd_front(&head, new_node);

    size = ft_lstsize(head);
    printf("Size after adding 3 nodes: %d\n", size);
    printf("\n");

    // Test 3: Add another node and check size
    new_node = ft_lstnew(strdup("Node 4"));
    ft_lstadd_front(&head, new_node);

    size = ft_lstsize(head);
    printf("Size after adding 1 more node: %d\n", size);
    printf("\n");

    return (0);
}
*/