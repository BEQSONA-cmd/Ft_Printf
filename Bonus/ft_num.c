/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:14:16 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/16 18:37:16 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num(int n, int j, char c)
{
	if ((c == ' ' || c == '+') && n >= 0)
		j = ft_char(c, j);
	if (n == -2147483648)
	{
		j = ft_char('-', j);
		j = ft_char('2', j);
		j = ft_num(147483648, j, '\0');
	}
	else if (n < 0)
	{
		j = ft_char('-', j);
		n = -n;
		j = ft_num(n, j, '\0');
	}
	else if (n >= 10)
	{
		j = ft_num(n / 10, j, '\0');
		j = ft_num(n % 10, j, '\0');
	}
	else
		j = ft_char((n % 10) + '0', j);
	return (j);
}

int	ft_num_p(int n, int j, char c)
{
	if ((c == ' ' || c == '+') && n >= 0)
		j = ft_char(c, j);
	if (n == -2147483648)
	{
		j = ft_char('2', j);
		j = ft_num(147483648, j, '\0');
	}
	else if (n < 0)
	{
		n = -n;
		j = ft_num(n, j, '\0');
	}
	else if (n >= 10)
	{
		j = ft_num(n / 10, j, '\0');
		j = ft_num(n % 10, j, '\0');
	}
	else
		j = ft_char((n % 10) + '0', j);
	return (j);
}

int	ft_space_number_before(int n, int j, char c, t_flags flags)
{
	int	i;
	int	x;
	int	len;

	len = ft_numlen((i = n));
	if ((c == ' ' || c == '+') && i >= 0)
		len++;
	x = flags.width;
	if (flags.precision > 0 && flags.precision >= len)
	{
		x = flags.precision;
		flags.fill = '0';
		if (i < 0)
			len--;
	}
	if (i < 0 && flags.fill == '0')
	{
		j = ft_print_space(flags.width - (x + 1), j, ' ');
		j = ft_char('-', j);
		j = ft_print_space(x - len, j, flags.fill);
		return (j = ft_num_p(i, j, c));
	}
	j = ft_print_space(flags.width - x, j, ' ');
	j = ft_print_space(x - len, j, flags.fill);
	return (j = ft_num(i, j, c));
}

int	ft_space_number_after(int n, int j, char c, int width)
{
	int	i;
	int	len;

	i = n;
	if (c == ' ' || c == '+')
		len = ft_numlen(i) + 1;
	else
		len = ft_numlen(i);
	j = ft_num(i, j, c);
	j = ft_print_space(width - len, j, ' ');
	return (j);
}

int	handle_format_d(va_list args, int j, t_flags flags)
{
	if (flags.width_before > 0 || flags.precision > 0)
		j = ft_space_number_before(va_arg(args, int), j, flags.flags[0], flags);
	else if (flags.width_after > 0)
		j = ft_space_number_after(va_arg(args, int), j, flags.flags[0],
				flags.width_after);
	else
		j = ft_num(va_arg(args, int), j, flags.flags[0]);
	return (j);
}
