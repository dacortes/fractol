/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_sets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:20:36 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/24 19:52:35 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

static void	put_str(t_fractol *f, char *str, int porx, int pory)	
{
	mlx_string_put(f->win.mlx, f->win.win,
		percentage(f->menu.txt_x, porx, WIDTH),
		percentage(f->menu.txt_y, pory, HEIGHT), create_trgb(100, 0, 0, 0), str);
}

void	txt(int x, int y, t_fractol *f)
{
	if (f->var.set == MANDELBROT)
	{
		put_str(f, "MANDELBROT", x, y);
		put_str(f, "En matemáticas, un conjunto multibrot", x - 10, y + 5);
		put_str(f, "es el conjunto de valores en el plano", x - 10, y + 7);
		put_str(f, "complejo cuyo valor absoluto", x - 10, y + 9);
		put_str(f, "permanece por debajo de algun valor", x - 10, y + 11);
		put_str(f, "finito en las iteraciones de un", x - 10, y + 13);
		put_str(f, "miembro de la familia general de los", x - 10, y + 15);
		put_str(f, "polinomios monicos de una variable", x - 10, y + 17);
		put_str(f, "recursivos.", x - 10, y + 19);
	}
	else if (f->var.set == JULIA)
	{
		put_str(f, "JULIA", x, y);
		put_str(f, "Los conjuntos de Julia, asi llamados", x - 10, y + 5);
		put_str(f, "por el matematico Gaston Julia son", x - 10, y + 7);
		put_str(f, "una familia de conjuntos fractales", x - 10, y + 9);
		put_str(f, "que se obtienen al estudiar el", x - 10, y + 11);
		put_str(f, "comportamiento de los numeros", x - 10, y + 13);
		put_str(f, "complejos al ser iterados por una", x - 10, y + 15);
		put_str(f, "funcion holomorfa.", x - 10, y + 17);
	}
	else if (f->var.set == BURNING_SHIP)
		put_str(f, "BURNING SHIP", x, y);
}
