/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:30:17 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/31 12:44:01 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				ft_raydistance(t_win *win, int x)
{
	t_wolf			*wolf;
	t_cast			*ray;

	ray = win->ray;
	wolf = win->wolf;
	ray->camx = 2.0 * x / (double)W - 1l;
	ray->rdirx = wolf->dirx + wolf->planex * ray->camx;
	ray->rdiry = wolf->diry + wolf->planey * ray->camx;
	ray->mapx = (int)(wolf->posx);
	ray->mapy = (int)(wolf->posy);
	ray->dedisx = fabs(1 / ray->rdirx);
	ray->dedisy = fabs(1 / ray->rdiry);
	ray->hit = 0;
	ft_raydchoose(win);
}

void				ft_rayhit(t_win *win)
{
	while (win->ray->hit == 0)
	{
		if (win->ray->sdx < win->ray->sdy)
		{
			win->ray->sdx += win->ray->dedisx;
			win->ray->mapx += win->ray->disx;
			win->ray->side = 0;
		}
		else
		{
			win->ray->sdy += win->ray->dedisy;
			win->ray->mapy += win->ray->disy;
			win->ray->side = 1;
		}
		if ((win->wolf->worldmap)[abs(win->ray->mapx)][abs(win->ray->mapy)] > 0)
			win->ray->hit = 1;
		if (win->ray->side == 0)
			win->ray->perwalldist = (win->ray->mapx - win->wolf->posx +\
					(1 - win->ray->disx) / 2) / win->ray->rdirx;
		else
			win->ray->perwalldist = (win->ray->mapy - win->wolf->posy +\
					(1 - win->ray->disy) / 2) / win->ray->rdiry;
	}
}

void				ft_rayheight(t_win *win)
{
	t_wolf			*wolf;
	t_cast			*ray;

	ray = win->ray;
	wolf = win->wolf;
	ray->lineheight = (int)(H / ray->perwalldist);
	ray->dstart = -ray->lineheight / 2 + H / 2;
	if (ray->dstart < 0)
		ray->dstart = 0;
	ray->dend = ray->lineheight / 2 + H / 2;
	if (ray->dend >= H)
		ray->dend = H - 1;
}

void				ft_color(t_win *win)
{
	t_wolf			*wolf;
	t_cast			*ray;
	int				a;

	ray = win->ray;
	wolf = win->wolf;
	a = (wolf->worldmap)[ray->mapx][ray->mapy];
	if (a == 1)
		ray->color = 0xFF0000;
	else if (a == 2)
		ray->color = 0x8B0000;
	else if (a == 3)
		ray->color = 0x800000;
	else if (a == 4)
		ray->color = 0xFF6347;
	else
		ray->color = 0xDB7093;
	if (ray->side == 1)
		ray->color = (ray->color >> 1) & 8355711;
}

void				ft_drawlines(t_win *win, int x)
{
	t_point			start;
	t_point			end;
	t_point			floor;
	t_point			sky;

	sky.x = x;
	sky.y = 0;
	sky.z = 0x87CEFA;
	floor.x = x;
	floor.y = IMG_HEIGHT;
	start.x = x;
	end.x = x;
	start.z = win->ray->color;
	start.y = win->ray->dstart;
	end.y = win->ray->dend;
	end.z = 0xa8775a;
	ft_putline(start, end, win->image);
	ft_putline(end, floor, win->image);
	ft_putline(sky, start, win->image);
}
