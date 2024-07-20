/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:00:27 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 18:10:50 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node	*lastnode(node **a)
{
	node	*current;

	current = (*a);
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

static void	reverse_rotate(node **stack)
{
	node	*last_node;
	node	*seconnd_last_node;

	last_node = lastnode(stack);
	seconnd_last_node = last_node->prev;
	seconnd_last_node->next = NULL;
	last_node->prev = NULL;
	last_node->next = (*stack);
	(*stack)->prev = last_node;
	(*stack) = last_node;
}

void	rra(node **a, bool print)
{
	reverse_rotate(a);
	if (print == true)
		write(1, "rra\n", 4);
}

void	rrb(node **b, bool print)
{
	reverse_rotate(b);
	if (print == true)
		write(1, "rrb\n", 4);
}

void	rrr(node **a, node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == true)
		write(1, "rrr\n", 4);
}
