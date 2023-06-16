/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:17:41 by thibault          #+#    #+#             */
/*   Updated: 2023/06/16 11:54:15 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_FUNCTIONS_H
# define INC_FUNCTIONS_H

/*main.c*/
t_nb	*argv_to_list(int argc, char **argv);
int		check_nbr(const char *str);
int		free_list(t_nb *head_list);
int		nb_op(char *tmp_list);
int		check_duplicates(t_nb *list_a);

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
int		get_median(t_nb *list_pt);
int		get_quartile(t_nb *head_list, int quartile);
int		get_octile(t_nb *head_list, int octile);
int		bubble_sort(int *arr, int size);
int		get_max(t_nb **list_pt);
int		get_min(t_nb **head_list);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
/*ft_atoi.c*/
int		ft_atoi(const char *str);

/*push_swap_reverse.c*/
int		swap(t_nb **head_list, char *stack, char **tmp_list);
int		push(t_nb **head_list_a, t_nb **head_list_b, char *stack, char **tmp_list);
int		rotate(t_nb **head_list, char *stack, char **tmp_list);
int		reverse_rotate(t_nb **head_list, char *stack, char **tmp_list);
int		edit_list(char *fct, char *stack, char **tmp_list);
/*quicksort.c*/
int		sort(t_nb **list_a, t_nb **list_b, char **tmp_list);
int		a_to_b_50(t_nb **list_a, t_nb **list_b, char **tmp_list);
int		a_to_b_100(t_nb **list_a, t_nb **list_b, char **tmp_list);
int		compare_elem_to_pivot(t_nb *head_list, int pivot);
int		sort_list(t_nb **list_a, t_nb **list_b, char **tmp_list);
int		b_to_a(t_nb **list_a, t_nb **list_b, char **tmp_list);

/*printf*/
int		ft_printf(const char *str, ...);
int		ft_printf_format(const char *s, va_list args, int *r);
int		ft_printf_c(unsigned char c, int *result);
int		ft_printf_s(char *s, int *result);
int		ft_printf_di(int n, int *result);
int		ft_printf_u(unsigned int n, int *result);
int		ft_printf_hex(unsigned long dec, int *result, int cap);
int		ft_printf_ptr(unsigned long dec, int *result);

#endif
