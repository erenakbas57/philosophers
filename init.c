/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:20:29 by makbas            #+#    #+#             */
/*   Updated: 2023/07/08 16:30:52 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philo, int argc, char **argv)
{
	int	is_dead;
	int	i;

	i = 0;
	is_dead = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].id = i;
		philo[i].nbr_philo = ft_atoi(argv[1]);
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].must_eat = ft_atoi(argv[5]);
		else
			philo[i].must_eat = -1;
		philo[i].last_meal = get_ms();
		philo[i].start_time = get_ms();
		philo[i].meals_eaten = 0;
		philo[i].is_dead = &is_dead;
		i++;
	}
}

void	init_fork(t_philo *philo, char **argv,
	pthread_mutex_t *forks, pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % philo->nbr_philo];
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(philo[i].left_fork, NULL);
		pthread_mutex_init(philo[i].right_fork, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}
