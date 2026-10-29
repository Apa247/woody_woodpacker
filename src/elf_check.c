/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:58:16 by daparici          #+#    #+#             */
/*   Updated: 2026/10/28 21:23:12 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int check_file(void *addr)
{
    Elf64_Ehdr *header = addr;
    if (header->e_ident[EI_MAG0] == ELFMAG0
        && header->e_ident[EI_MAG1] == ELFMAG1
        && header->e_ident[EI_MAG2] == ELFMAG2
        && header->e_ident[EI_MAG3] == ELFMAG3
        && header->e_ident[EI_CLASS] == ELFCLASS64)
    {
        return (header->e_type);
    }
    return (ET_NONE);
}