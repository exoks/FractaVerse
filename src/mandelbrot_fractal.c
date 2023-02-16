/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:35 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/16 13:19:51 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	display_mandelbrot_fractal(t_img *img)
{
	t_pixel_grid	grid;
	t_complex_plan	plan;
	t_z				z;

	grid.x = -1;
	while (++(grid.x) < 1200)
	{
		plan.xc =  -img->plan->y + ((grid.x * img->plan->x) / 1200) + img->plan->dx;
		grid.y = -1;
		while (++(grid.y) < 1200)
		{
			plan.yc = img->plan->y - ((grid.y * img->plan->x) / 1200) + img->plan->dy;
			z.r = 0;
			z.i = 0;
			z.n  = -1;
			while (++z.n < 255 && (z.r * z.r) + (z.i * z.i) < 4)
			{
				z.tmp = z.r;
				z.r = (z.r * z.r) - (z.i * z.i) + plan.xc;
				z.i = 2 * z.i * z.tmp + plan.yc;
			}
			if (z.n != 255)
				mlx_pixel_put_in_img(img, grid.x, grid.y, create_trgb(0, 256 - z.n, z.n, 256 - z.n));
			else
				mlx_pixel_put_in_img(img, grid.x, grid.y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(img->var->mlx, img->var->win, img->img, 0, 0);
}
/****** FROM COMPLEX PLAN TO PIXEL GRIDE ******/
/* 	x = (xc - 2) / step => ex step = 0.1      */
/*  y = (2 - yc) / step                       */
/**********************************************/

/****** FROM PIXEL GRIDE TO COMPLEX PALN ******/
/*	      xc = (2 - x / (h / 4))              */
/*        yc = (2 - y / (h / 4))              */
/**********************************************/
