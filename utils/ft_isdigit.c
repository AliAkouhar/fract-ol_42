/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:04:16 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/30 14:47:46 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	initial_vars(t_flags *flags)
{
	flags->i = 0;
	flags->plus = 0;
	flags->point = 0;
	flags->mince = 0;
	flags->flag = 0;
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
