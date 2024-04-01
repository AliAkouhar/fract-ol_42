/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:30:27 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/31 14:19:05 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	initialize_variables(t_vars *vars)
{
	vars->i = 0;
	vars->num = 0.0;
	vars->sign = 1;
	vars->n = 1;
}

double	ft_atof(char *str)
{
	t_vars	vars;

	initialize_variables(&vars);
	while (str[vars.i] == ' ' || (str[vars.i] >= 9 && str[vars.i] <= 13))
		vars.i++;
	if (str[vars.i] == '-' || str[vars.i] == '+')
	{
		if (str[vars.i] == '-')
			vars.sign = -1;
		vars.i++;
	}
	while (str[vars.i] && ft_isdigit(str[vars.i]))
		vars.num = vars.num * 10 + (str[vars.i++] - '0');
	if (str[vars.i] == '.')
	{
		vars.i++;
		while (str[vars.i] && ft_isdigit(str[vars.i]))
		{
			vars.num = vars.num * 10 + (str[vars.i++] - '0');
			vars.n *= 0.1;
		}
	}
	vars.num *= vars.n;
	return (vars.num * vars.sign);
}
