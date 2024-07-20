/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:20:15 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 19:33:04 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_swap(node **a, node **b)
{
    int lenstack_a;

    lenstack_a = stack_len(*a);
    if (lenstack_a-- > 3 && (stack_sorted(*a) == false))
        pa(a, b, true);
    if (lenstack_a-- > 3 && (stack_sorted(*a) == false))
        pa(a, b, true);
    while (lenstack_a > 3 && (stack_sorted(*a) == false))
    {
        init_a(a, b)
    }
    sort_three(a);
    while (!(b))
    {
        init_a()
    }
}