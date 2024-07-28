/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzi <kuzi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:33:39 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/28 00:36:38 by kuzi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node	*get_cheapest(node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

node *find_lowest(node **min)
{
    if (*min == NULL)
        return NULL;

    node *lowest = *min;
    node *temp = *min;

    while (temp != NULL)
    {
        if (temp->nbr < lowest->nbr)
        {
            lowest = temp;
        }
        temp = temp->next;
    }
    return lowest;
}

void set_targetb(node *a, node *b)
{
    node *currentb;
    node *currenta;
    node *target;
    long best_match;

    currentb = b;
    while (currentb)
    {
        best_match = LONG_MAX;
        currenta = a;
        while (currenta)
        {
            if ((currenta->nbr < b->nbr) && (currenta->nbr > best_match))
            {
                best_match = currenta->nbr;
                target = currenta;
            }
            currenta = currenta->next;
        }
        if (best_match == LONG_MAX)
            currentb->target_node = find_lowest(&b);
        else
        {
            currentb->target_node = target;
        }
        currentb = currentb->next;
    }
}

void init_b(node **a, node **b)
{
    current_index(a);
    current_index(b);
    set_targetb(*a, *b);
}
