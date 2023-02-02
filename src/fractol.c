/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:01:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/01 19:54:18 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int ac, char **av)
{
//	void	*mlx;
//	void	*win;

//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 1300, 700, "FRACTOL");
	if (ac == 1)
		return (display_options(), EXIT_SUCCESS);
	if (ac == 2 && ft_atoi(av[1]) == 1)
		display_mandelbrot_fractal();
//	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
/*int	main(void)
{
	void	*mlx;
	void	*win;
	double 	tmp;
	double  Xc;
	double 	Yc;
	double x, y;
	int	color = 0x0000FF00;
	// INIT A WINDOW
	 mlx = mlx_init();
	// INIT A WINDOW
	win = mlx_new_window(mlx, 1400, 1400, "Oussama");

	y = 0;
	while (y <= 1400)
	{
		Yc = 2 - (y / 350);
		x = 0;
		while (x <= 1400)
		{
			Xc = -2 + (x / 350);
			double	Zr = 0;
			double	Zi = 0;
			int	i = -1;
			while (++i < 1000)
			{
				tmp = Zr;
				Zr = (Zr * Zr) - (Zi * Zi) + Xc;
				Zi = (2 * tmp * Zi) + Yc;
				if ((Zr * Zr) + (Zi * Zi) > 4)
					break;
			}
			if (i == 1000)
				mlx_pixel_put(mlx, win, x, y, color);
			x += 1;
		}
		y += 1;
	}
	mlx_loop(mlx);
	//	mlx_put_image_to_window(mlx, win, image, 100, 100);
}*/

// EACH POINT IS A COMPLEX NUMBER : I CHECK EVERY PIXEL USING Zn = Zn+1 ^ 2 + C : IF NOT DEVERGE UNDER ITERATION OF 0 THEN THIS POINT FROM MANDELBROT SET ?
// HOW CAN I GET THE INFORMATION OF EACH PIXEL
//  RADIUS : CHO3A3 OF MANDEL BROT SET IS < 2 : SO IF THE PIXEL IS NOT DEVERGE AND (LMANDAM DYALHA) NOT >= 2 THEN THIS POINT IS A MANDEL BROT SET
//
// FIRST C REPRESENT EACH POINT OF MY PIXEL GRADE => I HAVE TO CHECK EACH PIXEL AND SEE IF DEVERGE OR NOT DEVERGE => THIS PART DETERMINE IF I HAVE TO DRAW THIS POINT OR NOT
