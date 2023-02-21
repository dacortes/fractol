/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:12:33 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/21 16:09:10 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"
void	set_pos(double posre, double posim, int *set, t_fractol *f)
{
	if (*set == 0)
	{
		f->var.x = posre;
		f->var.y = posim;
		*set = 1;
	}
	ft_printf(B"%d\n"E, *set);
}
int	julia_click(int x, int y, t_fractol *f)
{
	if (f->mouse.status == TRUE)
	{
		f->mouse.posre = f->var.min_re + (double)x * (f->var.max_re - f->var.min_re)
			/ WIDTH;
		f->mouse.posim = f->var.max_im + (double)y * (f->var.min_im - f->var.max_im)
			/ WIDTH;
		set_pos(f->mouse.posre, f->mouse.posim, &f->set_t, f);
		ft_printf("querio moverme\n");
	}
	else
	{
		f->mouse.posre = f->var.min_re + (double)f->var.x
			* (f->var.max_re - f->var.min_re) / WIDTH;
		f->mouse.posim = f->var.max_im + (double)f->var.y
			* (f->var.min_im - f->var.max_im) / WIDTH;
		ft_printf("no quiero moverme\n");
	}
	ft_printf(R"%d"E, f->set_t);
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
