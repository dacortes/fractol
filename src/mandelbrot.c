/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:05:01 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/17 12:11:40 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

/*int mandelbrot(double cr, double ci)
{
    double  zr;
    double  zi;
    double  tmp;
    int     i;

    zr = 0;
    zi = 0;
    i = 0;
    while (i < MAX_ITER)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break ;
        tmp = 2 * zr * zi + ci;
        zr = zr * zr - zi * zi + cr;
        zi = tmp;
        i++;
    }
    return (i);
}*/
int mandelbrot(double cr, double ci)
{
    double  zx;
    double  zy;
    double  tmp;
    int     i;

    zx = 0;
    zy = 0;
    i = -1;
    while (zx * zx + zy * zy <= 4.0 && ++i < MAX_ITER)
    {
        tmp = zx * zx - zy * zy + cr;
        zy = 2 * zx * zy + ci;
        zx = tmp;
    }
    return (i);
}