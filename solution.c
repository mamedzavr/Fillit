/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:00:46 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/01/21 17:01:06 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_tetra(t_map *map, t_tetra *tetra, int i, int j)
{
	int		arr;
	int		size;

	arr = 0;
	size = map->size;
	while (arr < 4)
	{
		if (tetra[0].xy[arr].y + j <= size - 1 &&
			tetra[0].xy[arr].x + i <= size - 1 &&
			map->map[tetra[0].xy[arr].x + i][tetra[0].xy[arr].y + j] == '.')
			arr++;
		else
			return (0);
	}
	return (1);
}

int			put_tetra(char **map, t_tetra *tetra, int i, int j)
{
	int		arr;
	char	letter;

	arr = 0;
	letter = tetra[0].letter;
	while (arr < 4)
	{
		map[i + tetra[0].xy[arr].x][j + tetra[0].xy[arr].y] = letter;
		arr++;
	}
	return (1);
}

void		put_dots(char **map, t_tetra *tetra, int i, int j)
{
	int		arr;
	char	letter;

	arr = 0;
	letter = tetra[0].letter;
	while (arr < 4)
	{
		map[i + tetra[0].xy[arr].x][j + tetra[0].xy[arr].y] = '.';
		arr++;
	}
}

int			solution(t_tetra *tetra, int tetras, int count, t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->size)
	{
		j = -1;
		while (++j < map->size && count < tetras)
		{
			if (check_tetra(map, &tetra[count], i, j) == 1)
			{
				put_tetra(map->map, &tetra[count], i, j);
				if (solution(tetra, tetras, count + 1, map) == 0)
					put_dots(map->map, &tetra[count], i, j);
				else
					return (1);
			}
		}
	}
	if (count != tetras)
		return (0);
	return (1);
}

int			solve(t_tetra *tetra, int tetras)
{
	t_map	*map;
	int		mapsize;

	mapsize = min_square(tetras);
	map = create_map(mapsize);
	while (solution(tetra, tetras, 0, map) == 0)
		map = resize_map(map, map->size + 1);
	print_solution(map);
	delete_map(&map);
	return (1);
}
