/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:17:41 by thibault          #+#    #+#             */
/*   Updated: 2023/05/18 15:16:04 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_FUNCTIONS_H
# define INC_FUNCTIONS_H

/*main.c*/
t_nb	*argv_to_list(int argc, char **argv);
int		check_nbr(const char *str);
int		free_list(t_nb *head_list);

/*libft_fct.c*/
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);
t_nb	*ft_lstnew(int nb);
void	ft_lstadd_back(t_nb **head_list_nb, t_nb *new_nb);
t_nb	*ft_lstlast(t_nb *list_pt);
int		print_list(t_nb *list_pt);
int		ft_lstsize(t_nb *liste);
void	ft_lstadd_front(t_nb **lst, t_nb *new);
/*ft_atoi.c*/
int		ft_atoi(const char *str);

/*push_swap_reverse.c*/
int		swap(t_nb **head_list);
int		push(t_nb **head_list_a, t_nb **head_list_b);
int		rotate(t_nb **head_list);
int		reverse_rotate(t_nb **head_list);

/*quicksort.c*/
t_nb	*quick_sort(t_nb *head_list);
int		compare_elem_to_pivot(t_nb *head_list, int pivot);

#endif
