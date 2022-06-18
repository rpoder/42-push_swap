/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_addons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:13:39 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/06/18 13:23:19 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstbeflast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

long int	ft_atol(char *s)
{
	long int		res;
	int				neg;
	int				i;

	res = 0;
	neg = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + ((long int) s[i] - 48);
		i++;
	}
	return ((long int)res * neg);
}

void	ft_free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*str_trim_zero_and_sign(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i] || str[i] == '0')
		i++;
	return (str + i);
}
