/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:09:56 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/16 21:01:05 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

void   *large_malloc(size_t s)
{
    void *addr;

    addr = mmap(NULL, s + sizeof(t_block), PROT_READ | PROT_WRITE,
      MAP_ANON | MAP_PRIVATE, -1, 0);
    if (addr == (void*)-1)
      return (NULL);
    creat_block(addr, s, LARGE);
    e.total += s;
    return (addr + sizeof(t_block));
}
