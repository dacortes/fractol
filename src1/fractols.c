/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:54:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/08 14:40:56 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	ft_px_put(t_win *img, int i, int col, int row)
{
	if (i < 100)
		my_mlx_pixel_put(img, col, row, genete_c(i));
	else
		my_mlx_pixel_put(img, col, row, 0x000000);
}

void	formula(t_var *f, int opt)
{
	if (opt == 0)
	{
		f->tmp_x = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zx * f->zy + f->cy;
		f->zx = f->tmp_x;
	}
	else if (opt == 1)
	{
		f->tmp_x = powf(f->zx * f->zx + f->zy * f->zy, f->n / 2)
			* cosf(f->n * atan2f(f->zy, f->zx)) + f->cx;
		f->zy = powf(f->zx * f->zx + f->zy * f->zy, f->n / 2)
			* sinf(f->n * atan2f(f->zy, f->zx)) + f->cy;
		f->zx = f->tmp_x;
	}
}

void	julia_mouse(t_win *img, int x, int y)
{
	t_var	f;

	f.zoom = img->m_zoom;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f.zx = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			f.zy = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
			f.r = 2;
			f.n = 2;
			f.i = -1;
			f.cx = (img->mx - WIDTH / 2.0) * 4.0 / WIDTH;
			f.cy = (img->my - HEIGHT / 2.0) * 4.0 / WIDTH;
			while (f.zx * f.zx + f.zy * f.zy <= f.r * f.r && ++f.i < 100)
				formula(&f, 0);
			ft_px_put(img, f.i, x, y);
		}
	}
}

void	mandelbrot_sets(t_win *img, int x, int y)
{
	t_var	f;

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f.zx = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			f.zy = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
			f.cx = f.zx;
			f.cy = f.zy;
			f.r = 2;
			f.n = 2;
			f.i = -1;
			while (f.zx * f.zx + f.zy * f.zy <= f.r * f.r && ++f.i < 100)
				formula(&f, 1);
			ft_px_put(img, f.i, x, y);
		}
	}
}
