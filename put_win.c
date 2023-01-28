/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:00:12 by areheman          #+#    #+#             */
/*   Updated: 2022/06/02 15:05:52 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_select(int k, int x, int y, t_prog p)
{
	if (k == '1')
		mlx_put_image_to_window(p.mlx, p.win, \
			p.wall.img, x * IMG_W, y * IMG_H);
	if (k == '0')
		mlx_put_image_to_window(p.mlx, p.win, p.back.img, \
			x * IMG_W, y * IMG_H);
	if (k == 'P')
		mlx_put_image_to_window(p.mlx, p.win, p.man.img, \
			x * IMG_W, y * IMG_H);
	if (k == 'C')
		mlx_put_image_to_window(p.mlx, p.win, p.money.img, \
			x * IMG_W, y * IMG_H);
	if (k == 'E')
		mlx_put_image_to_window(p.mlx, p.win, p.door.img, \
			x * IMG_W, y * IMG_H);
	if (k == 'B')
		mlx_put_image_to_window(p.mlx, p.win, p.enemy.img, \
			x * IMG_W, y * IMG_H);
}

static void	ft_direction(int x, int y, t_prog p)
{
	if (p.maps->map[y][x] == '1')
		ft_select('1', x, y, p);
	if (p.maps->map[y][x] == '0' || p.maps->map[y][x] == 'P' \
			|| p.maps->map[y][x] == 'C' || p.maps->map[y][x] == 'B')
		ft_select('0', x, y, p);
	if (p.maps->map[y][x] == 'P')
		ft_select('P', x, y, p);
	if (p.maps->map[y][x] == 'C')
		ft_select('C', x, y, p);
	if (p.maps->map[y][x] == 'E')
		ft_select('E', x, y, p);
	if (p.maps->map[y][x] == 'B')
		ft_select('B', x, y, p);
}

void	ft_put_to_win(t_prog p)
{	
	size_t	x;
	size_t	y;

	y = 0;
	while (y < p.maps->h_m)
	{
		x = 0;
		while (x < p.maps->s_m)
		{
			ft_direction(x, y, p);
			x++;
		}
		y++;
	}
	p.wd = ft_strjoin(p.wd, ft_itoa(p.move));
	mlx_string_put(p.mlx, p.win, 15, 15, 0xFF0000, p.wd);
}
