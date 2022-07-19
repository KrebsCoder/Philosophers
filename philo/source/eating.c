/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:19:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 04:49:08 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_eating(t_list *philo)
{
	if (check_if_is_dead(philo->philo))
		return ;
	pthread_mutex_lock(&philo->fork);
	if (check_if_is_dead(philo->philo))
		return ;
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (check_if_is_dead(philo->philo))
		return ;
	printf("%ld ms %d has taken a fork\n", current_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
	if (check_if_is_dead(philo->philo))
		return ;
	pthread_mutex_lock(&philo->next->fork);
	if (check_if_is_dead(philo->philo))
		return ;	
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (check_if_is_dead(philo->philo))
		return ;
	printf("%ld ms %d has taken a fork\n", current_time() - philo->start_time, philo->id);
	printf("%ld ms %d is eating\n", current_time() - philo->start_time, philo->id);
	if (check_if_is_dead(philo->philo))
		return ;
	philo->stopped_eating = current_time();
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
	usleep(philo->philo->time_eat * 1000);
	if (check_if_is_dead(philo->philo))
		return ;
	philo->eat_counter++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}
