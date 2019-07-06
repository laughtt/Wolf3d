/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:53:48 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 15:17:45 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int			a;
	int			i;
	int			c;

	a = -1;
	i = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (*(s1 + ++a))
	{
		if (*(s1 + a) == *(s2))
		{
			c = a;
			while (*(s1 + c++) == *(s2 + i++))
				if ((int)ft_strlen(s2) == i)
					return ((char *)s1 + a);
			i = 0;
		}
	}
	return (NULL);
}
