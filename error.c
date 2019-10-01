/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:15:32 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/19 15:04:30 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int output)
{
	ft_putendl("error");
	exit(output);
}

void	error_free(int output, char *str)
{
	ft_putendl("error");
	ft_strdel(&str);
	exit(output);
}

void	error_free_tbl(int output, char **tbl)
{
	ft_putendl("error");
	free_afterload(tbl);
	exit(output);
}

void	print_usage(void)
{
	ft_putendl("usage: ./fillit input_file");
	exit(0);
}
