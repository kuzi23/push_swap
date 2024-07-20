/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:00:56 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 16:24:37 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_strtol(char *str, char **endptr, int base)
{
	long int	num;
	int			i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '0' || str[i] == '1'
			|| str[i] == '2' || str[i] == '3'
			|| str[i] == '4' || str[i] == '5'
			|| str[i] == '6' || str[i] == '7'
			|| str[i] == '8' || str[i] == '9')
			num = num * base + (str[i] - '0');
		else
		{
			*endptr = &str[i];
			break ;
		}
		i++;
	}
	return (num);
}
