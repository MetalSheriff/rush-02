/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:14:27 by obritany          #+#    #+#             */
/*   Updated: 2020/09/27 20:17:29 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	check_input(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		if (i > 38)
		{
			ft_putstr("Dict Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int rslt;
	int check;

	rslt = 0;
	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error: Wrong number of arguments\n");
		return (0);
	}
	check = check_input(argv[argc - 1]);
	if (check == 1)
	{
		if (argc == 2)
			rslt = make_dict("numbers.dict");
		else if (argc == 3)
			rslt = make_dict(argv[1]);
		if (rslt)
			parse_num(argv[argc - 1]);
		else
			ft_putstr("Dict Error\n");
	}
	return (0);
}
