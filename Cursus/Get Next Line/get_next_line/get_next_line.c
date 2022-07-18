/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/18 12:38:42 by angmarti         ###   ########.fr       */
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
 *   fun- ción get_next_line.
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
char	*get_next_line(int fd)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE * sizeof (char));
	if (fd < 0)
		return (NULL);
	return (NULL);
}
