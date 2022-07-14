/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:41:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 05:17:29 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_dead(t_philo *philo, int philo_id)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	printf("%ld ms %d died\n", time_in_ms(philo->list), philo_id);
	pthread_mutex_unlock(&philo->is_dead_mutex);
	detach_thread(philo);
	ft_exit(philo->list);
}
