/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:35 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/22 23:40:32 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	display_fractal(t_img *img, int ac, char **av)
{
	if ((ac == 2 && str2double(av[1]) == MANDELBROT)
		|| (img->fractal == MANDELBROT))
		display_mandelbrot_fractal(img);
	if ((ac == 4 && str2double(av[1]) == JULIASET)
		|| (img->fractal == JULIASET))
	{
		if (ac != 0)
		{
			img->julia->cr = str2double(av[2]);
			img->julia->ci = str2double(av[3]);
			if (!(img->julia->cr >= -2 && img->julia->cr <= 2)
				|| !(img->julia->ci >= -2 && img->julia->ci <= 2))
				return (0);
		}
		display_julia_fractal(img);
	}
	if (img->fractal == JULIASET || img->fractal == MANDELBROT)
		return (display_usage_menu(img), img->fractal);
	return (0);
}

void	display_mandelbrot_fractal(t_img *img)
{
	t_pixel_grid	grid;
	t_equation		z;
	int				color;

	img->fractal = MANDELBROT;
	grid.x = -1;
	while (++(grid.x) < img->w)
	{
		img->p->xc = -img->p->b + (grid.x * slope(img)) + img->p->dx;
		grid.y = -1;
		while (++(grid.y) < img->h)
		{
			img->p->yc = img->p->b - (grid.y * slope(img)) + img->p->dy;
			z.r = 0;
			z.i = 0;
			z.n = -1;
			while (++z.n < img->nmax && modul_z(&z.r, &z.i, img) < 4.0)
				;
			color = hsv_to_rgb((z.n * 4) % 360, 100, 100, img);
			mlx_pixel_put_in_img(img, grid.x, grid.y, color);
			if (z.n == img->nmax)
				mlx_pixel_put_in_img(img, grid.x, grid.y, 0);
		}
	}
	mlx_put_image_to_window(img->var->mlx, img->var->win, img->img, 0, 0);
}

void	display_julia_fractal(t_img *img)
{
	t_pixel_grid	grid;
	t_equation		z;
	int				color;

	img->fractal = JULIASET;
	grid.x = -1;
	while (++(grid.x) < img->w)
	{
		grid.y = -1;
		while (++(grid.y) < img->h)
		{
			z.r = -img->p->b + (grid.x * slope(img)) + img->p->dx;
			z.i = img->p->b - (grid.y * slope(img)) + img->p->dy;
			z.n = -1;
			while (++z.n < img->nmax && modul_z(&z.r, &z.i, img) < 4.0)
				;
			color = hsv_to_rgb((z.n * 4) % 360, 100, 100, img);
			mlx_pixel_put_in_img(img, grid.x, grid.y, color);
			if (z.n == img->nmax)
				mlx_pixel_put_in_img(img, grid.x, grid.y, 0);
		}
	}
	mlx_put_image_to_window(img->var->mlx, img->var->win, img->img, 0, 0);
}
