/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:11:31 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/19 18:06:21 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_checks(t_check *checks)
{
	checks->i = -1;
	checks->ret = 1;
	checks->total_ret = 0;
	checks->check_newline = 0;
}

char		**read_input(int fd)
{
	char	**tab;
	t_check	checks;

	init_checks(&checks);
	if (!(tab = (char **)malloc(sizeof(*tab) * (27))))
		error(0);
	while (checks.ret > 0 && ++checks.i <= 26)
	{
		if (!(tab[checks.i] = ft_strnew(21)))
			error_free_tbl(0, tab);
		tab[checks.i + 1] = NULL;
		if ((checks.ret = read(fd, tab[checks.i], 21)) == -1)
			error_free_tbl(0, tab);
		if (checks.ret == 0)
			break ;
		check_all_chars(tab[checks.i], tab);
		sizecheck(tab[checks.i], tab, 0);
		tab[checks.i] = remove_nl(tab[checks.i], &checks.check_newline, tab);
		check_connection(tab[checks.i], tab);
		checks.total_ret += checks.ret;
	}
	ft_strdel(&tab[checks.i]);
	if (checks.total_ret == 0 || checks.i > 26 || checks.check_newline == 1)
		error_free_tbl(0, tab);
	return (tab);
}

void		rename_blocks(char **src)
{
	int		i;
	char	n;
	char	*tmp;

	i = 0;
	n = 'A';
	while (src[i])
	{
		tmp = src[i];
		while (*tmp)
		{
			if (*tmp == '#')
				*tmp = n;
			tmp++;
		}
		++n;
		++i;
	}
}

char		*remove_nl(char *tetri, int *check_newline, char **tab)
{
	int		i;
	int		k;
	char	*tmp;
	char	*res;

	i = -1;
	k = -1;
	if (!(tmp = ft_strnew(ft_strlen(tetri))))
		error_free_tbl(0, tab);
	if (ft_strlen(tetri) == 21)
		*check_newline = 1;
	else
		*check_newline = 0;
	while (tetri[++i])
	{
		if (tetri[i] == '\n')
			++i;
		tmp[++k] = tetri[i];
	}
	if (!(res = ft_strdup(tmp)))
		error_free_tbl(0, tab);
	ft_strdel(&tetri);
	ft_strdel(&tmp);
	return (res);
}

void		free_afterload(char **tbl)
{
	size_t	i;

	i = -1;
	if (tbl == 0 || *tbl == 0)
		return ;
	while (tbl[++i])
	{
		if (tbl[i])
			ft_strdel(&tbl[i]);
	}
	free(tbl);
	tbl = NULL;
}
