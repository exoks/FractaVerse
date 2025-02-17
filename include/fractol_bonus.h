/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:59:22 by oezzaou           #+#    #+#             */
/*   Updated: 2023/02/22 22:24:50 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "fractol.h"
# define ABS(A) A * ((A >= 0) - (A < 0))
# define RGB(R, G, B) (int) R << 16 | (int) G << 8 | (int) B
# define BUR "./fractol 3               => Burning ship fractal"

int		shift_color(t_img *img);
void	display_burning_ship_fractal(t_img *img);

#endif
