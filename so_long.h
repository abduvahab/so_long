/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:19:56 by areheman          #+#    #+#             */
/*   Updated: 2022/06/02 16:24:00 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./printf/ft_printf.h"
# include "gt_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include  <stdio.h>

# define IMG_W	50
# define IMG_H 	50
# define W		13
# define A		0
# define S		1
# define D		2
# define ESC	53

typedef struct s_enemy{
	char	*path;
	void	*img;
	int		x;
	int		y;
	size_t	x_p;
	size_t	y_p;
	int		sleep;
	int		flag;
}				t_enemy;

typedef struct s_wall{
	char	*path;
	void	*img;
	int		x;
	int		y;
}				t_wall;

typedef struct s_door{
	char	*path;
	void	*img;
	int		x;
	int		y;
}				t_door;

typedef struct s_back{
	char	*path;
	void	*img;
	int		x;
	int		y;
}				t_back;

typedef struct s_money{
	char	*path;
	void	*img;
	int		x;
	int		y;
}				t_money;

typedef struct s_collecter{
	char	*path;
	void	*img;
	int		x;
	int		y;
	size_t	x_p;
	size_t	y_p;
}				t_player;

typedef struct s_map{
	char	**map;
	size_t	s_m;
	size_t	h_m;
}				t_map;

typedef struct s_prog{
	void		*mlx;
	void		*win;
	char		*wd;
	t_map		*maps;
	t_player	man;
	int			move;
	int			time;
	t_enemy		enemy;
	t_wall		wall;
	t_door		door;
	t_back		back;
	t_money		money;
}				t_prog;

t_map	*check_map(int argv, char *argc);
void	ft_init_prog(t_prog *p);
void	ft_put_to_win(t_prog p);
void	find_player(t_prog *p);
void	find_enemy(t_prog *p);
int		my_close(t_prog *p);
int		key_hook(int keycode, t_prog *prog);
int		find_collection(t_prog *p);
int		my_animation(t_prog *p);

#endif
