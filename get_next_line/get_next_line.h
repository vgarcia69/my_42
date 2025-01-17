/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:54:37 by vgarcia           #+#    #+#             */
/*   Updated: 2024/11/27 12:07:08 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
int			read_and_fill(char **str, int fd, char *last_buf);
long int	check_newline(const char *str);
int			join_update_buf(char **str, char *last_buf);

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_strcpy(char *s1, const char *s2);
void		ft_bzero(void *s, size_t n);

#endif
