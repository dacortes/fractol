/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_btn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:02:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/28 17:48:15 by dacortes         ###   ########.fr       */
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

int	increase_iter(int *status)
{
	if (*status <= MAX_ITER)
		*status += 5;
	else
		*status = 50;
	return (*status);
	ft_printf(B"iter button status : %d \n"Y, *status);
}

int	iter_one_by_one(int *status)
{
	(*status)++;
	if (*status >= 4)
		*status = 1;
	ft_printf(Y"iter one by one : %d \n"E, *status);
	return (*status);
}
