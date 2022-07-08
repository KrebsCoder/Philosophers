/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:41:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/08 04:07:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_dead(t_philo *philo)
{
	pthread_mutex_t	is_dead;
	
	pthread_mutex_init(&is_dead, NULL);
	pthread_mutex_lock(&is_dead);
	printf("%ld ms %d died\n", time_in_ms(philo->list), philo->is_dead);
	detach_thread(philo);
	pthread_mutex_unlock(&is_dead);
	pthread_mutex_destroy(&is_dead);
	ft_exit(philo->list);
}
