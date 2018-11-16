/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:31:26 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/16 20:48:40 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void free_block(t_block *block)
{
  e.total -= block->size;
  if (block->type == LARGE)
    munmap(block, block->size + sizeof(t_block));
}

void free2(void *addr)
{
  t_block *block;
  t_block *tmp;

  tmp = NULL;
  block = e.block;
  if (!addr)
    return ;
  while (block && block->addr != addr)
  {
    tmp = block;
    block = block->next;
  }
  if (!block)
    return ;
  block->free = 0;
  if (block == e.block)
    e.block = e.block->next;
  else
    tmp->next = block->next;
  free_block(block);
}
