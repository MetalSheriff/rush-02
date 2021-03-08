/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:41:59 by obritany          #+#    #+#             */
/*   Updated: 2020/09/27 20:24:35 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*set_value(char *key, char *val)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (ft_strcmp(key, g_dig_key[i]) == 0)
			return (ft_strcpy(g_dig_val[i], val));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (ft_strcmp(key, g_dec_key[i]) == 0)
			return (ft_strcpy(g_dec_val[i], val));
		i++;
	}
	i = 0;
	while (i < 13)
	{
		if (ft_strcmp(key, g_pow_key[i]) == 0)
			return (ft_strcpy(g_pow_val[i], val));
		i++;
	}
	return (0);
}

void	skip_space(int file_desc, char *chr)
{
	while (*chr == ' ')
	{
		if (read(file_desc, chr, 1) <= 0)
			break ;
	}
}

void	read_key(int file_desc, char *chr, char *key)
{
	int i;

	i = 0;
	while (*chr >= '0' && *chr <= '9')
	{
		key[i] = *chr;
		i++;
		if (read(file_desc, chr, 1) <= 0)
			break ;
	}
	key[i] = 0;
}

void	read_val(int file_desc, char *chr, char *val)
{
	int i;

	i = 0;
	while (*chr >= PRNT_MIN && *chr <= PRNT_MAX)
	{
		val[i] = *chr;
		i++;
		if (read(file_desc, chr, 1) <= 0)
			break ;
		if (val[i - 1] == ' ')
			skip_space(file_desc, chr);
	}
	if (val[i - 1] == ' ')
		val[i - 1] = 0;
	val[i] = 0;
}

int		read_file(int file_desc)
{
	char chr;
	char key[1024];
	char val[1024];

	while (read(file_desc, &chr, 1) > 0)
	{
		if (chr == '\n')
			continue ;
		read_key(file_desc, &chr, key);
		skip_space(file_desc, &chr);
		if (chr != ':')
			return (0);
		read(file_desc, &chr, 1);
		skip_space(file_desc, &chr);
		read_val(file_desc, &chr, val);
		if (ft_strlen(key) == 0 || ft_strlen(val) == 0)
			return (0);
		set_value(key, val);
	}
	return (1);
}
