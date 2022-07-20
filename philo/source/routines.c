/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:33:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/20 04:06:25 by gcosta-d         ###   ########.fr       */
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
	while (!philo->philo->someone_is_dead)
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
