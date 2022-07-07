/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:19:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/07 03:51:01 by gcosta-d         ###   ########.fr       */
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
	
	// gettimeofday(&philo->philo->current_time, NULL);
	// printf("-> %ld\n", philo->philo->current_time.tv_sec);
	usleep(philo->philo->time_eat * 1000);
	// gettimeofday(&philo->philo->current_time, NULL);
	// printf("-> %ld\n", philo->philo->current_time.tv_sec);
	philo->eat_counter++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}
