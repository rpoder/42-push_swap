/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:40:57 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/25 09:49:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (0);
		if (!ft_is_int(ft_atol(argv[i])))
			return (0);
		if (!check_sign(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_sign(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] != 43 && arg[0] != 45 && !ft_isdigit(arg[0]))
		return (0);
	if (arg[0] == 43 || arg[0] == 45)
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_int(long int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}