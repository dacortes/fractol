/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:05:16 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/17 09:20:47 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static int calculete(t_fractol *f, double re, double im)
{
    int iter;

    iter = 0;
    if (f->var.set == MANDELBROT)
        iter = mandelbrot(re, im);
    else if (f->var.set == JULIA)
        iter = julia(re, im);
    return (iter);
}

void render (t_fractol *f, int x, int y)
{
    double  re;
    double  im;
    int     iter;

    mlx_clear_window(f->win.mlx, f->win.win);
    while (++y < HEIGHT)
    {
        x = -1;
        while(++x < WIDTH)
        {
            re = f->var.min_re + (double)x * (f->var.max_re - f->var.min_re) / WIDTH;
            im = f->var.max_im + (double)x * (f->var.min_im - f->var.max_im) / HEIGHT;
            iter = calculete(f, re, im);
        }
    }
    mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
}