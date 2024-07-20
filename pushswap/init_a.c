/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:33:39 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 21:56:00 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inti_nodes_a(node *a, node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	current_index(node *stack)
{
	node	*current;
	int		index;

	current = stack;
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
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			current_a->target_node = find_max(&b);
		else
		{
			current_a->target_node = best_match;
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
			a->push_cost += a->target_node->index;
		a = a->next;
	}
}

void	set_cheapest(node *stack)
{
	node	*current_a;

	
}