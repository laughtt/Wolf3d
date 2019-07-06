/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:04:22 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/31 12:49:23 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			freeall(t_win *win)
{
	free(win->wolf);
	free(win->image);
	free(win->ray);
	free(win);
}

t_image			*create_image(t_win *win)
{
	t_image		*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(win->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->size_line, &image->endian);
	image->bpp /= 8;
	return (image);
}

void			img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT)
	{
		*(int*)(img->data + ((x + (y * IMG_WIDTH)) * img->bpp)) = color;
	}
}

t_image			*mlx_win_init(t_win *win)
{
	t_image		*image;

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr,\
			IMG_HEIGHT, IMG_WIDTH, "mlx 42");
	image = create_image(win);
	return (image);
}

int				main(int arg, char **argv)
{
	t_win		*win;

	if (arg != 2)
	{
		write(1, "error", 6);
		return (0);
	}
	if (!(win = malloc(sizeof(t_win))))
		return (0);
	if (!(win->fd = open(argv[1], O_RDONLY)))
		return (0);
	win->image = mlx_win_init(win);
	ft_loop(win);
	freeall(win);
}
