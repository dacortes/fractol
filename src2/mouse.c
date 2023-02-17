/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:38:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/16 12:20:39 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"
#include<stdio.h>

int	move(int x, int y, t_win *win)
{
    win->mouse.m_x = x;
    win->mouse.m_y = y;
	julia_mouse(win, -1, -1);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	return (0);
}

/*int	zoom(int button, int x, int y, t_win *win)
{
	(void)(x);
	(void)(y);
	
	if (button == 4)
		win->mouse.m_zoom += 1.1;
	else if (button == 5)
		win->mouse.m_zoom -= 0.9;
	//printf("Zoom: %f", win->mouse.m_zoom);
	return (0);
}*/
// aumentar la escala de la imagen
int	scroll(int button, int x, int y, t_win *win)
{
	win->mouse.m_zoom = 1.1;	
	if (button == 4)
		zoom(win, x, y, 1.1);
	else if (button == 5)
		zoom(win, x, y, 0.9);
	//printf("Zoom: %f", win->mouse.m_zoom);
	return (0);
}

void	zoom(t_win *win, int x, int y, double zoom)
{
	double n_cx;
	double n_cy;

	n_cx = win->f.cx + (x - win->f.width / 2) * win->mouse.m_zoom / win->f.width;
	n_cy = win->f.cy + (y - win->f.height / 2) * win->mouse.m_zoom / win->f.height;

	win->mouse.m_zoom *= zoom;
	printf("Zoom: %f ", win->mouse.m_zoom);
	win->f.cx = n_cx - (x - win->f.width / 2) * win->mouse.m_zoom / win->f.width;
	win->f.cy = n_cy - (y - win->f.height / 2) * win->mouse.m_zoom / win->f.height;
	julia_mouse(win, -1, -1);
}