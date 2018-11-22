/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:57:13 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/22 17:38:58 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void	show_tiny(void)
{
	t_block		*block;
	void		*tmp;

	ft_printf("TINY: %#.8x\n", g_e.mem_tiny);
	block = g_e.mem_tiny;
	while (block && block < (t_block*)(g_e.mem_tiny + TINY_MEM_LENGTH))
	{
		if (block->free == MAGIC_FREE)
			ft_printf("%#.8x - %#.8x : %d octets\n", block->addr,
					block->addr + block->size, block->size);
		tmp = block;
		tmp += TINY_BLOCK;
		block = tmp;
	}
}

void	show_small(void)
{
	t_block		*block;
	void		*tmp;

	ft_printf("SMALL: %#.8x\n", g_e.mem_small);
	block = g_e.mem_small;
	while (block && block < (t_block*)(g_e.mem_small + SMALL_MEM_LENGTH))
	{
		if (block->free == MAGIC_FREE)
			ft_printf("%#.8x - %#.8x : %d octets\n", block->addr,
					block->addr + block->size, block->size);
		tmp = block;
		tmp += SMALL_BLOCK;
		block = tmp;
	}
}

void	show_large(void)
{
	t_block		*block;

	block = g_e.block;
	ft_printf("LARGE:\n");
	while (block)
	{
		if (block->type == LARGE)
			ft_printf("%#.8x - %#.8x : %d octets\n", block->addr,
					block->addr + block->size, block->size);
		block = block->next;
	}
}

void	show_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	show_tiny();
	show_small();
	show_large();
	ft_printf("Total: %d\n", g_e.total);
	pthread_mutex_unlock(&g_mutex);
}
