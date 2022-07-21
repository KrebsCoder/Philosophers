/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 06:51:24 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/21 01:26:47 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_death(t_philo *philo)
{
	int	stop_flag;

	//pthread_mutex_lock(&philo->check_deaths);
	stop_flag = philo->stop_flag;
	//pthread_mutex_unlock(&philo->check_deaths);
	return (stop_flag);
}
