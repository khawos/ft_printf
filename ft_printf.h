/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:08:31 by amedenec          #+#    #+#             */
/*   Updated: 2024/11/20 13:08:31 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H
# include <stdio.h>
# include <unistd.h>

int	hexa_lowercase(unsigned int nb);

int	hexa_uppercase(unsigned int nb);

int	putnbr_unsigned(unsigned int n);

int	putnbr_long(unsigned int n);

int	print_char(int c);

int	hexa_adress(unsigned long int nb);

int	ft_printf(const char *str, ...);

int	detect_arg(char c, va_list args);

int	print_str(char *str);


#endif
