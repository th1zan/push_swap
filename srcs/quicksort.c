/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:22:54 by thibault          #+#    #+#             */
/*   Updated: 2023/05/19 00:20:45 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

t_nb *quick_sort(t_nb *head_list)
{
	t_nb    *tmp;
	t_nb    *list_a;
	t_nb    *list_b;
	t_nb    *pivot_node;
	int     pivot;
	int     size;
	
	tmp = NULL;
	// printf("coucou\n");
	/*Si la longueur de la liste est inférieure ou égale à 1
	Retourner la liste telle quelle*/
	// printf("lst_size = %d\n", ft_lstsize(head_list));
	if (ft_lstsize(head_list) <= 1)
		return (head_list);
    /*Initialiser deux listes vides : list_a et list_b*/
	list_b = NULL;
	list_a = NULL;
	
	/*Choisir un pivot (par exemple, le dernier élément de la liste)*/
    pivot_node = ft_lstlast(head_list);
    pivot = pivot_node->nb;
    // printf("pivot : nb = %d, pt = %p, prev = %p, next = %p\n", pivot_node->nb, pivot_node, pivot_node->prev, pivot_node->next);
    if (compare_elem_to_pivot(head_list, pivot))
        return (head_list);
	/* Pour chaque élément dans head_list_a
        Si l'élément est inférieur ou égal au pivot
            Ajouter l'élément à list_a
        Sinon
            Ajouter l'élément à list_b
    */
    tmp = head_list;
    size = ft_lstsize(head_list);
	while (size >= 1)
	{
		// printf("%d %d <?> %d\n", size, tmp->nb, pivot);
		if (tmp->nb <= pivot)
		{	
			// printf("nb = %d, pt = %p, prev = %p, next = %p\n", tmp->nb, tmp, tmp->prev, tmp->next);
			push(&tmp, &list_a);
			// ft_putstr_fd("ra\n", 1);
			
		}
		else
		{	
	
			push(&tmp, &list_b);
			// ft_putstr_fd("pb\n", 1);
		}
		size--;
	}	
		
	// printf("list_a\n");
	// print_list(list_a);
	// printf("list_b\n");
	// print_list(list_b);
	

	
	/*LIGNES TEST*/
	
	// printf("coucou\n");
	
	// swap(&head_list_a);
	
	// push(&head_list_a, &head_list_b);
	// push(&head_list_a, &head_list_b);
	// print_list(head_list_a);
	// print_list(head_list_b);
	
	// rotate(&head_list_a);
	// rotate(&head_list_a);
	// print_list(head_list_a);
	// print_list(head_list_b);
	
	// reverse_rotate(&head_list_a);
	// reverse_rotate(&head_list_a);
	// print_list(head_list_a);
	// print_list(head_list_b);
	/*FIN LIGNES TEST*/
	
	/*Trier récursivement list_a en appelant Quicksort(list_a)*/
    /*Trier récursivement list_b en appelant Quicksort(list_b)*/
	// printf("-------sITERATION QUICK SORT-----\n");
	// head_list = NULL;
	

	list_a = quick_sort(list_a);
	if (!list_b)
		list_b = quick_sort(list_b);

	if (list_a != NULL)
	{
		tmp = ft_lstlast(list_a);
		tmp->next = list_b;
		if (list_b != NULL)
			list_b->prev = tmp;
	}
	else
	{
		list_a = list_b;
	}
	
	// head_list = list_a;
	// printf("head_list\n");
	// print_list(head_list);
	
	return (list_a);
}

/*
Algorithme Quicksort(head_list_a, head_list_b)
    Si la longueur de la liste est inférieure ou égale à 1
        Retourner la liste telle quelle
    
    Choisir un pivot (par exemple, le dernier élément de la liste)
    Initialiser deux listes vides : list_a et list_b
    
    Pour chaque élément dans head_list_a
        Si l'élément est inférieur ou égal au pivot
            Ajouter l'élément à list_a
        Sinon
            Ajouter l'élément à list_b
    
    Pour chaque élément dans head_list_b
        Si l'élément est inférieur au pivot
            Ajouter l'élément à list_a
        Sinon
            Ajouter l'élément à list_b
    
    Trier récursivement list_a en appelant Quicksort(list_a)
    Trier récursivement list_b en appelant Quicksort(list_b)
    
    Concaténer list_a, le pivot et list_b pour obtenir la liste triée
    
    Retourner la liste triée
*/

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