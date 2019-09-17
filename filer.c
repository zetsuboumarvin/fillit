/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:51:16 by clianne           #+#    #+#             */
/*   Updated: 2019/09/17 12:54:54 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include <stdio.h> /* todo: debug (delete) */

int		create_tetri_list(size_t t[4][4], t_tt_list **lst)
{
	size_t	hw[2]; /* todo: correct init */
	int		rc[3][2];
	size_t	index;
	int		i_rc;
	int		start_rc[2];

	if (!check_correct_tetri(t))
		return (0);
	printf("CREATE_TETRI_LIST: node is before creating ...\n");
	/* todo: define shape of tetri = kind of node */
//	get_tetri_shape(tetri, &tp[0], &tp[1], &tp[2]);
//static void     get_tetri_shape_new(size_t t[4][4], size_t *hw[2], int *rc[3][2])
/*              size_t *shape) *//* todo: ubderstand how find the shape? */

	index = 0;
	while (index < LLEN * LLEN && t[index / LLEN][index % LLEN] == 0)
		index++;
	start_rc[0] = index / LLEN;
	start_rc[1] = index % LLEN;
	printf("CREATE_TETRI_LIST: start[r] = %d, start[c] = %d\n", start_rc[0], start_rc[1]);
	index++;
	i_rc = -1;
	while (i_rc < 2)
	{
		printf("CREATE_TETRI_LIST: index = %zu, row = %zu, col = %zu\n", index, index / LLEN, index % LLEN);
		if (t[index / LLEN][index % LLEN])
		{
			i_rc++;
			rc[i_rc][0] = index / LLEN - start_rc[0];
			rc[i_rc][1] = index % LLEN - start_rc[1];
			printf("CREATE_TETRI_LIST: rc[%d][0] = %d, rc[%d][1] = %d\n", i_rc, rc[i_rc][0], i_rc, rc[i_rc][1]);
		}
		index++;
	}
	hw[0] = get_hw_tetri(rc, 0);
	hw[1] = get_hw_tetri(rc, 1);
//	printf("CREATE_TETRI_LIST: h = %lu, w = %lu, shape = %lu\n", tp[0], tp[1], tp[2]);
	printf("CREATE_TETRI_LIST: h = %lu, w = %lu\n", hw[0], hw[1]);
//	if (!(lst_push_back(lst, tp[0], tp[1], tp[2])))
	if (!(lst_push_back(lst, hw, rc)))
	{
		lst_clear(lst);
		return (0);
	}
	printf("CREATE_TETRI_LIST: node creation is completed.\n");
	return (1);
}
