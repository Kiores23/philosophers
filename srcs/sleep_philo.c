/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:52:00 by amery             #+#    #+#             */
/*   Updated: 2023/06/26 18:04:19 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_tails(t_philo *philo)
{
	pthread_mutex_lock(philo->c->start);
	*philo->c->start_count += 1;
	usleep(1000);
	pthread_mutex_unlock(philo->c->start);
}

int	philo_write(t_philo *philo,	char *msg)
{
	unsigned long	t;

	pthread_mutex_lock(philo->c->write);
	pthread_mutex_lock(philo->c->check_alive);
	gettimeofday(&philo->c->time, NULL);
	t = philo->c->time.tv_sec * 1000 + philo->c->time.tv_usec / 1000;
	if (!philo->alive)
	{
		pthread_mutex_unlock(philo->c->check_alive);
		pthread_mutex_unlock(philo->c->write);
		return (0);
	}
	pthread_mutex_unlock(philo->c->check_alive);
	printf("%lu %i %s\n", t - philo->c->t_start, philo->name, msg);
	pthread_mutex_unlock(philo->c->write);
	return (1);
}

int	death(t_philo *philo, unsigned long t)
{
	pthread_mutex_lock(philo->c->write);
	pthread_mutex_lock(philo->c->check_alive);
	if (!philo->alive)
	{
		pthread_mutex_unlock(philo->c->check_alive);
		pthread_mutex_unlock(philo->c->write);
		return (0);
	}
	philo->alive = 0;
	pthread_mutex_unlock(philo->c->check_alive);
	printf("%lu %i died\n", t - philo->c->t_start, philo->name);
	pthread_mutex_lock(philo->c->end);
	pthread_mutex_unlock(philo->c->end);
	pthread_mutex_unlock(philo->c->write);
	return (0);
}

int	wait_philo(t_philo *philo, unsigned long t_sleep)
{
	t_time			time;
	unsigned long	t;

	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (t - philo->t_stape < t_sleep)
	{
		usleep(1000);
		if (t - philo->t_reset > philo->p->time_to_die)
			return (death(philo, t));
		gettimeofday(&time, NULL);
		t = time.tv_sec * 1000 + time.tv_usec / 1000;
	}
	philo->t_stape = t;
	return (1);
}
