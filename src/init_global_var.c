/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:52:07 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/20 21:07:09 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"
int   init_global_var()
{
    if (!g_e.mem_tiny)
    {
      g_e.mem_tiny = mmap(NULL, TINY_MEM_LENGTH, PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
      g_e.mem_small = mmap(NULL, SMALL_MEM_LENGTH, PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
      if (g_e.mem_tiny == (void*)-1 || g_e.mem_small == (void*)-1)
      {
        g_e.mem_tiny = NULL;
        g_e.mem_small = NULL;
        return(0);
      }
    }
    return (1);
}

int   init_global_var_tiny()
{
    if (!g_e.mem_tiny)
    {
      g_e.mem_tiny = mmap(NULL, TINY_MEM_LENGTH, PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
      if (g_e.mem_tiny == (void*)-1)
      {
        g_e.mem_tiny = NULL;
        return(0);
      }
    }
    return (1);
}

int   init_global_var_small()
{
    if (!g_e.mem_small)
    {
      g_e.mem_small = mmap(NULL, SMALL_MEM_LENGTH, PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, -1, 0);
      if (g_e.mem_small == (void*)-1)
      {
        g_e.mem_small = NULL;
        return(0);
      }
    }
    return (1);
}
