/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:18:57 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/20 23:44:10 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	if (*src == '\0')
		return (dest);
	else
	{
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return ((char *)src);
	}
}
