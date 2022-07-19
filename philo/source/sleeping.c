/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:20:31 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 04:52:42 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_sleeping(t_list *philo)
{
	long			time_now;
	int				i;

	if (check_if_is_dead(philo->philo))
		return ;
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (check_if_is_dead(philo->philo))
		return ;
	printf("%ld ms %d is sleeping\n", current_time() - philo->start_time, philo->id);
	if (check_if_is_dead(philo->philo))
		return ;
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
	i = 0;
	while (i < philo->philo->time_sleep)
	{
		usleep(5000);
		time_now = current_time();
		if ((time_now - philo->stopped_eating) > philo->philo->time_die)
		{
			philo->philo->someone_is_dead = 1;
			philo_is_dead(philo->philo, philo->id);
		}
		i += 5;
	}
}
