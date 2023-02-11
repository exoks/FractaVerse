/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:01:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/11 22:45:55 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	close_window(int keycode, t_var *var)
{
	if (keycode == 53)
		exit(mlx_destroy_window(var->mlx, var->win) * 0);
	return (0);
}

int	zoom(int keycode, int x, int y, t_img *img)
{
	//if (keycode == 4)
		//display_mandelbrot_fractal(img, );
	return (0);
}

int	main(int ac, char **av)
{
	t_var	var;
	t_img	img;

//	printf("=> %f\n", atoi_double(av[2]));
//	printf("=> %f\n", atoi_double(av[3]));
	if (ac == 1 || ac > 4)
		return (display_options(), EXIT_SUCCESS);
	mlx_create_window(&var, "FRACTAL");
	mlx_create_image(&var, &img);
	if (ac == 2 && atoi_double(av[1]) == MANDELBROT)
		display_mandelbrot_fractal(&img, 4, 4);
	if (ac == 4 && atoi_double(av[1]) == JULIASET)
		display_julia_fractal(&img, atoi_double(av[2]), atoi_double(av[3]));
	//	draw_line(&img);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_key_hook(var.win, close_window, &var);
	mlx_mouse_hook(var.win, zoom, &var);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}

// EACH POINT IS A COMPLEX NUMBER : I CHECK EVERY PIXEL USING Zn = Zn+1 ^ 2 + C : IF NOT DEVERGE UNDER ITERATION OF 0 THEN THIS POINT FROM MANDELBROT SET ?
// HOW CAN I GET THE INFORMATION OF EACH PIXEL
//  RADIUS : CHO3A3 OF MANDEL BROT SET IS < 2 : SO IF THE PIXEL IS NOT DEVERGE AND (LMANDAM DYALHA) NOT >= 2 THEN THIS POINT IS A MANDEL BROT SET
//
// FIRST C REPRESENT EACH POINT OF MY PIXEL GRADE => I HAVE TO CHECK EACH PIXEL AND SEE IF DEVERGE OR NOT DEVERGE => THIS PART DETERMINE IF I HAVE TO DRAW THIS POINT OR NOT
