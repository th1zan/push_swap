/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:50:15 by tsanglar          #+#    #+#             */
/*   Updated: 2023/05/11 15:05:24 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





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
	Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
	
rrb (reverse rotate b) :
	Décale d’une position vers le bas tous les élements de
	la pile b. Le dernier élément devient le premier.
	
rrr :
	rra et rrb en même temps
*/