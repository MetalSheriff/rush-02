/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:00:04 by obritany          #+#    #+#             */
/*   Updated: 2020/09/27 18:25:08 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	g_last_char;

void	print_newline(void)
{
	ft_putstr("\n");
	g_last_char = '\n';
}

void	print_space(void)
{
	if (g_last_char != ' ' && g_last_char != '\n')
		ft_putstr(" ");
}

void	print_value(int table, int index)
{
	print_space();
	if (table == DIGITS)
		g_last_char = ft_putstr(g_dig_val[index]);
	if (table == DECIMAL)
		g_last_char = ft_putstr(g_dec_val[index]);
}

void	print_power(int pos)
{
	int index;

	if (pos > 2)
	{
		print_space();
		index = (pos - 1) / 3;
		g_last_char = ft_putstr(g_pow_val[index]);
	}
}

void	print_control(void)
{
	g_last_char = '\n';
}
