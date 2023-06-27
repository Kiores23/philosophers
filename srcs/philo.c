/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:22:45 by amery             #+#    #+#             */
/*   Updated: 2023/06/26 17:17:23 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_starter(t_philo *philo)
{
	t_time	t_start;

	while (1)
	{
		pthread_mutex_lock(philo->c->start);
		if (*philo->c->start_count == philo->p->nb_of_philo)
			break ;
		pthread_mutex_unlock(philo->c->start);
		usleep(1000);
	}
	gettimeofday(&t_start, NULL);
	philo->c->t_start = t_start.tv_sec * 1000 + t_start.tv_usec / 1000;
	pthread_mutex_unlock(philo->c->start);
}

void	philo_while(t_philo *philo)
{
	while (1)
	{
		if (!philo_thinking(philo))
			break ;
		if (!philo_eating(philo))
			break ;
		if (++philo->i == philo->p->nb_of_times_philo_eat
			&& philo->p->nb_of_times_philo_eat >= 0)
		{
			pthread_mutex_lock(philo->c->check_alive);
			if (philo->alive)
				philo->alive = -1;
			pthread_mutex_unlock(philo->c->check_alive);
		}
		if (!philo_sleeping(philo))
			break ;
	}
}

void	*philosopher(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	start_tails(philo);
	pthread_mutex_lock(philo->c->start_final);
	pthread_mutex_unlock(philo->c->start_final);
	philo->t_reset = philo->c->t_start;
	philo->t_stape = philo->c->t_start;
	philo->i = 0;
	philo_while(philo);
	pthread_mutex_lock(philo->c->check_alive);
	philo->alive = 0;
	pthread_mutex_unlock(philo->c->check_alive);
	return (NULL);
}

void	philo_master(t_params *params, t_philo *philo)
{
	int		i;

	i = -1;
	pthread_mutex_lock(philo->c->start_final);
	while (++i < params->nb_of_philo)
	{
		pthread_create(&philo->thread, NULL, philosopher, (void *)philo);
		philo = philo->next;
	}
	philo_starter(philo);
	pthread_mutex_unlock(philo->c->start_final);
	pthread_mutex_lock(philo->c->end);
	check_death(philo);
	kill_all_philo(philo);
	pthread_mutex_unlock(philo->c->end);
	i = -1;
	while (++i < philo->p->nb_of_philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
}
