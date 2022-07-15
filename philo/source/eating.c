/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:19:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/15 05:49:31 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	take_first_fork(t_list *philo);
static void	take_second_fork(t_list *philo);

void	philo_is_eating(t_list *philo)
{
	if (philo->philo->someone_is_dead)
		return ;
	take_first_fork(philo);
	if (philo->philo->someone_is_dead)
		return ;
	take_second_fork(philo);
	philo->stopped_eating = current_time();
	if (philo->philo->someone_is_dead)
		return ;
	usleep(philo->philo->time_eat * 1000);
	philo->eat_counter++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

static void take_first_fork(t_list *philo)
{
	if (philo->philo->someone_is_dead)
		return ;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (philo->philo->someone_is_dead)
		return ;
	printf("%ld ms %d has taken a fork\n", current_time() - philo->start_time, \
		philo->id);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
}

static void	take_second_fork(t_list *philo)
{
	if (philo->philo->someone_is_dead)
		return ;
	pthread_mutex_lock(&philo->next->fork);
	if (philo->philo->someone_is_dead)
		return ;
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (philo->philo->someone_is_dead)
		return ;
	printf("%ld ms %d has taken a fork\n", current_time() - philo->start_time, \
		philo->id);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (philo->philo->someone_is_dead)
		return ;
	printf("%ld ms %d is eating\n", current_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
}
