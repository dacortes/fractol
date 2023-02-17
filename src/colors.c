/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:21:47 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/17 10:23:59 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static int generete_c(t_fractol *f, int iter)
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
void	ft_put_pixel(t_fractol *f, int x, int y, int iter)
{
	my_mlx_pixel_put(f, x, y, generete_c(f, iter));
}
