/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:30:45 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/19 15:47:29 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int	is_valid_char(char c)
{
	return ((c == '\n' || c == '#' || c == '.') ? 1 : 0);
}

int			check_all_chars(char *str, char **tab)
{
	int		i;

	if (str[0] == '\n')
		error_free_tbl(0, tab);
	i = -1;
	while (str[++i])
	{
		if (!(is_valid_char(str[i])))
			error_free_tbl(0, tab);
	}
	return (1);
}

int			sizecheck(char *str, char **tab, int i)
{
	t_metrics	counter;

	counter = metrics_new(0, 0, 0);
	while (ft_strlen(str) > 1 && str[i])
	{
		if (str[i] == '.' || str[i] == '#')
			counter.len++;
		if (str[i] == '#')
			counter.hash++;
		if (str[i] == '\n')
		{
			if ((counter.len != 4 && counter.len != 0) || i > 21)
				error_free_tbl(0, tab);
			counter.height++;
			counter.len = 0;
		}
		i++;
	}
	if ((counter.height != 4 && counter.height != 5) || (counter.hash != 4))
		error_free_tbl(0, tab);
	return (1);
}

int			count_tetries(char const *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			++count;
		++i;
	}
	return (count);
}

int			check_connection(char const *str, char **tab)
{
	int		i;
	int		count;
	int		len;

	i = -1;
	len = (int)ft_strlen(str);
	count = 0;
	while (str[++i])
	{
		if (str[i] == BLOCK)
		{
			if ((i + 1) < len && str[i + 1] == BLOCK)
				++count;
			if ((i - 1) >= 0 && str[i - 1] == BLOCK)
				++count;
			if ((i + 4) < len && str[i + 4] == BLOCK)
				++count;
			if ((i - 4) >= 0 && str[i - 4] == BLOCK)
				++count;
		}
	}
	if (count != 6 && count != 8)
		error_free_tbl(0, tab);
	return (count);
}
