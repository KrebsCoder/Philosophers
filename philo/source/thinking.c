/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:21:07 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/15 06:56:44 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_thinking(t_list *philo)
{
	if (check_death(philo->philo))
		return ;
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (check_death(philo->philo))
		return ;
	printf("%ld ms %d is thinking\n", current_time() - philo->start_time, \
		philo->id);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
}
