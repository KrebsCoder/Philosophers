/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_vigilant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:05:50 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/14 02:45:08 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine_vigilant(void *node)
{
	struct timeval	time;
	long			time_now;
	int				time_waiting_for_fork;
	t_list			*philo;

	philo = (t_list *)node;
	while (1)
	{
		if (philo->has_fork == 1)
		{
			gettimeofday(&time, NULL);
			time_now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
			time_waiting_for_fork = time_now - philo->first_fork;
			if (time_waiting_for_fork > philo->philo->time_die)
				philo_is_dead(philo->philo, philo->id);
		}
		philo = philo->next;
	}
}