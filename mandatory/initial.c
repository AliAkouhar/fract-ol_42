/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:50:13 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/31 00:12:32 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(1);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bit_per_pixel,
			&fractal->size_line, &fractal->endian);
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->iter = 0;
	fractal->max_iter = 100;
	fractal->color = 0x001100;
	fractal->zoom_facteur = 1;
}
