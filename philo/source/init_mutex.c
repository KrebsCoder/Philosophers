/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:23:30 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 04:24:09 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_mutex(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	i = philo->nbr_philos;
	tmp = philo->list;
	while (i > 0)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_mutex_init(&tmp->stopped_eating_mutex, NULL);
		tmp = tmp->next;
		i--;
	}
	pthread_mutex_init(&philo->start_time_mutex, NULL);
	pthread_mutex_init(&philo->time_in_ms_mutex, NULL);
	pthread_mutex_init(&philo->is_printing_mutex, NULL);
	pthread_mutex_init(&philo->someone_is_dead_mutex, NULL);
}
