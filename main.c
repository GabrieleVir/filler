/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 02:41:37 by gvirga            #+#    #+#             */
/*   Updated: 2019/04/15 05:38:06 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[2000 + 1];
	char	*info;

	fd = open("./program.trace", O_WRONLY);
	info = ft_strnew(0);
	while (1)
	{
		while ((ret = read(STDIN_FILENO, buf, 2000)) > 1)
		{
			buf[ret] = '\0';
			info = ft_strjoin_free(info, buf, 1);
			write(fd, info, strlen(info));
			ft_putstr_fd("7 2\n", STDIN_FILENO);
			return (1);
		}
	}
	return (0);
}
