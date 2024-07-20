/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:47 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 18:12:36 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	find_median(node **stack) // using the turtoise and hare algorithm
{
	node	*slow;
	node	*fast;
	node	*prev_slow;

	slow = (*stack);
	fast = (*stack);
	prev_slow = NULL;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}
	if (fast != NULL)
	{
		return (slow->nbr);
	}
	else
	{
		return ((prev_slow->nbr + slow->nbr) / 2.0);
	}
}

int	find_max(node **max)
{
	int		current;
	node	*temp;

	temp = *max;
	if (temp == NULL)
		return (0);
	current = temp->nbr;
	while (temp != NULL)
	{
		if (temp->nbr > current)
		{
			current = temp->nbr;
		}
		temp = temp->next;
	}
	return (current);
}

void	turk_sort(node **a, node **b)
{
	double	median;
	int		len;
	int		rotations;
	int		max_value;

	len = stack_len(*a);
	rotations = 0;
	while (stack_sorted(*a) != true && len--)
	{
		median = find_median(a);
		if ((*a)->nbr > median)
		{
			pb(a, b, true);
			sa(a, true);
		}
		else
		{
			ra(a, true);
			rotations++;
		}
	}
	while (rotations--)
	{
		rra(a, true);
	}
	while (*b != NULL)
	{
		max_value = find_max(b);
		while ((*b) != NULL && (*b)->nbr != max_value)
		{
			rb(b, true);
		}
		if (*b != NULL)
			pa(b, a, true);
	}
}
