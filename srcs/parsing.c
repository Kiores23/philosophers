/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:22:31 by amery             #+#    #+#             */
/*   Updated: 2023/06/14 17:42:48 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pars_argv(char *argv1)
{
	int		result;
	long	tmp;

	if (!argv1)
		return (-1);
	tmp = ft_atoi(argv1);
	if (tmp > 2147483647)
		result = -1;
	else
		result = tmp;
	return (result);
}

t_params	*parsing(int argc, char **argv)
{
	t_params	*params;

	if (argc < 5 || 6 < argc)
		return (return_error("number of arguments\n"));
	params = malloc(sizeof(t_params));
	params->nb_of_philo = pars_argv(argv[1]);
	params->time_to_die = pars_argv(argv[2]);
	params->time_to_eat = pars_argv(argv[3]);
	params->time_to_sleep = pars_argv(argv[4]);
	params->nb_of_times_philo_eat = pars_argv(argv[5]);
	if (params->nb_of_philo <= 0)
		return_error("argument: number of philosophers\n");
	else if (params->time_to_die <= 0)
		return_error("argument: time to die\n");
	else if (params->time_to_sleep <= 0)
		return_error("argument: time to sleep\n");
	else if (params->time_to_eat <= 0)
		return_error("argument: time to eat\n");
	else if (argv[5] && params->nb_of_times_philo_eat < 0)
		return_error("argument: number_of_times_each_philosopher_must_eat\n");
	else
		return (params);
	return (free_ptr(params));
}
