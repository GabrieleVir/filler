/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 02:41:37 by gvirga            #+#    #+#             */
/*   Updated: 2019/04/15 07:02:43 by gvirga           ###   ########.fr       */
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
		while((get_next_line(STDIN_FILENO, &info)) > 0)
			write(fd, info, ft_strlen(info));
		ft_putstr_fd("8 2\n", 1);
		return (1);
	}
	return (0);
}
