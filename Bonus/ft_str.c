/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:59:46 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 21:26:04 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_dot(char *s, int j, int precision)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	if (precision == 0)
		precision = ft_strlen(s);
	if (precision < 0)
		precision = 0;
	while (s[i] != '\0' && i < precision)
	{
		j = ft_char(s[i], j);
		i++;
	}
	return (j);
}

int	ft_str_width_before(char *s, int j, t_flags flags, int precision)
{
	int	i;
	int	k;
	int	x;

	i = 0;
	k = 0;
	if (!s)
		s = "(null)";
	if (precision == 0)
		x = ft_strlen(s);
	else if (precision < 0)
		x = 0;
	else
		x = precision;
	j = ft_print_space(flags.width_before - x, j, flags.fill);
	while (s[i] != '\0' && i < x)
	{
		j = ft_char(s[i], j);
		i++;
	}
	return (j);
}

int	ft_str_width_after(char *s, int j, int width_after, int precision)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	if (precision == 0)
		precision = ft_strlen(s);
	if (precision < 0)
		precision = 0;
	while (s[i] != '\0' && i < precision)
	{
		j = ft_char(s[i], j);
		i++;
	}
	j = ft_print_space(width_after - i, j, ' ');
	return (j);
}

int	ft_str(char *s, int j)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		j = ft_char(s[i], j);
		i++;
	}
	return (j);
}
