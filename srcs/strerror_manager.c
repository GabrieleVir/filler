/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:21:44 by gvirga            #+#    #+#             */
/*   Updated: 2019/05/22 16:59:57 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		error_msg_fd(int error, int fd)
{
	char	*str;

	ft_putstr_fd("Error: ", fd);
	str = strerror(error);
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
	free(str);
	return (0);
}

int		error_str_fd(char *str, int fd)
{
	ft_putstr_fd("Error: ", fd);
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
	return (0);
}
