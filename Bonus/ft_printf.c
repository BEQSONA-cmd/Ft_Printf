/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:16 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/16 18:38:51 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_handle_minus_or_zero(const char *format, int i, t_flags flags)
{
	if (format[i - 1] == '-')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			flags.width_after = flags.width_after * 10 + (format[i] - '0');
			flags.flags_number++;
			i++;
		}
		flags.width = flags.width_after;
	}
	else if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			flags.width_before = flags.width_before * 10 + (format[i] - '0');
			flags.flags_number++;
			i++;
		}
		flags.width = flags.width_before;
	}
	return (flags);
}

int	ft_next_precent(const char *format, va_list args, int j, int i)
{
	int		l;
	t_flags	flags;

	l = 0;
	flags = init_flags(format, i);
	i = i + flags.flags_number;
	flags.flags_number = 0;
	flags = ft_handle_minus_or_zero(format, i, flags);
	i = i + flags.flags_number;
	flags.flags_number = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] < '0' || format[i] > '9')
			flags.precision = -1;
		while (format[i] >= '0' && format[i] <= '9')
		{
			flags.precision = flags.precision * 10 + (format[i] - '0');
			i++;
		}
	}
	j = ft_handle_input(format[i], args, j, flags);
	return (j);
}

t_print	ft_print(const char *a, va_list args, t_print print)
{
	int	k;
	int	save;

	save = 0;
	k = 0;
	if (a[print.i - 1] != '%' || a[print.i] == '%')
		print.i++;
	save = print.i;
	if (a[save] == '+' || a[save] == ' ' || a[save] == '#' || a[save] == '.'
		|| a[save] == '-' || (a[save] >= '0' && a[save] <= '9'))
	{
		while (a[save] != 's' && a[save] != 'c' && a[save] != 'd'
			&& a[save] != 'i' && a[save] != 'u' && a[save] != 'x'
			&& a[save] != 'X' && a[save] != 'p')
		{
			save++;
			k++;
		}
	}
	print.j = ft_next_precent(a, args, print.j, print.i);
	print.i = print.i + k;
	return (print);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	t_print	print;

	print.i = 0;
	print.j = 0;
	va_start(args, a);
	while (a[print.i] != '\0')
	{
		if (a[print.i] == '%' || (a[print.i - 1] == '%' && a[print.i] != ' '))
			print = ft_print(a, args, print);
		else
		{
			if (a[print.i] == '\0')
				break ;
			else if (a[print.i] != '%' || a[print.i] == ' ')
				print.j = ft_char(a[print.i], print.j);
		}
		print.i++;
	}
	va_end(args);
	return (print.j);
}
