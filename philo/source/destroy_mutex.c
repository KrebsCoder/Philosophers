/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:26:09 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 05:19:42 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	tmp = philo->list;
	i = philo->nbr_philos;
	while (i > 0)
	{
		pthread_mutex_destroy(&tmp->fork);
		tmp = tmp->next;
		i--;
	}
	pthread_mutex_destroy(&philo->start_time_mutex);
	pthread_mutex_destroy(&philo->time_in_ms_mutex);
	//pthread_mutex_destroy(&philo->is_dead_mutex);
	//pthread_mutex_destroy(&philo->is_printing_mutex);
}
