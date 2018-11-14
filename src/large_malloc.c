/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:09:56 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/14 19:25:23 by gdelabro         ###   ########.fr       */
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
    return (addr);
}
