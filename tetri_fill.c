/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:33:44 by clianne           #+#    #+#             */
/*   Updated: 2019/09/17 15:01:59 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> /* todo: devug (delete) */

void	fill_tetri_sym(int **m, size_t rc[2], t_tt_list *node, size_t n)
{
	size_t	index;

  	m[rc[0]][rc[1]] = n;
	index = 0;
	while (index < 3)
	{
		m[rc[0] + node->rc[index][0]][rc[1] + node->rc[index][1]] = n;
		index++;
	} 
}

size_t	fill_tetri(int **m, size_t rc[2], t_tt_list *node, size_t size)
{
	printf("FILL_TETRI: check for filling: row = %zu, col = %zu, h = %zu, w = %zu\n", rc[0], rc[1], node->height, node->width);
	if (check_tetri_place(m, rc, node, size) == 0)
	{
		printf("FILL_TETRI: filling is allowed\n");
		printf("FILL_TETRI: symbol for filling: %c\n", (int)node->sym);
		fill_tetri_sym(m, rc, node, node->sym);
		printf("FILL_TETRI: matrix is filled\n");
		return (1);
	}
	return (0);
}

void    del_tetri(int **m, size_t rc[2], t_tt_list *node)
{
	fill_tetri_sym(m, rc, node, 0);
}

size_t	get_hw_tetri(int rc[3][2], size_t nc)
{
	int		cmin;
	int		cmax;
	size_t  index;

	index = 1;
	cmin = rc[0][nc];
	cmax = rc[0][nc];
	while (index < 3)
	{
		if (cmin > rc[index][nc])
			cmin = rc[index][nc];
		if (cmax < rc[index][nc])
			cmax = rc[index][nc];
		index++;
	}
	return (cmin < 0 ? (size_t)(cmax - cmin + 1) : cmax + 1);
}
