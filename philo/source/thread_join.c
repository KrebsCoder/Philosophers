/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:13:47 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:13:49 by gcosta-d         ###   ########.fr       */
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
