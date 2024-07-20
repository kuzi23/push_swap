/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:00:37 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 17:00:06 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(node **stack)
{
	node	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(node **a, bool print)
{
	swap(a);
	if (print == true)
	{
		write(1, "sa\n", 3);
	}
}

void	sb(node **b, bool print)
{
	swap(b);
	if (print == true)
	{
		write(1, "sb\n", 3);
	}
}
