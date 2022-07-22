/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:19:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/22 03:32:12 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	take_first_fork(t_list *philo);
static int	take_second_fork(t_list *philo);

int	philo_is_eating(t_list *philo)
{
	take_first_fork(philo);
	take_second_fork(philo);
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	philo->eat_counter++;
	philo->stopped_eating = current_time();
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
	msleep(philo->philo->time_eat);
	if (check_death(philo->philo))
		return (0);
	pthread_mutex_unlock(&philo->fork);
	if (check_death(philo->philo))
		return (0);
	pthread_mutex_unlock(&philo->next->fork);
	return (1);
}

static int	take_first_fork(t_list *philo)
{
	if (check_death(philo->philo))
		return (0);
	pthread_mutex_lock(&philo->fork);
	print_philo(philo, FORK);
	return (1);
}

static int	take_second_fork(t_list *philo)
{
	if (check_death(philo->philo))
		return (0);
	pthread_mutex_lock(&philo->next->fork);
	print_philo(philo, FORK);
	print_philo(philo, EAT);
	return (1);
}
