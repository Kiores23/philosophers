/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:01:44 by amery             #+#    #+#             */
/*   Updated: 2023/06/26 17:15:00 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo)
{
	int		i;

	while (1)
	{
		pthread_mutex_lock(philo->c->check_alive);
		i = -1;
		while (++i < philo->p->nb_of_philo)
		{
			if (philo->alive == 1 || philo->alive == 0)
				break ;
			philo = philo->next;
		}
		if (i == philo->p->nb_of_philo || philo->alive == 0)
			break ;
		pthread_mutex_unlock(philo->c->check_alive);
		philo = philo->next;
		usleep(100);
	}
	pthread_mutex_unlock(philo->c->check_alive);
}

void	kill_all_philo(t_philo *philo)
{
	int		i;

	i = -1;
	pthread_mutex_lock(philo->c->check_alive);
	while (++i < philo->p->nb_of_philo)
	{
		philo->alive = 0;
		philo = philo->next;
	}
	pthread_mutex_unlock(philo->c->check_alive);
}
