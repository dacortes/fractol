/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:47:40 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/13 14:53:49 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void zoom_factor(t_win *win, int *h, int *w)
{
	*w = *w * win->mouse.m_zoom;
	*h = *h * win->mouse.m_zoom;
}

static	void	ft_put_pixel(t_win *win, int col, int row)
{
	if (win->f.i < 100)
		my_mlx_pixel_put(win, col, row, generete_c(win));
	else
		my_mlx_pixel_put(win, col, row, 0x000000);
}

static void	formula(t_var *f, int opt)
{
	if (opt == 0)
	{
		f->tmp_x = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zx * f->zy + f->cy;
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
	int	h = HEIGHT;
	int	w = WIDTH;
	zoom_factor(win, &h, &w);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			/*win->f.zx = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			win->f.zy = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
			win->f.cx = (win->mouse.m_x - WIDTH / 2.0) * 4.0 / WIDTH;
			win->f.cy = (win->mouse.m_y - HEIGHT / 2.0) * 4.0 / WIDTH;*/

			win->f.zx = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			win->f.zy = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
			win->f.cx = (win->mouse.m_x - WIDTH / 2.0) * 4.0 / WIDTH;
			win->f.cy = (win->mouse.m_y - HEIGHT / 2.0) * 4.0 / WIDTH;
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
