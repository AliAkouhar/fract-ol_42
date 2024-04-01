/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:49:53 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/31 15:44:49 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_param_valid(char *str)
{
	t_flags	flags;

	initial_vars(&flags);
	while (str[flags.i])
	{
		if ((str[flags.i] == '+' || str[flags.i] == '-')
			&& (!ft_isdigit(str[flags.i + 1])))
			return (1337);
		else if (str[flags.i] == '-' || str[flags.i] == '+')
			flags.mince++;
		else if (str[flags.i] == '.')
		{
			if (!ft_isdigit(str[flags.i - 1]))
				return (1337);
			flags.point++;
		}
		else if ((!ft_isdigit(str[flags.i])))
			flags.flag++;
		flags.i++;
	}
	if (flags.mince <= 1 && flags.plus <= 1 && flags.point <= 1
		&& flags.flag == 0)
		return (0);
	else
		return (1337);
}

void	check_arguments(int ac, char **av, t_fractal *fractal)
{
	if ((ft_strcmp(ft_tolower(av[1]), "mandelbrot") == 0 || ft_strcmp(av[1],
				"1") == 0) && ac == 2)
		fractal->name = "Mandelbrot set";
	else if (((ft_strcmp(ft_tolower(av[1]), "julia") == 0) || (ft_strcmp(av[1],
					"2") == 0)))
	{
		if (ac != 4)
			usage(2);
		if (is_param_valid(av[2]) > 1 || is_param_valid(av[3]) > 1)
			usage(3);
		fractal->name = "Julia set";
		fractal->c_r = ft_atof(av[2]);
		fractal->c_i = ft_atof(av[3]);
		if (fractal->c_r > 2 || fractal->c_r < -2 || fractal->c_i > 2
			|| fractal->c_i < -2)
			usage(1);
	}
	else
		usage(0);
}

void	draw_set(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	if (ft_strcmp(fractal->name, "Mandelbrot set") == 0)
		draw_mandelbrot(fractal, BLACK, fractal->color);
	else if (ft_strcmp(fractal->name, "Julia set") == 0)
		draw_julia(fractal, BLACK, fractal->color);
}

void	how_to_use(void)
{
	ft_putendl_fd("\n\t\x1b[33m^^^WELCOME TO FRACTALS^^^\x1b[0m\n", 1);
	ft_putendl_fd("\t\t       \x1b[33mHOW TO USE : \x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33mi/- Zoom : Scroll down or up\x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33mii/- Change iterations : + or -\x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33miii/- Move : arrow keys\x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33miv/- Close the window : ESC or Red cross\x1b[0m",
		1);
	ft_putendl_fd("\t\x1b[33mv/- Change color : use numbers (1 -> 5)\x1b[0m",
		1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
		usage(0);
	check_arguments(ac, av, &fractal);
	init_mlx(&fractal);
	how_to_use();
	draw_set(&fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook(fractal.win, 17,0 , ft_close, &fractal);
	mlx_loop(fractal.mlx);
}
