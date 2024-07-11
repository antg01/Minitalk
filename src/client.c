/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:02:47 by angerard          #+#    #+#             */
/*   Updated: 2024/07/11 13:35:48 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/**
 * Converts a string to an integer.
 * Handles optional leading whitespaces, plus/minus signs, and digits.
 * @param str The input string to convert.
 * @return The converted integer.
 */
int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

/**
 * Sends a character to the server as a series of bits using signals.
 * Sends SIGUSR1 for bit 1 and SIGUSR2 for bit 0.
 * @param pid The process ID of the server.
 * @param character The character to send.
 */
void	send_char_as_bits(int pid, char character)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((character & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

/**
 * Main function for the client program.
 * Takes server PID and a message string as arguments.
 * Converts the message to bits and sends it to the server.
 * @param argc Number of arguments.
 * @param argv Argument vector.
 * @return 0 on success, 1 on error.
 */
int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char_as_bits(server_pid, argv[2][i]);
			i++;
		}
		send_char_as_bits(server_pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
