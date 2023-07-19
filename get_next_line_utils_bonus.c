/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfettal <mfettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:11:26 by mfettal           #+#    #+#             */
/*   Updated: 2023/07/19 03:11:01 by mfettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*str_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_line1(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
	{
		return (NULL);
	}
	if (s1[0] == 0)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] && s1[i] != '\n')
		str[i] = s1[i];
	if (s1[i] == '\n')
		str[i++] = '\n';
	return (str[i] = '\0', str);
}

char	*get_rest(char *s1)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
		return (free (s1), NULL);
	while (s1[j])
		j++;
	len = j - i;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free(s1), NULL);
	j = 0;
	i++;
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	str[j] = '\0';
	return (free(s1), str);
}
