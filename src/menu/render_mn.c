/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:45:05 by dacortes          #+#    #+#             */
/*   Updated: 2023/06/23 17:14:06 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

int	percentage(int x, int por, int param)
{
	x = por * param / 100;
	return (x);
}

void	rendder_mn(t_fractol *f)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	f->menu.txt_x = 0;
	f->menu.txt_y = 0;
	while (++y < HEIGHT)
	{
		x = percentage(x, 70, WIDTH);
		while (++x < WIDTH)
			my_mlx_pixel_put(&f->win, x, y, create_trgb(100, 255, 255, 255));
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
	txt(82, 5, f);
}

void	status_menu_render(t_fractol *f)
{
	if (f->menu.status == FALSE && f->var.set != UNION)
	{
		render(f, -1, -1);
		rendder_mn(f);
	}
	else if (f->menu.status == FALSE && f->var.set == UNION)
	{
		f->var.uni = MANDELBROT;
		render_union(f, -1, -1, percentage(0, 50, WIDTH));
		f->var.uni = JULIA;
		render_union(f, percentage(40, 40, WIDTH), -1, WIDTH);
		rendder_mn(f);
	}
	else if (f->menu.status == TRUE && f->var.set == UNION)
	{
		f->var.uni = MANDELBROT;
		render_union(f, -1, -1, percentage(0, 50, WIDTH));
		f->var.uni = JULIA;
		render_union(f, percentage(40, 40, WIDTH), -1, WIDTH);
	}
	else
		render(f, -1, -1);
}
