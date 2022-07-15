/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_vigilant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:05:50 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/15 07:12:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine_vigilant(void *node)
{
	int		time_last_eaten;
	t_list	*philo;

	philo = (t_list *)node;
	while (!philo->philo->someone_is_dead)
	{
		pthread_mutex_lock(&philo->philo->is_printing_mutex);
		time_last_eaten = current_time() - philo->stopped_eating;
		if (time_last_eaten >= philo->philo->time_die)
		{
			pthread_mutex_lock(&philo->philo->check_deaths);
			philo->philo->someone_is_dead = 1;
			pthread_mutex_unlock(&philo->philo->check_deaths);
			destroy_mutex(philo->philo);
			break ;
		}
		pthread_mutex_unlock(&philo->philo->is_printing_mutex);
		philo = philo->next;
	}
	philo_is_dead(philo->philo, philo->id);
	return (NULL);
}
