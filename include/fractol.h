/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:59:22 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/22 23:00:17 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "ft_printf.h"
# include <math.h>
# define ABS(A) A * ((A >= 0) - (A < 0))
# define RGB(R, G, B) (int) R << 16 | (int) G << 8 | (int) B
# define WHITE 0xFFFFFF

//#############################
//#           Usage           #
//#############################
# define ITERATIONS "Iterations : "
# define USAGE "Usage :"
# define U_ARROWS "Arows       : moving fractal"
# define U_M_WHEEL "Mouse wheel : zoom in & out"
# define U_R "R           : reset"
# define U_ESC "ESC         : exit"

//############################
//#         FRACTALS         #
//############################
# define MANDELBROT 1
# define JULIASET 2
# define BURNING_SHIP 3

//############################
//#        MOUSE HOOK        #
//############################
# define SCROLL_UP 5
# define SCROLL_DOWN 4

//############################
//#        FRACTLAS          #
//############################
# define TITLE "=> Mandelbrot fractal example :\n"
# define DEV "<<| Made By OEZZAOU |>>"
# define SYNTAX "Usage : SYNTAX => ./fractol [ARG1] [ARG2] [ARG3]"
# define MAN "./fractol 1               => Mandelbrot fractal"
# define JUL "./fractol 2 [ARG1] [ARG2] => JULIA fractal"
# define ARG1 "-> -2 <= ARG1 <= 2"
# define ARG2 "-> -2 <= ARG2 <= 2"

//############################
//#         ARROWS           #
//############################
# define LEFT 124
# define RIGHT 123
# define UP 126
# define DOWN 125

//###########################
//#           KEYS          #
//###########################
# define RESET	15
# define ESC 53
# define PLUS 69
# define MINUS 78
# define J 38
# define K 40
# define F 3
# define D 2

//#############################
//#           WIN             #
//#############################
typedef struct s_var
{
	void		*mlx;
	void		*win;
}				t_var;

//############################
//#       COMPLEX PLAN       #
//############################
typedef struct s_complex_plan
{
	double		xc;
	double		yc;
	double		a;
	double		b;
	double		old_xc;
	double		old_yc;
	double		dx;
	double		dy;
}				t_complex_plan;

//###########################
//#        PIXEL grid       #
//###########################
typedef struct s_pixel_grid
{
	double		x;
	double		y;
}				t_pixel_grid;

//###########################
//#       Z = Z^2 + C       #
//###########################
typedef struct s_equation
{
	double		r;
	double		i;
	double		tmp;
	int			n;
}				t_equation;

//############################
//#          JULIA           #
//############################
typedef struct s_julia
{
	double		cr;
	double		ci;
}				t_julia;

//#############################
//#            RGB            #
//#############################
typedef struct s_rgb
{
	float		r;
	float		g;
	float		b;
	int			s;
}				t_rgb;

//############################
//#         IMAGE            #
//############################
typedef struct s_img
{
	void			*addr;
	void			*img;
	int				l_len;
	int				bpp;
	int				edn;
	int				h;
	int				w;
	int				fractal;
	int				nmax;
	t_rgb			*rgb;
	t_var			*var;
	t_complex_plan	*p;
	t_julia			*julia;
}					t_img;

	/********** EVENTS ************/
void	events_handler(t_img *img);
int		close_window(t_img *img);
int		zoom(int code, int x, int y, t_img *img);
int		on_press_button(int code, t_img *img);

	/********** FRACTALS **********/
void	display_julia_fractal(t_img *img);
void	display_mandelbrot_fractal(t_img *img);
void	display_burning_ship_fractal(t_img *img);
int		display_fractal(t_img *img, int ac, char **av);
void	display_options(void);

	/************ Mlx *************/	
void	mlx_create_image(t_var *var, t_img *img, t_julia *j, t_complex_plan *p);
void	mlx_create_window(t_var *var);
void	mlx_pixel_put_in_img(t_img *img, int x, int y, int color);
void	display_usage_menu(t_img *img);
int		hsv_to_rgb(int hue, float saturation, float value, t_img *img);

	/********** Utils *************/
double	modul_z(double *zr, double *zi, t_img *img);
double	slope(t_img *img);
int		create_color(int iter);
double	str2double(char *s);

#endif
