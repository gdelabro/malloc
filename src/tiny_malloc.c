/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:20:00 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/12 20:07:41 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

int   compare_tiny_ptr(void *addr)
{
  t_block *block;

  block = e.block;
  while (block)
  {
    if (block->addr == addr)
      return (0);
    block = block->next;
  }
  return (1);
}

void   *find_tiny_ptr(int type)
{
  void  *addr;

  type == TINY ? addr = e.mem_tiny : 0;
  type == SMALL ? addr = e.mem_small : 0;
  while (1)
  {
    if ((type == TINY && (addr + TINY_BLOCK) >= e.mem_tiny + TINY_MEM_LENGTH) ||
      (type == SMALL && (addr + SMALL_BLOCK) >= e.mem_small + TINY_MEM_LENGTH))
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

  (void)s;
  addr = find_tiny_ptr(TINY);
  addr ? creat_block(addr, s, TINY) : 0;
  /*if (!addr)
    return (small_malloc(s));*/
  return (addr);
}
