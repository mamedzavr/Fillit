/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:13:40 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/01/21 17:01:22 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(t_map *map)
{
	int cou;

	cou = 0;
	while (cou < map->size)
	{
		ft_putendl(map->map[cou]);
		cou++;
	}
}

int		main(int argc, char **argv)
{
	char		buf[22];
	int			fd;
	int			ret[2];
	int			count;
	t_tetra		tetra[26];

	count = 0;
	put_argc_error(argc);
	fd = open(argv[1], O_RDONLY);
	while ((ret[0] = read(fd, buf, 21)) > 0)
	{
		buf[ret[0]] = '\0';
		map_validation(buf, tetra, count);
		ret[1] = ret[0];
		count < 26 ? 0 : put_error();
		tetra[count].letter = count + 'A';
		set_min_xy(&tetra[count], count);
		count++;
	}
	(count == 0) ? put_error() : 0;
	ret[1] == 21 && ret[0] == 0 ? put_error() : 0;
	solve(tetra, count);
	return (0);
}
