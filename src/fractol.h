/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:34:26 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/08 14:05:50 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
// ================================= LIBRARIES ============================== //

#include"../miniLibX/mlx.h"
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
//Windows && Image
typedef struct s_win {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	float	mx;
	float	my;
	float	m_zoom;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_win;
//Fractals variables
typedef struct s_var
{
	float	zx;
	float	zy;
	float	cx;
	float	cy;
	float	n;
	float	r;
	float	tmp_x;
	int		i;
}	t_var;
//Colors
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		t;
}	t_color;
// ================================= FUNCTIONS ============================== //
//Check_error
void	error_agv(void);
int		check_arg(char *tmp);
int		check_arc(int argc, char *argv);
//utils
char	*conv_low(char *tmp, char *agv);
//Close window
int		close_win(t_win *win);
int		close_esc(int keycode, t_win *win);
//put pixel
void	ft_px_put(t_win *img, int i, int col, int row);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
//Fractals
void	formula(t_var *f, int opt);
void	mandelbrot_sets(t_win *img, int x, int y);
//pruebas
int		mouse(int x, int y, t_win *win);
int 	zoom(int button, int x, int y, t_win *img);
void	julia_mouse(t_win *img, int x, int y);
//colors
int		genete_c(int i);
int		create_trgb(int t, int r, int g, int b);
#endif
