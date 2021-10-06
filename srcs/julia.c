/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:06:51 by bahn              #+#    #+#             */
/*   Updated: 2021/10/06 18:59:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia_init(t_fractol *fractol)
{
	fractol->f_fractol_calc = &julia;
	fractol->center.x = 0;
	fractol->center.y = 0;
	if (WIDTH >= HEIGHT)
		fractol->pixel = WIDTH / 8;
	else
		fractol->pixel = HEIGHT / 8;
	fractol->complex.x = WIDTH / fractol->pixel;
	fractol->complex.y = HEIGHT / fractol->pixel;

	fractol->julia_const.x = -0.1875;
	fractol->julia_const.y = -1.0944;
	// fractol->julia_const.x = 0.290625;
    // fractol->julia_const.y = 0.011111;

	fractol->color.rgb_ptr = NULL;
	fractol->color.start.r = 0;
	fractol->color.start.g = 0;
	fractol->color.start.b = 112;
	fractol->color.end.r = 255;
	fractol->color.end.g = 255;
	fractol->color.end.b = 0;
}

int     julia(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

	c_re = fractol->julia_const.x;
	c_im = fractol->julia_const.y;
	x = fractol->center.x + ((double)w / fractol->pixel) - (fractol->complex.x / 2);
	y = fractol->center.y + ((double)h / fractol->pixel) - (fractol->complex.y / 2);
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}