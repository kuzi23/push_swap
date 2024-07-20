/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:47:32 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 21:52:44 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include <errno.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct t_stack_node
{
	int						nbr;
	bool					above_median;
	int						index;
	int						push_cost;
	bool					cheapest;
	struct t_stack_node		*target_node;
	struct t_stack_node		*next;
	struct t_stack_node		*prev;
}	node;

//overall functions
void		free_stack(node **a);
long int	ft_strtol(char *str, char **endptr, int base);
int			init_stack_a(node **a, char **argv);
char		**split(const char *s, char c);
size_t		ft_strlen(const char *s);
void		turk_sort(node **a, node **b);
void		sort_three(node **stack);
int			stack_len(node *stack);
bool		stack_sorted(node *stack);
void		bubble_sort(node **stack);

//role
void		rra(node **a, bool print);
void		pa(node **a, node **b, bool print);
void		pb(node **a, node **b, bool print);
void		rrb(node **b, bool print);
void		rrr(node **a, node **b, bool print);
void		ra(node **a, bool print);
void		rb(node **b, bool print);
void		rr(node **a, node **b, bool print);
void		sa(node **a, bool print);
void		sb(node **a, bool print);

//insiders
int			ft_word_count(const char *s, char c);

//node related functions
node		*create_node(int value);
node		*lastnode(node **a);
double		find_median(node **stack);
int			find_max(node **max);

#endif