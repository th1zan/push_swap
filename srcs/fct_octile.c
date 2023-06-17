/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_octile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:21:51 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 12:25:29 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	get_octile(t_nb *head_list, int octile)
{
	int		count;
	t_nb	*tmp;
	int		*values;
	int		octile_value;

	count = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	values = allocate_values_array(head_list, count);
	bubble_sort(values, count);
	octile_value = compute_octile_value(octile, count, values);
	free(values);
	return (octile_value);
}

int	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*allocate_values_array(t_nb *head_list, int count)
{
	int		*values;
	int		i;
	t_nb	*tmp;

	values = (int *)malloc(count * sizeof(int));
	i = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		values[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	return (values);
}

int	compute_octile_value(int octile, int count, int *values)
{
	int	octile_value;
	int	index;

	octile_value = -1;
	if (octile >= 1 && octile <= 8)
	{
		index = (octile * count) / 8;
		octile_value = values[index];
	}
	return (octile_value);
}

/*
int	get_octile(t_nb *head_list, int octile)
{
	int		count;
	int		*values;
	int		octile_value;
	t_nb	*tmp;
	int		index;
	int		i;

	count = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	values = (int *)malloc(count * sizeof(int));
	i = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		values[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	bubble_sort(values, count);
	if (octile >= 1 && octile <= 8)
	{
		index = (octile * count) / 8;
		octile_value = values[index];
	}
	else
		octile_value = -1;
	free(values);
	return (octile_value);
}
*/