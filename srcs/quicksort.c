/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:22:54 by thibault          #+#    #+#             */
/*   Updated: 2023/06/16 14:08:04 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	sort(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	if (check_duplicates(*list_a) < 0)
	{
		ft_putstr_fd("Il y a une valeur en double", 1);
		exit (0);
	}
	if (ft_lstsize(*list_a) <= 1)
		return (0);
	if (ft_lstsize(*list_a) <= 3)
	{
		sort_list(list_a, list_b, tmp_list);
		return (0);
	}
	if (ft_lstsize(*list_a) <= 50)
		a_to_b_50(list_a, list_b, tmp_list);
	else
		a_to_b_100(list_a, list_b, tmp_list);
	if (*list_b)
		b_to_a(list_a, list_b, tmp_list);
	return (0);
}
/*
int	b_to_a(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	position;
	int	size;

	size = ft_lstsize(*list_b);
	position = get_max(list_b);
	while (size > 1)
	{
		if (position < (size / 2))
		{
			position--;
			while (position--)
				rotate(list_b, "b", tmp_list);
		}
		else
		{	
			position = size - position + 1;
			while (position--)
				reverse_rotate(list_b, "b", tmp_list);
		}
		push(list_b, list_a, "a", tmp_list);
		size = ft_lstsize(*list_b);
		position = get_max(list_b);
	}
	push(list_b, list_a, "a", tmp_list);
	return (0);
}
*/

int	rotate_b_to_a(t_nb **list_b, char **tmp_list, int position)
{
	position--;
	while (position--)
		rotate(list_b, "b", tmp_list);
	return (position);
}

int	r_rotate_b_to_a(t_nb **list_b, char **tmp_list, int size, int position)
{
	position = size - position + 1;
	while (position--)
		reverse_rotate(list_b, "b", tmp_list);
	return (position);
}

int	b_to_a(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;
	int	position;

	size = ft_lstsize(*list_b);
	position = get_max(list_b);
	while (size > 1)
	{
		if (position < (size / 2))
			position = rotate_b_to_a(list_b, tmp_list, position);
		else
			position = r_rotate_b_to_a(list_b, tmp_list, size, position);
		push(list_b, list_a, "a", tmp_list);
		size = ft_lstsize(*list_b);
		position = get_max(list_b);
	}
	push(list_b, list_a, "a", tmp_list);
	return (0);
}

int	a_to_b_50(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;
	int	position;

	while (ft_lstsize(*list_a) > 2)
	{
		size = ft_lstsize(*list_a);
		position = get_min(list_a);
		if (position <= (size / 2 + 1))
		{
			position--;
			while (position--)
				rotate(list_a, "a", tmp_list);
		}
		else
		{	
			position = size - position + 1;
			while (position--)
				reverse_rotate(list_a, "a", tmp_list);
		}
		push(list_a, list_b, "b", tmp_list);
	}
	sort_list(list_a, list_b, tmp_list);
	while (ft_lstsize(*list_b) > 0)
		push(list_b, list_a, "a", tmp_list);
	return (0);
}

int	*get_octile_tab(t_nb **list_a, int *octile_tab)
{
	int	i;

	octile_tab = (int *)malloc(sizeof(int) * 7);
// printf("octile p: %p\n", octile_tab);
	if (!octile_tab)
		return (0);
	i = 0;
	while (i <= 7)
	{
		octile_tab[i] = get_octile(*list_a, i + 1);
		i++;
	}
	return (octile_tab);
}

int	a_to_b_100_last_octile(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;

	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		push(list_a, list_b, "b", tmp_list);
		rotate(list_a, "a", tmp_list);
	}
	return (0);
}

int	a_to_b_100(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;
	int	*octile_tab;
	int	i;

	octile_tab = NULL;
	octile_tab = get_octile_tab(list_a, octile_tab);
	size = ft_lstsize(*list_a);
	i = 0;
	while (i <= 7)
	{
		while (size-- >= 0)
		{
			if ((*list_a)->nb <= octile_tab[i])
				push(list_a, list_b, "b", tmp_list);
			else
				rotate(list_a, "a", tmp_list);
		}
		size = ft_lstsize(*list_a);
		i++;
	}
	a_to_b_100_last_octile(list_a, list_b, tmp_list);
	free(octile_tab);
	return (0);
}

int	compare_elem_to_pivot(t_nb *head_list, int pivot)
{
	t_nb	*tmp;

	tmp = head_list;
	while (tmp != 0)
	{
		if (tmp->nb != pivot)
			return (0);
		tmp = tmp->next;
	}	
	return (1);
}

int	sort_case_1(t_nb **list_a, char **tmp_list, t_nb *third_el)
{
	t_nb	*first_el;
	t_nb	*sec_el;

	first_el = *list_a;
	sec_el = (*list_a)->next;
	if (first_el->nb < third_el->nb)
		swap(list_a, "a", tmp_list);
	else if (sec_el->nb < third_el->nb)
		rotate(list_a, "a", tmp_list);
	else
	{
		reverse_rotate(list_a, "a", tmp_list);
		swap(list_a, "a", tmp_list);
		rotate(list_a, "a", tmp_list);
	}
	return (0);
}

int	sort_case_2(t_nb **list_a, t_nb **list_b, char **tmp_list, t_nb *third_el)
{
	t_nb	*first_el;
	t_nb	*sec_el;

	first_el = *list_a;
	sec_el = (*list_a)->next;
	if (sec_el->nb < third_el->nb)
		return (0);
	else if (first_el->nb < third_el->nb)
	{
		push(list_a, list_b, "b", tmp_list);
		swap(list_a, "a", tmp_list);
		push(list_b, list_a, "a", tmp_list);
	}
	else
		reverse_rotate(list_a, "a", tmp_list);
	return (0);
}

int	sort_list(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	t_nb	*first_el;
	t_nb	*sec_el;
	t_nb	*third_el;

	first_el = *list_a;
	sec_el = (*list_a)->next;
	third_el = sec_el->next;
	if (ft_lstsize(*list_a) == 2)
	{
		if (first_el->nb > sec_el->nb)
			rotate(list_a, "a", tmp_list);
		return (0);
	}
	if (first_el->nb > sec_el->nb)
		sort_case_1(list_a, tmp_list, third_el);
	if (first_el->nb < sec_el->nb)
		sort_case_2(list_a, list_b, tmp_list, third_el);
	return (0);
}

/*

int	sort_list(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	t_nb	*first_el;
	t_nb	*sec_el;
	t_nb	*third_el;

	first_el = *list_a;
	sec_el = (*list_a)->next;
	third_el = sec_el->next;
	if (ft_lstsize(*list_a) == 2)
	{
		if (first_el->nb > sec_el->nb)
			rotate(list_a, "a", tmp_list);
		return (0);
	}
	if (first_el->nb > sec_el->nb)
	{
		if (first_el->nb < third_el->nb)
			swap(list_a, "a", tmp_list);
		else if (sec_el->nb < third_el->nb)
			rotate(list_a, "a", tmp_list);
		else
		{
			reverse_rotate(list_a, "a", tmp_list);
			swap(list_a, "a", tmp_list);
			rotate(list_a, "a", tmp_list);
		}
	}
	if (first_el->nb < sec_el->nb)
	{
		if (sec_el->nb < third_el->nb)
			;
		else if (first_el->nb < third_el->nb)
		{
			push(list_a, list_b, "b", tmp_list);
			swap(list_a, "a", tmp_list);
			push(list_b, list_a, "a", tmp_list);
		}
		else
			reverse_rotate(list_a, "a", tmp_list);
	}
	return (0);
}
*/