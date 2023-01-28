/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:19:14 by areheman          #+#    #+#             */
/*   Updated: 2022/06/02 17:37:49 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_p_e(t_prog *p)
{
	find_player(p);
	p->wd = ft_strdup("Move: ");
	find_enemy(p);
	p->enemy.sleep = 3000;
	p->enemy.flag = 1;
}

void	ft_init_prog(t_prog *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->maps->s_m * IMG_W, \
			p->maps->h_m * IMG_H, "so_long");
	p->wall.path = "img/wall.xpm";
	p->wall.img = mlx_xpm_file_to_image(p->mlx, p->wall.path, \
			&p->wall.x, &p->wall.y);
	p->door.path = "img/o_exit.xpm";
	p->door.img = mlx_xpm_file_to_image(p->mlx, p->door.path, \
			&p->door.x, &p->door.y);
	p->back.path = "img/floor.xpm";
	p->back.img = mlx_xpm_file_to_image(p->mlx, p->back.path, \
			&p->back.x, &p->back.y);
	p->money.path = "img/collect.xpm";
	p->money.img = mlx_xpm_file_to_image(p->mlx, p->money.path, \
			&p->money.x, &p->money.y);
	p->man.path = "img/front.xpm";
	p->man.img = mlx_xpm_file_to_image(p->mlx, p->man.path, \
			&p->man.x, &p->man.y);
	p->enemy.path = "img/1.xpm";
	p->enemy.img = mlx_xpm_file_to_image(p->mlx, p->enemy.path, \
			&p->enemy.x, &p->enemy.y);
	ft_init_p_e(p);
}

int	main(int argv, char **argc)
{
	t_prog	prog;

	prog.maps = check_map(argv, argc[1]);
	if (!(prog.maps))
		exit(1);
	prog.move = 0;
	prog.time = 0;
	ft_init_prog(&prog);
	ft_put_to_win(prog);
	mlx_hook(prog.win, 17, 1l << 2, my_close, &prog);
	mlx_key_hook(prog.win, key_hook, &prog);
	if (prog.enemy.x_p != prog.maps->s_m)
		mlx_loop_hook(prog.mlx, my_animation, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
