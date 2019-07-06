/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:36:37 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/31 13:48:42 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "miniLibX/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>
# define SOUND_0 "./sounds/Clubstep.mp3"
# define SOUND_1 "./sounds/step.mp3"
# define SOUND_2 "./sounds/teleport.mp3"
# define W 1280
# define H 1280
# define SIZE 128
# define IMG_HEIGHT 1280
# define IMG_WIDTH 1280

typedef struct		s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	char		*str;
}					t_image;

typedef struct		s_wolf
{
	int				worldmap[SIZE][SIZE];
	int				mapwidth;
	int				mapheight;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	clock_t			start;
	clock_t			end;
	double			cpu_time_used;
	double			time;
	double			oldtime;
	double			mspeed;
	double			rspeed;
	double			timem;
}					t_wolf;

typedef	struct		s_rcast
{
	double			camx;
	double			rdirx;
	double			rdiry;
	int				mapx;
	int				mapy;
	double			sdx;
	double			sdy;
	double			dedisx;
	double			dedisy;
	double			perwalldist;
	int				disx;
	int				disy;
	int				hit;
	int				side;
	int				color;
	int				lineheight;
	int				dstart;
	int				dend;
}					t_cast;

typedef struct		s_pointmatch
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_po;

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_mov
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			posxtp;
	int			posytp;
}					t_keys;

typedef struct		s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	t_wolf		*wolf;
	t_cast		*ray;
	int			fd;
	t_keys		*key;
}					t_win;

void				definition(t_keys *key);
void				ft_tp_scroll(t_win *win);
int					ft_test2(t_win *win);
void				ft_time(t_win *win);
void				ft_check_map(t_win *win);
void				ft_check_portal(t_win *win);
void				ft_position(t_win *win);
void				ft_check_key(t_win *win);
int					ft_release(int	key, t_win *win);
void				freeall(t_win *win);
void				ft_error(void);
int					closewin(void *param);
void				ft_raydchoose(t_win *win);
int					get_next_line(const int	fd, char **line);
void				ft_putline(t_point	po1, t_point po2, t_image *img);
void				ft_raydistance(t_win *win, int x);
void				ft_rayhit(t_win *win);
void				ft_rayheight(t_win *win);
void				ft_color(t_win *win);
void				ft_drawlines(t_win *win, int x);
void				ft_left(t_win *win);
void				ft_right(t_win *win);
void				ft_down(t_win *win);
void				ft_up(t_win *win);
void				ft_loop(t_win *win);
t_image				*create_image(t_win *win);
void				img_pixel_put(t_image *img, int x, int y, int color);
t_image				*mlx_win_init(t_win *win);
#endif
