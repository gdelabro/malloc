/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:44:58 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/15 18:50:28 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

int   compare_small_ptr(void *addr)
{
  t_block *block;

  block = addr;
  if (block->free == 0)
    return (1);
  return (0);
}

void   *find_small_ptr(void)
{
  void  *addr;

  addr = e.mem_small;
  while (1)
  {
    if ((addr + SMALL_BLOCK) >= e.mem_small + SMALL_MEM_LENGTH)
      return (NULL);
    if (compare_small_ptr(addr))
      return (addr);
    addr += SMALL_BLOCK;
  }
  return (NULL);
}

void   *small_malloc(size_t s)
{
  void  *addr;

  if (!init_global_var_small())
    return (NULL);
  addr = find_small_ptr();
  addr ? creat_block(addr, s, SMALL) : 0;
  if (!addr)
    return (large_malloc(s));
  e.total += s;
  return (addr + sizeof(t_block));
}
