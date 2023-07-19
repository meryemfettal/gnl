/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfettal <mfettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:10:21 by mfettal           #+#    #+#             */
/*   Updated: 2023/07/19 02:48:28 by mfettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*copying(int len, char *s1, char *s2);
char	*str_join(char *s1, char *s2);
char	*get_line1(char *s1);
char	*get_rest(char *s1);

#endif
