/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:41:48 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/20 23:46:49 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill(const char *s, unsigned int start, size_t len, char *dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_lenght;

	if (ft_strlen(s) - start < len)
		new_lenght = ft_strlen(s) - start;
	else
		new_lenght = len;
	if (ft_strlen(s) == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (new_lenght + 1));
	if (!str)
		return (NULL);
	str = ft_fill(s, start, len, str);
	return (str);
}
