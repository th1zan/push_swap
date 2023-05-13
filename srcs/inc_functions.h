/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:17:41 by thibault          #+#    #+#             */
/*   Updated: 2023/05/13 15:10:31 by thibault         ###   ########.fr       */
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

/*ft_atoi.c*/
int		ft_atoi(const char *str);


#endif
