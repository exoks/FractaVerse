/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:01:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/22 23:41:34 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int ac, char **av)
{
	t_var			var;
	t_img			img;
	t_complex_plan	p;
	t_julia			julia;
	t_rgb			rgb;

	img.rgb = &rgb;
	mlx_create_window(&var);
	mlx_create_image(&var, &img, &julia, &p);
	if (!display_fractal(&img, ac, av))
		return (display_options(), EXIT_SUCCESS);
	events_handler(&img);
	mlx_loop(var.mlx);
	return (EXIT_SUCCESS);
}
