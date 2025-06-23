/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:20:40 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 17:20:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_int(int num);
void	put_uint(unsigned int num);
int		print_uint(unsigned int num);
int		print_percent(void);
int		print_ptr(void *ptr);
int		print_hex_format(unsigned int num, char format);
int		ft_formats(va_list args, const char format);

#endif