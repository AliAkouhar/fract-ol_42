/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:18:45 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/30 14:45:54 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_burningship(t_fractal *fractal, int in, int out)
{
	double	tmp;

	fractal->z_r = 0.0;
	fractal->z_i = 0.0;
	fractal->c_r = (((4 * fractal->x / WIDTH) - 2) * fractal->zoom_facteur)
		+ fractal->shift_x;
	fractal->c_i = (((4 * fractal->y / HEIGHT) - 2) * fractal->zoom_facteur)
		+ fractal->shift_y;
	fractal->iter = 0;
	while (fractal->iter < fractal->max_iter)
	{
		tmp = fractal->z_r;
		fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i
				* fractal->z_i) + fractal->c_r;
		fractal->z_i = fabs(2 * tmp * fractal->z_i) + fractal->c_i;
		if ((fractal->z_r * fractal->z_r) + (fractal->z_i * fractal->z_i) > 4.0)
			break ;
		fractal->iter++;
	}
	if (fractal->iter == fractal->max_iter)
		my_mlx_pixel_put(fractal, in);
	else
		my_mlx_pixel_put(fractal, out);
}

void	draw_burningship(t_fractal *fractal, int in, int out)
{
	fractal->x = 0.0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			calculate_burningship(fractal, in, out);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
