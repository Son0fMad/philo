/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:57:35 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/30 19:03:33 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_all	all;
	int		ret;

	if (ac != 5 && ac != 6)
		return (error_message(RED "Wrong arguments number" RESET));
	ret = init_all(&all, av);
	if (ret)
		return (error_manager(ret));
	if (launcher(&all))
		return (error_message(RED "Threads creating error" RESET));
	return (0);
}
