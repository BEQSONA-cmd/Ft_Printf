/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:16 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 22:16:23 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_next_precent(const char *format, va_list args, int j, int i)
{
	int		k;
	int		l;
	t_flags	flags;

	l = 0;
	flags.precision = 0;
	flags.width_before = 0;
	flags.width_after = 0;
	flags.fill = ' ';
	flags.width = 0;
	k = 0;
	flags.flags[0] = '\0';
	flags.flags[1] = '\0';
	flags.flags[2] = '\0';
	flags.flags[3] = '\0';
	flags.flags[4] = '\0';
	if (format[i] == '0')
		flags.fill = '0';
	while (format[i] == '-' || format[i] == '+' || format[i] == '0'
		|| format[i] == '#' || format[i] == ' ')
	{
		flags.flags[k] = format[i];
		i++;
		k++;
	}
	if (format[i - 1] == '-')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			flags.width_after = flags.width_after * 10 + (format[i] - '0');
			i++;
		}
		flags.width = flags.width_after;
	}
	else if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			flags.width_before = flags.width_before * 10 + (format[i] - '0');
			i++;
		}
		flags.width = flags.width_before;
	}
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
	if (format[i] == 's')
	{
		if (flags.width_before > 0)
			j = ft_str_width_before(va_arg(args, char *), j, flags,
					flags.precision);
		else if (flags.width_after > 0)
			j = ft_str_width_after(va_arg(args, char *), j, flags.width_after,
					flags.precision);
		else
			j = ft_str_dot(va_arg(args, char *), j, flags.precision);
	}
	else if (format[i] == 'c')
	{
		if (flags.width_before > 0)
			j = ft_char_width_before(va_arg(args, int), j, flags);
		else if (flags.width_after > 0)
			j = ft_char_width_after(va_arg(args, int), j, flags.width_after);
		else
			j = ft_char(va_arg(args, int), j);
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		if (flags.width_before > 0 || flags.precision > 0)
			j = ft_space_number_before(va_arg(args, int), j, flags.flags[0],
					flags);
		else if (flags.width_after > 0)
			j = ft_space_number_after(va_arg(args, int), j, flags.flags[0],
					flags.width_after);
		else
			j = ft_num(va_arg(args, int), j, flags.flags[0]);
	}
	else if (format[i] == 'x')
	{
		if (flags.width_before > 0 || flags.precision > 0)
			j = ft_hex_width_before(va_arg(args, size_t), j, flags.flags[0],
					flags);
		else if (flags.width_after > 0)
			j = ft_hex_width_after(va_arg(args, size_t), j, flags.flags[0],
					flags.width_after);
		else
			j = ft_hexl(va_arg(args, size_t), j, flags.flags[0]);
	}
	else if (format[i] == 'X')
	{
		if (flags.width_before > 0 || flags.precision > 0)
			j = ft_hexu_width_before(va_arg(args, size_t), j, flags.flags[0],
					flags);
		else if (flags.width_after > 0)
			j = ft_hexu_width_after(va_arg(args, size_t), j, flags.flags[0],
					flags.width_after);
		else
			j = ft_hexu(va_arg(args, size_t), j, flags.flags[0]);
	}
	else if (format[i] == 'u')
	{
		if (flags.width_before > 0 || flags.precision > 0)
			j = ft_uns_width_before(va_arg(args, unsigned int), j, flags);
		else if (flags.width_after > 0)
			j = ft_uns_width_after(va_arg(args, unsigned int), j,
					flags.width_after);
		else
			j = ft_uns(va_arg(args, unsigned int), j);
	}
	else if (format[i] == 'p')
	{
		if (flags.width_before > 0)
			j = ft_ptr_width_before(va_arg(args, unsigned long), j, flags);
		else if (flags.width_after > 0)
			j = ft_ptr_width_after(va_arg(args, unsigned long), j,
					flags.width_after);
		else
			j = ft_ptr(va_arg(args, unsigned long), j);
	}
	else if (format[i] == '%')
		j = ft_char('%', j);
	return (j);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		save;
	int		k;

	k = 0;
	save = 0;
	i = 0;
	j = 0;
	va_start(args, a);
	while (a[i] != '\0')
	{
		if (a[i] == '%' || (a[i - 1] == '%' && a[i] != ' '))
		{
			if (a[i - 1] != '%' || a[i] == '%')
				i++;
			save = i;
			if (a[save] == '+' || a[save] == ' ' || a[save] == '#'
				|| a[save] == '.' || a[save] == '-' || (a[save] >= '0'
					&& a[save] <= '9'))
			{
				while (a[save] != 's' && a[save] != 'c' && a[save] != 'd'
					&& a[save] != 'i' && a[save] != 'u' && a[save] != 'x'
					&& a[save] != 'X' && a[save] != 'p')
				{
					save++;
					k++;
				}
			}
			j = ft_next_precent(a, args, j, i);
		}
		else
		{
			while (k > 0)
			{
				i++;
				k--;
			}
			if (a[i] == '\0')
				break ;
			else if (a[i] != '%' || a[i] == ' ')
				j = ft_char(a[i], j);
		}
		i++;
	}
	va_end(args);
	return (j);
}
