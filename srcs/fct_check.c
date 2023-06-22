/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:21:06 by tsanglar          #+#    #+#             */
/*   Updated: 2023/06/22 21:39:41 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	check_duplicates(t_nb *list_a)
{
	t_nb	*current;
	t_nb	*temp;

	current = list_a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->nb == temp->nb)
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_sorted(t_nb *list_a)
{
	t_nb	*current;
	t_nb	*next;

	current = list_a;
	while (current->next != NULL)
	{
		next = current->next;
		if (current->nb > next->nb)
			return (0);
		next = next->next;
		current = current->next;
	}
	return (-1);
}

int	check_nbr(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_int(const char *str)
{
	double	result;
	int		neg;
	int		i;

	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	result = result * neg;
	if (result < -2147483648 || result > 2147483647)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}
