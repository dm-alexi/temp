/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:05:40 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/13 20:50:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define TRUE	1
# define FALSE	0
# define STEP	5

typedef struct s_philo
{
	int				num;
	long long		last_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	void			*rules;
}	t_philo;

typedef struct s_rules
{
	long long		ttd;
	long long		tte;
	long long		tts;
	int				number;
	int				meals;
	int				filled;
	int				finish;
	pthread_mutex_t output;
	pthread_mutex_t *forks;
	t_philo			*philos;
	pthread_t		*threads;
}	t_rules;

int	get_microseconds(char *s);
int	usage(void);
int	error(char *s);
long long now();

#endif