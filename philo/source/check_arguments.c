/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:29:51 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/26 00:11:09 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	check_number_of_arguments(int argc);
static void	check_if_args_are_numeric(char *argv[]);
static void	check_if_args_are_unsigned(char *argv[]);

void	check_arguments(int argc, char *argv[])
{
	check_number_of_arguments(argc);
	check_if_args_are_numeric(argv);
	check_if_args_are_unsigned(argv);
}

static void	check_number_of_arguments(int argc)
{
	if (argc > 6)
	{
		printf("Too many arguments\n");
		exit(1);
	}
	else if (argc < 5)
	{
		printf("Few arguments\n");
		exit(1);
	}
}

static void	check_if_args_are_numeric(char *argv[])
{
	int	i;
	
	i = 0;
	while (argv[++i])
	{
		if(is_str_positive_num(argv[i]) == 0)
		{
			printf("Arguments must only be numeric and a positive number\n");
			exit(1);
		}
	}
}

static void	check_if_args_are_unsigned(char *argv[])
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	while (argv[++i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr <= 0)
		{
			printf("Arguments must be only positive numbers\n");
			exit(1);
		}
	}
}
