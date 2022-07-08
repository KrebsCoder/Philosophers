/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:19:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/08 03:34:10 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_eating(t_list *philo)
{
	pthread_mutex_lock(&philo->fork);
	printf("%ld ms %d has taken a fork\n", time_in_ms(philo), philo->id);
	pthread_mutex_lock(&philo->next->fork);
	printf("%ld ms %d has taken a fork\n", time_in_ms(philo), philo->id);
	printf("%ld ms %d is eating\n", time_in_ms(philo), philo->id);
	usleep(philo->philo->time_eat * 1000);
	gettimeofday(&philo->stopped_eating, NULL);
	philo->eat_counter++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}
