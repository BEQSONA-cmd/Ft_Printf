/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:31:55 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/16 13:43:39 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_numlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_space(int size, int j, char c)
{
	while (size > 0)
	{
		j = ft_char(c, j);
		size--;
	}
	return (j);
}

int	ft_handle_input(char c, va_list args, int j, t_flags flags)
{
	if (c == 's')
		j = handle_format_s(args, j, flags);
	else if (c == 'c')
		j = handle_format_c(args, j, flags);
	else if (c == 'd' || c == 'i')
		j = handle_format_d(args, j, flags);
	else if (c == 'x')
		j = handle_format_x(args, j, flags);
	else if (c == 'X')
		j = handle_format_xu(args, j, flags);
	else if (c == 'u')
		j = handle_format_u(args, j, flags);
	else if (c == 'p')
		j = handle_format_p(args, j, flags);
	else if (c == '%')
		j = ft_char('%', j);
	return (j);
}

t_flags	init_flags(const char *format, int i)
{
	t_flags	flags;

	flags.precision = 0;
	flags.width_before = 0;
	flags.width_after = 0;
	flags.fill = ' ';
	flags.width = 0;
	flags.flags_number = 0;
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
		flags.flags[flags.flags_number] = format[i];
		i++;
		flags.flags_number++;
	}
	return (flags);
}
