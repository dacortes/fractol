/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:21:47 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/28 17:48:47 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static void	init_color(t_color *c, t_fractol *f)
{
	if (f->menu.key_t == BLUE)
	{
		c->r = 55.5;
		c->g = 20.5;
		c->b = 8.5;
	}
	else if (f->menu.key_t == GREEN)
	{
		c->r = 20.5;
		c->g = 80.5;
		c->b = 0.5;
	}
	else if (f->menu.key_t == RED)
	{
		c->r = 99.5;
		c->g = 0.2;
		c->b = 1.2;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	generete_c(int iter, t_fractol *f)
{
	t_color	c;
	double	t;
	int		r;
	int		g;
	int		b;

	init_color(&c, f);
	t = (double)iter / MAX_ITER;
	r = (int)(c.r * (1 - t) * t * t * t * 255);
	g = (int)(c.g * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(c.b * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 20 | g << 9 | b);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_pixel(t_fractol *f, int x, int y, int iter)
{
	my_mlx_pixel_put(&f->win, x, y, generete_c(iter, f));
}
