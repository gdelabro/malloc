/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:59:35 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/20 22:03:57 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(int argc, char const *argv[]) {
	char *str;

	str = malloc(32);
  strcpy(str, "bonjour");
  show_alloc_mem_hex(str);
	return 0;
}
