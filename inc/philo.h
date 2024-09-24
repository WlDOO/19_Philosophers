/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:44:52 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/24 15:51:35 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;
struct					s_data;

typedef struct s_philo
{
	pthread_t				thread;
	_Atomic long long		last_eat;
	int						death;
	int						id;
	int						left_fork;
	int						right_fork;
	int						check_meal;
	struct s_data			*data;
}				t_philo;

typedef struct s_data
{
	int				error;
	int				nbr_philo;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	_Atomic int		die;
	long long		time_die;
	int				eat;
	long long		sleep;
	int				nbr_eat;
	long long		start_time;
	t_mutex			write_lock;
	t_mutex			moment_death;
}					t_data;

long long	get_time(void);
int			main(int ac, char **av);
void		*routine(void *arg);
void		thinking(t_data *data, t_philo *philo);
void		pick_fork(t_philo *philo);
void		my_sleep(long long time, t_data *data);
void		is_eating(t_philo *philo);
void		is_sleeping(t_data *data, t_philo *philo);
void		ft_check_eat(t_data *data);
void		start_philo(t_data *data);
int			ft_parsing(char **av);
int			ft_check_num(char **av);
void		ft_check_death(t_data *data);
void		free_all(t_data *data, t_philo *philo);
int			ft_all_eat(t_data *data);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str1);

#endif