/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:41:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 04:16:30 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_dead(t_philo *philo, int philo_id)
{
	pthread_mutex_t	is_dead;

	pthread_mutex_init(&is_dead, NULL);
	pthread_mutex_lock(&is_dead);
	printf("%ld ms %d died\n", time_in_ms(philo->list), philo_id);
	detach_thread(philo);
	pthread_mutex_unlock(&is_dead);
	pthread_mutex_destroy(&is_dead);
	ft_exit(philo->list);
}
