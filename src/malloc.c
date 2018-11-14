/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:23:15 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/14 19:29:32 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../malloc.h"

t_malloc e = {
  NULL,
  NULL,
  NULL
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
