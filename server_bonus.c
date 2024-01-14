/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:01:35 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/14 17:18:06 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mini_helper(t_data *data)
{
	if (data->c >= 240)
		data->is_unicode = 4;
	else if (data->c >= 224)
		data->is_unicode = 3;
	else if (data->c >= 192)
		data->is_unicode = 2;
	if (data->is_unicode && data->is_unicode - data->i >= 1)
	{
		ft_memset((unsigned char *)&data->s + data->i, data->c, 1);
		data->i++;
	}
	if (data->is_unicode && data->is_unicode == data->i)
	{
		write(1, &data->s, data->is_unicode);
		data->is_unicode = 0;
		data->i = 0;
	}
	else if (!data->is_unicode)
		write(1, &data->c, 1);
	data->c = 0;
	data->counter = 0;
}

void	helper(t_data *data, siginfo_t *info)
{
	if (data->counter == 8)
	{
		if (!data->c)
			kill(info->si_pid, SIGUSR2);
		else
			mini_helper(data);
	}
}

void	handle_signales(int sig, siginfo_t *info, void *context)
{
	static t_data	data;

	(void)context;
	if (data.pid != info->si_pid)
	{
		data.pid = 0;
		data.c = 0;
		data.s = 0;
		data.i = 0;
		data.is_unicode = 0;
		data.counter = 0;
		data.pid = info->si_pid;
	}
	data.c <<= 1;
	if (sig == SIGUSR1)
		data.c = data.c | 1;
	data.counter++;
	helper(&data, info);
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
