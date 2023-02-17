/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/17 09:58:33 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void zoom (t_fractol *f, double zoom)
{
    double  cen_re;
    double  cen_im;

    cen_re = f->var.min_re - f->var.max_re;
    cen_im = f->var.max_im - f->var.min_im;
    f->var.max_re = f->var.max_re + (cen_re - zoom * cen_re) / 2;
    f->var.min_re = f->var.max_re + zoom * cen_re;
    f->var.min_im = f->var.min_im + (cen_im - zoom * cen_im) / 2;
    f->var.max_im = f->var.min_im + zoom * cen_im;
}

static void move(t_fractol *f, double distance, char direction)
{
    double  cen_re;
    double  cen_im;

    cen_re = f->var.min_re - f->var.max_re;
    cen_im = f->var.min_im - f->var.max_im;
    if (direction == 'R')
    {
        f->var.min_re += cen_re * distance;
        f->var.max_re += cen_re * distance;
    }
    else if (direction == 'L')
    {
        f->var.min_re -= cen_re * distance;
        f->var.max_re -= cen_re * distance;
    }
    else if (direction == 'D')
    {
        f->var.min_im -= cen_im * distance;
        f->var.max_im -= cen_im * distance;
    }
    else if (direction == 'U')
    {
        f->var.max_im += cen_im * distance;
        f->var.max_im += cen_im * distance;
    }
}

int key_event(int keycode, t_fractol *f)
{
    if (keycode == KEY_ESC)
    {
        end_fractol(f);
        return (0);
    }
    else if (keycode == KEY_PLUS)
        zoom(f, 0.5);
    else if (keycode == KEY_MINUS)
        zoom(f, 2);
    else if (keycode == KEY_UP)
        move(f, 0.2, 'U');
    else if (keycode == KEY_DOWN)
        move(f, 0.2, 'D');
    else if (keycode == KEY_LEFT)
        move(f, 0.2, 'L');
    else if (keycode == KEY_RIGHT)
        move (f, 0.2, 'R');
    else
        return (1);
    render(f, -1, -1);
    return (0);
}

int mouse_event(int keycode, int x, int y, t_fractol *f)
{
    if (keycode == SCROLL_UP)
    {
        zoom(f, 0.5);
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
        zoom(f, 2);
    else if (keycode == MIDDLE_CLICK)
    {
        if (f->var.set == JULIA)
            julia_click(x, y, f);
    }
    else
        return (0);
    render(f, -1, -1);
    return (0);
}