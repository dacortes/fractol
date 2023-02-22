/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_btn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:02:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/22 18:10:57 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fractol.h"

int	status_btn(int *status)
{
	(*status)++;
	if (*status >= 2)
		*status = 0;
	ft_printf(G"button %d pressed\n"E, *status);
	return (*status);
}
