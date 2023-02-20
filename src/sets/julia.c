/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:12:33 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/20 15:51:49 by dacortes         ###   ########.fr       */
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
	return (0);
}

int	julia(t_fractol *f, double zr, double zi)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->mouse.posim;
		zr = zr * zr - zi * zi + f->mouse.posre;
		zi = tmp;
		i++;
	}
	return (i);
}
