/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:55:13 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/23 11:51:09 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

void	clean_win(int code, t_fractol *f)
{
	if (!f)
		exit(code);
	if (f->win.img)
		mlx_destroy_image(f->win.mlx, f->win.img);
	if (f->win.mlx)
		mlx_destroy_window(f->win.mlx, f->win.win);
	exit(code);
}

int	msg_err(char *str, int error)
{
	ft_printf(R"Fractol :\n"E);
	ft_printf("%s", str);
	return (error);
}

int	end_fractol(t_fractol *f)
{
	ft_printf(B"--> Bye bye 👋\n"E);
	clean_win(0, f);
	return (SUCCES);
}
