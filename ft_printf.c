/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:12:13 by fdi-tria          #+#    #+#             */
/*   Updated: 2024/10/26 14:15:18 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex((unsigned long)ptr, 0);
	}
	return (count);
}

int	handle_conversion(char specifier, va_list *args)
{
	int	count;

	count = 0;
	if (specifier == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (specifier == 'u')
		count += ft_putunsigned(va_arg(*args, unsigned int));
	else if (specifier == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (specifier == 'p')
		count += handle_pointer(va_arg(*args, void *));
	else if (specifier == 'x')
		count += ft_puthex((unsigned long)va_arg(*args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_puthex((unsigned long)va_arg(*args, unsigned int), 1);
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_conversion(*format, &args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
