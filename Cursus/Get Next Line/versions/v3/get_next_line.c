/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/25 17:20:59 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// void	gnl_replace_line(char **ptr2myline, char *newline)
// {
// 	if (ptr2myline && *ptr2myline)
// 	{
// 		free(*ptr2myline);
// 	}
// 	*ptr2myline = newline;
// }

/**
 * It takes two strings and returns a new string that is the concatenation of 
 * the two strings
 * 
 * @param myline the line that was read in the previous iteration of the loop
 * @param buffer the buffer that is being read from the file descriptor
 * 
 * @return A pointer to a string.
 */
char	*gnl_strjoin(char **myline, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!buffer)
		return (*myline);
	if (!*myline)
		return (buffer);
	str = (char *) ft_calloc(ft_strlen(*myline) + ft_strlen(buffer) + 1,
			sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while ((*myline)[i])
		str[i++] = (*myline)[j++];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	// str[i] = '\0';
	free(*myline);
	return (str);
}

/**
 * It reads from a file descriptor and adds the read characters to a string
 * 
 * @param fd the file descriptor to read from
 * @param currentline a pointer to a pointer to a char. This is the address of
 * the pointer to the string that we're reading
 * @param len the length of the current line
 * 
 * @return The number of characters read.
 */
// ssize_t	gnl_read_and_add(int fd, char **ptr2myline, size_t len)
ssize_t	gnl_read_and_add(int fd, char **ptr2myline)
{
	char	*buffer;
	char	*newline;
	ssize_t	result;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	result = read(fd, buffer, BUFFER_SIZE);
	if (result < 1) // si es 0 lo que se ha leido no tiene sentido modificar myline
		return (result);
	buffer[result] = 0;
	newline = gnl_strjoin(ptr2myline, buffer);
	if (!newline)
		return (-1);
	*ptr2myline = ft_substr(newline, 0, ft_strlen(newline));
	free(newline);
	return (result);
}

/**
 * It takes a pointer to a string, and a length, and returns a pointer to 
 * a substring of the original string, and modifies the original string to 
 * be the remainder of the original string
 * 
 * @param ptr2myline a pointer to the pointer to the line.
 * @param len the length of the line to be cut
 * 
 * @return A pointer to a string.
 */
char	*gnl_getsubstr_cutmyline(char **ptr2myline, size_t len)
{
	char	*substr;
	char	*newline;

	// substr = ft_calloc(len + 1, sizeof(char));
	// if (!substr)
	// 	return (NULL);
	// ft_memcpy(substr, *myline, len);
	// substr[len] = 0;
	substr = ft_substr(*ptr2myline, 0, len);
	if (!substr)
		return (NULL);
	newline = ft_substr(*ptr2myline, len, ft_strlen(*ptr2myline) - len + 1);
	free(*ptr2myline);
	*ptr2myline = ft_substr(newline, 0, ft_strlen(newline));
	free(newline);
	return (substr);
}

/**
 * It reads a file descriptor until it finds a newline character,
 * then returns the line.
 * It can be called again and will return the next line each time.
 * 
 * @param fd file descriptor to the file whose line will be readed
 * 
 * @return A pointer to a string that contains the line.
 */
char	*get_next_line(int fd)
{
	static char		*myline;
	ssize_t			result;
	size_t			partial_len;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	if (!myline)
		myline = ft_calloc(1, sizeof(char));
	result = 1;
	while (myline && result != -1)
	{
		partial_len = 0;
		if (*myline)
		{
			while (myline[partial_len])
				if (myline[partial_len++] == '\n')
					break ;
			if (myline[partial_len - 1] == '\n')
				return (gnl_getsubstr_cutmyline(&myline, partial_len));
			if (!result)
				return (gnl_getsubstr_cutmyline(&myline, partial_len));
		}
		if (!result){
			if (myline)
			free (myline);
			return (NULL);}
		result = gnl_read_and_add(fd, &myline);
	}
			if (myline)
	free (myline);
	return (NULL);
}
