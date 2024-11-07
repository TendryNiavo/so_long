/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:47:05 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/20 23:40:57 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*call;

	call = (void *)malloc(nmemb * size);
	if (call == NULL)
		return (NULL);
	ft_bzero (call, size * nmemb);
	return (call);
}
