/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:08:51 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/24 15:45:58 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->nbr_philo == 1)
	{
		printf("%lld	%d  has taken a fork\n",
			get_time() - philo->data->start_time, philo->id);
		my_sleep(data->time_die, philo->data);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	while (!data->die)
	{
		if (philo->data->nbr_eat == philo->check_meal)
			return (NULL);
		pick_fork(philo);
		is_eating(philo);
		is_sleeping(data, philo);
		thinking(data, philo);
	}
	return (NULL);
}
