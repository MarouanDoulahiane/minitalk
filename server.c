/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:01:35 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/16 14:14:35 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signales(int sig, siginfo_t *info, void *context)
{
	static int		counter;
	static char		c;
	static int		pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = 0;
		c = 0;
		counter = 0;
		pid = info->si_pid;
	}
	c <<= 1;
	if (sig == SIGUSR1)
		c = c | 1;
	counter++;
	if (counter == 8)
	{
		write(1, &c, 1);
		c = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("server pid: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_sigaction = &handle_signales;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
