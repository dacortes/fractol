/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:48:51 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/23 20:02:39 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

int	burning_ship(t_fractol *f, double cr, double ci)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	zx = 0;
	zy = 0;
	i = -1;
	while (zx * zx + zy * zy <= 4.0 && ++i < f->iter_max)
	{
		tmp = zx * zx - zy * zy + cr;
		zy = fabs(2.0 * zx * zy) + ci;
		zx = tmp;
	}
	return (i);
}
