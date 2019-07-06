/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolftest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 12:25:39 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/31 13:50:08 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				hook_keydown(int key, t_win *win)
{
	if (key == 126)
		win->key->up = 1;
	if (key == 125)
		win->key->down = 1;
	if (key == 124)
		win->key->right = 1;
	if (key == 123)
		win->key->left = 1;
	if (key == 17)
		ft_tp_scroll(win);
	if (key == 53)
	{
		freeall(win);
		closewin(win);
	}
	return (0);
}

static int		ft_test(t_win *win)
{
	t_wolf		*wolf;
	t_cast		*ray;
	int			x;

	ft_check_key(win);
	ray = win->ray;
	wolf = win->wolf;
	wolf->start = clock();
	x = 0;
	ft_check_portal(win);
	while (x < IMG_WIDTH)
	{
		ft_raydistance(win, x);
		ft_rayhit(win);
		ft_rayheight(win);
		ft_color(win);
		ft_drawlines(win, x);
		x++;
	}
	ft_time(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,\
			win->image->ptr, 0, 0);
	return (0);
}

int				ft_create_map(t_win *win)
{
	char		*line;
	int			height;
	int			width;

	height = 0;
	ft_bzero(win->wolf->worldmap, SIZE * SIZE * sizeof(int));
	while (get_next_line(win->fd, &line) > 0)
	{
		width = 0;
		while (line[width] != '\0')
		{
			if (line[width] >= '0' && line[width] <= '9')
				win->wolf->worldmap[width][height] = line[width] - '0';
			if (width >= SIZE - 1 || height >= SIZE - 1)
				return (1);
			width++;
		}
		free(line);
		height++;
	}
	ft_check_map(win);
	win->wolf->mapwidth = width;
	win->wolf->mapheight = height;
	return (0);
}

int				ft_def_position(t_win *win)
{
	t_wolf		*wolf;
	t_cast		*ray;
	t_keys		*key;

	wolf = malloc(sizeof(t_wolf));
	ray = malloc(sizeof(t_cast));
	key = malloc(sizeof(t_keys));
	definition(key);
	key->down = 0;
	key->left = 0;
	key->right = 0;
	wolf->posx = 12;
	wolf->posy = 22;
	wolf->dirx = -1;
	wolf->diry = 0;
	wolf->planex = 0;
	wolf->planey = 0.66;
	wolf->time = 0;
	wolf->oldtime = 0;
	win->wolf = wolf;
	win->ray = ray;
	win->key = key;
	if (ft_create_map(win))
		return (1);
	return (0);
}

void			ft_loop(t_win *win)
{
	if (ft_def_position(win))
	{
		ft_putstr("error map \n");
		freeall(win);
		ft_error();
		return ;
	}
	mlx_hook(win->win_ptr, 2, 0, hook_keydown, win);
	mlx_hook(win->win_ptr, 17, 0, closewin, win);
	mlx_hook(win->win_ptr, 3, 0, ft_release, win);
	mlx_loop_hook(win->mlx_ptr, ft_test, win);
	system("sh ./scripts/play_music.sh &");
	mlx_loop(win->mlx_ptr);
}
