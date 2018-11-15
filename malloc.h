/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:12:56 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/14 20:01:07 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "ft_printf/ft_printf.h"
# include <sys/mman.h>
# include <sys/resource.h>
# include <pthread.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define TINY 1
# define SMALL 2
# define LARGE 4

# define TINY_MAX     128
# define TINY_BLOCK	  (TINY_MAX + sizeof(t_block))
# define TINY_MEM_LENGTH (15 * getpagesize())

# define SMALL_MAX    1024
# define SMALL_BLOCK	(SMALL_MAX + sizeof(t_block))
# define SMALL_MEM_LENGTH (265 * getpagesize())

typedef struct s_block
{
  int          free;
  void         *addr;
  int          size;
  int          type;
  void         *next;
}              t_block;

typedef struct s_malloc
{
  t_block      *block;
  void         *mem_tiny;
  void         *mem_small;
  int          total;
}              t_malloc;

t_malloc e;

void	         free2(void *ptr);
void	         *malloc2(size_t s);
void	         *realloc2(void *ptr, size_t size);
void           show_alloc_mem();
void           *tiny_malloc(size_t s);
void           *small_malloc(size_t s);
void           *large_malloc(size_t s);
int            init_global_var();
int            init_global_var_tiny();
int            init_global_var_small();
void           creat_block(void *addr, int size, int type);

#endif
