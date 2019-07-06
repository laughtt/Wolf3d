/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:57:04 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/31 12:43:35 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				ft_raydchoose(t_win *win)
{
	t_wolf			*wolf;
	t_cast			*ray;

	ray = win->ray;
	wolf = win->wolf;
	if (ray->rdirx < 0)
	{
		ray->disx = -1;
		ray->sdx = (wolf->posx - ray->mapx) * ray->dedisx;
	}
	else
	{
		ray->disx = 1;
		ray->sdx = (ray->mapx + 1.0 - wolf->posx) * ray->dedisx;
	}
	if (ray->rdiry < 0)
	{
		ray->disy = -1;
		ray->sdy = (wolf->posy - ray->mapy) * ray->dedisy;
	}
	else
	{
		ray->disy = 1;
		ray->sdy = (ray->mapy + 1.0 - wolf->posy) * ray->dedisy;
	}
}

void				ft_error(void)
{
	write(1, "error bad map \n", 15);
	exit(EXIT_SUCCESS);
}

void				ft_putline(t_point po1, t_point po2, t_image *img)
{
	t_po			point;

	point.dx = abs(po1.x - po2.x);
	point.dy = -abs(po1.y - po2.y);
	point.sx = po1.x < po2.x ? 1 : -1;
	point.sy = po1.y < po2.y ? 1 : -1;
	point.err = point.dx + point.dy;
	while (1)
	{
		img_pixel_put(img, po1.x, po1.y, po1.z);
		if (po1.x == po2.x && po1.y == po2.y)
			break ;
		point.e2 = 2 * point.err;
		if (point.e2 >= point.dy)
		{
			point.err += point.dy;
			po1.x += point.sx;
		}
		if (point.e2 <= point.dx)
		{
			point.err += point.dx;
			po1.y += point.sy;
		}
	}
}

void				ft_check_key(t_win *win)
{
	t_keys			*key;

	key = win->key;
	if (key->up)
		ft_up(win);
	if (key->down)
		ft_down(win);
	if (key->left)
		ft_left(win);
	if (key->right)
		ft_right(win);
}

int					closewin(void *param)
{
	(void)param;
	system("kill $(ps -e | egrep '[m]usic' | awk -F' ' '{print $1}')");
	system("killall afplay");
	exit(0);
	return (0);
}
