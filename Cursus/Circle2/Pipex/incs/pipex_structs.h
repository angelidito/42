/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:45 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/16 18:22:48 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

typedef struct s_vars
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**path;
}			t_vars;

#endif
