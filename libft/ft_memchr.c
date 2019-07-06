/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:59:11 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 13:23:46 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*b;
	size_t			i;

	b = (const char*)s;
	i = -1;
	while (++i < n)
		if (*(b + i) == (char)c)
			return ((void *)b + i);
	return (NULL);
}
