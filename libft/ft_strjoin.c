/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:25:24 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 11:50:00 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*b;
	int			a;
	int			c;
	int			d;
	int			e;

	if (!s1 || !s2)
		return (NULL);
	d = ft_strlen(s1);
	e = ft_strlen(s2);
	b = ft_strnew(d + e);
	if (!b)
		return (NULL);
	a = -1;
	c = -1;
	while (++a < d)
		*(b + a) = *(s1 + a);
	while (++c < e)
		*(b + a++) = *(s2 + c);
	return (b);
}
