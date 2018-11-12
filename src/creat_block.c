/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:18:47 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/12 20:03:06 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void *new_block(void *addr, int s, int type)
{
  t_block   *block;

  block = mmap(NULL, sizeof(t_block),
  PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
  block->addr = addr;
  block->size = s;
  block->type = type;
  block->next = NULL;
  return (block);
}

void creat_block(void *addr, int size, int type)
{
  t_block   *block;

  block = e.block;
  if (!block)
    e.block = new_block(addr, size, type);
  else
  {
    while (block->next)
      block = block->next;
    block->next = new_block(addr, size, type);
  }
}
