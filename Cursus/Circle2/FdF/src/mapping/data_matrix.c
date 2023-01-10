/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:56:35 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/10 20:04:39 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf_events.h"
#include "../../incs/fdf.h"

/**
 * It prints the file matrix
 * 
 * @param map the map structure
 */
void	map_file_matrix_print(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data_matrix[i][j])
				ft_printf("%d ", map->data_matrix[i][j]);
			else
				ft_printf("%d  ", map->data_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

/**
 * It reads a file and returns a linked list of the lines in the file
 * 
 * @param file The file to be read
 * 
 * @return A linked list of lines from the file.
 */
t_list	*linelist(const char *file)
{
	t_list	*lines;
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error openning file %s\n\n", file);
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	lines = ft_lstnew(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back(&lines, ft_lstnew(line));
	}
	close(fd);
	return (lines);
}
// t_list	*it;
// it = lines;
// while (it->content)
// {ft_printf("%s", it->content);it = it->next;
// }

/**
 * Takes an array of strings and an array of integers, converts the strings to
 * integers and stores them in the integer array
 * 
 * @param line The line of the map file that was read in
 * @param map_matrix_row The row of the map matrix we are currently working on
 */
void	store_line_numbers(char **line, int *map_matrix_row)
{
	int	word;
	int	i;
	int	n;

	i = 0;
	word = 0;
	while (line[i])
	{
		if (*line[i])
		{
			n = ft_atoi(line[i]);
			map_matrix_row[word++] = n;
		}
		i++;
	}
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
}

/**
 * It takes a linked list of lines, and returns a 2D array of integers
 * 
 * @param lines Linked list of strings, each string is a line from the map file
 * 
 * @return 0 if no errors occurred,
	and the amount of calls to malloc before mallor error.
 */
int	get_map_matrix(t_list *lines, t_vars *vars)
{
	int		i;
	char	**line;
	int		words;

	i = ft_lstsize(lines);
	vars->map->data_matrix = ft_calloc(i + 1, sizeof(int **));
	if (!vars->map->data_matrix)
		return (-1);
	vars->map->height = i;
	i = 0;
	while (lines)
	{
		line = ft_split(lines->content, ' ');
		words = words_calc(line);
		vars->map->data_matrix[i] = ft_calloc(words + 1, sizeof(int *));
		if (!vars->map->data_matrix[i])
			return (i);
		store_line_numbers(line, vars->map->data_matrix[i++]);
		lines = lines->next;
	}
	vars->map->width = words;
	return (0);
}

/**
 * It reads the map file and stores the map matrix in the vars struct
 * 
 * @param file The file name
 * @param vars Struct that holds all the variables for the program
 * 
 * @return 0 if no error occurred and map matrix was created
 */
int	set_map_data_matrix(const char *file, t_vars *vars)
{
	t_list	*lines;
	int		errors;

	lines = linelist(file);
	errors = get_map_matrix(lines, vars);
	if (errors)
		free_data_matrix_i(errors, vars->map->data_matrix);
	ft_lstclear(&lines, free);
	if (!vars->map->data_matrix)
		return (-1);
	// map_print(vars->map);
	return (0);
}
