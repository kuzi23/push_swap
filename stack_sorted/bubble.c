/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:47:07 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 15:47:11 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"

// void bubble_sort(node **stack)
// {
//     int len = stack_len(*stack);
//     int i, j;
//     node *temp;

//     for (i = 0; i < len - 1; i++)
//     {
//         for (j = 0; j < len - i - 1; j++)
//         {
//             if ((*stack)->nbr > (*stack)->next->nbr)
//             {
//                 // Swap nodes
//                 temp = (*stack);
//                 (*stack) = (*stack)->next;
//                 temp->next = (*stack)->next;
//                 (*stack)->next = temp;
//             }
//             (*stack) = (*stack)->next;
//         }
//         // Reset pointer to start of list
//         while ((*stack)->next != NULL)
//         {
//             (*stack) = (*stack)->next;
//         }
//     }
// }
