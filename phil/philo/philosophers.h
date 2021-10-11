/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:05:40 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/11 19:49:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef struct s_philo
{
	int	num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_eat;
}	t_philo;

int	get_non_negative(char *s);
int	usage(void);
int	error(char *s);
long long now();

#endif