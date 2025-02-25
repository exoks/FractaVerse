/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:22:41 by oezzaou           #+#    #+#             */
/*   Updated: 2025/02/25 07:54:00 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

//====<[ slop: ]>===============================================================
double	slope(t_img *img)
{
	return (img->p->a / img->h);
}

//====<[ modul_z: ]>============================================================
double	modul_z(double *zr, double *zi, t_img *img)
{
	double	tmp;

	tmp = *zr;
	if (img->fractal == JULIASET)
	{
		*zr = ((*zr) * (*zr)) - ((*zi) * (*zi)) + img->julia->cr;
		*zi = 2 * tmp * (*zi) + img->julia->ci;
	}
	else if (img->fractal == MANDELBROT)
	{
		*zr = ((*zr) * (*zr)) - ((*zi) * (*zi)) + img->p->xc;
		*zi = 2 * tmp * (*zi) + img->p->yc;
	}
	else
	{
		*zr = (ABS(*zr) * ABS(*zr)) - (ABS(*zi) * ABS(*zi)) + img->p->xc;
		*zi = 2 * ABS(tmp) * ABS(*zi) + img->p->yc;
	}
	return (((*zr) * (*zr)) + ((*zi) * (*zi)));
}

//====<[ str2double: ]>=========================================================
double	str2double(char *s)
{
	double	p1;
	double	p2;
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	p1 = (double) ft_atoi(s);
	p1 = p1 * ((*s != '-') - (*s == '-'));
	tmp = ft_strchr(s, '.');
	if (tmp && ++tmp)
		p2 = (double) ft_atoi(tmp);
	i = -1;
	while (tmp && ++i < ft_strlen(tmp))
		p2 /= 10.0;
	return ((p1 + p2) * ((*s != '-') - (*s == '-')));
}
