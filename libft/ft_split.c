/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:24:29 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/20 23:43:59 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	unsigned int	i;
	int				count;

	count = 0;
	i = 1;
	if (!*s)
		return (0);
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **ret)
{
	unsigned int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret[i]);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	char	*position;

	ret = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			position = (char *)s;
			while (*s && *s != c)
				s++;
			ret[i] = ft_substr(position, 0, s - position);
			if (ret[i] == NULL)
				return (ft_free(ret));
			i++;
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}
