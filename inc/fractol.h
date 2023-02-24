/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:38 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/24 11:40:45 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
// ================================= LIBRARIES ============================== //

# include"../miniLibX/mlx.h"
# include"../libft/libft.h"
# include"../libft/ft_printf.h"
# include"keyscode.h"
# include<math.h>

// ================================= MACROS ================================= //

/* Dimensions */
# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 400

/* Outputs */
# define SUCCES 0
# define FALSE 0
# define TRUE 1
# define ERROR 0
# define E_EXIT 1

/* Fractal sets */
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

// ================================= COLORS ================================= //

# define E "\033[m"        //end
# define R "\033[1;31m"    //red
# define G "\033[1;32m"    //green
# define Y "\033[1;33m"    //yellow
# define B "\033[1;34m"    //blue
// ================================= STRUCTURES ============================= //

/* Menu */
typedef struct s_menu
{
	int	status;
}	t_menu;

/* Mouse */
typedef struct s_mouse
{
	double	posre;
	double	posim;
	double	zoom;
	int		status;
	int		x;
	int		y;
}	t_mouse;

/* window and image */
typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_win;

/* Fractals variables */
typedef struct s_var
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	sx;
	double	rx;
	double	fx;
	double	x;
	double	y;
	int		set;
}	t_var;

/* Fractol */
typedef struct s_fractol
{
	int		iter_max;
	int		set_t;
	t_win	win;
	t_var	var;
	t_menu	menu;
	t_mouse	mouse;
}	t_fractol;

// ================================= FUNCTIONS ============================== //
/* menu/render_mn.c */
void	rendder_mn(t_fractol *f);
void	status_menu_render(t_fractol *f);
/* sets/Burning_ship.c*/
int		burning_ship(t_fractol *f, double cr, double ci);
/* sets/julia.c */
int		julia_move(int x, int y, t_fractol *f);
int		julia_click(int x, int y, t_fractol *f);
int		julia(t_fractol *f, double zr, double zi);
/* sets/mandelbrot.c */
int		mandelbrot(double cr, double ci, t_fractol *f);
/* colors.c */
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	ft_put_pixel(t_fractol *f, int x, int y, int iter);
/* events.c */
int		key_event(int keycode, t_fractol *f);
int		mouse_event(int keycode, int x, int y, t_fractol *f);
/* exit.c */
void	clean_win(int code, t_fractol *f);
int		msg_err(char *str, int error);
int		end_fractol(t_fractol *f);
/* init_var */
void	init_var(t_fractol *f);
void	get_num_complex(t_fractol *f);
void	init(t_fractol *f, int check);
/* render.c */
void	render(t_fractol *f, int x, int y);
/* check_arg.c */
int		check_arc(int argc, char *argv);
/* reset_var.c */
void	reset_var(t_fractol *f);
/* status_btn.c */
int		status_btn(int *status);
int		increase_iter(int *status);
#endif