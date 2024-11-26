/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:36:14 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/26 17:01:58 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(char *str, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *storage, char *buff);
char	*str_start(char *str);
char	*read_check(char *str, int fd);
char *get_next_line(int fd);

#endif