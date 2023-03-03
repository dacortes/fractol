/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:05:16 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/03 08:43:54 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static int	calculete(t_fractol *f, double re, double im, int uni)
{
	int	iter;

	iter = 0;
	if (f->var.set == MANDELBROT && uni == FALSE)
		iter = mandelbrot(re, im, f);
	else if (f->var.set == JULIA && uni == FALSE)
		iter = julia(f, re, im);
	else if (f->var.set == BURNING_SHIP && uni == FALSE)
		iter = burning_ship(f, re, im);
	else if (f->var.set == UNION)
	{
		if (uni == MANDELBROT)
			iter = mandelbrot(re, im, f);
		else if (uni == JULIA)
			iter = julia(f, re, im);
	}
	return (iter);
}

void	render(t_fractol *f, int x, int y)
{
	double	re;
	double	im;
	int		iter;

	mlx_clear_window(f->win.mlx, f->win.win);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			re = f->var.min_re + (double)x * (f->var.max_re - f->var.min_re)
				/ WIDTH;
			im = f->var.max_im + (double)y * (f->var.min_im - f->var.max_im)
				/ HEIGHT;
			iter = calculete(f, re, im, f->var.uni);
			ft_put_pixel(f, x, y, iter);
		}
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
}

void swap(int *x, int *tmp)
{
	*x = *tmp;
}
void	render_union(t_fractol *f, int x, int y, int width)
{
	double	re;
	double	im;
	int		iter;
	int		tmp;

	tmp = x;
	mlx_clear_window(f->win.mlx, f->win.win);
	while (++y < HEIGHT)
	{
		swap(&x, &tmp);
		while (++x < width)
		{
			re = f->var.min_re + (double)x  * (f->var.max_re - f->var.min_re)
				/ width;
			im = f->var.max_im + (double)y * (f->var.min_im - f->var.max_im)
				/ HEIGHT;
			iter = calculete(f, re, im, f->var.uni);
			ft_put_pixel(f, x, y, iter);
		}
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
}