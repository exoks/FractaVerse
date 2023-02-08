/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:27 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/06 15:14:12 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_mandelbrot_fractal(void)
{
	double	XYc[2];
	int		xy[2];
	double	Z[3];
	int		i;
	char	**info;

	info = ft_split(INFO, '|');
	xy[0] = -1;
	while (++xy[0] <= 40)
	{
		XYc[0] = 2 - (((double) xy[0]) / 10);
		xy[1] = -1;
		while (++xy[1] <= 40)
		{
			Z[0] = 0;
			Z[1] = 0;
			XYc[1] = -2 + (((double) xy[1]) / 10);
			i = -1;
			while (++i < 100 && (Z[0] * Z[0]) + (Z[1] * Z[1]) < 4)
			{
				Z[2] = Z[0];
				Z[0] = (Z[0] * Z[0]) - (Z[1] * Z[1]) + XYc[1];
				Z[1] = 2 * Z[2] * Z[1] + XYc[0];
			}
			if (xy[0] > 8 && xy[0] < 31 && xy[1] != 29)
				ft_printf("\033[1;0m%c\033[1;36m", (i == 100) * '*' + (i != 100) * ' ');
			if (xy[0] > 8 && xy[0] < 31 && xy[1] == 29)
				ft_printf("%c", '|');
		}
		if (xy[0] > 14 && xy[0] < 31)
			ft_printf("%c |%30c", '\n', '|');
		if (xy[0] > 8 && xy[0] <= 15 && *info)
			ft_printf("\n |%-29s|", *info++);
	}
	ft_printf("%29c|\n", ' ');
}

void	display_options(void)
{
	ft_printf("\n %s\n\n %s", MENU, TITLE);
	ft_mandelbrot_fractal();
	ft_printf(" %s\n\n\n%8c%s\n%8c%s\n\n", DEV, ' ', MANDEL, ' ', JULIA);
}
