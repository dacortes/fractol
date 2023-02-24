/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_sets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:20:36 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/24 18:41:34 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

static void	put_str(t_fractol *f, char *str, int porx, int pory)	
{
	mlx_string_put(f->win.mlx, f->win.win,
		percentage(f->menu.txt_x, porx, WIDTH),
		percentage(f->menu.txt_y, pory, HEIGHT), create_trgb(0, 0, 0, 0), str);
}

void	txt(int x, int y, t_fractol *f)
{
	if (f->var.set == MANDELBROT)
		put_str(f, "MANDELBROT", x, y);
	else if (f->var.set == JULIA)
		put_str(f, "JULIA", x, y);
	else if (f->var.set == BURNING_SHIP)
		put_str(f, "BURNING SHIP", x, y);
}
