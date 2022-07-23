/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_is_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:12:42 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:12:51 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_philo_is_dead(t_list *philo, char *string)
{
	printf("%ld %d %s\n", current_time() - philo->start_time, \
		philo->id, string);
	if (check_death(philo->philo))
		return ;
}
