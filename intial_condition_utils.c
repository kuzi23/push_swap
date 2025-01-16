/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intial_condition_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:25:12 by mkwizera          #+#    #+#             */
/*   Updated: 2025/01/16 17:31:44 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initial(char **argv, int argc, t_stack_node **a)
{
	char	**modified_argv;

	modified_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		free_errors(NULL, NULL, 0);
	else if (argc == 2)
	{
		modified_argv = ft_split(argv[1], ' ');
		if (!modified_argv)
			return (1);
	}
	if (argc == 2)
		init_stack_a(a, modified_argv, argc);
	else
		init_stack_a(a, argv + 1, argc);
	if (argc == 2)
		free_split(modified_argv);
	return (1);
}
