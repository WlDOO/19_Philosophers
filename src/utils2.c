/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:39:10 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/24 15:44:38 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	ft_atoi(const char *str1)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str1[i] == 32 || (str1[i] >= 9 && str1[i] <= 13))
		i++;
	if (str1[i] == '-' || str1[i] == '+')
	{
		if (str1[i] == '-')
			sign *= -1;
		i++;
	}
	while (str1[i] >= '0' && str1[i] <= '9')
	{
		nb *= 10;
		nb = nb + (str1[i++] - 48);
	}
	return (nb * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
