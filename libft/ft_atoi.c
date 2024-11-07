/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:24:31 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/21 10:12:00 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_return(unsigned int sign, unsigned int neg, unsigned int nb)
{
	if (sign > 1)
		return (0);
	if (neg > 0)
		return (-nb);
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	neg;
	unsigned int	nb;
	unsigned int	sign;

	neg = 0;
	sign = 0;
	nb = 0;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg++;
		sign++;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nb *= 10;
		nb += nptr[i] - 48;
		i++;
	}
	return (ft_return(sign, neg, nb));
}
