/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:25:12 by mkwizera          #+#    #+#             */
/*   Updated: 2025/01/16 15:57:12 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_lowest(*a)->nbr)
	{
		if (find_lowest(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len_stack_a;

	len_stack_a = stack_len(*a);
	if (len_stack_a-- > 3 && !(sorted_stack(*a)))
		pb(b, a);
	if (len_stack_a-- > 3 && !(sorted_stack(*a)))
		pb(b, a);
	while (len_stack_a-- > 3 && !(sorted_stack(*a)))
	{
		inti_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	three_list_sort(a);
	while (*b)
	{
		inti_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
