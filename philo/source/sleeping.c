/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:20:31 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/15 03:36:44 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_sleeping(t_list *philo)
{
	long			time_stopped_eating;
	int				i;

	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	printf("%ld ms %d is sleeping\n", current_time() - philo->start_time, \
		philo->id);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
	time_stopped_eating = current_time();
	i = 0;
	while (i < philo->philo->time_sleep)
	{
		usleep(5000);
		if ((current_time() - time_stopped_eating) > philo->philo->time_die)
			philo_is_dead(philo->philo, philo->id);
		i += 5;
	}
}
