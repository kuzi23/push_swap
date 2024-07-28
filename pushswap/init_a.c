/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzi <kuzi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:33:39 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/28 00:23:25 by kuzi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_index(node **stack)
{
	node	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		index = index + 1;
		current = current->next;
	}
}

void	set_target(node *a, node *b)
{
	node	*current_a;
	node	*current_b;
	node	*target;
	long	best_match;

	current_a = a;
	while (current_a != NULL)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b != NULL)
		{
			if ((current_b->nbr < a->nbr) && (current_b->nbr > best_match))
			{
				best_match = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			current_a->target_node = find_highest(&b);
		else
		{
			current_a->target_node = target;
		}
		current_a = current_a->next;
	}
}

void	cost_analysis_a(node *a, node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a != NULL)
	{
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(node *stack) // tommorrow i will finish this well
{
	node	*current_a;
	long	cheapest_value;

	if (!stack)
		return ;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			current_a = stack;
		}
		stack = stack->next;
	}
	current_a->cheapest = true;
}

void	inti_nodes_a(node *a, node *b)
{
	current_index(&a);
	current_index(&b);
	set_target(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}