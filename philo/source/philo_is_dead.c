/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:41:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 04:49:52 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_dead(t_philo *philo, int philo_id)
{
	pthread_mutex_lock(&philo->is_printing_mutex);
	printf("%ld ms %d died\n", current_time() - philo->list->start_time, philo_id);
	pthread_mutex_unlock(&philo->is_printing_mutex);
}
