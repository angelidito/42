/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:24 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 14:52:24 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/mylibft/incs/libft.h"
# include <fcntl.h> /* Open function */
# include <time.h>

//	DEBUGGING

void	breakpoint(void);

//	UTILS
char	*get_cmd_file(char const *cmd, char **path_var);
char	**get_path(char *envp[]);
char	**exec_cmd(char const *cmd, char **path_var, char *envp[]);

//	FT_FUNCTIONS

void	ft_freechararr(char **chararr);

char	*ft_strjoin_n_free(const char *s1, const char *s2);
char	*ft_strjoin_n_free_op(const char *s1, const char *s2, int f1, int f2);

#endif
