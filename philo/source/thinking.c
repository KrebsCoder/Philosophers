/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:21:07 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 05:18:33 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_thinking(t_list *philo)
{
	//pthread_mutex_lock(&philo->philo->is_printing_mutex);
	printf("%ld ms %d is thinking\n", time_in_ms(philo), philo->id);
	//pthread_mutex_unlock(&philo->philo->is_printing_mutex);
}
