/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:03:43 by fdi-tria          #+#    #+#             */
/*   Updated: 2024/10/26 13:56:54 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	return (ret);
}

int	ft_putstr(char *str)
{
	int	count;
	int	ret;

	count = 0;
	if (str == NULL)
	{
		ret = write(1, "(null)", 6);
		if (ret == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		ret = ft_putchar(*str);
		if (ret == -1)
			return (-1);
		count += ret;
		str++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int		count;
	int		ret;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		count += ret;
		num = -num;
	}
	if (num >= 10)
	{
		ret = ft_putnbr(num / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((num % 10) + '0');
	if (ret == -1)
		return (-1);
	return (count += ret);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putunsigned(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_puthex(unsigned long n, int uppercase)
{
	int		count;
	int		ret;
	char	*hex_digits;

	count = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		ret = ft_puthex(n / 16, uppercase);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(hex_digits[n % 16]);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

