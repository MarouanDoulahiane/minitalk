/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:01:55 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/16 14:14:05 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int pid, char c)
{
	unsigned char	s;
	int				i;

	i = 0;
	s = c;
	while (i < 8)
	{
		if (s << i & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(800);
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

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("\033[1;33mUsage: <pid> <msg>\033[0m\n");
	}
	else
	{
		pid = ft_atoi(av[1]);
		if (pid < 1 || valid_pid(av[1]))
		{
			ft_putstr("\033[1;31mError: wrong `pid`\033[0m\n");
			return (1);
		}
		while (av[2][i])
		{
			handler(pid, av[2][i]);
			i++;
		}
	}
	return (0);
}
