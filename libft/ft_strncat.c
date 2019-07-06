/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:01:25 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 14:59:37 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		strl;
	int		a;

	a = -1;
	strl = (int)ft_strlen(dest);
	while (*(src + ++a) && a < (int)n)
	{
		*(dest + strl++) = *(src + a);
	}
	*(dest + strl) = '\0';
	return (dest);
}
