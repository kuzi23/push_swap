/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:53:07 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 15:56:09 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(node** stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if ((first > second) && (second > third))
	{
		sa(stack, true);
		rra(stack, true);
	}
	else if ((first > second) && (first > third))
		sa(stack, true);
	else if ((second > first) && (second > third))
	{
		if (first > third)
			ra(stack, true);
		else
		{
			sa(stack, true);
			ra(stack, true);
		}
	}
	else if ((third > first) && (second > first))
		rra(stack, true);
	else if ((third > first) && (first > second))
	{
		sa(stack, true);
		rra(stack, true);
	}
}
