/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:18:47 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/22 17:31:48 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void	*new_block(void *addr, int s, int type)
{
	t_block		*block;

	block = addr;
	block->free = MAGIC_FREE;
	block->addr = addr + sizeof(t_block);
	block->size = s;
	block->type = type;
	block->next = NULL;
	return (block);
}

void	creat_block(void *addr, int size, int type)
{
	t_block		*block;

	block = g_e.block;
	if (!block)
		g_e.block = new_block(addr, size, type);
	else
	{
		block = new_block(addr, size, type);
		block->next = g_e.block;
		g_e.block = block;
	}
}
