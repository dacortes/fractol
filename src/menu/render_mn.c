/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:45:05 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/24 11:41:42 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

static int percentage(int x)
{
	x = 70 * WIDTH / 100;
	return (x);
}

void	rendder_mn(t_fractol *f)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
    while (++y < HEIGHT)
    {
		x = percentage(x);
		while (++x < WIDTH)
		my_mlx_pixel_put(&f->win, x, y, create_trgb(100, 255, 255, 255));
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
}

void	status_menu_render(t_fractol *f)
{
	if (f->menu.status == FALSE)
	{
		render(f, -1, -1);
		rendder_mn(f);
	}
	else
		render(f, -1, -1);
}