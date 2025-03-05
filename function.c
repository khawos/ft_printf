/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:20:03 by amedenec          #+#    #+#             */
/*   Updated: 2024/11/19 04:20:03 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	hexa_lowercase(unsigned int nb)
{
	char	*set;
	char	num;
	int	total;

	total = 0;
	set = "0123456789abcdef";
	if (nb >= 16)
		total += hexa_lowercase(nb / 16);
	num = set[nb % 16];
	total += write(1, &num,1);
	return (total);
}

int	hexa_uppercase(unsigned int nb)
{
	char	*set;
	char	num;
	int	total;

	total = 0;
	set = "0123456789ABCDEF";
	if (nb >= 16)
		total += hexa_uppercase(nb / 16);
	num = set[nb % 16];
	total += write(1, &num,1);
	return (total);
}

int	putnbr_unsigned(unsigned int n)
{
	char	c;
	int	total;

	total = 0;
	if (n > 9)
		total += putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	total += write(1, &c, 1);
	return (total);
}

int	putnbr_long(int n)
{
	char	c;
	int	total;

	total = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		total++;
		n = -n;
	}
	if (n > 9)
	{
		total += putnbr_long(n / 10);
	}
	c = (n % 10) + '0';
	total += write(1, &c, 1);
	return (total);
}

int	print_char(int c)
{
	write(1, &c,1);
	return (1);
}


/*int	main(void)
{
	unsigned int	dest;

	dest = 4294967295;
	printf("le vrai: %u\n", dest);
	putnbr_long(dest);
	return (0);
}*/
