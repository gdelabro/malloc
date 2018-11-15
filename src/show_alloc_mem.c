/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:57:13 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/15 18:51:25 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void nb_block() {
  t_block *block;
  int i;

  i = 0;
  block = e.block;
  while (block)
  {
    i++;
    ft_printf("free -> %d\n", block->free);
    block = block->next;
  }
  ft_printf("nb block -> %d\n", i);
}

void show_tiny()
{
  t_block *block;
  void    *tmp;

  ft_printf("TINY: %#.8x\n", e.mem_tiny);
  block = e.mem_tiny;
  while (block && block < (t_block*)(e.mem_tiny + TINY_MEM_LENGTH))
  {
    if (block->free)
      ft_printf("%#.8x - %#.8x : %d octets\n", block->addr,
      block->addr + block->size, block->size);
    tmp = block;
    tmp += TINY_BLOCK;
    block = tmp;
  }
}


void show_small()
{
  t_block *block;
  void    *tmp;

  ft_printf("SMALL: %#.8x\n", e.mem_small);
  block = e.mem_small;
  while (block && block < (t_block*)(e.mem_small + SMALL_MEM_LENGTH))
  {
    if (block->free)
      ft_printf("%#.8x - %#.8x : %d octets\n", block->addr,
      block->addr + block->size, block->size);
    tmp = block;
    tmp += SMALL_BLOCK;
    block = tmp;
  }
}

void show_large()
{
  t_block *block;

  block = e.block;
  ft_printf("LARGE:\n");
  while (block)
  {
    if (block->type == LARGE)
      ft_printf("%#.8x - %#.8x : %d octets\n", block->addr,
      block->addr + block->size, block->size);
    block= block->next;
  }
}

void show_alloc_mem()
{
  //nb_block();
  show_tiny();
  show_small();
  show_large();
  ft_printf("Total: %d\n", e.total);
}
