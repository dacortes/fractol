/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_sets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:32 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/03 13:59:59 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

void	txt_union(int x, int y, t_fractol *f)
{
	put_str(f, "UNION MANDELBROT & JULIA", x - 5, y);
	put_str(f, "I plotted both the Mandelbrot and", x - 10, y + 5);
	put_str(f, "Julia fractals simultaneously, just", x - 10, y + 7);
	put_str(f, "because I was motivated to do so.", x - 10, y + 9);
}

void	put_str(t_fractol *f, char *str, int porx, int pory)
{
	mlx_string_put(f->win.mlx, f->win.win,
		percentage(f->menu.txt_x, porx, WIDTH),
		percentage(f->menu.txt_y, pory, HEIGHT),
		create_trgb(100, 0, 0, 0), str);
}

void	txt(int x, int y, t_fractol *f)
{
	if (f->var.set == MANDELBROT)
		txt_mandelbrot(x, y, f);
	else if (f->var.set == JULIA)
		txt_julia(x, y, f);
	else if (f->var.set == BURNING_SHIP)
		txt_butning_ship(x, y, f);
	else if (f->var.set == UNION)
		txt_union(x, y, f);
	txt_defaul(x, y, f);
}
