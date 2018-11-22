/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:31:26 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/22 17:32:24 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void	free_block(t_block *block)
{
	g_e.total -= block->size;
	if (block->type == LARGE)
		munmap(block, block->size + sizeof(t_block));
}

void	free(void *addr)
{
	t_block		*block;
	t_block		*tmp;

	pthread_mutex_lock(&g_mutex);
	tmp = NULL;
	block = g_e.block;
	if (!addr && pthread_mutex_unlock(&g_mutex) != 445446)
		return ;
	while (block && block->addr != addr)
	{
		tmp = block;
		block = block->next;
	}
	if (!block && pthread_mutex_unlock(&g_mutex) != 445454)
		return ;
	block->free = 0;
	if (block == g_e.block)
		g_e.block = g_e.block->next;
	else
		tmp->next = block->next;
	free_block(block);
	pthread_mutex_unlock(&g_mutex);
}

void	big_free(void)
{
	while (g_e.block)
		free(g_e.block->addr);
}
