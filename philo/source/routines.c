/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:33:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 04:46:39 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* static void	check_if_is_dead(t_philo *philo); */

void	*routine(void *node)
{
	t_list	*philo;

	philo = (t_list *)node;
	philo->start_time = current_time();
	pthread_mutex_lock(&philo->stopped_eating_mutex);
	philo->stopped_eating = current_time();
	pthread_mutex_unlock(&philo->stopped_eating_mutex);
	if (philo->id % 2 != 0)
		usleep(2000);
	printf("entrou philo %d\n", philo->id);
	while (!philo->philo->someone_is_dead)
	{
		if (check_if_is_dead(philo->philo))
			break ;
		philo_is_eating(philo);
		if (check_if_is_dead(philo->philo))
			break ;
		philo_is_sleeping(philo);
		if (check_if_is_dead(philo->philo))
			break ;
		philo_is_thinking(philo);
	}
	return (NULL);
}
