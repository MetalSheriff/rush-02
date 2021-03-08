/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obritany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:37:50 by obritany          #+#    #+#             */
/*   Updated: 2020/09/27 18:25:35 by obritany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <unistd.h>
# include <fcntl.h>

# define DIGITS   1
# define DECIMAL  2
# define POWER    3

# define PRNT_MIN 32
# define PRNT_MAX 126

char	*g_dig_key[20];
char	*g_dec_key[10];
char	*g_pow_key[13];

char	g_dig_val[20][1024];
char	g_dec_val[10][1024];
char	g_pow_val[13][1024];

int		make_dict(char *file_name);
int		read_file(int file_desc);
void	parse_num(char *str);
char	ft_putstr(char *str);
int		ft_strlen(char *str);
char	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);

void	print_control(void);
void	print_newline(void);
void	print_space(void);
void	print_value(int table, int index);
void	print_power(int pos);
#endif
