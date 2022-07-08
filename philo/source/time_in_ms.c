/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_in_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:07:30 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/08 02:14:56 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	time_in_ms(t_list *philo)
{
	long	time_in_ms;
	long	current_time_ms;

	gettimeofday(&philo->philo->current_time, NULL);
	current_time_ms = (philo->philo->current_time.tv_sec * 1000) + \
		(philo->philo->current_time.tv_usec / 1000);
	time_in_ms = current_time_ms - philo->philo->start_time;
	return (time_in_ms);
}
