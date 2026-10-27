/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody_woodpacker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:32:20 by daparici          #+#    #+#             */
/*   Updated: 2026/10/27 00:16:29 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_H
# define WOODY_H 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <zlib.h>
#include <openssl/rand.h>
#include <errno.h>
#include <elf.h>
#include "libft.h"

typedef struct s_elf
{
    void    *adr;
    long    size;
    
} t_elf;

#endif