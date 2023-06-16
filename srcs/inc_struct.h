/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:31:25 by thibault          #+#    #+#             */
/*   Updated: 2023/06/16 13:43:19 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_STRUCT_H
# define INC_STRUCT_H

typedef struct s_nb
{
	int			nb;
	int			pivot;
	int			index;
	struct s_nb	*prev;
	struct s_nb	*next;
}	t_nb;
#endif