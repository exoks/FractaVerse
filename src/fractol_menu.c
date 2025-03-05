/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:27 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/25 07:52:38 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

//====<[ display_options: ]>====================================================
void	display_options(void)
{
	ft_printf("\n\n%s\n", TITLE);
	ft_printf("%53d\n%54.4d\n%55.6d\n%55.5d\n", 0, 0, 0, 0);
	ft_printf("%46d%10.9d\n%43.3d%17.16d\n", 0, 0, 0, 0);
	ft_printf("%62.24d%4.3d\n%64.28d\n%66.31d\n", 0, 0, 0, 0);
	ft_printf("%67.33d\n%66.32d\n%21d%6.5d%40.34d\n", 0, 0, 0, 0, 0);
	ft_printf("%29.11d%37.34d\n%30.13d%35.33d\n", 0, 0, 0, 0);
	ft_printf("%15.2d%15.14d%35.33d\n", 0, 0, 0);
	ft_printf("%.63d\n", 0);
	ft_printf("%15.2d%15.14d%35.33d\n", 0, 0, 0);
	ft_printf("%30.13d%35.33d\n%29.11d%37.34d\n", 0, 0, 0, 0);
	ft_printf("%21d%6.5d%40.34d\n%66.32d\n%67.33d\n", 0, 0, 0, 0, 0);
	ft_printf("%66.31d\n%64.28d\n%62.24d%4.3d\n", 0, 0, 0, 0);
	ft_printf("%43.3d%17.16d\n%46d%10.9d\n", 0, 0, 0, 0);
	ft_printf("%55.5d\n%55.6d\n%54.4d\n%53d\n", 0, 0, 0, 0);
	ft_printf("\n%65s", DEV);
	ft_printf("\n\n\n%60s\n\n", SYNTAX);
	ft_printf("%62s\n", MAN);
	ft_printf("%57s\n", JUL);
	ft_printf("%37s\n%37s\n\n\n", ARG1, ARG2);
}

//====<[ display_usage_menu: ]>=================================================
void	display_usage_menu(t_img *img)
{
	char	*tmp;
	char	*iter;

	tmp = ft_itoa(img->nmax);
	iter = ft_strjoin(ITERATIONS, tmp);
	mlx_string_put(img->var->mlx, img->var->win, 10, 15, WHITE, USAGE);
	mlx_string_put(img->var->mlx, img->var->win, 20, 40, WHITE, U_ESC);
	mlx_string_put(img->var->mlx, img->var->win, 20, 60, WHITE, U_R);
	mlx_string_put(img->var->mlx, img->var->win, 20, 80, WHITE, U_ARROWS);
	mlx_string_put(img->var->mlx, img->var->win, 20, 100, WHITE, U_M_WHEEL);
	mlx_string_put(img->var->mlx, img->var->win, 10, 1170, WHITE, iter);
	free(tmp);
	free(iter);
}
