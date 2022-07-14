/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:19:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 03:13:04 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_eating(t_list *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&philo->fork);
	printf("%ld ms %d has taken a fork\n", time_in_ms(philo), philo->id);
	gettimeofday(&time, NULL);
	philo->first_fork = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	philo->has_fork = 1;
	pthread_mutex_lock(&philo->next->fork);
	philo->has_fork = 0;
	philo->first_fork = 0;
	printf("%ld ms %d has taken a fork\n", time_in_ms(philo), philo->id);
	printf("%ld ms %d is eating\n", time_in_ms(philo), philo->id);
	
	usleep(philo->philo->time_eat * 1000);
	
	gettimeofday(&philo->stopped_eating, NULL);
	philo->eat_counter++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}
