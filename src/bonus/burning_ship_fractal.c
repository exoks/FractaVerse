/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:35 by oezzaou           #+#    #+#             */
/*   Updated: 2025/02/25 07:58:35 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol_bonus.h"

//====<[ display_burning_ship_fractal: ]>=======================================
void	display_burning_ship_fractal(t_img *img)
{
	t_pixel_grid	grid;
	t_equation		z;
	int				color;

	img->fractal = BURNING_SHIP;
	grid.x = -1;
	while (++(grid.x) < img->w)
	{
		img->p->xc = -img->p->b + (grid.x * slope(img)) + img->p->dx;
		grid.y = -1;
		while (++(grid.y) < img->h)
		{
			img->p->yc = -img->p->b + (grid.y * slope(img)) + img->p->dy;
			z.r = 0;
			z.i = 0;
			z.n = -1;
			while (++z.n < img->nmax && modul_z(&z.r, &z.i, img) < 4)
				;
			color = hsv_to_rgb((z.n * 6 + img->rgb->s) % 360, 100, 100, img);
			mlx_pixel_put_in_img(img, grid.x, grid.y, color);
			if (z.n == img->nmax)
				mlx_pixel_put_in_img(img, grid.x, grid.y, 0);
		}
	}
	mlx_put_image_to_window(img->var->mlx, img->var->win, img->img, 0, 0);
}
