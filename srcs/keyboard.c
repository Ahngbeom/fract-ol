/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/09/16 16:37:26 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
        printf("Key Press : %#08X\n", key);
	if (key == 0x00FF1B)
                exit(0);
        if (key == 0x000072)
        {
                fractol->zoom->mag = 0.5;
                fractol->zoom->center_x = -0.5;
                fractol->zoom->center_y = 0;
                ft_fractol(fractol);
        }
}