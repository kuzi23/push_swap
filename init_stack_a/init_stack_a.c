/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:03:07 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 16:19:08 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(node **a)
{
	node	*temp;

	while (*a != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
}

node	*create_node(int value)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	push(node **a, int value)
{
	node	*new_node;

	new_node = create_node(value);
	if (*a == NULL)
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		{
			new_node->next = *a;
			(*a)->prev = new_node;
			*a = new_node;
		}
	}
}

int	init_stack_a(node **a, char **argv)
{
	char	*endptr;
	long	value;
	int		i;

	i = 0;
	endptr = NULL;
	while (argv[i] != NULL)
	{
		errno = 0;
		value = strtol(argv[i], &endptr, 10);
		if (errno == ERANGE || *endptr != '\0'
			|| value > INT_MAX || value < INT_MIN)
		{
			printf("long ints only\n");
			free_stack(a);
			return (-1);
		}
		else
		{
			push(a, value);
		}
		i++;
	}
	return (0);
}