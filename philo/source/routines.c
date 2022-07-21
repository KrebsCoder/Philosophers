/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:33:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/21 01:26:57 by lkrebs-l         ###   ########.fr       */
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
		msleep(2);
	while (!philo->philo->stop_flag)
	{
		if (!philo_is_eating(philo))
			break ;
		if (!philo_is_sleeping(philo))
			break ;
		if (!philo_is_thinking(philo))
			break ;
	}
	return (NULL);
}
