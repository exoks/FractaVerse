/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:48:56 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/16 13:11:23 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	display_julia_fractal(t_img *img, t_julia *c)
{
	t_pixel_grid	grid;
	t_z				z;
	
	grid.x = -1;
	while (++(grid.x) < 1200)
	{
		grid.y = -1;
		while (++(grid.y) < 1200)
		{
			z.r = -img->plan->y + (grid.x * img->plan->x/ 1200) + img->plan->dx;
			z.i = img->plan->y - (grid.y * img->plan->x/ 1200) + img->plan->dy;
			z.n = -1;
			while (++z.n < 255 && (z.r * z.r) + (z.i * z.i) < 4.0)
			{
				z.tmp = z.r;
				z.r = (z.r * z.r) - (z.i * z.i) + c->cr;
				z.i = (2 * z.tmp * z.i) + c->ci;
			}
			if (z.n == 255)
				mlx_pixel_put_in_img(img, grid.x, grid.y, create_trgb(0, 0, 255, 0));
		}
	}
	mlx_put_image_to_window(img->var->mlx, img->var->win, img->img, 0, 0);
}
