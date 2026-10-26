/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:31:36 by daparici          #+#    #+#             */
/*   Updated: 2026/10/26 22:14:55 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void handle_error(char *msg)
{
    fprintf(stderr, "woody_woodpacker: %s: %s\n", msg, strerror(errno));
}

int woody_woodpacker(char *filename)
{
    int fd;
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        handle_error("open");
        return errno;
    }
    if (close(fd) == -1)
    {
        handle_error("close");
        return errno;
    }
    return fd;
}

int main(int ac, char**av)
{   
    int ret;
    if (ac != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", av[0]);
        return EINVAL;
    }
    ret = woody_woodpacker(av[1]);
    return (ret);
}
