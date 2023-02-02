/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:35 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/01 20:06:14 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	display_mandelbrot_fractal(void)
{
	double	xy[2];
	double	xyc[3];
	int		iter;
	double	zr;
	double	zi;

	xyc[0] = -2;
	while (xy[0] < 2)
	{
		xy[0] = (xyc[0] + 2) * 10; /* ====> (2 - xyc[0]) * (4 / 0.1)*/
		xyc[1] = -2;
		while (xyc[1] < 2)
		{
			xy[1] = (xyc[1] - 2) * 10;
			//zr = 0;
			//zi = 0;
			//iter  = -1;
		//	printf("===> C (%f, %f)\n", xyc[0], xyc[1]);
			printf("===> R (%f, %f)\n", xy[0], xy[1]);
			/*while (++iter < 255 && (zr * zr) + (zi * zi) < 4)
			{
				xyc[2] = zi;
				zr = (zr * zr) - (zi * zi) + xyc[1];
				zi = 2 * zi * xyc[2] + xyc[0];
			}
			if (iter == 255)
				mlx_pixel_put(mlx, win, xy[0], xy[1], 0x000000FF);*/
			xyc[1] += 0.1;
		}
		xyc[0] += 0.1;
	}
}
