/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:35:08 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 15:01:43 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	int			a;
	size_t		b;
	size_t		c;

	a = 0;
	i = ft_strlen(dst);
	b = ft_strlen(src);
	c = ft_strlen(dst);
	if (size < i + 1)
		return (size + b);
	if (size > i + 1)
	{
		while (c < size - 1)
			*(dst + c++) = *(src + a++);
		*(dst + c) = '\0';
	}
	return (i + b);
}
