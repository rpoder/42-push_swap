/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:40:57 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/18 13:36:11 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	int	i;

	i = 0;
	if (!argv[0])
		return (0);
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (0);
		if (ft_strlen(str_trim_zero_and_sign(argv[i])) > 11)
			return (0);
		if (ft_is_only_sign(argv[i]))
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

int	ft_is_only_sign(char *str)
{
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		return (1);
	return (0);
}

int	ft_isonlyspaces(char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (1);
}
