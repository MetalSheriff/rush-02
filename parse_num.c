/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:41:22 by obritany          #+#    #+#             */
/*   Updated: 2020/09/27 18:24:36 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	parse_one(char *str, int pos)
{
	print_value(DIGITS, (str[0] - '0'));
	print_power(pos);
}

void	parse_two(char *str, int pos)
{
	if (str[0] == '0' && str[1] == '0')
	{
		print_power(pos);
		return ;
	}
	if (str[0] == '0')
	{
		parse_one((str + 1), (pos - 1));
		return ;
	}
	if (str[0] == '1')
		print_value(DIGITS, (10 + (str[1] - '0')));
	else
	{
		print_value(DECIMAL, (str[0] - '0'));
		if (str[1] != '0')
			print_value(DIGITS, (str[1] - '0'));
	}
	print_power(pos);
}

void	parse_three(char *str, int pos)
{
	if (str[0] == '0' && str[1] == '0' && str[2] == '0')
		return ;
	if (str[0] == '0')
	{
		parse_two((str + 1), (pos - 1));
		return ;
	}
	parse_one(str, 3);
	parse_two(str + 1, pos - 1);
}

int		get_step(int mod)
{
	int rslt;

	if (mod == 1)
		rslt = 1;
	if (mod == 2)
		rslt = 2;
	if (mod == 0)
		rslt = 3;
	return (rslt);
}

void	parse_num(char *str)
{
	int pos;
	int mod;

	print_control();
	while (*str == '0' && *(str + 1) != 0)
		str = str + 1;
	pos = 0;
	pos = ft_strlen(str);
	while (pos > 0)
	{
		mod = pos % 3;
		if (mod == 1)
			parse_one(str, pos);
		if (mod == 2)
			parse_two(str, pos);
		if (mod == 0)
			parse_three(str, pos);
		str = str + get_step(mod);
		pos = pos - get_step(mod);
	}
	print_newline();
}
