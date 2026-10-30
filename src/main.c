/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:31:36 by daparici          #+#    #+#             */
/*   Updated: 2026/10/30 16:19:19 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void handle_error(char *msg)
{
    fprintf(stderr, "woody_woodpacker: %s: %s\n", msg, strerror(errno));
}

int woody_woodpacker(char *filename)
{
    int             fd;
    int             ret;
    unsigned long   size;
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
        fprintf(stderr, "woody_woodpacker: archivo vacio\n");
        close(fd);
        return(EXIT_FAILURE);
    }
    addr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED)
    {
        handle_error("mmap");
        close(fd);
        return(errno);
    }
    if (size < sizeof(Elf64_Ehdr))
    {
        fprintf(stderr, "woody_woodpacker: archivo demasiado pequeño\n");
        munmap(addr, size);
        close(fd);
        return EINVAL;
    }
    ret = check_file(addr);
	if (ret == ET_EXEC || ret == ET_DYN)
		ret = 0;
    else
    {
        fprintf(stderr, "woody_woodpacker: debe ser un archivo ELF de 64 bits\n");
        munmap(addr, size);
        close(fd);
    }
    munmap(addr, size);
    close(fd);
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
