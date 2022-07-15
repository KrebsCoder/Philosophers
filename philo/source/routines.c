/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:33:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/15 07:13:04 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* static void	check_if_is_dead(t_philo *philo); */

void	*routine(void *node)
{
	t_list	*philo;

	philo = (t_list *)node;
	philo->start_time = current_time();
	philo->stopped_eating = philo->start_time;
	if (philo->id % 2 != 0)
		usleep(2 * 1000);
	while (!philo->philo->someone_is_dead)
	{
		if (check_death(philo->philo))
			break ;
		philo_is_eating(philo);
		if (check_death(philo->philo))
			break ;
		philo_is_sleeping(philo);
		if (check_death(philo->philo))
			break ;
		philo_is_thinking(philo);
	}
	return (NULL);
}
