/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:48:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/01/30 11:11:57 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	gc_az_azp(int i, t_color *c)
{
	if (i < 65)
	{
		c->t = 20;
		c->r = 50;
		c->g = 100;
		c->b = 255;
	}
	if (i < 45)
	{
		c->t = 0;
		c->r = 200;
		c->g = 0;
		c->b = 255;
	}
	return (create_trgb(c->t, c->r, c->g, c->b));
}

int	gc_bla_fux(int i, t_color *c)
{
	if (i < 35)
	{
		c->t = 0;
		c->r = 0;
		c->g = 150;
		c->b = 255;
	}	
	if (i < 25)
	{
		c->t = 0;
		c->r = 0;
		c->g = 200;
		c->b = 255;
	}
	if (i < 5)
	{
		c->t = 0;
		c->r = 0;
		c->g = 246;
		c->b = 255;
	}
	return (create_trgb(c->t, c->r, c->g, c->b));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	genete_c(int i)
{
	t_color	c;

	gc_az_azp(i, &c);
	gc_bla_fux(i, &c);
	return (create_trgb(c.t, c.r, c.g, c.b));
}
