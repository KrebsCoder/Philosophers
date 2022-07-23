/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:15:20 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:15:24 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_death(t_philo *philo)
{
	int	stop_flag;

	pthread_mutex_lock(&philo->check_deaths);
	stop_flag = philo->stop_flag;
	pthread_mutex_unlock(&philo->check_deaths);
	return (stop_flag);
}
