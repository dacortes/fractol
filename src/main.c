/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:32:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/02 10:06:47 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

static void	get_set(t_fractol *f, int check)
{
	if (check == MANDELBROT)
	{
		ft_printf(G"Mandelbrot fractal generated correctly👍\n"E);
			f->var.set = MANDELBROT;
	}
	else if (check == JULIA)
	{
		ft_printf(G"Julia fractal generated correctly👍\n"E);
		f->var.set = JULIA;
	}
	else if (check == BURNING_SHIP)
	{
		ft_printf(G"Burning ship fractal generated correctly👍\n"E);
		f->var.set = BURNING_SHIP;
	}
	else if (check == UNION)
	{
		ft_printf(G"mandelbrot and julia fractal generated correctly👍\n"E);
		f->var.set = UNION;
	}
}

int	main(int ac, char **av)
{
	t_fractol	f;
	int			check;

	check = check_arc(ac, av[1]);
	if (check == ERROR)
		exit(E_EXIT);
	init_var(&f);
	get_set(&f, check);
	init(&f, check);
	status_menu_render(&f);
	mlx_hook(f.win.win, BTN_X, 0, end_fractol, &f);
	mlx_key_hook(f.win.win, key_event, &f);
	mlx_mouse_hook(f.win.win, mouse_event, &f);
	mlx_loop(f.win.mlx);
	return (SUCCES);
}
