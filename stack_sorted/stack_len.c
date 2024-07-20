/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:41:49 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 15:44:06 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_len(node *stack)
{
	int		i;
	node	*current;

	current = stack;
	i = 0;
	if (!(current))
		return (0);
	while (current != NULL)
	{
		i += 1;
		current = current->next;
	}
	return (i);
}
