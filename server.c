/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:58:51 by mbaj              #+#    #+#             */
/*   Updated: 2024/07/11 13:59:24 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	read_signal(int signum)
{
	static int	i;
	static int	character;

	if (signum == SIGUSR1)
	{
		character |= (1 << i);
		i++;
	}
	else if (signum == SIGUSR2)
	{
		character |= (0 << i);
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", character);
		i = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
	}
	pid = getpid();
	ft_printf("pid : %d\n", pid);
	signal(SIGUSR1, read_signal);
	signal(SIGUSR2, read_signal);
	while (1)
	{
	}
	return (0);
}
