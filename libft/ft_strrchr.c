/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:12:31 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/12 11:51:57 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = (int)ft_strlen(str) + 1;
	while (i--)
	{
		if (*(str + i) == (char)c)
			return (((char *)str + i));
	}
	return (NULL);
}
