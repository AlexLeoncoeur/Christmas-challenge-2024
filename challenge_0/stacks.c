/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:23:35 by aarenas-          #+#    #+#             */
/*   Updated: 2024/12/02 13:35:44 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_diff.h"

int	ft_lstsize_tstack(t_stack *lst)
{
	t_stack	*aux;
	int		i;

	aux = lst;
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	ft_ordering(t_stack *stack)
{
	t_stack	*current;
	t_stack	*smallest;
	int		index;

	current = stack;
	smallest = stack;
	index = 0;
	while (index <= ft_lstsize_tstack(stack))
	{
		while (current)
		{
			if (current->nb < smallest->nb)
				smallest = current;
			current = current->next;
		}
		smallest->index = index;
		index++;
	}
}

static void	ft_clean_input(char *line, t_stack *a_stack, t_stack *b_stack)
{
	char	*num1;
	char	*num2;
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	num1 = ft_substr(line, 0, ft_strlen(line) - ft_strlen(&line[i]));
	num2 = ft_substr(line, i + 3, ft_strlen(&line[i + 3]));
	a_stack->nb = ft_atoi(num1);
	b_stack->nb = ft_atoi(num2);
	free(num1);
	free(num2);
}

void	ft_read_and_divide(int fd, t_stack *a_stack, t_stack *b_stack)
{
	char	*line;

	while (1)
	{
		line = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_clean_input(line, a_stack, b_stack);
		free(line);
	}
	if (ft_lstsize_tstack(a_stack) != ft_lstsize_tstack(b_stack))
	{
		dprintf(2, "error: wrong lists length does not match\n");
		ft_free_tstack(&a_stack);
		ft_free_tstack(&b_stack);
		exit(1);
	}
}

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	(*stack).nb = 0;
	(*stack).index = -1;
	(*stack).next = NULL;
	return (stack);
}
