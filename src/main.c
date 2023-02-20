/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:32:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/20 15:43:51 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/fractol.h"

static void	get_set(t_fractol *f, int check)
{
	if (check == 1)
	{
		ft_printf(G"Mandelbrot fractal generated correctly👍\n"E);
			f->var.set = MANDELBROT;
	}
	else if (check == 2)
	{
		ft_printf(G"Julia fractal generated correctly👍\n"E);
		f->var.set = JULIA;
	}
}
#include <stdio.h>
int	main(int ac, char **av)
{
	t_fractol	f;
	int			check;
	int		*prueba;

	prueba = NULL;
	check = check_arc(ac, av[1]);
	if (check == ERROR)
		exit(E_EXIT);
	init_var(&f);
	get_set(&f, check);
	init(&f, check);
	render(&f, -1, -1);
	mlx_hook(f.win.win, BTN_X, 0, end_fractol, &f);
	mlx_key_hook(f.win.win, key_event, &f);
	mlx_mouse_hook(f.win.win, mouse_event, &f);
	*prueba = mlx_loop(f.win.mlx);
	printf("%p", prueba);
	return (SUCCES);
}
