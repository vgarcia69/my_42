/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:46:05 by vgarcia           #+#    #+#             */
/*   Updated: 2024/11/18 11:03:44 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *a, ...);
int		ft_printarg(va_list arg, char c);

int		ft_putnbase(unsigned int n, char *base);
int		ft_putnbr(int n);
int		ft_putmem(void *p, char *base);

int		isinbase(char c, const char *set);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strlen(const char *s);
char	*ft_reversestr(char *str);
char	*ft_itoa(int n);
int		ft_writestr(char *s);
int		ft_writechar(char c);

#endif
