/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:29:09 by amery             #+#    #+#             */
/*   Updated: 2023/06/26 14:38:22 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct timeval	t_time;

typedef struct s_params
{
	int				nb_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				nb_of_times_philo_eat;
}	t_params;

typedef struct s_controller
{
	int					*start_count;
	pthread_mutex_t		*start;
	pthread_mutex_t		*start_final;
	pthread_mutex_t		*check_alive;
	pthread_mutex_t		*write;
	pthread_mutex_t		*end;
	struct timeval		time;
	pthread_t			death_thread;
	unsigned long		t_start;
}	t_contr;

typedef struct s_philo
{
	int					name;
	pthread_t			thread;
	pthread_mutex_t		fork;
	unsigned long		t_reset;
	unsigned long		t_stape;
	int					i;
	int					alive;
	struct s_controller	*c;
	struct s_params		*p;
	struct s_philo		*next;
	struct s_philo		*prec;
}	t_philo;

#endif