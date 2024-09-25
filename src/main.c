/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:38 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/25 15:03:55 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//gettimeofday * 1000 + gettimeofday \ 1000

int	init_fork(t_data **data)
{
	int	i;

	i = 0;
	(*data)->fork = malloc(sizeof(pthread_mutex_t) * (*data)->nbr_philo);
	if (!(*data)->fork)
		return (1);
	while (i < (*data)->nbr_philo)
	{
		pthread_mutex_init(&(*data)->fork[i], NULL);
		i++;
	}
	return (0);
}

int	init_philo(t_data **data)
{
	int			i;
	long long	value;

	i = -1;
	(*data)->philo = NULL;
	(*data)->philo = malloc(sizeof(t_philo) * (*data)->nbr_philo);
	if (!(*data)->philo)
		return (1);
	while (++i < (*data)->nbr_philo)
	{
		(*data)->philo[i].check_meal = 0;
		(*data)->philo[i].death = 0;
		(*data)->philo[i].id = i + 1;
		(*data)->philo[i].left_fork = (*data)->philo[i].id - 1;
		if ((*data)->philo[i].id + 1 != (*data)->nbr_philo)
		{
			value = ((*data)->philo[i].id) % (*data)->nbr_philo;
			(*data)->philo[i].right_fork = value;
		}
		else
			(*data)->philo[i].right_fork = ((*data)->philo[i].id);
		(*data)->philo[i].last_eat = get_time();
		(*data)->philo[i].data = *data;
	}
	return (0);
}

int	init_data(int ac, char	**av, t_data **data)
{
	int	i;

	i = 0;
	*data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	(*data)->error = 0;
	(*data)->die = 0;
	(*data)->nbr_philo = ft_atoi(av[1]);
	(*data)->time_die = ft_atoi(av[2]);
	(*data)->eat = ft_atoi(av[3]);
	(*data)->sleep = ft_atoi(av[4]);
	(*data)->start_time = get_time();
	pthread_mutex_init(&(*data)->moment_death, NULL);
	pthread_mutex_init(&(*data)->write_lock, NULL);
	if (init_fork(data) == 1)
		return (1);
	if (ac == 6)
		(*data)->nbr_eat = ft_atoi(av[5]);
	else
		(*data)->nbr_eat = -1;
	if (init_philo(data) == 1)
		return (1);
	return (0);
}

void	ft_check_death(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_all_eat(data) == 1)
			return ;
		ft_check_eat(data);
		if (data->die == 1)
			return ;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = -1;
	data = NULL;
	if (ac < 5 || ac > 6)
		return (printf("Error\n"), 0);
	if (ft_parsing(av) == 1)
		return (1);
	if (init_data(ac, av, &data))
		return (printf("Error\n"), free_all(data, data->philo), 1);
	while (++i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&routine, &data->philo[i]) != 0)
			return (printf("Error\n"), free_all(data, data->philo),
				data->die = 1, 1);
	}
	i = -1;
	ft_check_death(data);
	while (++i < data->nbr_philo)
		if (pthread_join(data->philo[i].thread, (void *)&data->philo[i]) != 0)
			return (printf("Error\n"), free_all(data, data->philo),
				data->die = 1, 1);
	free_all(data, data->philo);
}
