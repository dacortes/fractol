/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:24:03 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/01 21:21:09 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int zoom(int button, int x, int y, t_win *img)
{
    (void)(x);
    (void)(y);

    img->m_zoom = 1.1;
    if (button == 4)
        img->m_zoom += 1.1;
    else if (button == 5)
        img->m_zoom -= 1.1;
    printf("Zoom: %f", img->m_zoom);
    return (0);
}