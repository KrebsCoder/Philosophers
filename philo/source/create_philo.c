/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:06:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/15 03:27:21 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_philo(t_philo *philo)
{
	init_linked_list(philo);
	init_mutex(philo);
	create_threads(philo);
	thread_join(philo);
}
