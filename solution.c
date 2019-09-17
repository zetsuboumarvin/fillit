/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:02:37 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/17 15:08:51 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <stdio.h> // delete

static void			null_matrix(int **mat, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			mat[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

static int			**create_matrix(t_tt_list *tetri, size_t *size)
{
	size_t		i;
	int			**mat;
	t_tt_list	*head;

	i = 0;
	head = tetri;
	if (*size == 0)
		while (head)
		{
			(*size)++;
			head = head->next;
		}
	*size = ft_nearsqrt(*size * 4);
	mat = (int**)malloc(sizeof(int*) * (*size));
	if (!mat)
		return (0);
	while (i < *size)
	{
		mat[i] = (int*)malloc(sizeof(int) * (*size));
		if (!mat[i++])
			return (0);
	}
	null_matrix(mat, *size);
	return (mat);
}

static int			get_next_cell(size_t *arr, int **mat, size_t size)
{
	size_t	row;
	size_t	col;

	row = arr[0];
	col = arr[1];
	while (row < size)
	{
		while (col < size)
		{
			if (mat[row][col] == 0)
			{
				arr[0] = row;
				arr[1] = col;
				return (1);
			}
			col++;
		}
		col = 0;
		row++;
	}
	arr[0] = row;
	arr[1] = col;
	return (0);
}

int					backtrack(t_tt_list *tetri, int **mat, size_t size)
{
	size_t		arr[2];
	size_t		row;
	size_t		col;

	int			test;
	int			test1;


	arr[0] = 0;
	arr[1] = 0;
	if (tetri)
	{
		while ((test = get_next_cell(arr, mat, size)))
		{
			row = arr[0];
			col = arr[1];
			printf("%d -- result of getcell, row - %zu, col - %zu\n", test, row, col); // delete
			printf("\nBacktrack: before if for col and row: row - %zu, col - %zu\n", row + tetri->height, col + tetri->width); // delete
			printf("TETRI- WIDTH - %zu\n", tetri->width); //delete
				printf("Backtrack: if for col and row: row - %zu, col - %zu\n", row + tetri->height, col + tetri->width); // delete
				if ((test1 = fill_tetri(mat, arr, tetri, size)))
				{
					tetri->row = row;
					tetri->col = col;
/**********************************************************************************************/
/*					size_t i = 0;
					size_t j = 0;

					while (i < size)
					{
						while (j < size)
						{
							ft_putnbr(mat[i][j]);
							j++;
						}
						ft_putchar('\n');
						j = 0;
						i++;
					}*/
					print_sol(mat, size);
/*****************************************************************************************************/
					printf("\nENTER RECURSION\n"); //delete
					if (backtrack(tetri->next, mat, size))
						return (1);
					printf("\nafter recursion\n"); // delete
					del_tetri(mat, arr, tetri);
				}
			arr[1]++;
		}
		printf("%d - result of fill_tetri\n", test); //delete
		return (0);
	}
	return (1);
}

int					solution(t_tt_list *tetri)
{
	size_t			size;
	int				**matrix;

	size = 0;
	while (1)
	{
		matrix = create_matrix(tetri, &size);
		if (!matrix)
		{
			ft_putstr(STR_ERROR);
			return (0);
		}
		if (backtrack(tetri, matrix, size))
			break ;
		free_all(matrix, size);
		free(matrix);
		size++;
		printf("New size for backtracking - %zu\n", size); // delete
	}
	print_sol(matrix, size);
	free_all(matrix, size);
	free(matrix);
	return (1);
}
