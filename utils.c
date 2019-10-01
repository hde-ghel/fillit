/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 04:46:36 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/20 17:22:32 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_tbl(char **tbl)
{
	int		res;

	res = 0;
	while (tbl[res])
		++res;
	return (res);
}

t_metrics	metrics_new(int height, int len, int hash)
{
	t_metrics	a;

	a.height = height;
	a.len = len;
	a.hash = hash;
	return (a);
}

int			allocate_map(char **map, int n_size, int i)
{
	if ((map[i] = ft_strnew(n_size)) == 0)
	{
		delete_map(map);
		return (0);
	}
	return (1);
}
