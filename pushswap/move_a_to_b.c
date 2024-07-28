/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzi <kuzi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:19:43 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/28 00:04:34 by kuzi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(node **a,node **b, node* cheapest_node)
{
	while (*b != cheapest_node-> target_node && *a != cheapest_node)
	{
		rr(a, b, true);
	}
	current_index(a);
	current_index(b);
}

static void rev_rotate_both(node **a, node **b, node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		rrr(a, b, true);
	}
	current_index(a);
	current_index(b);
}

static void prep_for_push(node **stack, node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void move_a_to_b(node **a, node**b)
{
	node *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median && cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(a, cheapest_node->target_node, 'b');
	pa(b, a, false);
}

void move_b_to_a(node **a, node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pb(a, b, true);
}