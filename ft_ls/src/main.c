/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:24:40 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/20 01:40:51 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_param	param;
	t_list	*files;

	ft_bzero(&param, sizeof(param));
	files = input(ac, av, &param);
	(void)files;
	return (0);
}
