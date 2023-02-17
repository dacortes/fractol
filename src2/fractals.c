/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:47:40 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/16 12:16:52 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void	formula(t_var *f, int opt)
{
	if (opt == 0)
	{
		f->tmp_x = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zx * f->zy + f->cy ;
		f->zx = f->tmp_x;
	}
	else if (opt == 1)
	{
		f->tmp_x = pow(f->zx * f->zx + f->zy * f->zy, f->n / 2.0)
			* cos(f->n * atan2(f->zy, f->zx)) + f->cx;
		f->zy = pow(f->zx * f->zx + f->zy * f->zy, f->n / 2.0)
			* sin(f->n * atan2(f->zy, f->zx)) + f->cy;
		f->zx = f->tmp_x;
	}
}

void	julia_mouse(t_win *win, int x, int y)
{
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			win->f.zx = (x - win->f.width / 2.0) * 4.0 / win->f.width;
			win->f.zy = (y - win->f.height / 2.0) * 4.0 / win->f.width;
			win->f.cx = (win->mouse.m_x - win->f.width / 2.0) * 4.0 / win->f.width;
			win->f.cy = (win->mouse.m_y - win->f.height / 2.0) * 4.0 / win->f.width;
			win->f.r = 4; 
			win->f.n = 2;
			win->f.i = -1;
			while (win->f.zx * win->f.zx + win->f.zy * win->f.zy <= win->f.r
				&& ++win->f.i < 50)
				formula(&win->f, 0);
			ft_put_pixel(win, x, y);
		}
	}
}

void	mandelbrot(t_win *win, int x, int y)
{
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			win->f.zx = (x - WIDTH / 2.0) * 3.0 / WIDTH;
			win->f.zy = (y - HEIGHT / 2.0) * 3.0 / WIDTH;
			win->f.cx = win->f.zx;
			win->f.cy = win->f.zy;
			win->f.r = 4;
			win->f.n = 2;
			win->f.i = -1;
			while (win->f.zx * win->f.zx + win->f.zy * win->f.zy <= win->f.r
				&& ++win->f.i < 50)
				formula(&win->f, 1);
			ft_put_pixel(win, x, y);
		}
	}
}
