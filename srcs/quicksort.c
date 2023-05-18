/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:22:54 by thibault          #+#    #+#             */
/*   Updated: 2023/05/18 17:38:00 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

t_nb *quick_sort(t_nb *head_list)
{
	t_nb    *tmp;
	t_nb    *right_list;
	t_nb    *left_list;
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
    /*Initialiser deux listes vides : left_list et right_list*/
	right_list = NULL;
	left_list = NULL;
	
	/*Choisir un pivot (par exemple, le dernier élément de la liste)*/
    pivot_node = ft_lstlast(head_list);
    pivot = pivot_node->nb;
    // printf("pivot : nb = %d, pt = %p, prev = %p, next = %p\n", pivot_node->nb, pivot_node, pivot_node->prev, pivot_node->next);
    if (compare_elem_to_pivot(head_list, pivot))
        return (head_list);
	/* Pour chaque élément dans head_list_a
        Si l'élément est inférieur ou égal au pivot
            Ajouter l'élément à left_list
        Sinon
            Ajouter l'élément à right_list
    */
    tmp = head_list;
    size = ft_lstsize(head_list);
	while (size >= 1)
	{
		// printf("%d %d <?> %d\n", size, tmp->nb, pivot);
		if (tmp->nb <= pivot)
		{	
			// printf("nb = %d, pt = %p, prev = %p, next = %p\n", tmp->nb, tmp, tmp->prev, tmp->next);
			push(&tmp, &left_list);
			
		}
		else
		{	
	
			push(&tmp, &right_list);			
		}
		size--;
	}	
		
	// printf("left_list\n");
	// print_list(left_list);
	// printf("right_list\n");
	// print_list(right_list);
	

	
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
	
	/*Trier récursivement left_list en appelant Quicksort(left_list)*/
    /*Trier récursivement right_list en appelant Quicksort(right_list)*/
	// printf("-------sITERATION QUICK SORT-----\n");
	// head_list = NULL;
	

	left_list = quick_sort(left_list);
	right_list = quick_sort(right_list);

	if (left_list != NULL)
	{
		tmp = ft_lstlast(left_list);
		tmp->next = right_list;
		if (right_list != NULL)
			right_list->prev = tmp;
	}
	else
	{
		left_list = right_list;
	}
	
	// head_list = left_list;
	// printf("head_list\n");
	// print_list(head_list);
	
	return (left_list);
}

/*
Algorithme Quicksort(head_list_a, head_list_b)
    Si la longueur de la liste est inférieure ou égale à 1
        Retourner la liste telle quelle
    
    Choisir un pivot (par exemple, le dernier élément de la liste)
    Initialiser deux listes vides : left_list et right_list
    
    Pour chaque élément dans head_list_a
        Si l'élément est inférieur ou égal au pivot
            Ajouter l'élément à left_list
        Sinon
            Ajouter l'élément à right_list
    
    Pour chaque élément dans head_list_b
        Si l'élément est inférieur au pivot
            Ajouter l'élément à left_list
        Sinon
            Ajouter l'élément à right_list
    
    Trier récursivement left_list en appelant Quicksort(left_list)
    Trier récursivement right_list en appelant Quicksort(right_list)
    
    Concaténer left_list, le pivot et right_list pour obtenir la liste triée
    
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