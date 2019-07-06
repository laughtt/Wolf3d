/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:47:44 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/31 12:44:18 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_up(t_win *win)
{
	t_wolf	*wolf;

	wolf = win->wolf;
	if ((wolf->worldmap)[(int)(wolf->posx +\
				wolf->dirx * wolf->mspeed)][(int)(wolf->posy)] == false)
		wolf->posx += wolf->dirx * wolf->mspeed;
	if ((wolf->worldmap)[(int)(wolf->posx)][(int)(wolf->posy\
				+ wolf->diry * wolf->mspeed)] == false)
		wolf->posy += wolf->diry * wolf->mspeed;
	win->wolf->time = win->wolf->mspeed + win->wolf->time;
	if (win->wolf->time >= 1.5)
	{
		win->wolf->time = 0;
		system("afplay " SOUND_1 " &");
	}
	ft_bzero(win->image->data, IMG_WIDTH * IMG_HEIGHT * win->image->bpp);
}

void		ft_down(t_win *win)
{
	t_wolf	*wolf;

	wolf = win->wolf;
	if (wolf->worldmap[(int)(wolf->posx - wolf->dirx * \
				wolf->mspeed)][(int)(wolf->posy)] == false)
		wolf->posx -= wolf->dirx * wolf->mspeed;
	if (wolf->worldmap[(int)(wolf->posx)][(int)(wolf->posy \
				- wolf->diry * wolf->mspeed)] == false)
		wolf->posy -= wolf->diry * wolf->mspeed;
	ft_bzero(win->image->data, IMG_WIDTH * IMG_HEIGHT * win->image->bpp);
}

void		ft_right(t_win *win)
{
	double	oldplanex;
	double	olddirx;
	t_wolf	*wolf;

	wolf = win->wolf;
	olddirx = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(-wolf->rspeed) - \
			wolf->diry * sin(-wolf->rspeed);
	wolf->diry = olddirx * sin(-wolf->rspeed) +\
			wolf->diry * cos(-wolf->rspeed);
	oldplanex = wolf->planex;
	wolf->planex = wolf->planex * cos(-wolf->rspeed)\
				- wolf->planey * sin(-wolf->rspeed);
	wolf->planey = oldplanex * sin(-wolf->rspeed)\
				+ wolf->planey * cos(-wolf->rspeed);
	ft_bzero(win->image->data, IMG_WIDTH * IMG_HEIGHT * win->image->bpp);
}

void		ft_left(t_win *win)
{
	double	olddirx;
	double	oldplanex;
	t_wolf	*wolf;

	wolf = win->wolf;
	olddirx = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(wolf->rspeed)
				- wolf->diry * sin(wolf->rspeed);
	wolf->diry = olddirx * sin(wolf->rspeed) +
				wolf->diry * cos(wolf->rspeed);
	oldplanex = wolf->planex;
	wolf->planex = wolf->planex * cos(wolf->rspeed)\
				- wolf->planey * sin(wolf->rspeed);
	wolf->planey = oldplanex * sin(wolf->rspeed) +\
					wolf->planey * cos(wolf->rspeed);
	ft_bzero(win->image->data, IMG_WIDTH * IMG_HEIGHT * win->image->bpp);
}
