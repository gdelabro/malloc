/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:09:56 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/20 21:07:18 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

int    large_malloc_length(int size)
{
  int i;

  i = getpagesize();
  while (i < size)
    i += getpagesize();
  return (i);
}

void   *large_malloc(size_t s)
{
    void *addr;

    addr = mmap(NULL, large_malloc_length(s + sizeof(t_block)),
    PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (addr == (void*)-1 && pthread_mutex_unlock(&g_mutex) != 45465468)
      return (NULL);
    creat_block(addr, s, LARGE);
    g_e.total += s;
    pthread_mutex_unlock(&g_mutex);
    return (addr + sizeof(t_block));
}
