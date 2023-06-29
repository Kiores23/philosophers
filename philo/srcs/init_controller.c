/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_contr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:54:42 by amery             #+#    #+#             */
/*   Updated: 2023/05/16 15:10:03 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_contr	*init_controller_next(t_contr *controller)
{
	controller->check_alive = malloc(sizeof(pthread_mutex_t));
	if (!controller->check_alive)
		return (NULL);
	pthread_mutex_init(controller->check_alive, NULL);
	controller->end = malloc(sizeof(pthread_mutex_t));
	if (!controller->end)
		return (NULL);
	pthread_mutex_init(controller->end, NULL);
	return (controller);
}

t_contr	*init_controller(void)
{
	t_contr		*controller;

	controller = malloc(sizeof(t_contr));
	if (!controller)
		return (NULL);
	controller->start_count = malloc(sizeof(int *));
	*controller->start_count = 0;
	controller->t_start = 0;
	controller->write = malloc(sizeof(pthread_mutex_t));
	if (!controller->write)
		return (NULL);
	pthread_mutex_init(controller->write, NULL);
	controller->start = malloc(sizeof(pthread_mutex_t));
	if (!controller->start)
		return (NULL);
	pthread_mutex_init(controller->start, NULL);
	controller->start_final = malloc(sizeof(pthread_mutex_t));
	if (!controller->start_final)
		return (NULL);
	pthread_mutex_init(controller->start_final, NULL);
	return (init_controller_next(controller));
}
