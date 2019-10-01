/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:27:51 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/20 17:15:53 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, size_t size)
{
	int		i;

	i = -1;
	while (++i < (int)size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

void	delete_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_strdel(&map[i]);
		++i;
	}
	free(map);
	map = NULL;
}

char	**new_map(size_t size)
{
	int		i;
	int		j;
	int		n_size;
	char	**map;

	n_size = size + 3;
	if (!(map = (char **)malloc(sizeof(char*) * (n_size + 1))))
		return (NULL);
	i = -1;
	while (++i < (int)size)
	{
		if (allocate_map(map, n_size, i) == 0)
			return (0);
		j = -1;
		while (++j < (int)size)
			map[i][j] = '.';
	}
	while (i < n_size)
	{
		if (allocate_map(map, n_size, i) == 0)
			return (0);
		++i;
	}
	map[i] = 0;
	return (map);
}

size_t	initial_board_size(size_t nb_blocks)
{
	size_t min_size;
	size_t i;

	i = 2;
	min_size = nb_blocks * 4;
	while (min_size > (i * i))
		i++;
	return (i);
}

char	get_letter(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}
