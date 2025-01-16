/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:25:12 by mkwizera          #+#    #+#             */
/*   Updated: 2025/01/16 15:57:45 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_we_push;

	if (!*src)
		return ;
	node_we_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_we_push -> prev = NULL;
	if (!*dest)
	{
		*dest = node_we_push;
		node_we_push -> next = NULL;
	}
	else
	{
		node_we_push -> next = (*dest);
		node_we_push -> next -> prev = node_we_push;
		*dest = node_we_push;
	}
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}
