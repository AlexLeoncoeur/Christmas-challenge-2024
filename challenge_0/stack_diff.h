/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_diff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:46:45 by aarenas-          #+#    #+#             */
/*   Updated: 2024/12/02 13:36:12 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_DIFF_H
# define STACK_DIFF_H

# include "libft/libft.h"

typedef struct s_stack
{
	int					nb;
	int					index;
	struct s_stack		*next;
}	t_stack;

t_stack		*ft_init_stack(void);
int			ft_lstsize_tstack(t_stack *lst);
void		ft_ordering(t_stack *stack);
void		ft_free_tstack(t_stack **lst);
void		ft_read_and_divide(int fd, t_stack *a_stack, t_stack *b_stack);

#endif