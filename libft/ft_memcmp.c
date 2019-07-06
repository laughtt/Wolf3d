/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:11:21 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 14:54:00 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*b;
	unsigned char		*c;
	size_t				i;

	i = -1;
	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (++i < n && (*(b + i) == *(c + i)))
		;
	if (i == n)
		return (0);
	return (*(b + i) - *(c + i));
}
