/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:59:22 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/09 15:44:47 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define INFO "The Mandelbrot set is :|the set of complex numbers c|for which the function|fc(z) = z^2 + c does not di|verge to infinity when|iterated from z = 0."
# define MENU "====> THIS MENU SHOWS YOU ALL THE AVAILIBLE FRACTALS : "
# define TITLE "===== (MANDELBROT SET ?) ========== (MANDELBORT FRACTAL) ===="
# define DEV "==================== (MADE BY OEZZAOU) ======================"
# define MANDEL "1|_Mandelbrot fractol ====> ./fractal 1"
# define JULIA "2|_Julia fractol      ====> ./fractal 2 [ARG1] [ARG2] (-2 <= ARG <= 2)"
# include "mlx.h"
# include "ft_printf.h"
# include <stdio.h>

typedef struct s_var
{
	void	*mlx;
	void	*win;
}				t_var;

typedef struct s_img
{
	void	*addr;
	void	*img;
	int		line_len;
	int		bpp;
	int		endian;
}				t_img;

void	mlx_pixel_put_in_img(t_img *img, int x, int y, int color);
void	display_options(void);
void	display_mandelbrot_fractal(t_var *var, t_img *img);
void    display_julia_fractal(void *mlx, void *win, double xc, double yc);
#endif
