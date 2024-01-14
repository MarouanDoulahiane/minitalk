/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:59:07 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/16 14:13:05 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

typedef struct data
{
	int				counter;
	unsigned char	c;
	int				s;
	int				pid;
	int				is_unicode;
	int				i;
}	t_data;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	*ft_memset(void *b, int c, size_t len);

int		ft_atoi(const char *str);

#endif 
