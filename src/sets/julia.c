/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:12:33 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/02 22:44:49 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

int	julia_move(int x, int y, t_fractol *f)
{
	f->mouse.x = x;
	f->mouse.y = y;
	julia_click(f->mouse.x, f->mouse.y, f);
	return (0);
}

void	set_pos(double posre, double posim, int *set, t_fractol *f)
{
	if (*set != 1)
	{
		f->var.x = posre;
		f->var.y = posim;
		*set = 1;
	}	
}

int	julia_click(int x, int y, t_fractol *f)
{
	if (f->mouse.status == TRUE)
	{
		f->mouse.posre = f->var.min_re + (double)x
			* (f->var.max_re - f->var.min_re) / WIDTH;
		f->mouse.posim = f->var.max_im + (double)y
			* (f->var.min_im - f->var.max_im) / WIDTH;
		f->set_t = 0;
		f->var.x = f->mouse.posre;
		f->var.y = f->mouse.posim;
	}
	else if (f->mouse.status == FALSE)
	{
		f->mouse.posre = f->var.x;
		f->mouse.posim = f->var.y;
		set_pos(f->mouse.posre, f->mouse.posim, &f->set_t, f);
	}
	status_menu_render(f);
	return (SUCCES);
}

int	julia(t_fractol *f, double zx, double zy)
{
	double	tmp;
	int		i;

	i = 0;
	while (zx * zx + zy * zy <= 4.0 && ++i < f->iter_max)
	{
		tmp = 2 * zx * zy + f->mouse.posim;
		zx = zx * zx - zy * zy + f->mouse.posre;
		zy = tmp;
		i++;
	}
	return (i);
}
