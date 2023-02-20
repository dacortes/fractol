/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:12:33 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/20 15:59:58 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

int	julia_click(int x, int y, t_fractol *f)
{
	f->mouse.posre = f->var.min_re + (double)x * (f->var.max_re - f->var.min_re)
		/ WIDTH;
	f->mouse.posim = f->var.max_im + (double)y * (f->var.min_im - f->var.max_im)
		/ WIDTH;
	render(f, -1, -1);
	return (SUCCES);
}

int	julia(t_fractol *f, double zx, double zy)
{
	double	tmp;
	int		i;

	i = 0;
	while (zx * zx + zy * zy <= 4.0 && ++i < MAX_ITER)
	{
		tmp = 2 * zx * zy + f->mouse.posim;
		zx = zx * zx - zy * zy + f->mouse.posre;
		zy = tmp;
		i++;
	}
	return (i);
}
