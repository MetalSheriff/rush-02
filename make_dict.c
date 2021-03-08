/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:40:45 by obritany          #+#    #+#             */
/*   Updated: 2020/09/27 17:48:55 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*g_dig_key[20];
char	*g_dec_key[10];
char	*g_pow_key[13];

char	g_dig_val[20][1024];
char	g_dec_val[10][1024];
char	g_pow_val[13][1024];

void	create_digit(void)
{
	g_dig_key[0] = "0";
	g_dig_key[1] = "1";
	g_dig_key[2] = "2";
	g_dig_key[3] = "3";
	g_dig_key[4] = "4";
	g_dig_key[5] = "5";
	g_dig_key[6] = "6";
	g_dig_key[7] = "7";
	g_dig_key[8] = "8";
	g_dig_key[9] = "9";
	g_dig_key[10] = "10";
	g_dig_key[11] = "11";
	g_dig_key[12] = "12";
	g_dig_key[13] = "13";
	g_dig_key[14] = "14";
	g_dig_key[15] = "15";
	g_dig_key[16] = "16";
	g_dig_key[17] = "17";
	g_dig_key[18] = "18";
	g_dig_key[19] = "19";
}

void	create_decimal(void)
{
	g_dec_key[0] = "";
	g_dec_key[1] = "";
	g_dec_key[2] = "20";
	g_dec_key[3] = "30";
	g_dec_key[4] = "40";
	g_dec_key[5] = "50";
	g_dec_key[6] = "60";
	g_dec_key[7] = "70";
	g_dec_key[8] = "80";
	g_dec_key[9] = "90";
}

void	create_power(void)
{
	g_pow_key[0] = "100";
	g_pow_key[1] = "1000";
	g_pow_key[2] = "1000000";
	g_pow_key[3] = "1000000000";
	g_pow_key[4] = "1000000000000";
	g_pow_key[5] = "1000000000000000";
	g_pow_key[6] = "1000000000000000000";
	g_pow_key[7] = "1000000000000000000000";
	g_pow_key[8] = "1000000000000000000000000";
	g_pow_key[9] = "1000000000000000000000000000";
	g_pow_key[10] = "1000000000000000000000000000000";
	g_pow_key[11] = "1000000000000000000000000000000000";
	g_pow_key[12] = "1000000000000000000000000000000000000";
}

int		make_dict(char *file_name)
{
	int i;
	int file_desc;
	int rslt;

	rslt = 0;
	create_digit();
	create_decimal();
	create_power();
	i = 0;
	while (i < 20)
		g_dig_val[i++][0] = 0;
	i = 0;
	while (i < 10)
		g_dec_val[i++][0] = 0;
	i = 0;
	while (i < 13)
		g_pow_val[i++][0] = 0;
	if ((file_desc = open(file_name, O_RDONLY)) != -1)
	{
		rslt = read_file(file_desc);
		close(file_desc);
	}
	return (rslt);
}
