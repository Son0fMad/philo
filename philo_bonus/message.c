/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:02:06 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/30 19:02:29 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_print(t_all *all, int id, char *str)
{
	sem_wait(all->message);
	if (!(all->dead))
	{
		printf(WHT "%lli ", timestamp() - all->time_start);
		printf(WHT "%i ", id + 1);
		printf(RED "%s\n", str);
	}
	sem_post(all->message);
	return ;
}

int	error_message(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, MAG "Error" RESET, 5);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (error_message(RED "At least one wrong argument" RESET));
	if (error == 2)
		return (error_message(RED "Semaphore initialisation error" RESET));
	return (1);
}
