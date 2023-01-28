/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:17:58 by areheman          #+#    #+#             */
/*   Updated: 2022/06/02 17:33:00 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_next_enemy(t_prog *p)
{
	if (p->maps->map[p->enemy.y_p][p->enemy.x_p + \
		p->enemy.flag] == '0')
		return (1);
	else if (p->maps->map[p->enemy.y_p][p->enemy.x_p + \
			p->enemy.flag] == 'P')
		return (1);
	else
		return (0);
}

int	my_animation(t_prog *p)
{
	p->time++;
	find_enemy(p);
	if (p->time % p->enemy.sleep == 0)
	{
		if (ft_next_enemy(p))
		{
			p->maps->map[p->enemy.y_p][p->enemy.x_p] = '0';
			if (p->maps->map[p->enemy.y_p][p->enemy.x_p + \
				p->enemy.flag] == 'P')
			{
				ft_printf("you have been killed !!");
				my_close(p);
			}
			p->maps->map[p->enemy.y_p][p->enemy.x_p + \
				p->enemy.flag] = 'B';
		}
		else
			p->enemy.flag *= (-1);
		ft_put_to_win(*p);
	}
	return (0);
}
