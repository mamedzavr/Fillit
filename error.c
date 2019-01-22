/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:14:37 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/01/22 12:51:47 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_argc_error(int a)
{
	if (a != 2)
	{
		ft_putendl("usage: ./fillit filename");
		exit(EXIT_FAILURE);
	}
}

void	put_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
