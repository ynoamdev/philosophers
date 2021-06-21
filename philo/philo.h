/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:16:48 by ynoam             #+#    #+#             */
/*   Updated: 2021/06/21 11:55:30 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

int	ft_isdigit(int c);
int	input_error(char *av[]);
int ft_atoi(const char *str);

typedef struct s_philo
{
    int philo_num;
    pthread_mutex_t *forks;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_tm_philo_must_eat;
}   t_philo;

t_philo *g_philo;

#endif