#include "minitalk.h"

void	send_signal(int pid, char *message)
{
	unsigned char c;
	int bit;
	while (*message )
	{
		c = *(message);
		bit = 0;
		while (bit < 8)
		{
			if (c << bit & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			bit++;
		}
		message++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
		exit(1);
	}
	send_signal(atoi(av[1]), av[2]);
	return (0);
}