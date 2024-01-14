/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:24:57 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/16 14:13:53 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + 48);
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	a = b;
	i = 0;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	signal;

	nb = 0;
	i = 0;
	signal = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		nb = nb * 10 + str[i++] - 48;
	return (nb * signal);
}
