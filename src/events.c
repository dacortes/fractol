/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/24 11:47:04 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static void	zoom(t_fractol *f, double zoom)
{
	double	cen_re;
	double	cen_im;

	cen_re = f->var.min_re - f->var.max_re;
	cen_im = f->var.max_im - f->var.min_im;
	f->var.max_re = f->var.max_re + (cen_re - zoom * cen_re) / 2;
	f->var.min_re = f->var.max_re + zoom * cen_re;
	f->var.min_im = f->var.min_im + (cen_im - zoom * cen_im) / 2;
	f->var.max_im = f->var.min_im + zoom * cen_im;
}

static void	move(t_fractol *f, double distance, char direction)
{
	double	cen_re;
	double	cen_im;

	cen_re = f->var.min_re - f->var.max_re;
	cen_im = f->var.min_im - f->var.max_im;
	if (direction == 'D')
	{
		f->var.min_re += cen_re * distance;
		f->var.max_re += cen_re * distance;
	}
	else if (direction == 'R')
	{
		f->var.min_re -= cen_re * distance;
		f->var.max_re -= cen_re * distance;
	}
	else if (direction == 'U')
	{
		f->var.min_im -= cen_im * distance;
		f->var.max_im -= cen_im * distance;
	}
	else if (direction == 'L')
	{
		f->var.min_im += cen_im * distance;
		f->var.max_im += cen_im * distance;
	}
}

static int	key_event_extend(int keycode, t_fractol *f)
{
	if (keycode == KEY_F)
	{
		status_btn(&f->mouse.status);
		if (f->var.set == JULIA)
			mlx_hook(f->win.win, 6, 1L << 6, julia_move, f);
	}
	else if (keycode == KEY_I)
		ft_printf(B"iter button status: %d \n"Y, increase_iter(&f->iter_max));
	else if (keycode == KEY_R)
		reset_var(f);
	else if (keycode == KEY_M)
		status_btn(&f->menu.status);
	else
		return (TRUE);
	status_menu_render(f);
	return (FALSE);
}

int	key_event(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(f);
		return (SUCCES);
	}
	else if (keycode == KEY_PLUS)
		zoom(f, 0.2);
	else if (keycode == KEY_MINUS)
		zoom(f, 2);
	else if (keycode == KEY_UP)
		move(f, 0.2, 'U');
	else if (keycode == KEY_LEFT)
		move(f, 0.2, 'D');
	else if (keycode == KEY_DOWN)
		move(f, 0.2, 'L');
	else if (keycode == KEY_RIGHT)
		move (f, 0.2, 'R');
	else if (!key_event_extend(keycode, f))
		return (TRUE);
	else
		return (TRUE);
	status_menu_render(f);
	return (FALSE);
}

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == SCROLL_UP)
	{
		zoom(f, 0.8);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, (double)x * -1 / WIDTH, 'L');
		else if (x < 0)
			move(f, (double)x / WIDTH, 'R');
		else if (y < 0)
			move(f, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move(f, (double)y / HEIGHT, 'D');
	}
	else if (keycode == SCROLL_DOW)
		zoom(f, 2.0);
	else
		return (FALSE);
	status_menu_render(f);
	return (FALSE);
}
