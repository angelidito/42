/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/08/11 16:59:12 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 *
 * Funciones autorizadas: read, malloc, free.
 *
 * • Llamar a tu función get_next_line de manera repetida (por ejemplo, usando 
 *   un bucle) te permitirá leer el contenido del archivo hacia el que apunta 
 *   el file descriptor, línea a línea, hasta el final.
 *
 * • Tu función deberá devolver la línea que se acaba de leer. 
 *     Si no hay nada más que leer o si ha ocurrido un error, deberá devolver 
 *   NULL.
 *
 * • Asegúrate de que tu función se comporta adecuadamente 
 *   cuando lea de un archivo y cuando lea de stdin.
 *
 * • Ten en cuenta que la línea devuelta debe terminar con el caracter \n, 
 *   excepto si se ha llegado al final del archivo y esté no termina con un 
 *   caracter \n.
 *
 * • En el header get_next_line.h deberás tener como mínimo el prototipo de la 
 *   función get_next_line.
 *
 * • Añade todas las funciones de ayuda que necesites en el archivo 
 *   get_next_line_utils.c
 *
 * • Tu programa debe compilar con el flag -D BUFFER_SIZE=xx.
 *     Este flag se utilizará para determinar el tamaño del buffer de las 
 *   lecturas de tu get_next_line(). 
 *     Este parámetro será modificado por tus evaluadores y por Moulinette para 
 *   probar tu programa.
 *
 * • El programa se compilará de la siguiente forma (se utiliza como ejemplo un 
 *   tamaño de buffer de 42):
 *     cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.
 *
 * • Se considera que get_next_line() tiene un comportamiento indeterminado si 
 *   el archivo al que apunta el fd ha cambiado desde la última vez que se 
 *   llamó, siempre que read() no haya llegado al final del archivo.
 *
 * • Se considera que get_next_line() tiene un comportamiento indeterminado 
 *   cuando lo que se lee es un archivo binario. Sin embargo, puedes 
 *   inmplementar alguna manera lógica de sortear este problema, si quieres.
 *
 *
 * ¿Funciona correctamente tu get_next_line si el BUFFER_SIZE es 9999?
 * ¿Y si es 1? ¿Qué tal con 10000000? ¿Sabes por qué?
 *
 *
 * Intenta leer lo menos posible cada vez que se llame a get_next_line(). 
 * Si encuentras un salto de línea, deberás devolver la línea actual. 
 * No leas el archivo entero y luego proceses cada línea.
 *
 *
 **/

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}

int	freecat(char **oldline, char *buff, ssize_t bytes)
{
	char	*newline;
	size_t	i;
	ssize_t	j;

	i = 0;
	while (*oldline && (*oldline)[i])
		i++;
	newline = malloc((i + bytes + 1) * sizeof (char));
	if (!newline)
		return (-1);
	i = 0;
	while (*oldline && (*oldline)[i])
	{
		newline[i] = (*oldline)[i];
		i++;
	}
	j = 0;
	while (j < bytes)
		newline[i + j++] = *buff++;
	newline[i + j] = '\0';
	if (*oldline)
		free(*oldline);
	*oldline = newline;
	return (0);
}

int	read_until_newline(int fd, char **line)
{
	char			*buff;
	int				found;
	ssize_t			bytes;
	ssize_t			i;

	found = 0;
	bytes = -1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buff)
		return (-1);
	buff[BUFFER_SIZE] = '\0';
	bytes = read(fd, buff, BUFFER_SIZE);
	if (!bytes){
		free(buff);
		return (-1);
	}
	while (!found && bytes)
	{
		//printf("\tbuff: \"%s\"\n", buff);
		if (!buff || bytes == -1 || -1 == freecat(line, buff, bytes))
			return (-1);
		i = -1;
		while (++i < BUFFER_SIZE)
			if (i < bytes && buff[i] == '\n')
				found = 1;
			else if (i >  bytes)
				buff[i] = '-';
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (!found)
		return (0);
	return (1);
}

char	*get_until_newline(char **oldline)
{
	size_t	i;
	size_t	newlen;
	char	*substr;
	char	*newline;

//	printf("result oldln: %s\n", *oldline);
	i = 0;
	while (*oldline && (*oldline)[i] && (*oldline)[i] != '\n')
		i++;
	substr = malloc((i + 2) * sizeof (char));
	if (!substr)
		return (NULL);
	i = 0;
	while (*oldline && (*oldline)[i] && (*oldline)[i] != '\n')
	{
		substr[i] = (*oldline)[i];
		i++;
	}
	substr[i] = '\n';
	substr[i + 1] = '\0';
	newlen = 0;
	while (*oldline && (*oldline)[i + 1 + newlen])
		newlen++;
	newline = malloc((newlen + 1) * sizeof (char));
	newlen = 0;
	while (*oldline && (*oldline)[i + 1])
		newline[newlen++] = (*oldline)[1 + i++];
	//free(*oldline);
	*oldline = newline;
	free(newline);
	return (substr);
}

int	contains_newline(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		if (line[i++] == '\n')
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*substr;
	int				result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (line == NULL || !contains_newline(line))
	{
		result = read_until_newline(fd, &line);
		if (-1 == result || !line || !*line)
			return (NULL);
		if (0 == result)
			return (line);
	}
	substr = get_until_newline(&line);
	if (!substr)
		return (NULL);
	//printf("result sbstr : %s\n", substr);
	//printf("result lline : %s\n", line);
	return (substr);
}

int	main(void)
{
	int		fd;
	int		i;

	fd = open("prueba2", O_RDONLY);
//	fd = open("gnlTester/files/empty", O_RDWR);
//	fd = open("gnlTester/files/nl", O_RDWR);
//	fd = open("gnlTester/files/41_no_nl", O_RDWR);
//	fd = open("gnlTester/files/41_with_nl", O_RDWR);
//	fd = open("gnlTester/files/42_no_nl", O_RDWR);
//	fd = open("gnlTester/files/42_with_nl", O_RDWR);
//	fd = open("gnlTester/files/43_no_nl", O_RDWR);
//	fd = open("gnlTester/files/43_with_nl", O_RDWR);
//	fd = open("gnlTester/files/multiple_nlx5", O_RDWR);
//	fd = open("gnlTester/files/multiple_line_no_nl", O_RDWR);
//	fd = open("gnlTester/files/multiple_line_with_nl", O_RDWR);
//	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDWR);
//	fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDWR);
//	fd = open("gnlTester/files/big_line_no_nl", O_RDWR);
//	fd = open("gnlTester/files/big_line_with_nl", O_RDWR);
//	fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDWR);

	i = 0;
	while (++i <= 2)
	{
		//printf("Vuelta: %d\n", i);
		char *str = get_next_line(fd);
		if (str != NULL)
			printf("------------->%s", str);
		else 
			printf("------------->NULL");
		//printf("result line : \"%s\"\n", get_next_line(fd));
	}
	return (0);
}
