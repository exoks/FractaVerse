/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:01:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/16 13:28:46 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	close_window(int keycode, t_var *var)
{
	printf("keycode => %d\n", keycode);
	if (keycode == 53)
		exit(mlx_destroy_window(var->mlx, var->win) * 0);
	return (0);
}

// MAKE ANY POINT YOU CHOSE AS THE REFERENCE POINT
int	zoom(int code, int x, int y, t_img *img)
{
	int	i;
	double	new_x, new_y;

	mlx_clear_window(img->var->mlx, img->var->win);
	if (!(x == img->plan->m_x && y == img->plan->m_y))
	{
			img->plan->old_x = -img->plan->y + (((double) x) * img->plan->x / 1200.0) + img->plan->dx;
			img->plan->old_y = img->plan->y - (((double) y) * img->plan->x / 1200.0) + img->plan->dy;
	}
	img->plan->m_y = y;
	img->plan->m_x = x;
	if (code == SCROLL_DOWN || code == SCROLL_UP)
	{
		img->plan->x /= 1.3 * (code == 4) +  (1 / 1.4) * (code == 5);
		img->plan->y /= 1.3 * (code == 4) + (1 / 1.4) * (code == 5);
		new_x = -img->plan->y + (((double) x) * img->plan->x / 1200.0);
		new_y = img->plan->y - (((double) y) * img->plan->x / 1200.0);
		img->plan->dx = img->plan->old_x - new_x;
		img->plan->dy = img->plan->old_y - new_y;
//		if (img->c->cr < 4 && img->c->ci < 4) 
//			display_julia_fractal(img, img->c);
//		else
			display_mandelbrot_fractal(img);
	}
	return (0);
}

int	display_fractal(t_img *img, int ac, char **av)
{
	t_julia	c;
	if (ac == 2 && str2double(av[1]) == MANDELBROT)
		return (display_mandelbrot_fractal(img), MANDELBROT);
	if (ac == 4 && str2double(av[1]) == JULIASET)
	{
		c.cr = str2double(av[2]);
		c.ci = str2double(av[3]);
		return (display_julia_fractal(img, img->c), JULIASET);
	}
	return (0);
}
int	main(int ac, char **av)
{
	t_var			var;
	t_img			img;
	t_julia			julia;
	t_c_plan		plan;
	
	mlx_create_window(&var, "FRACTAL");
	mlx_create_image(&var, &img, 0, &plan);
	if (!display_fractal(&img, ac, av))
		return (display_options(), EXIT_SUCCESS);
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
