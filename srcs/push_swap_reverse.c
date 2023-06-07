/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:50:15 by tsanglar          #+#    #+#             */
/*   Updated: 2023/06/05 17:59:02 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int swap(t_nb **head_list, char stack)
{
    t_nb *sec_el;
    t_nb *third_el;
    
    if (!(*head_list) || !(*head_list)->next)
        return (-1);
    
    sec_el = (*head_list)->next;
    third_el = sec_el->next;
    
    (*head_list)->next = third_el;
    (*head_list)->prev = sec_el;
    sec_el->next = (*head_list);
    sec_el->prev = (*head_list)->prev;;
    if (third_el)
        third_el->prev = (*head_list);
    (*head_list) = sec_el;
    (*head_list)->prev = NULL;
    ft_printf("s%c\n", stack);
    return (0);
}

int push(t_nb **head_list_a, t_nb **head_list_b, char stack)
{
	t_nb    *tmp;
	
	if (!head_list_a)
		return (0);
		
	tmp = *head_list_a;
	
	if ((*head_list_a)->next != NULL)
		*head_list_a = (*head_list_a)->next;
	(*head_list_a)->prev = NULL;
	tmp->next = *head_list_b;
	tmp->prev = NULL;
	*head_list_b = tmp;
	if ((*head_list_a)->next)
	{
		tmp = (*head_list_a)->next;
		tmp->prev = *head_list_a;
	}
	else
		tmp->prev = NULL;

	if ((*head_list_b)->next)
	{
		tmp = (*head_list_b)->next;
		tmp->prev = *head_list_b;
	}
	else
		tmp->prev = NULL;
	ft_printf("p%c\n", stack);
	return (0);
}

int rotate(t_nb **head_list, char stack)
{
	t_nb    *tmp;
	t_nb    *last;
	
	if (!head_list)
		return (-1);
	tmp = *head_list;
	last = ft_lstlast(*head_list);
	(*head_list) = (tmp)->next;
	(*head_list)->prev = NULL;
	last->next = tmp;
	tmp->next = NULL;
	tmp->prev = last;
	ft_printf("r%c\n", stack);
	return (0);
}

int reverse_rotate(t_nb **head_list, char stack)
{
	t_nb    *first;
	t_nb    *last;
	t_nb    *b_last;
	
	if (!head_list)
		return (-1);
	first = *head_list;
	last = ft_lstlast(first);
	b_last = last->prev;
	if(last->prev == first)
	{
		swap(head_list, stack);
		ft_printf("s%c\n", stack);
		return (0);
	}
	b_last->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	(*head_list) = last;
	ft_printf("rr%c\n", stack);
	return (0);
}


/*
sa (swap a) :
	Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.

sb (swap b ) :
	Intervertit les 2 premiers éléments au sommet de la pile b.
	Ne fait rien s’il n’y en a qu’un ou aucun.

ss : 
	sa et sb en même temps.

pa (push a) :
	Prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.

pb (push b) :
	Prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.

ra (rotate a) :
	Décale d’une position vers le haut tous les élements de la pile a.
	Le premier élément devient le dernier.

rb (rotate b) :
	Décale d’une position vers le haut tous les élements de la pile b.
	Le premier élément devient le dernier.
rr :
	ra et rb en même temps.

rra (reverse rotate a) :
	Décale d’une position vers le bas tous les élements de la pile a.
	Le dernier élément devient le premier.
	
rrb (reverse rotate b) :
	Décale d’une position vers le bas tous les élements de
	la pile b. Le dernier élément devient le premier.
	
rrr :
	rra et rrb en même temps
*/