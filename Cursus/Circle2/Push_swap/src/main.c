/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:24:56 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/28 15:06:45 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 
 * * El juego se compone de dos stacks, llamados a y b.
 * * Para empezar:
 * * En a tendrás números positivos y/o negativos, nunca duplicados.
 * * En b no habrá nada.
 * * El objetivo es ordenar los números del stack a en orden ascendente.
 * * Para hacerlo tienes las siguientes operaciones a tu disposición:
 * 	sa : swap a - intercambia los dos primeros elementos encima del stack a. 
 * 		No hace nada si hay uno o menos elementos.
 * 	sb : swap b - intercambia los dos primeros elementos encima del stack b. 
 * 		No hace nada si hay uno o menos elementos.
 * 	ss : swap a y swap b a la vez.
 * 	pa : push a - toma el primer elemento del stack b y lo pone encima del 
 * 		stack a. No hace nada si b está vacío.
 * 	pb : push b - toma el primer elemento del stack a y lo pone encima del 
 * 		stack b. No hace nada si a está vacío.
 * 	ra : rotate a - desplaza hacia arriba todos los elementos del stack a una 
 * 		posición, de forma que el primer elemento se convierte en el último.
 * 	rb : rotate b - desplaza hacia arriba todos los elementos del stack b una 
 * 		posición, de forma que el primer elemento se convierte en el último.
 * 	rr : rotate a y rotate b - desplaza al mismo tiempo todos los elementos del
 * 		stack a y del stack b una posición hacia arriba, de forma que el primer
 * 		elemento se convierte en el último.
 * 	rra : reverse rotate a - desplaza hacia abajo todos los elementos del stack
 * 		a una posición, de forma que el último elemento se convierte en 
 * 		el primero.
 * 	rrb : reverse rotate b - desplaza hacia abajo todos los elementos del stack
 * 		b una posición, de forma que el último elemento se convierte en 
 * 		el primero.
 * 	rrr : reverse rotate a y reverse rotate b - desplaza al mismo tiempo todos 
 * 		los elementos del stack a y del stack b una posición hacia abajo, 
 * 		de forma que el último elemento se convierte en el primero.
 */

/**
 * 
 * - Debes escribir un programa llamado push_swap que recibirá como argumento 
 * 		el stack a con el formato de una lista de enteros. El primer argumento 
 * 		debe ser el que esté encima del stack (cuidado con el orden).
 * - El programa debe mostrar la lista de instrucciones (más corta posible) 
 * 		para ordenar el stack a, de menor a mayor donde el menor se sitúe en 
 * 		la cima del stack.
 * - Las instrucciones deben separarse utilizando un “\n” y nada más.
 * - El objetivo es ordenar el stack con el mínimo número de operaciones 
 * 		posible. Durante la evaluación compararemos el número de instrucciones 
 * 		obtenido por tu programa con un rango de instrucciones máximo.
 * - Tu programa no recibirá puntos tanto si tu programa muestra una lista 
 * 		demasiado larga como si el resultado no es correcto.
 * - Si no se especifican parámetros, el programa no deberá mostrar nada y 
 * 		eberá devolver el control al usuario.
 * - En caso de error, deberás mostrar Error seguido de un “\n” en la salida de
 * 		errores estándar. Algunos de los posibles errores son: argumentos que 
 * 		no son enteros, argumentos superiores a un int, y/o encontrar números 
 * 		duplicados.
 * 			$>./push_swap 2 1 3 6 5 8
 * 			sa
 * 			pb
 * 			pb
 * 			pb
 * 			sa
 * 			pa
 * 			pa
 * 			pa
 * 			$>./push_swap 0 one 2 3
 * 			Error
 * 			$>
 * Durante la evaluación tendrás a tu disposición un binario para verificar el 
 * 		correcto funcionamiento de tu programa. Funciona de la siguiente forma:
 * 			$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
 * 			6
 * 			$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
 * 			OK
 * 			$>
 * Si el programa checker_OS muestra KO, implicará que tu programa push_swap 
 * 		encontró una solución inválida (lo que quiere decir que no ordenaba la 
 * 		lista). El programa checker_OS está disponible en la parte “recursos 
 * 		del proyecto” en la Intranet.
 * Puedes encontrar su funcionamiento descrito debajo, en la “parte bonus”.
 */

// ! Can use only: write read malloc free exit

int	main(int argc, char const *argv[])
{
	if (argc == 1)
	return (0);
}
