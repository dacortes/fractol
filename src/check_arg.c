/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:20:43 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/17 10:32:29 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"


static char	*conv_low(char *tmp, char *agv)
{
	int	i;

	tmp = ft_calloc(ft_strlen(agv) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	ft_strlcpy(tmp, agv, ft_strlen(agv) + 1);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	return (tmp);
}

static void	error_agv(void)
{
	ft_printf(B"Error-->Usage: ./fractol [fractal]\n"E);
	ft_printf(B"Fractals :\n1.Mandelbrot\n2.Julia\n"E);
}

static int	check_arg(char *tmp)
{
	if (ft_strncmp(tmp, "mandelbrot", 10) != 0
		&& ft_strncmp(tmp, "julia", 5) != 0)
	{
		ft_printf(R"Error-->Wrong fractal name\n"E);
		error_agv();
		return (0);
	}
	else
	{
		if (ft_strncmp(tmp, "mandelbrot", 10) == 0)
			return (1);
		else if (ft_strncmp(tmp, "julia", 5) == 0)
			return (2);
	}
	return (0);
}

int	check_arc(int argc, char *argv)
{
	char	*tmp;
	int		f;

	tmp = ft_calloc(1, 1);
	f = 0;
	if (!tmp)
		return (0);
	if (argc != 2)
	{
		ft_printf(R"Error-->Wrong number of arguments\n"E);
		error_agv();
		return (0);
	}
	else
	{
		tmp = conv_low(tmp, argv);
		f = check_arg(tmp);
		if (f == 0)
			return (0);
	}
	if (tmp)
		free(tmp);
	return (f);
}
