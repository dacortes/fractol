/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:44:54 by dacortes          #+#    #+#             */
/*   Updated: 2023/01/31 15:12:17 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	close_esc(int keycode, t_win *win)
{
	if (keycode == 53)
	{
		mlx_clear_window(win->mlx, win->win);
		mlx_destroy_image(win->mlx, win->img);
		mlx_destroy_window(win->mlx, win->win);
		ft_printf(B"--> Bye bye 👋\n"E);
		exit(0);
	}
	return (0);
}

int	close_win(t_win *win)
{
	mlx_clear_window(win->mlx, win->win);
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	ft_printf(B"--> Bye bye 👋\n"E);
	exit(0);
}

char	*conv_low(char *tmp, char *agv)
{
	int	i;

	tmp = ft_calloc(ft_strlen(agv) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	ft_strlcpy(tmp, agv, ft_strlen(agv) + 1);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	return (tmp);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
