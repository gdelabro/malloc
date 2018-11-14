/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:18:47 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/14 19:22:33 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void *new_block(void *addr, int s, int type)
{
  t_block   *block;

  block = addr;
  block->free = 1;
  block->addr = addr + sizeof(t_block);
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
    block = new_block(addr, size, type);
    block->next = e.block;
    e.block = block;
  }
}
