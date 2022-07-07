/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:06:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/07 02:25:33 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_philo(t_philo *philo)
{
	init_linked_list(philo);
	init_mutex(philo);
	create_threads(philo);
	thread_join(philo);
	pthread_mutex_destroy(&philo->list->fork);
	ft_exit(philo->list);
}
