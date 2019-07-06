/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:13:16 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 11:51:24 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*b;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	b = ft_strnew(len);
	if (!b)
		return (NULL);
	while (i < (int)len)
		*(b + i++) = *(s + start++);
	return (b);
}
