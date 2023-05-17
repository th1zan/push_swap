/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:22:54 by thibault          #+#    #+#             */
/*   Updated: 2023/05/16 16:10:07 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

t_nb *quick_sort(t_nb *head_list_a, t_nb *head_list_b)
{
	t_nb    *tmp;
	t_nb    *right_list;
	t_nb    *left_list;
	int     pivot;
	int     size;
	
	
	tmp = NULL;
	/*Si la longueur de la liste est inférieure ou égale à 1
	Retourner la liste telle quelle*/
	if (ft_lstsize(head_list_a) <= 1)
		return (head_list_a);
	/*Choisir un pivot (par exemple, le dernier élément de la liste)*/
    tmp = ft_lstlast(head_list_a);
    pivot = tmp->nb;
    /*Initialiser deux listes vides : left_list et right_list*/
	right_list = NULL;
	left_list = NULL;
	/* Pour chaque élément dans head_list_init
        Si l'élément est inférieur ou égal au pivot
            Ajouter l'élément à left_list
        Sinon
            Ajouter l'élément à right_list
    */
    tmp = head_list_a;
    size = ft_lstsize(head_list_a);
	while (size >= 1)
	{
		printf("%d %d <?> %d\n", size, tmp->nb, pivot);
		if (tmp->nb <= pivot)
		{	
			printf("nb = %d, pt = %p, prev = %p, next = %p\n", tmp->nb, tmp, tmp->prev, tmp->next);
			push(&tmp, &left_list);
			
		}
		else
		{	
	
			push(&tmp, &right_list);			
		}
		size--;
		
		
	}	
		// printf("coucou\n");
	
	printf("left_list\n");
	print_list(left_list);
	printf("right_list\n");
	print_list(right_list);
	
	// tmp = head_list_b;
	
	// swap(&head_list_a);
	print_list(head_list_a);
	print_list(head_list_b);
	
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
	
	return (head_list_a);
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