/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:32:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/17 11:01:44 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void get_set(t_fractol *f, int check)
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

int main(int ac, char **av)
{
    t_fractol f;
    int check;
    
    check = check_arc(ac, av);
    init_var(&f);
    get_set(&f, check);
    init(&f, check);
    render(&f, -1, -1);
    mlx_hook(f.win.win, BTN_X, 0, end_fractol, &f);
    mlx_key_hook(f.win.win, key_event, &f);
    mlx_mouse_hook(f.win.win, mouse_event, &f);
    mlx_loop(f.win.mlx);
}