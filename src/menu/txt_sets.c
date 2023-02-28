/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_sets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:27:59 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/28 11:44:48 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/fractol.h"

void	txt_mandelbrot(int x, int y, t_fractol *f)
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

void	txt_julia(int x, int y, t_fractol *f)
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

void	txt_butning_ship(int x, int y, t_fractol *f)
{
	put_str(f, "BURNING SHIP", x, y);
	put_str(f, "El fractal de Burning Ship es una", x - 10, y + 5);
	put_str(f, "variante del conjunto de Mandelbrot,", x - 10, y + 7);
	put_str(f, "que se caracteriza por tener una", x - 10, y + 9);
	put_str(f, "forma cuadrada  y simétrica similar a", x - 10, y + 11);
	put_str(f, "un barco  en llamas navegando en el", x - 10, y + 13);
	put_str(f, "mar.", x - 10, y + 15);
}

void txt_defaul(int x, int y, t_fractol *f)
{
	
}