/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:09:09 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:09:12 by gcosta-d         ###   ########.fr       */
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
