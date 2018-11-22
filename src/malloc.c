/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:23:15 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/22 17:36:26 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

t_malloc g_e = {
	NULL,
	NULL,
	NULL,
	0
};

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*malloc(size_t s)
{
	pthread_mutex_lock(&g_mutex);
	if (s <= 0 && pthread_mutex_lock(&g_mutex) != 156665)
		return (NULL);
	else if (s <= TINY_MAX)
		return (tiny_malloc(s));
	else if (s <= SMALL_MAX)
		return (small_malloc(s));
	else
		return (large_malloc(s));
}

void	*calloc(size_t nmemb, size_t size)
{
	void	*addr;

	addr = malloc(nmemb * size);
	pthread_mutex_lock(&g_mutex);
	if (addr)
		ft_memset(addr, 0, nmemb * size);
	pthread_mutex_unlock(&g_mutex);
	return (addr);
}
