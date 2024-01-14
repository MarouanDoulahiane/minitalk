/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:01:55 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/16 14:16:32 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int pid, char *str)
{
	unsigned char	s;
	int				k;
	int				i;

	k = 0;
	while (str[k])
	{
		s = str[k];
		i = 0;
		while (i < 8)
		{
			if (s << i & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(800);
		}
		k++;
	}
}

int	valid_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	message_received(int sig)
{
	(void)sig;
	ft_putstr("\033[1;32mThe message was received\033[0m\n");
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		ft_putstr("\033[1;33mUsage: <pid> <msg>\033[0m\n");
	else
	{
		pid = ft_atoi(av[1]);
		if (pid < 1 || valid_pid(av[1]))
		{
			ft_putstr("\033[1;31mError: wrong `pid`\033[0m\n");
			return (1);
		}
		signal(SIGUSR2, &message_received); 
		handler(pid, av[2]);
		while (i < 8)
		{
			kill(pid, SIGUSR2);
			usleep(800);
			i++;
		}
	}
	return (0);
}
