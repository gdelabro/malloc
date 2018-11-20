/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:12:56 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/20 22:00:43 by gdelabro         ###   ########.fr       */
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

# define MAGIC_FREE 145785245

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

t_malloc g_e;
extern pthread_mutex_t g_mutex;

void	         free(void *ptr);
void	         *malloc(size_t s);
void	         *realloc(void *ptr, size_t size);
void           *calloc(size_t nmemb, size_t size);
void           show_alloc_mem();
void           *tiny_malloc(size_t s);
void           *small_malloc(size_t s);
void           *large_malloc(size_t s);
int            init_global_var();
void           big_free(void);
int            init_global_var_tiny();
int            init_global_var_small();
void           show_alloc_mem_hex(void *addr);
void           creat_block(void *addr, int size, int type);

#endif
