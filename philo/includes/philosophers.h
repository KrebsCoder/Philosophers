/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:54:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/27 20:06:12 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int	nbr_philos;
	int	nbr_forks;
	int	time_eat;
	int	time_sleep;
	int	time_die;
	int	times_must_eat;
}	t_philo;

void	check_arguments(int argc, char *argv[]);

// Utils
int		ft_atoi(const char *str);
void	ft_init(t_philo *ph, int argc, char *argv[]);
int		is_str_positive_num(char *str);

#endif