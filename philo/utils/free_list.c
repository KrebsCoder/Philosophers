/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:15:42 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:15:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_list(t_list *philo)
{
	t_list	*node;
	int		i;

	i = philo->philo->nbr_philos;
	while (i > 0)
	{
		node = philo;
		philo = philo->next;
		free(node);
		i--;
	}
}
