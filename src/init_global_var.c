/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:52:07 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/12 20:10:22 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

int   init_global_var()
{
    if (!e.mem_tiny)
    {
      e.mem_tiny = mmap(NULL, TINY_MEM_LENGTH, PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
      e.mem_small = mmap(NULL, SMALL_MEM_LENGTH, PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
      if (e.mem_tiny == (void*)-1 || e.mem_small == (void*)-1)
        return(0);
    }
    return (1);
}
