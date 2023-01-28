/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:06:04 by areheman          #+#    #+#             */
/*   Updated: 2022/06/02 15:28:51 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_close(t_prog *p)
{
	mlx_destroy_window(p->mlx, p->win);
	exit(1);
}

void	find_player(t_prog *p)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < p->maps->h_m)
	{
		x = 0;
		while (x < p->maps->s_m)
		{
			if (p->maps->map[y][x] == 'P')
				break ;
			x++;
		}
		if (p->maps->map[y][x] == 'P')
			break ;
		y++;
	}
	p->man.x_p = x;
	p->man.y_p = y;
}

int	find_collection(t_prog *p)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < p->maps->h_m)
	{
		x = 0;
		while (x < p->maps->s_m)
		{
			if (p->maps->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	find_enemy(t_prog *p)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < p->maps->h_m)
	{
		x = 0;
		while (x < p->maps->s_m)
		{
			if (p->maps->map[y][x] == 'B')
				break ;
			x++;
		}
		if (p->maps->map[y][x] == 'B')
			break ;
		y++;
	}
	p->enemy.x_p = x;
	p->enemy.y_p = y;
}
