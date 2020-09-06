/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:29:10 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/21 11:47:43 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetri(char **map, char *tetri, int col, int row)
{
	char	ch;
	int		i;

	ch = get_letter(tetri);
	i = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (i == 4)
				return ;
			if (map[row][col] == ch)
			{
				i++;
				map[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

void	place(char **map, char *tetri, int col, int row)
{
	size_t	i;
	int		init_col;

	init_col = col;
	i = 0;
	while (*tetri == '.' && ((++i && ++tetri) || 1))
		--init_col;
	while (*tetri != '\0')
	{
		if (i > 3 && !(i = 0) && ++row)
			col = init_col;
		if (*tetri == '.')
		{
			++i;
			++col;
		}
		if (map[row][col] == EMPTY && *tetri != EMPTY)
		{
			map[row][col] = *tetri;
			++col;
			++i;
		}
		tetri++;
	}
}

t_bool	is_safe(char **map, char *tetri, int col, int row)
{
	size_t	i;
	int		init_col;

	init_col = col;
	i = 0;
	while (*tetri == '.' && ((++i && ++tetri) || 1))
		--init_col;
	if (init_col < 0)
		return (false);
	while (*tetri != '\0')
	{
		if (i > 3 && ++row && !(i = 0))
			col = init_col;
		if (*tetri == '.' && ++i && ++col)
			NULL;
		if (((map[row][col] != EMPTY) && map[row][col] && *tetri != EMPTY) ||
			(!map[row][col] && *tetri != EMPTY))
			return (false);
		if (map[row][col] == EMPTY && *tetri != EMPTY && ++col && ++i)
			NULL;
		tetri++;
	}
	return (true);
}

t_bool	recursion(char **tbl, char **map, int col, int row)
{
	if (!*tbl)
		return (true);
	while (map[row])
	{
		while (map[row][col])
		{
			if (is_safe(map, *tbl, col, row) == true)
			{
				place(map, *tbl, col, row);
				if (recursion(tbl + 1, map, 0, 0) == true)
					return (true);
				else
					remove_tetri(map, *tbl, col, row);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (false);
}

int		solve(char **tbl, size_t blocks)
{
	char	**map;
	size_t	map_size;

	map_size = initial_board_size(blocks);
	if ((map = new_map(map_size)) == 0)
		error_free_tbl(0, tbl);
	while (recursion(tbl, map, 0, 0) == false)
	{
		map_size++;
		delete_map(map);
		if ((map = new_map(map_size)) == 0)
			error_free_tbl(0, tbl);
	}
	print_map(map, map_size);
	delete_map(map);
	return (0);
}
