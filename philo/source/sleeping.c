/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:13:34 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:13:36 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_is_sleeping(t_list *philo)
{
	print_philo(philo, SLEEP);
	msleep(philo->philo->time_sleep);
	return (1);
}
