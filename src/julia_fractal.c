/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:48:56 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/15 18:55:51 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	display_julia_fractal(t_img *img, t_julia_const *c)
{
	double	xy[2];
	double	z[3];
	int		i;

	printf("Cr => %f\n", c->cr);
	printf("Ci => %f\n", c->ci);	
	xy[0] = -1;
	while (++xy[0] < 1200)
	{
		xy[1] = -1;
		while (++xy[1] < 1200)
		{
			z[0] = -img->plan->y + (xy[0] * img->plan->x/ 1200) + img->plan->dx;
			z[1] = img->plan->y - (xy[1] * img->plan->x/ 1200) + img->plan->dy;
			i = -1;
			while (++i < 255 && (z[0] * z[0]) + (z[1] * z[1]) < 4.0)
			{
				z[2] = z[0];
				z[0] = (z[0] * z[0]) - (z[1] * z[1]) + c->cr;
				z[1] = (2 * z[2] * z[1]) + c->ci;
			}
			if (i == 255)
				mlx_pixel_put_in_img(img, xy[0], xy[1], create_trgb(0, 0, 255, 0));
		}
	}
	mlx_put_image_to_window(img->var->mlx, img->var->win, img->img, 0, 0);
}
