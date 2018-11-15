/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:59:35 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/15 18:53:18 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int argc, char const *argv[]) {
  char *str;
  char *str2;
  char *tmp;
  int i;

  i = 0;
  str = NULL;
  while (i++ < 30)
  {
    str = malloc2(543);
  }
  show_alloc_mem();
  return 0;
}
