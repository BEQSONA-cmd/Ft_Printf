/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:14:16 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 22:21:24 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	i = n;
	if (c == ' ' || c == '+')
		len = ft_numlen(i) + 1;
	else
		len = ft_numlen(i);
	x = flags.width;
	if (flags.precision > 0)
	{
		x = flags.precision;
		flags.fill = '0';
		if (i < 0)
			len--;
	}
	if (i < 0 && flags.fill == '0')
	{
		j = ft_char('-', j);
		j = ft_print_space(x - len, j, flags.fill);
		j = ft_num_p(i, j, c);
	}
	else
	{
		j = ft_print_space(x - len, j, flags.fill);
		j = ft_num(i, j, c);
	}
	return (j);
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
