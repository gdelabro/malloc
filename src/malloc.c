/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:23:15 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/15 19:32:53 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

t_malloc e = {
  NULL,
  NULL,
  NULL,
  0
};

void      *malloc2(size_t s)
{
  if (s <= 0)
    return (NULL);
  else if (s <= TINY_MAX)
    return (tiny_malloc(s));
  else if (s <= SMALL_MAX)
    return (small_malloc(s));
  else
    return (large_malloc(s));
  return (NULL);
}

void    *calloc2(size_t nmemb, size_t size)
{
  void *addr;

  addr = malloc2(nmemb * size);
  if (addr)
    ft_memset(addr, 0, nmemb * size);
  return (addr);
}
