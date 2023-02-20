/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:21:47 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/20 15:51:32 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static int	generete_c(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / 100.0;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_pixel(t_fractol *f, int x, int y, int iter)
{
	my_mlx_pixel_put(&f->win, x, y, generete_c(iter));
}

/*static void	color_shift_special(t_fractol *f)
{
	int	alt_color;

	if (f->color == 0xFFFFFF)
		alt_color = 0xCCCCCC;
	else
		alt_color = f->color;
	if (f->color_pattern == 5)
		set_color_contrasted(f, alt_color);
	else if (f->color_pattern == 6)
		set_color_opposites(f, f->color);
	else if (f->color_pattern == 7)
		set_color_graphic(f, f->color);
	else if (f->color_pattern == 8)
		set_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

static void	color_shift_striped(t_fractol *f)
{
	if (f->color_pattern == 2)
		set_color_zebra(f, f->color);
	else if (f->color_pattern == 3)
		set_color_triad(f, f->color);
	else if (f->color_pattern == 4)
		set_color_tetra(f, f->color);
	else
		color_shift_special(f);
}

void	color_shift(t_fractol *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		set_color_mono(f, alt_color);
	else if (f->color_pattern == 1)
		set_color_multiple(f, (int [4]){0x000000, alt_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(f);
}*/