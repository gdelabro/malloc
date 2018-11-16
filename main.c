/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:59:35 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/16 21:11:46 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int argc, char const *argv[]) {
  char *str;
  int i;

  malloc2(10);
  malloc2(10);
  str = malloc2(10);
  malloc2(10);
  malloc2(10);


  str = realloc2(str, 130);
  show_alloc_mem();
  ft_printf("\n\n");

  str = realloc2(str, 10210);
  show_alloc_mem();
  ft_printf("\n\n");

  str = realloc2(str, 10);
  str = realloc2(0, 30);
  show_alloc_mem();
  return 0;
}
