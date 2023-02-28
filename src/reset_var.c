/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:13:31 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/28 17:36:27 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

void	reset_var(t_fractol *f)
{
	f->iter_max = 50;
	f->var.x = 0;
	f->var.y = 0;
	f->menu.key_t = 1;
	f->mouse.posre = 0;
	f->mouse.posim = 0;
	f->mouse.zoom = 0;
	f->mouse.status = 0;
	f->mouse.x = 0;
	f->mouse.y = 0;
}
