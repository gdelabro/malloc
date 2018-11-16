/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:56:14 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/16 21:07:39 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

t_block *find_block_addr(void *addr)
{
  t_block *block;

  block = e.block;
  while (block)
  {
    if (block->addr == addr)
      return (block);
    block = block->next;
  }
  return (NULL);
}

int     check_special_case(t_block *block, size_t size)
{
  int type;

  type = size <= TINY_MAX ? TINY : LARGE;
  type = size <= SMALL_MAX && size > TINY_MAX ? SMALL : type;
  if ((block->type == type && type != LARGE) || size <= (size_t)block->size)
  {
    e.total += size - block->size;
    block->size = size;
    return (1);
  }
  return (0);
}

void    *realloc2(void *addr, size_t size)
{
  t_block   *block;
  void      *new_addr;

  if (!addr)
    return (malloc2(size));
  block = find_block_addr(addr);
  if (!block)
    return (NULL);
  if (!size)
  {
    free2(addr);
    return (NULL);
  }
  if (check_special_case(block, size))
    return (block->addr);
  new_addr = calloc2(size, 1);
  ft_memmove(new_addr, block->addr, block->size);
  free2(block->addr);
  return (new_addr);
}
