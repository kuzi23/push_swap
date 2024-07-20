/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:00:32 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 16:59:58 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(node **stack)
{
	node	*last_node;
	node	*firstnode;
	node	*secondnode;

	last_node = lastnode(stack);
	firstnode = (*stack);
	secondnode = firstnode->next;
	firstnode->next = NULL;
	secondnode->prev = NULL;
	firstnode->prev = last_node;
	last_node->next = firstnode;
	(*stack) = secondnode;
}

void	ra(node **a, bool print)
{
	rotate(a);
	if (print == true)
	{
		write(1, "ra\n", 3);
	}
}

void	rb(node **b, bool print)
{
	rotate(b);
	if (print == true)
	{
		write(1, "rb\n", 3);
	}
}

void	rr(node**a, node**b, bool print)
{
	rotate(a);
	rotate(b);
	if (print == true)
	{
		write(1, "rb\n", 3);
	}
}
