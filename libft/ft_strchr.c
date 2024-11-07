/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 07:56:17 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/20 23:44:03 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr(const char *str, char *cmp)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (!str[i] && !cmp[y])
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}
