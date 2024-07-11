/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:03:15 by angerard          #+#    #+#             */
/*   Updated: 2024/07/11 13:45:43 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/**
 * Signal handler to receive bits from the client.
 * Reconstructs the character from the received bits and prints it.
 * @param sig The received signal.
 */
void	receive_bit(int sig)
{
	static int	bit = 0;
	static int	character = 0;

	if (sig == SIGUSR1)
		character |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", character);
		fflush(stdout);
		bit = 0;
		character = 0;
	}
}

/**
 * Main function for the server program.
 * Prints the server PID and waits for signals to receive bits.
 * @return 0 on success.
 */
int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	while (1)
		pause();
	return (0);
}
