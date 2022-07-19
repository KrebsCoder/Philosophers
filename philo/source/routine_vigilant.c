/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_vigilant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:05:50 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/19 04:46:51 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine_vigilant(void *node)
{
	long			time_now;
	long			last_meal;
	t_list			*philo;

	philo = (t_list *)node;
	printf("entrou vigilante\n");
	while (!philo->philo->someone_is_dead)
	{
		pthread_mutex_lock(&philo->philo->is_printing_mutex);

		time_now = current_time();
		pthread_mutex_lock(&philo->stopped_eating_mutex);
		last_meal = time_now - philo->stopped_eating;
		//printf("last_meal: %ld | philosopher: %d\n", last_meal, philo->id);
		pthread_mutex_unlock(&philo->stopped_eating_mutex);
		if (last_meal >= philo->philo->time_die)
		{
			philo->philo->someone_is_dead = 1;
			destroy_mutex(philo->philo);
			philo_is_dead(philo->philo, philo->id);
			break ;
		}
		pthread_mutex_unlock(&philo->philo->is_printing_mutex);
		philo = philo->next;
	}
	return (NULL);
}