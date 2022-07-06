/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:54:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/06 04:25:01 by gcosta-d         ###   ########.fr       */
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

typedef struct s_list
{
	pthread_mutex_t	mutex;
	pthread_t		thread;
	int				id;
	long			time;
	long			time_start;
	struct	timeval current_time;
	struct	s_list *previous;
	struct	s_list *next;
	struct	s_philo	*philo;
}	t_list;

typedef struct s_philo
{
	int		nbr_philos;
	int		nbr_forks;
	int		time_eat;
	int		time_sleep;
	int		time_die;
	int		times_must_eat;
	t_list	*list;
}	t_philo;


void	check_arguments(int argc, char *argv[]);
void	create_philo(t_philo *ph);
void	*routine(void *philo);

// Utils
int		ft_atoi(const char *str);
void	ft_init(t_philo *ph, int argc, char *argv[]);
int		is_str_positive_num(char *str);
void	ft_exit(t_list *list);
t_list	*ft_lstnew(int id, t_philo *philo);
void	ft_lstadd_front(t_list *lst, t_list *new);

#endif