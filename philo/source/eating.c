/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:19:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/20 04:21:46 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	take_first_fork(t_list *philo);
static int	take_second_fork(t_list *philo);

int	philo_is_eating(t_list *philo)
{
	take_first_fork(philo);
	take_second_fork(philo);
	philo->stopped_eating = current_time();
	msleep(philo->philo->time_eat);
	if (check_death(philo->philo))
		return (0);
	pthread_mutex_unlock(&philo->fork);
	if (check_death(philo->philo))
		return (0);
	pthread_mutex_unlock(&philo->next->fork);
	philo->eat_counter++;
	return (1);
}

static int take_first_fork(t_list *philo)
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
