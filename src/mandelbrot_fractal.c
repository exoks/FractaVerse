/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:41:35 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/11 22:46:15 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	display_mandelbrot_fractal(t_img *img, double rx, double ry)
{
	double	xy[2];
	double	xyc[3];
	int		iter;
	double	zr;
	double	zi;

	xy[0] = -1;
	while (++xy[0] < 1200)
	{
		xyc[0] = -2 + ((xy[0] * rx) / 1200);
		xy[1] = -1;
		while (++xy[1] < 1200)
		{
			xyc[1] = 2 - ((xy[1] * ry) / 1200);
			zr = 0;
			zi = 0;
			iter  = -1;
			while (++iter < 256 && (zr * zr) + (zi * zi) < 4)
			{
				xyc[2] = zr;
				zr = (zr * zr) - (zi * zi) + xyc[0];
				zi = 2 * zi * xyc[2] + xyc[1];
			}
			if (iter != 256)
				mlx_pixel_put_in_img(img, xy[0], xy[1], create_trgb(iter, 256 - iter, iter, 256 - iter));
		}
	}
}
/****** FROM COMPLEX PLAN TO PIXEL GRIDE ******/
/* 	x = (xc - 2) / step => ex step = 0.1      */
/*  y = (2 - yc) / step                       */
/**********************************************/

/****** FROM PIXEL GRIDE TO COMPLEX PALN ******/
/*	      xc = (2 - x / (h / 4))              */
/*        yc = (2 - y / (h / 4))              */
/**********************************************/
