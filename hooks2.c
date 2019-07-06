/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:14:08 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/31 13:49:49 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			ft_time(t_win *win)
{
	t_wolf		*wolf;

	wolf = win->wolf;
	wolf->end = clock();
	wolf->cpu_time_used = ((double)(wolf->end - wolf->start)) / 100000.0;
	wolf->mspeed = wolf->cpu_time_used * 2;
	wolf->rspeed = wolf->cpu_time_used;
}

int				ft_release(int key, t_win *win)
{
	if (key == 126)
		win->key->up = 0;
	if (key == 125)
		win->key->down = 0;
	if (key == 124)
		win->key->right = 0;
	if (key == 123)
		win->key->left = 0;
	return (0);
}

void			ft_check_map(t_win *win)
{
	int			a;
	int			b;

	a = 0;
	b = 0;
	while (b < SIZE)
	{
		win->wolf->worldmap[a][b++] = 1;
	}
	while (a < SIZE)
	{
		win->wolf->worldmap[a++][b - 1] = 1;
	}
	while (a > 0)
	{
		win->wolf->worldmap[b - 1][--a] = 1;
	}
	while (b > 0)
		win->wolf->worldmap[--b][a] = 1;
}

void			ft_check_portal(t_win *win)
{
	t_wolf		*wolf;

	wolf = win->wolf;
	if ((wolf->worldmap)[(int)wolf->posx + 1][(int)wolf->posy] == 5)
	{
		wolf->posx = win->key->posxtp;
		wolf->posy = win->key->posytp;
		system("afplay " SOUND_2 " &");
	}
	if ((wolf->worldmap)[(int)wolf->posx - 1][(int)wolf->posy] == 5)
	{
		wolf->posx = win->key->posxtp;
		wolf->posy = win->key->posytp;
		system("afplay " SOUND_2 " &");
	}
	if ((wolf->worldmap)[(int)wolf->posx][(int)wolf->posy + 1] == 5)
	{
		wolf->posx = win->key->posxtp;
		wolf->posy = win->key->posytp;
		system("afplay " SOUND_2 " &");
	}
}

void			ft_tp_scroll(t_win *win)
{
	win->key->posxtp = win->wolf->posx;
	win->key->posytp = win->wolf->posy;
}
