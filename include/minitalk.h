/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:03:56 by angerard          #+#    #+#             */
/*   Updated: 2024/07/11 11:25:52 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	send_char_as_bits(int pid, char c);
void	receive_bit(int sig);

#endif
