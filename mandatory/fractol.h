/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:32:39 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/31 14:17:53 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../utils/utils.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 700
# define HEIGHT 700

# define ESC 53
# define BLACK 0x000000
# define ONE 0x001111
# define TWO 0x110011
# define THREE 0x111100
# define FOUR 0x100101
# define FIVE 0xEDFFFF

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	int		iter;
	int		max_iter;
	int		color;
	double	shift_x;
	double	shift_y;
	double	zoom_facteur;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	x;
	double	y;
	char	*name;
}			t_fractal;

void		init_mlx(t_fractal *fractal);
void		check_arguments(int ac, char **av, t_fractal *fractal);
void		draw_set(t_fractal *fractal);
void		calculate_mandelbrot(t_fractal *fractal, int in, int out);
void		calculate_julia(t_fractal *fractal, int in, int out);
void		draw_mandelbrot(t_fractal *fractal, int in, int out);
void		draw_julia(t_fractal *fractal, int in, int out);
void		usage(int i);
int			ft_close(t_fractal *fractal);
int			key_hook(int key_code, t_fractal *fractal);
void		my_mlx_pixel_put(t_fractal *fractal, int color);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
void		change_color(t_fractal *fractal, int color);
void		arrow_keys(t_fractal *fractal, int key_code);
void		how_to_use(void);
int			is_param_valid(char *str);
#endif