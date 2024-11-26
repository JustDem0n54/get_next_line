/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:24:09 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/26 16:56:41 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *create_storage(char *str)
{
	size_t	i;
	size_t	j;
	char	*storage;
	
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i + 1] == '\0')
	{
		free (str);
		return (NULL);
	}
	storage = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (storage == NULL)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		storage[j++] = str[i++];
	storage[j] = '\0';
	free (str);
	return(storage);
}

char	*read_check(char *str, int fd)
{
	int size_rd;
	char *buff;
	char *temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	size_rd = 1;
	while (ft_strchr(str, '\n') == 0 && size_rd != 0)
	{
		size_rd = read(fd, buff, BUFFER_SIZE);
		if (size_rd == -1)
		{
			free(buff);
			return (NULL);
		}
		temp = str;
		buff[size_rd] = '\0';
		str = ft_strjoin(str, buff);
		free (temp);
	}
	free(buff);
	return (str);
}

char *ft_strcpy(char *str)
{
	size_t i;
	char *buff;

	i = 0;
	buff = malloc(ft_strlen(str) + 1 * sizeof(char));
	if (buff == NULL)
		return (NULL);
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

char *get_next_line(int fd)
{
	char *str;
	static char *storage;

	if (BUFFER_SIZE <= 0 || fd < 0 || read (fd, 0, 0) <  0)
		return (NULL);
	storage = read_check(storage, fd);
	if (!storage)
		return (NULL);
	str = ft_strcpy(storage);
	storage = create_storage(storage);
	return (str);
}

int main() {
    int fd = open("example.txt", O_RDONLY);
    int i = 3;
	char *GNL;
	
    if (fd == -1) {
        perror("Erreur à l'ouverture du fichier");
        return 1;
    }
	while (i > 0)
	{
		GNL = get_next_line(fd);
		printf("%s", GNL);
		free (GNL);
		i--;
	}
    close(fd);
    return 0;
}
