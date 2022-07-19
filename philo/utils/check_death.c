/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 06:51:24 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/19 05:52:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_death(t_philo *philo)
{
	int	is_someone_dead;

	//pthread_mutex_lock(&philo->check_deaths);
	is_someone_dead = philo->someone_is_dead;
	//pthread_mutex_unlock(&philo->check_deaths);
	return (is_someone_dead);
}
