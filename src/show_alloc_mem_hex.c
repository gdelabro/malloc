/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:47:41 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/22 17:39:32 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void	aff_line_hex(t_block *block, int l)
{
	int		i;

	i = -1;
	while (++i < 20 && l + i < block->size)
		ft_printf("%.2x ", *(char*)(block->addr + l + i));
	ft_printf("\n");
}

void	aff_mem_hex(t_block *block)
{
	int		i;

	i = 0;
	ft_printf("%#.8x ->\n", block->addr);
	while (i < block->size)
	{
		aff_line_hex(block, i);
		i += 20;
	}
}

void	show_alloc_mem_hex(void *addr)
{
	t_block		*block;

	pthread_mutex_lock(&g_mutex);
	block = g_e.block;
	while (block && block->addr != addr)
		block = block->next;
	if (!block && pthread_mutex_unlock(&g_mutex) != 456564)
		return ;
	aff_mem_hex(block);
	pthread_mutex_unlock(&g_mutex);
}
