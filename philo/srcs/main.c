/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:53:42 by amery             #+#    #+#             */
/*   Updated: 2023/06/27 10:30:55 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_params		*params;
	t_contr			*controller;
	t_philo			*philo;

	params = parsing(argc, argv);
	controller = init_controller();
	philo = NULL;
	if (params && controller)
		philo = init_philo(params, controller);
	if (philo && params->nb_of_times_philo_eat != 0)
		philo_master(params, philo);
	philo = free_philo(philo, params, controller);
	return (0);
}

	//	system("leaks philo | grep 0x | tail -n +2");