/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:21:53 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/08 04:07:19 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void free_list(t_list *philo)
{
	t_list *node;
	int	i;

	i = philo->philo->nbr_philos;
	
	while (i > 0)
	{
		node = philo;
		philo = philo->next;
		free(node);
		i--;
	}
}

void	ft_exit(t_list *list)
{
	destroy_mutex(list->philo);
	free_list(list);
	exit(0);
}
