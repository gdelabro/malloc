/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:59:35 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/14 19:34:13 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int argc, char const *argv[]) {
  char *str;
  char *tmp;
  int i;

  i = 0;
  str = NULL;
  while (i++ < 1024)
  {
    str = malloc2(1024);
    str[1029] = 42;
    ft_printf("%#.8d\n", str);
  }
  return 0;
}
