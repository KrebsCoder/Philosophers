/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:06:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/14 05:19:37 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_philo(t_philo *philo)
{
	init_linked_list(philo);
	init_mutex(philo);
	pthread_mutex_init(&philo->start_time_mutex, NULL);
	pthread_mutex_init(&philo->time_in_ms_mutex, NULL);
	pthread_mutex_init(&philo->is_dead_mutex, NULL);
	//pthread_mutex_init(&philo->is_printing_mutex, NULL);
	create_threads(philo);
	thread_join(philo);
}
