/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzi <kuzi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:20:15 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/28 00:44:42 by kuzi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node *find_highest(node **max)
{
    if (*max == NULL)
        return NULL;

    node *highest = *max;
    node *temp = *max;

    while (temp != NULL)
    {
        if (temp->nbr > highest->nbr)
        {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

static void min_on_top(node **a)
{
	while ((*a)->nbr != find_lowest(a)->nbr)
	{
		if(find_lowest(a)->above_median)
			ra(a, true);
		else
		{
			rra(a, true);
		}
	}
}

void	push_swap(node **a, node **b)
{
	int	lenstack_a;

	lenstack_a = stack_len(*a);
	if (lenstack_a-- > 3 && (stack_sorted(*a) == false))
		pa(a, b, true);
	if (lenstack_a-- > 3 && (stack_sorted(*a) == false))
		pa(a, b, true);
	while (lenstack_a > 3 && (stack_sorted(*a) == false))
	{
		inti_nodes_a(*a, *b);
		move_a_to_b(a, b);
        lenstack_a--;
	}
	sort_three(a);
	while (!(b))
	{
		init_b(a, b);
		move_b_to_a(a, b);
	}
	current_index(a);
	min_on_top(a);
}
