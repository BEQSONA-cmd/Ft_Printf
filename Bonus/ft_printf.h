/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:19 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/16 13:51:31 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	int		i;
	int		j;
}			t_print;

typedef struct s_flags
{
	int		width_before;
	int		flags_number;
	int		width_after;
	int		precision;
	char	flags[5];
	int		width;
	char	fill;
}			t_flags;

int			ft_str(char *a, int i);
int			ft_str_dot(char *s, int j, int precision);
int			handle_format_s(va_list args, int j, t_flags flags);
int			ft_str_width_before(char *s, int j, t_flags flags, int precision);
int			ft_str_width_after(char *s, int j, int width_after, int precision);

int			ft_char(char c, int i);
int			ft_char_width_before(char c, int j, t_flags flags);
int			ft_char_width_after(char c, int j, int width_after);
int			handle_format_c(va_list args, int j, t_flags flags);

int			ft_numlen(long n);
int			ft_num(int n, int j, char c);
int			handle_format_d(va_list args, int j, t_flags flags);
int			ft_space_number_after(int n, int j, char c, int width);
int			ft_space_number_before(int n, int j, char c, t_flags flags);

int			ft_hexlen(long n);
int			ft_hexl(size_t n, int i, char c);
int			handle_format_x(va_list args, int j, t_flags flags);
int			ft_hex_width_before(size_t n, int j, char c, t_flags flags);
int			ft_hex_width_after(size_t n, int j, char c, int width_after);

int			ft_hexu(size_t n, int i, char c);
int			handle_format_xu(va_list args, int j, t_flags flags);
int			ft_hexu_width_before(size_t n, int j, char c, t_flags flags);
int			ft_hexu_width_after(size_t n, int j, char c, int width_after);

int			ft_unslen(long n);
int			ft_uns(unsigned int n, int i);
int			handle_format_u(va_list args, int j, t_flags flags);
int			ft_uns_width_before(unsigned int n, int j, t_flags flags);
int			ft_uns_width_after(unsigned int n, int j, int width_after);

int			ft_ptr(unsigned long nb, int j);
int			ft_print_ptr(unsigned long nb, int j);
int			handle_format_p(va_list args, int j, t_flags flags);
int			ft_ptr_width_before(unsigned long ptr, int j, t_flags flags);
int			ft_ptr_width_after(unsigned long ptr, int j, int width_after);

int			ft_strlen(char *s);
int			ft_printf(const char *a, ...);
t_flags		init_flags(const char *format, int i);
int			ft_print_space(int size, int j, char c);
int			ft_handle_input(char c, va_list args, int j, t_flags flags);
int			ft_next_precent(const char *format, va_list args, int j, int i);

#endif
