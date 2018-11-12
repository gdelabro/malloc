/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:59:35 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/12 20:15:02 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int argc, char const *argv[]) {
  char *str;
  int i;

  i = 0;
  ft_printf("%d\n", getpagesize());
while (i++ < 150)
{
  str = malloc2(100);
  ft_printf("%#.8x\n", str);}
  return 0;
}
