/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:21:07 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 04:48:37 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_thinking(t_list *philo)
{
	if (check_if_is_dead(philo->philo))
		return ;
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (check_if_is_dead(philo->philo))
		return ;
	printf("%ld ms %d is thinking\n", current_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
}
