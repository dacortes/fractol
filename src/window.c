/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:08:12 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/10 10:24:39 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"
#include<stdio.h>

int	close_win(t_win *win)
{
	mlx_clear_window(win->mlx, win->win);
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	ft_printf(B"--> Bye bye 👋\n"E);
	exit(0);
}

int	close_esc(int keycode, t_win *win)
{
	if (keycode == 53)
	{
		mlx_clear_window(win->mlx, win->win);
		mlx_destroy_image(win->mlx, win->img);
		mlx_destroy_window(win->mlx, win->win);
		ft_printf(B"--> Bye bye 👋\n"E);
	}
	exit(0);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
