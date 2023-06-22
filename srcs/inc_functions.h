/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:17:41 by thibault          #+#    #+#             */
/*   Updated: 2023/06/22 22:25:26 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_FUNCTIONS_H
# define INC_FUNCTIONS_H

/*fct_argv_argc.c*/
char	**analyze_argv(char **argv);
int		count_argc(char **new_argv);
t_nb	*argv_to_list(int argc, char **argv);

/*fct_check*/
int		check_duplicates(t_nb *list_a);
int		check_nbr(const char *str);
int		check_int(const char *str);
int		check_sorted(t_nb *list_a);

/*fct_get_minmax.c*/
int		get_max(t_nb **head_list);
int		get_min(t_nb **head_list);

/*handle_list.c*/
t_nb	*ft_lstnew(int nb);
void	ft_lstadd_back(t_nb **head_list_nb, t_nb *new_nb);
t_nb	*ft_lstlast(t_nb *list_pt);
int		ft_lstsize(t_nb *liste);
void	ft_lstadd_front(t_nb **lst, t_nb *new);

/*fct_libft.c*/
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

/*fct_octile.c*/
int		get_octile(t_nb *head_list, int octile);
int		bubble_sort(int *arr, int size);
int		*allocate_values_array(t_nb *head_list, int count);
int		compute_octile_value(int octile, int count, int *values);

/*fct_utils.c*/
int		print_list(t_nb *list_pt);
int		nb_op(char *tmp_list);

/*ft_atoi.c*/
int		ft_atoi(const char *str);

/*printf files*/
int		ft_printf(const char *str, ...);
int		ft_printf_format(const char *s, va_list args, int *r);
int		ft_printf_c(unsigned char c, int *result);
int		ft_printf_s(char *s, int *result);
int		ft_printf_di(int n, int *result);
int		ft_printf_u(unsigned int n, int *result);
int		ft_printf_hex(unsigned long dec, int *result, int cap);
int		ft_printf_ptr(unsigned long dec, int *result);

/*ft_split.c*/
void	ft_strcpy(char *dst, char *init, char *fin);
int		ft_nbline(char *s, char c);
void	ft_tab(char **tab, char *s, char c);
char	**ft_split(char const *s, char c);

/*main.c*/
int		main(int argc, char **argv);
t_nb	*get_arg(int new_argc, char **new_argv, t_nb *list_a);
int		free_list(t_nb *head_list);
int		free_new_argv(char **new_argv, int new_argc);

/*push_swap_reverse.c*/
int		swap(t_nb **h_list, char *stack, char **tmp_list);
int		edit_list(char *fct, char *stack, char **tmp_list);
int		push(t_nb **h_list_a, t_nb **h_list_b, char *stack, char **tmp_list);
int		rotate(t_nb **h_list, char *stack, char **tmp_list);
int		reverse_rotate(t_nb **h_list, char *stack, char **tmp_list);
int		count_argc(char **new_argv);

/*sort_a_to_b_50.c*/
int		a_to_b_50(t_nb **list_a, t_nb **list_b, char **tmp_list);

/*sort_a_to_b_100.c*/
int		a_to_b_100(t_nb **list_a, t_nb **list_b, char **tmp_list);
int		*get_octile_tab(t_nb **list_a, int *octile_tab);
int		a_to_b_100_last_octile(t_nb **list_a, t_nb **list_b, char **tmp_list);

/*sort_b_to_a.c*/
int		rotate_b_to_a(t_nb **list_b, char **tmp_list, int position);
int		r_rotate_b_to_a(t_nb **list_b, char **tmp_list, int size, int position);
int		b_to_a(t_nb **list_a, t_nb **list_b, char **tmp_list);

/*sort_list.c*/
int		sort(t_nb **list_a, t_nb **list_b, char **tmp_list);
int		sort_list(t_nb **list_a, t_nb **list_b, char **tmp_list);
int		sort_case_1(t_nb **list_a, char **tmp_list, t_nb *third_el);
int		sort_case_2(t_nb **l_a, t_nb **l_b, char **tmp_l, t_nb *third_el);

#endif
