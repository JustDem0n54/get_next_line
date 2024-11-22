/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:05:50 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/22 16:53:43 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>



char	*str_start(char *str)
{
	int i;
	int j;
	char *buff;
	
	i = 0;
	buff = malloc(ft_strlen(str) * sizeof(char));
	while (str[i] != '\n')
		i++;
	j = 0;
	i++;
	while(str[i])
		buff[j++] = str[i++];
	while(j < i)
		buff[j++] = '\0';
	return(buff);
}

char	*read_check(char *str, int fd)
{
	int size_rd;
	char *buff;

	buff = malloc(sizeof(char) * BUFFER + 1);
	if (buff == NULL)
		return (NULL);
	size_rd = 1;
	while (ft_strchr(str, '\n') == 0 && size_rd != 0)
	{
		size_rd = read(fd, buff, BUFFER);
		buff[size_rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char *get_next_line(int fd)
{
	static char *str;
	char *buff;
	int i;
	
	i = 0;
	if (str != NULL)
		str = str_start(str);
	else
		str = ft_calloc(BUFFER, sizeof(char));
	str = read_check(str, fd);
	buff = malloc(ft_strlen(str) + 1 * sizeof(char));
	while (str[i] != '\n' && str[i])
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

// int main() {
//     int fd = open("example.txt", O_RDONLY);  // Ouvre le fichier en mode lecture seule
//     int i = 5;
	
//     if (fd == -1) {
//         perror("Erreur à l'ouverture du fichier");
//         return 1;
//     }
// 	while (i > 0)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i--; // Affiche les données lues
// 	}
//     close(fd);  // Ferme le fichier
//     return 0;
// }

