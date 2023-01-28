/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:57:19 by areheman          #+#    #+#             */
/*   Updated: 2022/06/02 17:45:47 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	check_map_name(char *s)
{
	char	*tmp;

	tmp = ft_strnstr(s, ".ber", ft_strlen(s));
	if (!tmp)
		return (0);
	if (ft_strncmp(tmp, ".ber", ft_strlen(tmp)) == 0)
		return (1);
	return (0);
}

static t_map	*get_maps(char *s)
{
	t_map	*maps;
	int		fd;
	size_t	x;

	maps = (t_map *)malloc(sizeof(t_map));
	fd = open(s, O_RDONLY);
	x = 0;
	while (get_next_line(fd))
		x++;
	close(fd);
	maps->h_m = x;
	maps->map = ft_calloc(maps->h_m, sizeof(char *));
	if (!maps->map)
		return (0);
	fd = open(s, O_RDONLY);
	x = 0;
	while (x < maps->h_m)
		maps->map[x++] = get_next_line(fd);
	close(fd);
	maps->s_m = ft_strlen(maps->map[0]);
	return (maps);
}

static int	check_walls(t_map m)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (m.map[0][x] == '1' && m.map[m.h_m - 1][x] == '1')
		x++;
	if (x != m.s_m)
		return (0);
	y = 0;
	while ((y < m.h_m) && m.map[y][0] == '1' && m.map[y][m.s_m - 1] == '1')
		y++;
	if (y != m.h_m)
		return (0);
	y = 0;
	while (y < m.h_m)
	{
		if (ft_strlen(m.map[y]) != m.s_m)
			return (0);
		y++;
	}
	return (1);
}

static int	check_elements(t_map m)
{
	size_t	y;
	int		p;
	int		c;
	int		e;

	p = 0;
	e = 0;
	c = 0;
	if (!check_walls(m))
		return (0);
	y = 0;
	while (y < m.h_m)
	{	
		if (ft_strchr(m.map[y], 'P'))
			p++;
		if (ft_strchr(m.map[y], 'C'))
			c++;
		if (ft_strchr(m.map[y], 'E'))
			e++;
		y++;
	}
	if (!(e && p && c))
		return (0);
	return (1);
}

t_map	*check_map(int n, char *s)
{
	t_map	*maps;
	size_t	y;

	if (n != 2)
	{
		ft_printf("Error\nillegal arguments!!\n");
		return (0);
	}
	if (!check_map_name(s))
	{
		ft_printf("Error\nmap name is wrong, it must end with <*.ber> !!\n");
		return (0);
	}
	maps = get_maps(s);
	y = 0;
	while (y < maps->h_m)
		maps->map[y++][maps->s_m - 1] = '\0';
	maps->s_m -= 1;
	if (!check_elements(*maps))
	{
		ft_printf("Error\nplease enter a valid map!!\n");
		free(maps);
		return (0);
	}
	return (maps);
}
