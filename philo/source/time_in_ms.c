/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_in_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:07:30 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 03:32:43 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	time_in_ms(t_list *philo)
{
	long	time_in_ms;
	long	current_time_ms;

	pthread_mutex_lock(&philo->philo->time_in_ms_mutex);
	current_time_ms = current_time();
	time_in_ms = current_time_ms - philo->start_time;
	pthread_mutex_unlock(&philo->philo->time_in_ms_mutex);
	return (time_in_ms);
}
