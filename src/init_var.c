/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:34:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/03 13:37:25 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

void	init_var(t_fractol *f)
{
	f->iter_max = 50;
	f->set_t = 0;
	f->win.mlx = NULL;
	f->win.win = NULL;
	f->win.img = NULL;
	f->win.addr = NULL;
	f->win.bits_per_pixel = 0;
	f->win.line_length = 0;
	f->win.endian = 0;
	f->var.min_re = 0;
	f->var.max_re = 0;
	f->var.min_im = 0;
	f->var.max_im = 0;
	f->var.set = -1;
	f->var.uni = 0;
	f->var.x = 0;
	f->var.y = 0;
	f->menu.status = 0;
	f->menu.key_t = 1;
	f->mouse.posre = 0;
	f->mouse.posim = 0;
	f->mouse.zoom = 0;
	f->mouse.status = 0;
	f->mouse.x = 0;
	f->mouse.y = 0;
}

void	get_num_complex(t_fractol *f)
{
	if (f->var.set == JULIA)
	{
		f->var.min_re = -2.0;
		f->var.max_re = 2.0;
		f->var.min_im = -2.0;
		f->var.max_im = f->var.min_im + (f->var.max_re - f->var.min_re)
			* HEIGHT / WIDTH;
	}
	else if (f->var.set == UNION)
	{
		f->var.min_re = -3.5;
		f->var.max_re = 1.5;
		f->var.min_im = -2.2;
		f->var.max_im = f->var.min_im + (f->var.max_re - f->var.min_re)
			* HEIGHT / WIDTH;
	}
	else
	{
		f->var.min_re = -1.8;
		f->var.max_re = 1.5;
		f->var.max_im = -2.8;
		f->var.min_im = f->var.min_im + (f->var.max_re - f->var.min_re)
			* HEIGHT / WIDTH;
	}
}

static void	init_img(t_fractol *f)
{
	f->win.img = mlx_new_image(f->win.mlx, WIDTH, HEIGHT);
	if (!(f->win.img))
		clean_win(msg_err("IMG : error creation error.", 1), f);
	f->win.addr = mlx_get_data_addr(f->win.img, &f->win.bits_per_pixel,
			&f->win.line_length, &f->win.endian);
}

static char	*name_win(int check)
{
	char	*name;

	name = NULL;
	if (check == MANDELBROT)
		name = "Mandelbrot";
	else if (check == JULIA)
		name = "Julia";
	else if (check == BURNING_SHIP)
		name = "Burning ship";
	else if (check == UNION)
		name = "Union";
	return (name);
}

void	init(t_fractol *f, int check)
{
	f->win.mlx = mlx_init();
	if (!f->win.mlx)
		clean_win(msg_err("MLX: error connecting to mlx.", 1), f);
	f->win.win = mlx_new_window(f->win.mlx, WIDTH, HEIGHT, name_win(check));
	if (!f->win.win)
		clean_win(msg_err("MLX: error connecting to mlx.", 1), f);
	init_img(f);
	f->var.sx = 2.0;
	f->var.rx = 0.5;
	f->var.fx = 1.0;
	get_num_complex(f);
}
