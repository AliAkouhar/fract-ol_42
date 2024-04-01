/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:39:08 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/31 14:16:19 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct vars
{
	int		i;
	int		sign;
	double	n;
	double	num;
}			t_vars;

typedef struct t_flags
{
	int		i;
	int		plus;
	int		mince;
	int		point;
	int		flag;
}			t_flags;

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putendl_fd(char *s, int fd);
char		*ft_tolower(char *str);
double		ft_atof(char *str);
void		initial_vars(t_flags *flags);
int			ft_isdigit(int c);

#endif