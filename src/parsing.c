/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:43:06 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/24 15:46:11 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_parsing(char **av)
{
	int	i;
	int	y;

	i = 0;
	while (av[++i])
	{
		if (av[i][0] == '-')
			return (printf("Error : chiffre negatif\n"), 1);
	}
	i = 0;
	while (av[++i])
	{
		y = -1;
		while (av[i][++y])
		{
			if (ft_isdigit(av[i][y]) == 0)
				return (printf("Error : charactere differents d un nombres"),
					1);
		}
	}
	if (ft_check_num(av) == 1)
		return (1);
	return (0);
}

int	ft_check_num(char **av)
{
	int	i;

	i = 1;
	while (av[++i])
	{
		if (i == 5)
			break ;
		if (ft_atoi(av[i]) < 60)
		{
			printf("Error : valeur plus basse que 60 ms\n");
			return (1);
		}
	}
	return (0);
}
