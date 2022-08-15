/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/08/15 18:12:40 by angmarti         ###   ########.fr       */
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

#include "get_next_line.h"

ssize_t	read_and_add(int fd, char **currentline, size_t len)
{
	char	*buffer;
	char	*newline;
	ssize_t	result;
	size_t	i;
	size_t	j;

	buffer = malloc((BUFFER_SIZE + 0) * sizeof(char));
	if (!buffer)
		return (-1);
	result = read(fd, buffer, BUFFER_SIZE);
	if (result == -1)
		return (-1);
	newline = malloc((len + result + 1) * sizeof(char));
	if (!newline)
		return (-1);
	i = 0;
	while (i < len)
	{
		*(newline + i) = *(*currentline + i);
		i++;
	}
	j = 0;
	while (i < len + result)
		*(newline + i++) = *(buffer + j++);
	*(newline + i) = '\0';
	if (currentline)
		free(*currentline);
	*currentline = newline; 
	return (result);
}

char	*cut_line(char **currentline, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*newline;
	char	*substr;

	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(substr + i) = (*currentline)[i];
		i++;
	}
	j = 0;
	*(substr + i) = '\0';
	while (*(*currentline + (i + j)))
	{
		j++;
	}
	newline = malloc ((j + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	k = 0;
	while (k < j)
	{
		*(newline + k) = *(*currentline + i + k);
	}
	newline[k] = '\0';
	//printf("\nCrntLne: '%s'\n", *currentline);
	if (currentline)
		free(*currentline);
	*currentline = newline; 
	//printf("NewLine: '%s'\n", newline);
	//printf(" SubStr: '%s'\n", substr);
	return (substr);
}

char	*get_next_line(int fd)
{
	static char		*line;
	ssize_t			result;
	size_t			i;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	result = 1;
	while (result != -1)
	{
		i = 0;
		while (line && line[i])
			if (line[i++] == '\n')
				break ;
		if (line && line[0] && line[i - 1] == '\n')
			return (cut_line(&line, i));
		if (line && *line && !result)
			return (line);
		if (!result)
			return (NULL);
		result = read_and_add(fd, &line, i);
	}
	return (NULL);
}


int	main(void)
{
	int		fd;
	int		i;

	fd = open("prueba", O_RDWR);
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
	while (++i <= 50)
	{
		//printf("~Vuelta: %d~", i);
		char *str = get_next_line(fd);
		//if (str != NULL)
			printf("%s", str);
			//printf("\nLINEA: '%s'", str);
			//printf("------------->%s", str);
		//else 
		//	printf("->NULL");
			//printf("------------->NULL");
		//printf("result line : \"%s\"\n", get_next_line(fd));
	}

	return (0);
}
