/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:53:41 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/01/21 17:04:33 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_tetra
{
	t_xy		xy[4];
	char		letter;
}				t_tetra;

typedef struct	s_map
{
	int			size;
	char		**map;
}				t_map;

void			put_argc_error(int a);
void			put_error(void);
void			map_validation(char *buf, t_tetra *tetra, int count);
void			set_min_xy(t_tetra *tetra, int count);
int				min_square(int num);
t_map			*create_map(int size);
t_map			*resize_map(t_map *map, int size);
void			delete_map(t_map **map);
void			delete_split(char **map);
int				solution(t_tetra *tetra, int tetras, int count, t_map *map);
int				solve(t_tetra *tetra, int tetras);
void			put_dots(char **map, t_tetra *tetra, int i, int j);
void			print_solution(t_map *map);
t_xy			set_xy(int x, int y);
int				tetr_validation(char **split, int i, int j);

#endif
