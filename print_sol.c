/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:11:30 by jflorent          #+#    #+#             */
/*   Updated: 2019/09/17 12:15:04 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_sol(int **mat, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (mat[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(mat[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
