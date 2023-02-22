/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_btn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:02:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/22 19:58:02 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

int	status_btn(int *status)
{
	(*status)++;
	if (*status >= 2)
		*status = 0;
	ft_printf(G"switch button status : %d\n"E, *status);
	return (*status);
}

int increase_iter(int *status)
{
	if (*status <= MAX_ITER)
		*status += 5;
	else
		*status = 50;
	return(*status);
	ft_printf(B"iter button status : %d \n"Y, *status);
}
