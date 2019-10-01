/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:11:13 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/20 17:16:18 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		n_tetri;
	char	**tbl;
	int		fd;

	if (ac != 2)
	{
		print_usage();
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error(0);
	tbl = read_input(fd);
	n_tetri = count_tbl(tbl);
	if (!(valid_pattern(tbl, n_tetri)))
	{
		free_afterload(tbl);
		error(0);
	}
	rename_blocks(tbl);
	solve(tbl, n_tetri);
	free_afterload(tbl);
	close(fd);
	return (0);
}
