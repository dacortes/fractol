/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_sets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:27:59 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/03 13:59:37 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

static void	logo(int x, int y, t_fractol *f)
{
	put_str(f, "/* ******************************* */", x - 10, y + 75);
	put_str(f, "/*           :::      ::::::::     */", x - 10, y + 77);
	put_str(f, "/*         :+:      :+:    :+:     */", x - 10, y + 79);
	put_str(f, "/*       +:+ +:+         +:+       */", x - 10, y + 81);
	put_str(f, "/*      +#+  +:+       +#+         */", x - 10, y + 83);
	put_str(f, "/*     +#+#+#+#+#+    +#+          */", x - 10, y + 85);
	put_str(f, "/*           #+#    #+#            */", x - 10, y + 87);
	put_str(f, "/*          ###   ########.fr      */", x - 10, y + 89);
	put_str(f, "/* ******************************* */", x - 10, y + 91);
}

void	txt_mandelbrot(int x, int y, t_fractol *f)
{
	put_str(f, "MANDELBROT", x, y);
	put_str(f, "In mathematics, a multibrot set is the", x - 10, y + 5);
	put_str(f, "set of complex plane values for which", x - 10, y + 7);
	put_str(f, "the absolute value remains below a", x - 10, y + 9);
	put_str(f, "certain finite value in the iterations", x - 10, y + 11);
	put_str(f, "of a member of the general family of", x - 10, y + 13);
	put_str(f, "recursively defined monic polynomials", x - 10, y + 15);
	put_str(f, "of one variable.", x - 10, y + 17);
}

void	txt_julia(int x, int y, t_fractol *f)
{
	put_str(f, "JULIA", x, y);
	put_str(f, "Julia sets, named after the", x - 10, y + 5);
	put_str(f, "mathematician Gaston Julia, are", x - 10, y + 7);
	put_str(f, "a family fractal sets obtained", x - 10, y + 9);
	put_str(f, "by studying the behavior of complex", x - 10, y + 11);
	put_str(f, "numbers when iterated by a holomorphic ", x - 10, y + 13);
	put_str(f, "function.", x - 10, y + 15);
}

void	txt_butning_ship(int x, int y, t_fractol *f)
{
	put_str(f, "BURNING SHIP", x, y);
	put_str(f, "The Burning Ship fractal is a variant", x - 10, y + 5);
	put_str(f, "of the Mandelbrot set, characterized", x - 10, y + 7);
	put_str(f, "by a square and symmetric shape that", x - 10, y + 9);
	put_str(f, "resembles a burning ship sailing on", x - 10, y + 11);
	put_str(f, "the sea.", x - 10, y + 13);
}

void	txt_defaul(int x, int y, t_fractol *f)
{
	put_str(f, "CONTROLS:", x - 10, y + 25);
	put_str(f, "Keyboard:", x - 10, y + 28);
	put_str(f, "i -> controls the number of iterations", x - 10, y + 30);
	put_str(f, "r -> restarts the fractal", x - 10, y + 32);
	put_str(f, "f -> only works for julia and saves", x - 10, y + 34);
	put_str(f, "the state of the fractal.", x - 10, y + 36);
	put_str(f, "m -> hides and shows the menu", x - 10, y + 38);
	put_str(f, "t -> changes the theme.", x - 10, y + 40);
	put_str(f, "move:", x - 10, y + 42);
	put_str(f, "->up arrow", x - 10, y + 44);
	put_str(f, "->left arrow", x - 10, y + 46);
	put_str(f, "->rigth arrow", x - 10, y + 48);
	put_str(f, "->down arrow", x - 10, y + 50);
	put_str(f, "Mouse:", x - 10, y + 55);
	put_str(f, "Depends on mouse settings.", x - 10, y + 57);
	put_str(f, "scroll up -> zoom out/in", x - 10, y + 59);
	put_str(f, "scroll down -> zoom in/out", x - 10, y + 61);
	logo(x, y, f);
}
