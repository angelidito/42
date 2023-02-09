/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:21:15 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/09 15:58:21 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_ONS_H
# define ADD_ONS_H

//	PROJECTS

int		ft_printf(char const *str, ...);

char	*get_next_line(int fd);

//	FUNCTIONS

int		ft_isspace(char c);

char	*ft_str_replace_dup_whitespaces(const char *str, char c);

#endif
