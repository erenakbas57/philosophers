/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:20:09 by makbas            #+#    #+#             */
/*   Updated: 2023/07/08 16:30:56 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dining(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	status(philo, "has taken a fork");
	status(philo, "is eating");
	pthread_mutex_lock(philo->death);
	philo->meals_eaten++;
	philo->last_meal = get_ms();
	pthread_mutex_unlock(philo->death);
	ft_sleep(philo->time_to_eat);
	status(philo, "is sleeping");
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	ft_sleep(philo->time_to_sleep);
	return (0);
}

void	*dinner(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->nbr_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		status(philo, "has taken a fork");
		ft_sleep(philo->time_to_die);
	}
	while (1)
	{
		dining(philo);
		status(philo, "is thinking");
	}
	return (NULL);
}
