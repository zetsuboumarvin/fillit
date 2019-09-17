/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:35:16 by clianne           #+#    #+#             */
/*   Updated: 2019/09/17 12:54:22 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> /* todo: debug (delete) */
#include "fillit.h"
#include "get_next_line.h"

static int		read_file(const int fd, t_tt_list **lst)
{
	size_t	tetrim[4][4] = {{0}}; /* todo: correct init */
	char	*line;
	size_t	nl;
	size_t	index;
	size_t	ll;

	line = 0;
	nl = 1;
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("READ_FILE: line %0d: %s\n", (int)nl, line);
		ll = ft_strlen(line);
		if ((!(nl % (LLEN + 1)) && ll) || ((nl % (LLEN + 1)) && (ll != LLEN)))
			return (-1);
		index = 0;
		while (*line && ll == LLEN)
		{
			if (!check_tetri_correct_symbol(*line))
				return (-1);
				printf("READ_FILE: line = %lu, fill in sym = <%c> tetrim[%lu][%lu] = %d\n", nl, *line, nl % (LLEN + 1) - 1, index, ((*line == CBLOCK) ? 1 : 0));
			tetrim[nl % (LLEN + 1) - 1][index++] = ((*line++ == CBLOCK) ? 1 : 0);
		}
		/* todo: debug (delete) */
		/* printf("line %0d: is well processed\n", (int)nl); */
		if (++nl % (LLEN + 1) == 0)
			if (!create_tetri_list(tetrim, lst))
				return (-1);
	}
	printf("READ_FILE: file <%d> is processed OK.\n", fd);
	printf("READ_FILE: last line = %d\n", (int)nl);
	printf("READ_FILE: return code = %d\n", (nl % (LLEN + 1) == 0) ? 0 : -1);
	return ((nl % (LLEN + 1) == 0) ? 0 : -1);
}

static	void	free_file(int fd, t_tt_list **lst)
{
	if (fd)
	{
		printf("FREE_LIST: try to close the file <%d>\n", fd);
		close(fd);
		printf("FREE_LIST: file is closed\n");
	}
	if (lst)
	{
		printf("FREE_LIST: try to free the list\n");
		lst_clear(lst);
		printf("FREE_LIST: list is freed\n");
	}
}

int				main(int gc, char **gv)
{
	t_tt_list	*tetri_list;
	int			fd;

	if (gc != 2)
		ft_putstr(STR_USAGE);
	else if (!gv[1] || (fd = open(gv[1], O_RDONLY)) < 0)
		ft_putstr(STR_ERROR);
	else
	{
		tetri_list = 0;
		printf("MAIN: file <%d> is opened\n", fd);
		if (read_file(fd, &tetri_list) < 0)
		{
			printf("MAIN: file <%d> reading is not successful\n", fd);
			free_file(fd, &tetri_list);
			ft_putstr(STR_ERROR);
		}
		else
		{
			printf("MAIN: file <%d> reading is completed successfully\n", fd);
			/* todo: working with tetri_list */
			lst_print(tetri_list);
			solution(tetri_list);
			free_file(fd, &tetri_list);
			printf("MAIN: program is completed\n");
		}
	}
	return (1);
}
