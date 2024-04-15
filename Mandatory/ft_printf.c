/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:08:41 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 22:53:23 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c, int i)
{
	i++;
	write(1, &c, 1);
	return (i);
}

int	ft_str(char *a, int i)
{
	int	j;

	j = 0;
	if (!a)
	{
		i = ft_str("(null)", i);
	}
	else
	{
		while (a[j])
		{
			write(1, &a[j], 1);
			j++;
			i++;
		}
	}
	return (i);
}

int	ft_num(int n, int i)
{
	if (n == -2147483648)
	{
		i = ft_char('-', i);
		i = ft_char('2', i);
		i = ft_num(147483648, i);
	}
	else if (n < 0)
	{
		i = ft_char('-', i);
		n = -n;
		i = ft_num(n, i);
	}
	else if (n >= 10)
	{
		i = ft_num((n / 10), i);
		i = ft_num((n % 10), i);
	}
	else
	{
		i = ft_char(((n % 10) + '0'), i);
	}
	return (i);
}

int	ft_next_precent(const char *format, va_list args, int j, int i)
{
	if (format[i] == 's')
		j = ft_str(va_arg(args, char *), j);
	if (format[i] == 'c')
		j = ft_char(va_arg(args, int), j);
	if (format[i] == 'd')
		j = ft_num(va_arg(args, int), j);
	if (format[i] == 'i')
		j = ft_num(va_arg(args, int), j);
	if (format[i] == 'x')
		j = ft_hexl(va_arg(args, int), j);
	if (format[i] == 'X')
		j = ft_hexu(va_arg(args, int), j);
	if (format[i] == '%')
		j = ft_char('%', j);
	if (format[i] == 'u')
		j = ft_uns(va_arg(args, int), j);
	if (format[i] == 'p')
		j = ft_ptr(va_arg(args, unsigned int), j);
	return (j);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, a);
	while (a[i] != '\0')
	{
		if (a[i] == '%')
			j = ft_next_precent(a, args, j, ++i);
		else
		{
			j++;
			write(1, &a[i], 1);
		}
		i++;
	}
	va_end(args);
	return (j);
}
