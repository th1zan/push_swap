/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:22:54 by thibault          #+#    #+#             */
/*   Updated: 2023/06/06 11:09:00 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

t_nb *sort(t_nb **head_list)
{
	t_nb *list_a;
	t_nb *list_b;
	
	list_b = NULL;
	list_a = *head_list;
	list_a = a_to_b(list_a, list_b);
	// head_list = a_to_b(head_list);
	return (list_a);
}

t_nb *a_to_b(t_nb *list_a, t_nb *list_b)
{
	// t_nb    *tmp;
	// t_nb    *list_a;
	// t_nb    *list_b;
	// t_nb    *pivot_node;
	int     pivot;
	int     size;
	
	// tmp = NULL;
	// printf("coucou\n");
	/*Si la longueur de la liste est inférieure ou égale à 1
	Retourner la liste telle quelle*/
	// printf("lst_size = %d\n", ft_lstsize(head_list));
	if (ft_lstsize(list_a) <= 1)
		return (list_a);
	if (ft_lstsize(list_a) <= 3)
	{
		// print_list(head_list);
		list_a = sort_list(list_a);
		return (list_a);
	}
    /*Initialiser deux listes vides : list_a et list_b*/
	// list_b = NULL;
	// list_a = head_list;
	
	/*Choisir un pivot (par exemple, le dernier élément de la liste)*/
    size = ft_lstsize(list_a);
    while (size >= 3)
    {
	    pivot = get_median(list_a);
			    // pivot_node = ft_lstlast(list_a);
			    // pivot = pivot_node->nb;
			    // printf("pivot : nb = %d, pt = %p, prev = %p, next = %p\n", pivot_node->nb, pivot_node, pivot_node->prev, pivot_node->next);
	    if (compare_elem_to_pivot(list_a, pivot))
	        return (list_a);
		/* Pour chaque élément dans head_list_a
	        Si l'élément est inférieur ou égal au pivot
	            Ajouter l'élément à list_a
	        Sinon
	            Ajouter l'élément à list_b
	    */
	    // tmp = list_a;
		while (size >= 1)
		{
			// printf("%d %d <?> %d\n", size, tmp->nb, pivot);
			list_a->pivot = pivot;
			rotate(&list_a, 'a');
			if (list_a->nb >= pivot)
			{	
				list_a->pivot = pivot;
				push(&list_a, &list_b, 'b');
				// printf("nb = %d, pt = %p, prev = %p, next = %p\n", tmp->nb, tmp, tmp->prev, tmp->next);
			}
			size--;
		}	
		size = ft_lstsize(list_a);
	}
	printf("list_a\n");
	print_list(list_a);
	printf("list_b\n");
	print_list(list_b);
	
	

	
	return (list_a);
}

int compare_elem_to_pivot(t_nb *head_list, int pivot)
{
	t_nb    *tmp;
	
	tmp = head_list;
	while (tmp != 0)
	{
		// printf("nb = %d =? %d\n", tmp->nb, pivot);
		if (tmp->nb != pivot)
			return(0);
		tmp = tmp->next;
	}	
	return (1);
}

t_nb *sort_list(t_nb *head_list)
{
	t_nb    *first_el;
	t_nb    *sec_el;
	t_nb    *third_el;
	t_nb    *head_list_b;
	
	first_el = head_list;
	sec_el = head_list->next;
	third_el = sec_el->next;
	head_list_b = NULL;
	if (ft_lstsize(head_list) == 2)
	{
		if (first_el->nb > sec_el->nb)
			rotate(&head_list, 'a');
		//PRINT
			// ft_putstr_fd("test tri 2 nb", 1);
			// print_list(head_list);
		return (head_list);
	}
	if (first_el->nb > sec_el->nb)
	{
		if (first_el->nb < third_el->nb)
			swap(&head_list, 'a');
		else if (sec_el->nb < third_el->nb)
			rotate(&head_list, 'a');
		else
		{
			reverse_rotate(&head_list, 'a');
			swap(&head_list, 'a');
			rotate(&head_list, 'a');
		}
	}
	if (first_el->nb < sec_el->nb)
	{
		if (sec_el->nb < third_el->nb);
		else if (first_el->nb < third_el->nb)
		{
			push(&head_list, &head_list_b, 'a');
			swap(&head_list, 'a');
			push(&head_list_b, &head_list, 'b');
		}
		else
			reverse_rotate(&head_list, 'a');
	}
		//PRINT
			// ft_putstr_fd("test tri 3 nbs", 1);
			// print_list(head_list);
	return (head_list);
}

/*
cas de figure
1 2 3   y1 3 2  x2 1 3     y2 3 1   x3 1 2   x3 2 1
ras             swap        rr        r        rr
				1 2 3      1 2 3    1 3 2    1 3 2
		push                                  swap
		3 2 / 1                              3 1 2
		swap                                   r
		2 3 / 1                              1 2 3
		push
		1 2 3 

*/