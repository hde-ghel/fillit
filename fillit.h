/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:49:22 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/12/21 11:43:04 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFFER_SIZE 1
# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "libft/includes/libft.h"

/*
 **Reading fuctions
*/
char			**read_input(int fd);
void			free_afterload(char **tab);
void			rename_blocks(char **src);
char			*remove_nl(char *tetri, int *check_newline, char **tab);
/*
 **File Checking functions
*/
int				sizecheck(char *str, char **tab, int i);
int				count_tetries(char const *str);
int				check_input_format(char *str, int bytes);
int				check_all_chars(char *str, char **tab);
int				check_connection(char const *str, char **tab);
/*
 **Pattern/tetrimino validity
*/
int				valid_pattern(char **src, int blocks);
void			populate_valid(int i, char valid[20][15]);
/*
 **MAP
*/
void			print_map(char **map, size_t size);
int				allocate_map(char **map, int n_size, int i);
void			delete_map(char **map);
char			**new_map(size_t size);
size_t			initial_board_size(size_t nb_blocks);
char			get_letter(char *str);
/*
 **structures
*/
typedef	enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_metrics
{
	int			height;
	int			len;
	int			hash;

}				t_metrics;

typedef struct	s_check
{
	int			total_ret;
	int			check_newline;
	int			ret;
	int			i;

}				t_check;
/*
 **solving
*/
t_bool			recursion(char **tbl, char **map, int col, int row);
t_bool			is_safe(char **map, char *tetri, int col, int row);
void			place(char **map, char *tetri, int col, int row);
void			remove_tetri(char **map, char *tetri, int col, int row);
int				solve(char **tbl, size_t blocks);
/*
 **error handling and usage printing
*/
void			error(int output);
void			print_usage(void);
void			error_free(int output, char *str);
void			error_free_tbl(int output, char **tbl);
/*
 **utils.c
*/
int				count_tbl(char **tbl);
t_metrics		metrics_new(int height, int len, int hash);
#endif
