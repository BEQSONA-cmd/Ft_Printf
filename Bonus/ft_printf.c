/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:16 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 13:48:16 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_next_precent(const char *format, va_list args, int j, int i)
{
	int		width_after;
	int		width_before;
	int		precision;
	int		k;
	int		l;
	char	flags[5];

	l = 0;
	precision = 0;
	width_before = 0;
	width_after = 0;
	k = 0;
	flags[0] = '\0';
	flags[1] = '\0';
	flags[2] = '\0';
	flags[3] = '\0';
	flags[4] = '\0';
	while (format[i] == '-' || format[i] == '+' || format[i] == '0'
		|| format[i] == '#' || format[i] == ' ')
	{
		flags[k] = format[i];
		i++;
		k++;
	}
	if (format[i - 1] == '-' || (format[i - 1] == '0' && format[i - 2] == '-'))
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			width_after = width_after * 10 + (format[i] - '0');
			i++;
		}
	}
	else if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			width_before = width_before * 10 + (format[i] - '0');
			i++;
		}
	}
	if (format[i] == '.')
	{
		i++;
		while (format[i] >= '0' && format[i] <= '9')
		{
			precision = precision * 10 + (format[i] - '0');
			i++;
		}
	}
	if (format[i] == 's')
	{
		if (width_before > 0)
			j = ft_str_width_before(va_arg(args, char *), j, width_before,
					precision);
		else if (width_after > 0)
			j = ft_str_width_after(va_arg(args, char *), j, width_after,
					precision);
		else
			j = ft_str_dot(va_arg(args, char *), j, precision);
	}
	else if (format[i] == 'c')
	{
		if (width_before > 0)
			j = ft_char_width_before(va_arg(args, int), j, width_before);
		else if (width_after > 0)
			j = ft_char_width_after(va_arg(args, int), j, width_after);
		else
			j = ft_char(va_arg(args, int), j);
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		if (width_before > 0)
			j = ft_space_number_before(va_arg(args, int), j, flags[0],
					width_before);
		else if (width_after > 0)
			j = ft_space_number_after(va_arg(args, int), j, flags[0],
					width_after);
		else
			j = ft_num(va_arg(args, int), j, flags[0]);
	}
	else if (format[i] == 'x')
	{
		if (width_before > 0)
			j = ft_hex_width_before(va_arg(args, size_t), j, flags[2],
					width_before);
		else if (width_after > 0)
			j = ft_hex_width_after(va_arg(args, size_t), j, flags[2],
					width_after);
		else
			j = ft_hexl(va_arg(args, size_t), j, flags[2]);
	}
	else if (format[i] == 'X')
	{
		if (width_before > 0)
			j = ft_hexu_width_before(va_arg(args, size_t), j, flags[2],
					width_before);
		else if (width_after > 0)
			j = ft_hexu_width_after(va_arg(args, size_t), j, flags[2],
					width_after);
		else
			j = ft_hexu(va_arg(args, size_t), j, flags[2]);
	}
	else if (format[i] == 'u')
	{
		if (width_before > 0)
			j = ft_uns_width_before(va_arg(args, unsigned int), j,
					width_before);
		else if (width_after > 0)
			j = ft_uns_width_after(va_arg(args, unsigned int), j, width_after);
		else
			j = ft_uns(va_arg(args, unsigned int), j);
	}
	else if (format[i] == 'p')
	{
		if (width_before > 0)
			j = ft_ptr_width_before(va_arg(args, unsigned long), j,
					width_before);
		else if (width_after > 0)
			j = ft_ptr_width_after(va_arg(args, unsigned long), j, width_after);
		else
			j = ft_ptr(va_arg(args, unsigned long), j);
	}
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
		if (a[i] == '%')
		{
			save = i;
			i++;
			if (a[save + 1] == '+' || a[save + 1] == ' ' || a[save + 1] == '#'
				|| a[save + 1] == '.' || a[save + 1] == '-' || (a[save
					+ 1] >= '0' && a[save + 1] <= '9'))
			{
				while (a[save] != 's' && a[save] != 'c' && a[save] != 'd'
					&& a[save] != 'i' && a[save] != 'u' && a[save] != 'x'
					&& a[save] != 'X' && a[save] != 'p')
				{
					save++;
					k++;
				}
				k--;
			}
			j = ft_next_precent(a, args, j, i);
		}
		else
		{
			while (k > 0)
			{
				k--;
				i++;
			}
			write(1, &a[i], 1);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}
