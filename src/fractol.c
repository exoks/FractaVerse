/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:01:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/13 19:39:05 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	close_window(int keycode, t_var *var)
{
	if (keycode == 53)
		exit(mlx_destroy_window(var->mlx, var->win) * 0);
	return (0);
}

// MAKE ANY POINT YOU CHOSE AS THE REFERENCE POINT
int	zoom(int keycode, int x, int y, t_img *img)
{
	int	i;

	i = -1;
	while (++i < 1200 * 1200)
		*((int *) img->addr + i) = 0;
//	mlx_clear_window(img->var->mlx, img->var->win);
	if (keycode == 4)
	{
//		printf("Xc => %f\n", -2.0 + ((double) x / 300.0));
//		printf("Yc => %f\n", 2.0 - ((double) y / 300.0));
//		if (img->plan->x == 2)
//			img->plan->x = -2.0 + ((double) x / 300.0);
//		if (img->plan->y == 2)
//			img->plan->y = 2.0 - ((double) y / 300.0);
		img->plan->x /= 1.2;
		img->plan->y /= 1.2;
		display_mandelbrot_fractal(img, -2.0 + ((double) x / 300.0), 2.0 - ((double) y / 300.0));
	}
	if (keycode == 5)
	{
		img->plan->x *= 1.2;
		img->plan->y *= 1.2;
	}
	display_mandelbrot_fractal(img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	var;
	t_img	img;
	t_c_plan	plan;
//	printf("=> %f\n", atoi_double(av[2]));
//	printf("=> %f\n", atoi_double(av[3]));

	if (ac == 1 || ac > 4)
		return (display_options(), EXIT_SUCCESS);
	mlx_create_window(&var, "FRACTAL");
	mlx_create_image(&var, &img, &plan);
	if (ac == 2 && atoi_double(av[1]) == MANDELBROT)
		display_mandelbrot_fractal(&img, 0, 0);
	if (ac == 4 && atoi_double(av[1]) == JULIASET)
		display_julia_fractal(&img, atoi_double(av[2]), atoi_double(av[3]));
	//	draw_line(&img);
//	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_key_hook(var.win, close_window, &var);
	mlx_mouse_hook(img.var->win, zoom, &img);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}

// EACH POINT IS A COMPLEX NUMBER : I CHECK EVERY PIXEL USING Zn = Zn+1 ^ 2 + C : IF NOT DEVERGE UNDER ITERATION OF 0 THEN THIS POINT FROM MANDELBROT SET ?
// HOW CAN I GET THE INFORMATION OF EACH PIXEL
//  RADIUS : CHO3A3 OF MANDEL BROT SET IS < 2 : SO IF THE PIXEL IS NOT DEVERGE AND (LMANDAM DYALHA) NOT >= 2 THEN THIS POINT IS A MANDEL BROT SET
//
// FIRST C REPRESENT EACH POINT OF MY PIXEL GRADE => I HAVE TO CHECK EACH PIXEL AND SEE IF DEVERGE OR NOT DEVERGE => THIS PART DETERMINE IF I HAVE TO DRAW THIS POINT OR NOT
