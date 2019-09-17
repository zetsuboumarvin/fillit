/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:19:04 by clianne           #+#    #+#             */
/*   Updated: 2019/09/17 15:24:37 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> /* todo: debug (delete) */
int		check_tetri_empty(char c)
{
	return (c == CEMPTY);
}

int		check_tetri_symbol(char c)
{
	return (c == CBLOCK);
}

int		check_tetri_correct_symbol(char c)
{
	return (check_tetri_empty(c) || check_tetri_symbol(c));
}

int		check_correct_tetri(size_t t[4][4])
{
	size_t  il;
	size_t  nlinks;
	size_t  nblocks;

	il = 0;
	nlinks = 0;
	nblocks = 0;
	while (il < LLEN * LLEN)
	{
		printf("CHECK_CORRECT_TETRI: tetrim[%lu][%lu] = %lu\n", il / LLEN, il % LLEN, t[il / LLEN][il % LLEN]);
		nblocks += t[il / LLEN][il % LLEN];
		if (t[il / LLEN][il % LLEN])
			nlinks += (il / LLEN && t[il / LLEN - 1][il % LLEN]) +
			(il / LLEN < LLEN - 1 && t[il / LLEN + 1][il % LLEN]) +
			(il % LLEN && t[il / LLEN][il % LLEN - 1]) +
			(il % LLEN < LLEN - 1 && t[il / LLEN][il % LLEN + 1]);
			il++;
	}
	printf("CHECK_CORRECT_TETRI: qty of blocks = %lu, qty of links = %lu\n", nblocks, nlinks);
	printf("CHECK_CORRECT_TETRI: check_tetrin returns %d\n", (nblocks == LLEN && nlinks >= 6 && nlinks <= 8) ? 1 : 0);
	return ((nblocks == LLEN && nlinks >= 6 && nlinks <= 8) ? 1 : 0);
}

size_t	check_tetri_place(int **m, size_t rc[2], t_tt_list * node, size_t size)
{
	size_t  sum_tetri;
	size_t  index;

	index = 0;
	sum_tetri = 0;
	while (index < 3)
	{
		printf("CHECK_TETRI_PLACE: row = %zu, col = %zu, r diff = %d, c diff = %d\n", rc[0], rc[1], node->rc[index][0], node->rc[index][1]);
		if ((int)rc[0] + node->rc[index][0] < 0 ||
			(int)rc[0] + node->rc[index][0] > (int)size - 1 ||
			(int)rc[1] + node->rc[index][1] < 0 ||
			(int)rc[1] + node->rc[index][1] > (int)size - 1)
		{
			sum_tetri++;
			break ;
		}
		sum_tetri += m[rc[0] + node->rc[index][0]][rc[1] + node->rc[index][1]];
		index++;
	}
	return (sum_tetri);
}
