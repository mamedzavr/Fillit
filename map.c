/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:32:51 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/01/21 17:03:44 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_square(int num)
{
	int		i;

	i = 0;
	while (++i)
	{
		if (i * i >= num * 4)
			return (i);
	}
	return (0);
}

t_map	*create_map(int size)
{
	int		i;
	t_map	*map;

	i = -1;
	map = (t_map *)malloc(sizeof(t_map));
	(map == NULL) ? put_error() : 0;
	map->size = size;
	map->map = (char **)malloc(sizeof(char*) * size);
	(map->map == NULL) ? put_error() : 0;
	while (++i < size)
	{
		map->map[i] = ft_strnew(size);
		ft_memset(map->map[i], '.', size);
	}
	return (map);
}

void	delete_split(char **map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(map);
}

void	delete_map(t_map **map)
{
	int		i;
	int		size;

	i = 0;
	size = (*map)->size;
	while (i < size)
	{
		ft_strdel(&(*map)->map[i]);
		i++;
	}
	free((*map)->map);
	if (*map)
		free(*map);
}

t_map	*resize_map(t_map *map, int size)
{
	t_map *maps;

	delete_map(&map);
	maps = create_map(size);
	return (maps);
}
