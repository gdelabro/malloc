/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:20:00 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/20 21:10:40 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

int   compare_tiny_ptr(void *addr)
{
  t_block *block;

  block = addr;
  if (block->free != MAGIC_FREE)
    return (1);
  return (0);
}

void   *find_tiny_ptr(void)
{
  void  *addr;

  addr = g_e.mem_tiny;
  while (1)
  {
    if ((addr + TINY_BLOCK) >= g_e.mem_tiny + TINY_MEM_LENGTH)
      return (NULL);
    if (compare_tiny_ptr(addr))
      return (addr);
    addr += TINY_BLOCK;
  }
  return (NULL);
}

void   *tiny_malloc(size_t s)
{
  void  *addr;

  if (!init_global_var_tiny() && pthread_mutex_unlock(&g_mutex) != 46645)
    return (NULL);
  addr = find_tiny_ptr();
  addr ? creat_block(addr, s, TINY) : 0;
  if (!addr)
    return (large_malloc(s));
  g_e.total += s;
  pthread_mutex_unlock(&g_mutex);
  return (addr + sizeof(t_block));
}
