/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:31:36 by daparici          #+#    #+#             */
/*   Updated: 2026/10/27 02:03:22 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void handle_error(char *msg)
{
    fprintf(stderr, "woody_woodpacker: %s: %s\n", msg, strerror(errno));
}

int woody_woodpacker(char *filename)
{
    int     fd;
    off_t   size;
    void    *addr;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        handle_error("open");
        return errno;
    }
    size = lseek(fd, 0, SEEK_END);
    if (size < 0)
    {
        handle_error("lseek");
        close(fd);
        return(errno);
    }
    else if(size == 0)
    {
        handle_error("archivo vacío");
        close(fd);
        return(errno);
    }
    addr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED)
    {
        handle_error("mmap");
        close(fd);
        return(errno);
    }
    
    if (close(fd) == -1)
    {
        handle_error("close");
        return errno;
    }
    return errno;
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
