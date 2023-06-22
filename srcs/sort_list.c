/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:22:54 by thibault          #+#    #+#             */
/*   Updated: 2023/06/22 21:53:47 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	sort(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	if (check_duplicates(*list_a) < 0)
		exit (0);
	if (ft_lstsize(*list_a) <= 1)
		return (0);
	if (ft_lstsize(*list_a) <= 3)
	{
		sort_list(list_a, list_b, tmp_list);
		return (0);
	}
	if (check_sorted(*list_a) < 0)
		return (0);
	if (ft_lstsize(*list_a) <= 50)
		a_to_b_50(list_a, list_b, tmp_list);
	else
		a_to_b_100(list_a, list_b, tmp_list);
	if (*list_b)
		b_to_a(list_a, list_b, tmp_list);
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

int	sort_case_2(t_nb **l_a, t_nb **l_b, char **tmp_l, t_nb *third_el)
{
	t_nb	*first_el;
	t_nb	*sec_el;

	first_el = *l_a;
	sec_el = (*l_a)->next;
	if (sec_el->nb < third_el->nb)
		return (0);
	else if (first_el->nb < third_el->nb)
	{
		push(l_a, l_b, "b", tmp_l);
		swap(l_a, "a", tmp_l);
		push(l_b, l_a, "a", tmp_l);
	}
	else
		reverse_rotate(l_a, "a", tmp_l);
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