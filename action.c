/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:13:47 by areheman          #+#    #+#             */
/*   Updated: 2022/06/02 15:10:47 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_s(t_prog *p)
{
	find_player(p);
	p->maps->map[p->man.y_p][p->man.x_p] = '0';
	if (p->maps->map[p->man.y_p + 1][p->man.x_p] == 'E')
	{
		if (!find_collection(p))
		{	
			ft_printf("you win !!\n");
			my_close(p);
		}
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	}
	else if (p->maps->map[p->man.y_p + 1][p->man.x_p] == '0')
		p->maps->map[p->man.y_p + 1][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p + 1][p->man.x_p] == '1')
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p + 1][p->man.x_p] == 'C')
		p->maps->map[p->man.y_p + 1][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p + 1][p->man.x_p] == 'B')
	{
		ft_printf("you have been killed !!!");
		my_close(p);
	}
}

static void	move_w(t_prog *p)
{
	find_player(p);
	p->maps->map[p->man.y_p][p->man.x_p] = '0';
	if (p->maps->map[p->man.y_p - 1][p->man.x_p] == 'E')
	{
		if (!find_collection(p))
		{	
			ft_printf("you win !!\n");
			my_close(p);
		}
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	}
	else if (p->maps->map[p->man.y_p - 1][p->man.x_p] == '0')
		p->maps->map[p->man.y_p - 1][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p - 1][p->man.x_p] == '1')
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p - 1][p->man.x_p] == 'C')
		p->maps->map[p->man.y_p - 1][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p - 1][p->man.x_p] == 'B')
	{
		ft_printf("you have been killed !!!");
		my_close(p);
	}
}

static void	move_a(t_prog *p)
{
	find_player(p);
	p->maps->map[p->man.y_p][p->man.x_p] = '0';
	if (p->maps->map[p->man.y_p][p->man.x_p - 1] == 'E')
	{	
		if (!find_collection(p))
		{	
			ft_printf("you win !!\n");
			my_close(p);
		}
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	}
	else if (p->maps->map[p->man.y_p][p->man.x_p - 1] == '0')
		p->maps->map[p->man.y_p][p->man.x_p - 1] = 'P';
	else if (p->maps->map[p->man.y_p][p->man.x_p - 1] == '1')
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p][p->man.x_p - 1] == 'C')
		p->maps->map[p->man.y_p][p->man.x_p - 1] = 'P';
	else if (p->maps->map[p->man.y_p][p->man.x_p - 1] == 'B')
	{
		ft_printf("you have been killed !!!");
		my_close(p);
	}
}

static void	move_d(t_prog *p)
{
	find_player(p);
	p->maps->map[p->man.y_p][p->man.x_p] = '0';
	if (p->maps->map[p->man.y_p][p->man.x_p + 1] == 'E')
	{	
		if (!find_collection(p))
		{	
			ft_printf("you win !!\n");
			my_close(p);
		}
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	}
	else if (p->maps->map[p->man.y_p][p->man.x_p + 1] == '0')
		p->maps->map[p->man.y_p][p->man.x_p + 1] = 'P';
	else if (p->maps->map[p->man.y_p][p->man.x_p + 1] == '1')
		p->maps->map[p->man.y_p][p->man.x_p] = 'P';
	else if (p->maps->map[p->man.y_p][p->man.x_p + 1] == 'C')
		p->maps->map[p->man.y_p][p->man.x_p + 1] = 'P';
	else if (p->maps->map[p->man.y_p][p->man.x_p + 1] == 'B')
	{
		ft_printf("you have been killed !!!");
		my_close(p);
	}
}

int	key_hook(int k, t_prog *p)
{
	mlx_clear_window(p->mlx, p->win);
	if (k == ESC)
		my_close(p);
	if (k == W || k == A || k == S || k == D)
	{
		p->move += 1;
		ft_printf("Your current move is : %d\n", p->move);
	}
	if (k == W)
		move_w(p);
	else if (k == S)
		move_s(p);
	else if (k == A)
		move_a(p);
	else if (k == D)
		move_d(p);
	ft_put_to_win(*p);
	return (0);
}
