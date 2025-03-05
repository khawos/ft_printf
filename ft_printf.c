/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:39:33 by amedenec          #+#    #+#             */
/*   Updated: 2024/11/19 01:39:33 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	hexa_adress(unsigned long int nb)
{
	int	index;
	int	total;
	char	*set;
	char	buffer[17];

	set = "0123456789abcdef";
	index = 0;
	total = 0;

	if (nb == 0)
		return (write(1, "(nil)", 5));
	while (nb > 0)
	{
		buffer[index++] = set[nb % 16];
		nb /= 16;
	}
	total += write(1,"0x", 2);
	while (--index >= 0)
		total += write(1, &buffer[index], 1);
	return (total);
}

int	print_str(char *str)
{
	int	total;

	total = 0;
	if (str == NULL)
	{
		total += write(1, "(null)", 6);
		return (total);
	}
	while (*str)
	{
		write(1, &(*str),1);
		total++;
		str++;
	}
	return (total);
}

int	detect_arg(char	c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(args, int));
	else if (c == 's')
		count += print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += putnbr_long(va_arg(args, int));
	else if (c == 'x')
		count += hexa_lowercase(va_arg(args, unsigned int));
	else if (c == 'X')
		count += hexa_uppercase(va_arg(args, unsigned int));
	else if (c == 'u')
		count += putnbr_unsigned(va_arg(args,unsigned int));
	else if (c == 'p')
		count += hexa_adress(va_arg(args, unsigned long int));
	else
		count += write(1, &c, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	total;

	va_start(args, str);
	total = 0;
	while (*str)
	{
		if (*str == '%')
			total += detect_arg(*++str, args);
		else
			total += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (total);
}

/*int	main(void)
{
	void	*str;

	int	a, b;

	a = ft_printf("%s\n", NULL);
	b = printf("%s\n", NULL);
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}*/
