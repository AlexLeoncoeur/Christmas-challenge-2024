/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_diff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:44:02 by aarenas-          #+#    #+#             */
/*   Updated: 2024/12/02 13:34:03 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_diff.h"

void	ft_free_tstack(t_stack **lst)
{
	t_stack	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		free(aux);
	}
}

static int	ft_index_diff(t_stack *a_stack, t_stack *b_stack, int index)
{
	t_stack	*a_aux;
	t_stack	*b_aux;

	a_aux = a_stack;
	b_aux = b_stack;
	while (a_aux->index != index)
		a_aux = a_aux->next;
	while (b_aux->index != index)
		b_aux = a_aux->next;
	return (a_aux->index - b_aux->index);
}

static int	ft_total_diff_nb(t_stack *a_stack, t_stack *b_stack)
{
	int	index;
	int	total;

	index = 0;
	total = 0;
	while (index <= ft_lstsize_tstack(a_stack))
	{
		total += ft_index_diff(a_stack, b_stack, index);
		index++;
	}
	return (total);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		total;
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_WRONLY);
	if (fd < 0)
		perror("Error");
	total = 0;
	a_stack = ft_init_stack();
	b_stack = ft_init_stack();
	printf("pipo\n");
	ft_read_and_divide(fd, a_stack, b_stack);
	ft_ordering(a_stack);
	ft_ordering(b_stack);
	total = ft_total_diff_nb(a_stack, b_stack);
	printf("%d\n", total);
	ft_free_tstack(&a_stack);
	ft_free_tstack(&b_stack);
	return (close(fd), 0);
}
