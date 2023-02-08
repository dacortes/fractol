/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:47:00 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/01 12:26:08 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	mouse(int x, int y, t_win *win)
{
	win->mx = x;
	win->my = y;
	//mlx_mouse_hook(win->win, zoom, win);
	julia_mouse(win, -1, -1);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	return (0);
}

int	prueba_m(char *argv)
{
	t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WIDTH, HEIGHT, argv);
	if (win.win == NULL)
		return (0);
	win.img = mlx_new_image(win.mlx, WIDTH, HEIGHT);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel,
			&win.line_length, &win.endian);
	mandelbrot_sets(&win, -1, -1);
	mlx_clear_window(win.mlx, win.win);
	mlx_put_image_to_window(win.mlx, win.win, win.img, 0, 0);
	mlx_hook(win.win, 2, 1L << 0, close_esc, &win);
	mlx_hook(win.win, 17, 1L << 17, close_win, &win);
	mlx_loop(win.mlx);
	return (1);
}

int	prueba_mouse_julia(char *argv)
{
	t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WIDTH, HEIGHT, argv);
	if (win.win == NULL)
		return (0);
	win.img = mlx_new_image(win.mlx, WIDTH, HEIGHT);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel,
			&win.line_length, &win.endian);
	mlx_hook(win.win, 6, 1L << 6, mouse, &win);
	//mlx_mouse_hook(win.win, zoom, &win);
	mlx_hook(win.win, 4, 0, zoom, &win);//scroll up
	//mlx_hook(win.win, 4, 1L << 12, zoom, &win);//scroll down
	mlx_hook(win.win, 2, 1L << 0, close_esc, &win);
	mlx_hook(win.win, 17, 1L << 17, close_win, &win);
	mlx_loop(win.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	int	f;

	f = check_arc(argc, argv[1]);
	if (f == 1)
	{
		ft_printf(G"Mandelbrot fractal generated correctly👍\n"E);
		if (prueba_m(argv[1]) == 0)
		{
			ft_printf(R"Error: mlx_new_window() "E);
			ft_printf(R"failed to create a new image 😢\n"E);
		}
	}
	else if (f == 2)
	{
		ft_printf(G"Julia fractal generated correctly👍\n"E);
		if (prueba_mouse_julia(argv[1]) == 0)
		{
			ft_printf(R"Error: mlx_new_window() "E);
			ft_printf(R"failed to create a new image 😢\n"E);
		}
	}
	return (0);
}
