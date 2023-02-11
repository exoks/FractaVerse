/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:48:56 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/11 12:32:29 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	display_julia_fractal(t_img *img, double xc, double yc)
{
	double	xy[2];
	double	z[3];
	int		i;
//	double step;
	printf("%f %f\n", xc, yc);
	xc = -xc;
	xy[0] = -1;
	while (++xy[0] < 1200)
	{
		xy[1] = -1;
		while (++xy[1] < 1200)
		{
			z[0] = -2 + (xy[0] / 300);
			z[1] = 2 - (xy[1] / 300);
			i = -1;
			while (++i < 256 && (z[0] * z[0]) + (z[1] * z[1]) < 4.0)
			{
				z[2] = z[0];
				z[0] = (z[0] * z[0]) - (z[1] * z[1]) + xc;
				z[1] = (2 * z[2] * z[1]) + yc;
			}
			mlx_pixel_put_in_img(img, xy[0], xy[1], create_trgb(0, 256 - i, 256, i));
		}
	}
}
