/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:39:23 by clianne           #+#    #+#             */
/*   Updated: 2019/09/17 15:07:47 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define STR_USAGE "usage: fillit source_file\n"
# define STR_ERROR "error\n"
# define CBLOCK '#'
# define CEMPTY '.'
# define LLEN 4
# define MIN_Q_TETRI 1
# define MAX_Q_TETRI 26

typedef struct			s_tt_list
{
	size_t				height;
	size_t				width;
	size_t				row;
	size_t				col;
	size_t				sym;
	struct s_tt_list	*next;
	int					rc[3][2];
}						t_tt_list;

int						lst_push_back(t_tt_list **begin_list, size_t hw[2],
			int rc[3][2]);
void					lst_clear(t_tt_list **begin_list);
void					lst_print(t_tt_list *lst);
int						check_tetri_empty(char c);
int						check_tetri_symbol(char c);
int						check_tetri_correct_symbol(char c);
int						check_correct_tetri(size_t t[4][4]);
size_t					get_hw_tetri(int rc[3][2], size_t nc);
int						create_tetri_list(size_t t[4][4], t_tt_list **lst);
size_t					fill_tetri(int **m, size_t rc[2], t_tt_list *node, size_t size);
void					fill_tetri_sym(int **m, size_t rc[2], t_tt_list *node, size_t n);
void					del_tetri(int **m, size_t rc[2], t_tt_list *node);
size_t					check_tetri_place(int **m, size_t rc[2], t_tt_list *node, size_t size);
void					fill_O(int **m, size_t r, size_t c, int n);
void					fill_I(int **m, size_t rc[2], size_t tshape, int n);
void					fill_T(int **m, size_t rc[2], size_t tshape, int n);
void					fill_SZ(int **m, size_t rc[2], size_t tshape, int n);
void					fill_S(int **m, size_t rc[2], size_t c, int n);
void					fill_J(int **m, size_t rc[2], size_t tshape, int n);
int						solution(t_tt_list *tetri);
size_t					ft_nearsqrt(size_t n);
void					free_all(int **mat, size_t size);
void					print_sol(int** mat, size_t size);

#endif
