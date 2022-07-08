/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:33:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/08 04:26:47 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	check_if_is_dead(t_philo *philo);

void	*routine(void *node)
{
	t_list	*philo = (t_list *)node;

	start_time(philo->philo);
	while (1)
	{
		check_if_is_dead(philo->philo);
		philo_is_eating(philo);
		check_if_is_dead(philo->philo);
		philo_is_sleeping(philo);
		check_if_is_dead(philo->philo);
		philo_is_thinking(philo);
	}
	return (NULL);
}

static void	check_if_is_dead(t_philo *philo)
{
	if (philo->is_dead != -1)
		philo_is_dead(philo);
}
