/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:04:14 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/12 02:00:47 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_time(t_philo *philo)
{
	struct timeval	start_time;
	pthread_mutex_t	start_time_mutex;

	pthread_mutex_init(&start_time_mutex, NULL);
	pthread_mutex_lock(&start_time_mutex);
	if (philo->start_time_flag == 0)
	{
		philo->start_time_flag = 1;
		gettimeofday(&start_time, NULL);
		philo->start_time = (start_time.tv_sec * 1000) + \
			(start_time.tv_usec / 1000);
	}
	pthread_mutex_unlock(&start_time_mutex);
}
