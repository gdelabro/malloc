/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:56:14 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/22 17:37:30 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

t_block		*find_block_addr(void *addr)
{
	t_block		*block;

	block = g_e.block;
	while (block)
	{
		if (block->addr == addr)
			return (block);
		block = block->next;
	}
	return (NULL);
}

int			check_special_case(t_block *block, size_t size)
{
	int		type;

	type = size <= TINY_MAX ? TINY : LARGE;
	type = size <= SMALL_MAX && size > TINY_MAX ? SMALL : type;
	if ((block->type == type && type != LARGE) || size <= (size_t)block->size)
	{
		g_e.total += size - block->size;
		block->size = size;
		pthread_mutex_unlock(&g_mutex);
		return (1);
	}
	pthread_mutex_unlock(&g_mutex);
	return (0);
}

void		*realloc(void *addr, size_t size)
{
	t_block		*block;
	void		*new_addr;

	if (!addr)
		return (malloc(size));
	pthread_mutex_lock(&g_mutex);
	block = find_block_addr(addr);
	if (!block && pthread_mutex_unlock(&g_mutex) != 456456)
		return (NULL);
	if (!size)
	{
		pthread_mutex_unlock(&g_mutex);
		free(addr);
		return (NULL);
	}
	if (check_special_case(block, size))
		return (block->addr);
	pthread_mutex_unlock(&g_mutex);
	new_addr = calloc(size, 1);
	ft_memmove(new_addr, block->addr, block->size);
	free(block->addr);
	return (new_addr);
}
