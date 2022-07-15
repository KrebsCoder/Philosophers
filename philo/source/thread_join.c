/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:24:55 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/15 04:02:00 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	thread_join(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	i = philo->nbr_forks;
	tmp = philo->list;
	while (i > 0)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		i--;
	}
	pthread_join(tmp->philo->vigilant, NULL);
}
