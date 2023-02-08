/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:48:56 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/06 14:41:09 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	display_julia_fractal(void *mlx, void *win, double xc, double yc)
{
	double xyc[2];
	double z[3];
	double	i;
	double step;

	step = 0.0033;
	xyc[0] = -2;
	while (xyc[0] <= 2)
	{
		xyc[1] = -2;
		while (xyc[1] <= 2)
		{
			z[0] = xyc[0];
			z[1] = xyc[1];
	//		printf("(z[0], z[1]) => (%.2f, %.2f)\n", z[0], z[1]);
			i = -1;
			while (++i < 100 && (z[0] * z[0]) + (z[1] * z[1]) < 4)
			{
				z[2] = z[0];
				z[0] = (z[0] * z[0]) - (z[1] * z[1]) + xc;
				z[1] = (2 * z[2] * z[1]) + yc;
			}
			if (i == 100)
				mlx_pixel_put(mlx, win, (2 - xyc[0]) / step, (2 - xyc[1]) / step, 0x000000FF);
			xyc[1] += step;
		}
		xyc[0] += step;
	}
}
