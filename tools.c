/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:20:57 by makbas            #+#    #+#             */
/*   Updated: 2023/07/08 16:32:15 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int wait_time)
{
	t_time	time;

	time = get_ms();
	while (get_ms() - time < (t_time)wait_time)
		usleep(100);
}

t_time	get_ms(void)
{
	struct timeval		tv;
	t_time				time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_free(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		pthread_mutex_destroy(philo[i].left_fork);
		pthread_mutex_destroy(philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(philo->death);
	free(forks);
	free(death);
	free(philo);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - 48) * sign;
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
		i++;
	}
	return (num);
}
