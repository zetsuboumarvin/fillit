/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:49:32 by clianne           #+#    #+#             */
/*   Updated: 2019/09/17 14:59:36 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <stdio.h> // todo: debug (delete)

static t_tt_list	*lst_create_elem(size_t hw[2], int rc[3][2], size_t sym)
{
	size_t		index;
	t_tt_list	*list;

	list = (t_tt_list*)malloc(sizeof(t_tt_list));
	if (!list)
		return (NULL);
	list->width = hw[1];
	list->height = hw[0];
	list->next = NULL;
	list->row = 0;
	list->col = 0;
	list->sym = sym;
	index = 0;
	while (index < 3)
	{
		list->rc[index][0] = rc[index][0];
		list->rc[index][1] = rc[index][1];
		index++;
	}
	return (list);
}

void				lst_clear(t_tt_list **begin_list)
{
	t_tt_list	*list;
	t_tt_list	*buf;

	if (*begin_list)
	{
		list = *begin_list;
		buf = NULL;
		while (list)
		{
			if (list->next)
				buf = list->next;
			else
				buf = NULL;
			free(list);
			list = buf;
		}
		*begin_list = NULL;
	}
}

int					lst_push_back(t_tt_list **begin_list, size_t hw[2],
		int rc[3][2])
{
	size_t		sym;
	t_tt_list   *list;

	if (!*begin_list)
	{
		if (!(*begin_list = lst_create_elem(hw, rc, 'A' + 0)))
			return (0);
	}
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		sym = list->sym;
		if (sym == 'Z' || !(list->next = lst_create_elem(hw, rc, sym + 1)))
			return (0);
	}
 	return (1);
 }
 
void				lst_print(t_tt_list *lst)
{
	size_t	index;

	index = 0;
	ft_putstr("******************\n");
	ft_putstr("List of tetrimnos:\n");
	ft_putstr("******************\n");
	while (lst)
	{
		ft_putstr("tetri #");
		ft_putnbr((int)index++);
		ft_putstr(": ");
		ft_putstr("w = ");
		ft_putnbr((int)lst->width);
		ft_putstr(", h = ");
		ft_putnbr((int)lst->height);
		ft_putstr(", sym = ");
		ft_putchar(lst->sym);
		ft_putchar('\n');
		lst = lst->next;
	}
	ft_putstr("******************\n");
}
