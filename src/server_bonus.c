/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:58:51 by angerard          #+#    #+#             */
/*   Updated: 2024/07/11 13:37:23 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

/**
 * Signal handler to receive bits from the client.
 * Reconstructs the character from the received bits and prints it.
 * Sends confirmation signal to the client when the full message is received.
 * @param sig The received signal.
 * @param info Signal info structure.
 * @param context Signal context.
 */
void	receive_bit(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	character = 0;

	(void)context;
	if (sig == SIGUSR1)
		character |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (character == 0)
			kill(info->si_pid, SIGUSR2);
		else
			ft_printf("%c", character);
		fflush(stdout);
		bit = 0;
		character = 0;
	}
}

/**
 * Main function for the server_bonus program.
 * Prints the server PID and waits for signals to receive bits.
 * Uses sigaction for signal handling to provide more information.
 * @return 0 on success.
 */
int	main(void)
{
	int					server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	sa.sa_sigaction = receive_bit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
