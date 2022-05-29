/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:19:38 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/29 18:30:33 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (s_len <= start)
		len = 0;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
