/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:14:41 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/01/21 17:04:46 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			set_min_xy(t_tetra *tetra, int count)
{
	int		minx;
	int		miny;
	int		i;

	i = 0;
	minx = tetra[0].xy[i].x;
	miny = tetra[0].xy[i].y;
	tetra[0].letter = count + 'A';
	while (i < 4)
	{
		if (tetra[0].xy[i].x <= minx)
			minx = tetra[0].xy[i].x;
		if (tetra[0].xy[i].y <= miny)
			miny = tetra[0].xy[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetra[0].xy[i].x -= minx;
		tetra[0].xy[i].y -= miny;
		i++;
	}
}

t_xy			set_xy(int x, int y)
{
	t_xy result;

	result.x = x;
	result.y = y;
	return (result);
}

int				tetr_validation(char **split, int i, int j)
{
	int			touch;

	touch = 0;
	(j - 1 > -1 && split[i][j - 1] == '#') ? touch++ : 0;
	(j + 1 < 4 && split[i][j + 1] == '#') ? touch++ : 0;
	(i - 1 > -1 && split[i - 1][j] == '#') ? touch++ : 0;
	(i + 1 < 4 && split[i + 1][j] == '#') ? touch++ : 0;
	return (touch);
}

int				check_len(char *buf)
{
	int	a;

	a = ft_strlen(buf);
	if (a > 19 && (buf[19] == '\n' && (buf[20] == '\0' || buf[20] == '\n')))
		return (0);
	return (1);
}

void			map_validation(char *buf, t_tetra *tetra, int count)
{
	char				**sp;
	t_xy				xy;
	int					hash;
	int					touch;

	xy.x = -1;
	hash = 0;
	touch = 0;
	(check_len(buf) == 0) ? (sp = ft_strsplit(buf, '\n')) : put_error();
	while (++xy.x < 4)
	{
		xy.y = -1;
		while (++xy.y < 4)
		{
			(sp[xy.x][xy.y] != '.' && sp[xy.x][xy.y] != '#') ? put_error() : 0;
			if (sp[xy.x][xy.y] == '#')
			{
				touch += tetr_validation(sp, xy.x, xy.y);
				tetra[count].xy[hash] = set_xy(xy.x, xy.y);
				hash++;
			}
		}
		(xy.y != 4) ? put_error() : 0;
	}
	(hash == 4 && (touch == 6 || touch == 8)) ? delete_split(sp) : put_error();
}
