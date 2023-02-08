/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:22:41 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/08 18:29:35 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*double	atoi_double(char *str)
{
	int		power;
	double	nb;
	int		sign;

	nb = 0;
	power = 0;
	sign = 1;
	if (*str && ft_strchr("+-", *str))
		if (*str == '-')
			sign = -1;
	while (*str)
		if (
			nb = (nb * 10) + (*(str++) - '0');
	return (nb * sign);
}*/

void	mlx_pixel_put_in_img(t_img img, int x, int y, int color)
{
	int	*pixel;

	pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*pixel = color;
}
