/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:23:15 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/12 20:05:12 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

t_malloc e = {
  NULL,
  NULL,
  NULL
};

void      *malloc2(size_t s) {
  void *ptr;

  if (!init_global_var())
    return (NULL);
  if (s <= TINY_BLOCK)
    return (tiny_malloc(s));
  ptr = mmap(NULL, s, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
  return (NULL);
}
