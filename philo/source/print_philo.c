/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:41:01 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/20 02:43:41 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_philo(t_list *philo, char *string)
{
	if (check_death(philo->philo))
		return ;
	pthread_mutex_lock(&philo->philo->is_printing_mutex);
	if (check_death(philo->philo))
		return ;
	printf("%ld %d %s\n", current_time() - philo->start_time, \
		philo->id, string);
	pthread_mutex_unlock(&philo->philo->is_printing_mutex);
}
