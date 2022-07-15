/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:29:39 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/15 05:29:54 by lkrebs-l         ###   ########.fr       */
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
