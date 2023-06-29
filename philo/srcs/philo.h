/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:54:50 by amery             #+#    #+#             */
/*   Updated: 2023/06/28 15:29:51 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "utils/philo_utils.h"
# include "struct.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

// Parsing

t_params		*parsing(int argc, char **argv);

// Pasing utils

void			*return_error(const char *msg);

// Init philo

t_philo			*init_philo(t_params *params, t_contr *contr);
t_contr			*init_controller(void);
void			*free_philo(t_philo *philo, t_params *params, t_contr *contr);
void			printphilo(t_philo *philo, t_params *params);

// Philo

void			philo_master(t_params *params, t_philo *philo);

// Philo action

int				philo_thinking(t_philo *philo);
int				philo_sleeping(t_philo *philo);
int				philo_eating(t_philo *philo);
int				philo_taken_a_fork(t_philo *philo);

// Sleep philo

unsigned long	get_current_time_in_ms(void);
int				philo_write(t_philo *philo,	char *msg);
void			start_tails(t_philo *philo);
int				wait_philo(t_philo *philo, unsigned long t_sleep);

// Parent process

void			check_death(t_philo *philo);
void			kill_all_philo(t_philo *philo);

#endif