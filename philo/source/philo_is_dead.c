/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:41:23 by gcosta-d          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/14 05:17:29 by gcosta-d         ###   ########.fr       */
=======
/*   Updated: 2022/07/14 04:16:30 by lkrebs-l         ###   ########.fr       */
>>>>>>> 5438eaa7842ef7c85736d2d4d28472f7d4601ec3
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_is_dead(t_philo *philo, int philo_id)
{
	pthread_mutex_lock(&philo->is_dead_mutex);
	printf("%ld ms %d died\n", time_in_ms(philo->list), philo_id);
	pthread_mutex_unlock(&philo->is_dead_mutex);
	detach_thread(philo);
	ft_exit(philo->list);
}
