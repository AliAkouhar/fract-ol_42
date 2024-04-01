/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:07:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/30 01:11:11 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	change_color(t_fractal *fractal, int color)
{
	if (color == 83)
		fractal->color = ONE;
	if (color == 84)
		fractal->color = TWO;
	if (color == 85)
		fractal->color = THREE;
	if (color == 86)
		fractal->color = FOUR;
	if (color == 87)
		fractal->color = FIVE;
	draw_set(fractal);
}

void	arrow_keys(t_fractal *fractal, int key_code)
{
	if (key_code == 123)
		fractal->shift_x -= 0.1;
	if (key_code == 124)
		fractal->shift_x += 0.1;
	if (key_code == 125)
		fractal->shift_y += 0.1;
	if (key_code == 126)
		fractal->shift_y -= 0.1;
	draw_set(fractal);
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		ft_close(fractal);
	if (key_code == 83)
		change_color(fractal, 83);
	if (key_code == 84)
		change_color(fractal, 84);
	if (key_code == 85)
		change_color(fractal, 85);
	if (key_code == 86)
		change_color(fractal, 86);
	if (key_code == 87)
		change_color(fractal, 87);
	if (key_code == 69 || key_code == 78)
	{
		if (key_code == 69)
			fractal->max_iter += 5;
		else
			fractal->max_iter -= 5;
		draw_set(fractal);
	}
	if (key_code == 123 || key_code == 124 || key_code == 125
		|| key_code == 126)
		arrow_keys(fractal, key_code);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom;

	if (mouse_code == SCROLL_DOWN || mouse_code == SCROLL_UP)
	{
		if (mouse_code == SCROLL_DOWN)
			zoom = 1.1;
		else
			zoom = 0.9;
		fractal->zoom_facteur *= zoom;
		mouse_x = (4 * x / WIDTH - 2) * fractal->zoom_facteur;
		mouse_y = (4 * y / HEIGHT - 2) * fractal->zoom_facteur;
		fractal->shift_x = (fractal->shift_x + mouse_x) - (mouse_x * zoom);
		fractal->shift_y = (fractal->shift_y + mouse_y) - (mouse_y * zoom);
		draw_set(fractal);
	}
	return (0);
}
