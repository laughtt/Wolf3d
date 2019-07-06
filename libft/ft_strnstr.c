/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:05:52 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 15:26:06 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int		a;
	int		i;
	int		c;

	a = -1;
	i = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (*(s1 + ++a) && a < (int)len)
	{
		if (*(s1 + a) == *(s2))
		{
			c = a;
			while (*(s1 + c++) == *(s2 + i++) && c - 1 < (int)len)
				if ((int)ft_strlen(s2) == i)
					return ((char *)s1 + a);
			i = 0;
		}
	}
	return (NULL);
}
