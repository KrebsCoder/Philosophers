/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_is_dead.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 04:02:55 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/19 04:23:41 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_if_is_dead(t_philo *philo)
{
	int	is_dead;
	
	pthread_mutex_lock(&philo->someone_is_dead_mutex);
	is_dead = 0;
	if (philo->someone_is_dead)
		is_dead = 1;
	pthread_mutex_unlock(&philo->someone_is_dead_mutex);
	return (is_dead);
}
