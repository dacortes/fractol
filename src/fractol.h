/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:38 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/13 12:29:08 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
// ================================= LIBRARIES ============================== //

# include"../miniLibX/mlx.h"
# include"../libft/libft.h"
# include"../libft/ft_printf.h"
# include<math.h>

// ================================= MACROS ================================= //

# define WIDTH 1000
# define HEIGHT 1000 
# define ZOOM (float)1.1

// ================================= COLORS ================================= //

# define E "\033[m"        //end
# define R "\033[1;31m"    //red
# define G "\033[1;32m"    //green
# define Y "\033[1;33m"    //yellow
# define B "\033[1;34m"    //blue
// ================================= STRUCTURES ============================= //

//colors trgb
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		t;
}	t_color;

//Mouse
typedef struct s_mouse
{
	float	m_x;
	float	m_y;
	double	m_zoom;
}	t_mouse;

//Fractals variables
typedef struct s_var
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	float	n;
	float	r;
	float	tmp_x;
	int		i;
}	t_var;

//Windows && Image
typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_var	f;
	t_mouse	mouse;
	t_color	colors;
}	t_win;

// ================================= FUNCTIONS ============================== //

//fractals
void	mandelbrot(t_win *win, int x, int y);
void	julia_mouse(t_win *win, int x, int y);
//window && imagen
int		close_win(t_win *win);
int		close_esc(int keycode, t_win *win);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
//mouse
int		move(int x, int y, t_win *win);
int		zoom(int button, int x, int y, t_win *win);
//colors
int		generete_c(t_win *win);
int		create_trgb(int t, int r, int g, int b);
//errors
char	*conv_low(char *tmp, char *agv);
int		check_arg(char *tmp);
int		check_arc(int argc, char *argv);
#endif