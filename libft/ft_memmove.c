/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:19:07 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/20 23:42:27 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*c_src;
	char	*c_dst;

	if (!dst && !src)
		return (NULL);
	c_src = (char *)src;
	c_dst = (char *)dst;
	if (c_dst < c_src)
		ft_memcpy(c_dst, c_src, n);
	else
	{
		while (n > 0)
		{
			c_dst[n - 1] = c_src[n - 1];
			n--;
		}
	}
	return (dst);
}
