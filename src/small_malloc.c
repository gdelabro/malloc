/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:44:58 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/29 17:13:32 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

int		compare_small_ptr(void *addr)
{
	t_block		*block;

	block = addr;
	if (block->free != MAGIC_FREE)
		return (1);
	return (0);
}

void	*find_small_ptr(void)
{
	void	*addr;

	addr = g_e.mem_small;
	while (1)
	{
		if ((addr + SMALL_BLOCK) >= g_e.mem_small + (265 * getpagesize()))
			return (NULL);
		if (compare_small_ptr(addr))
			return (addr);
		addr += SMALL_BLOCK;
	}
	return (NULL);
}

void	*small_malloc(size_t s)
{
	void	*addr;

	if (!init_global_var_small() && pthread_mutex_unlock(&g_mutex) != 44564)
		return (NULL);
	addr = find_small_ptr();
	addr ? creat_block(addr, s, SMALL) : 0;
	if (!addr)
		return (large_malloc(s));
	g_e.total += s;
	pthread_mutex_unlock(&g_mutex);
	return (addr + sizeof(t_block));
}
