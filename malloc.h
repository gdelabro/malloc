/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:12:56 by gdelabro          #+#    #+#             */
/*   Updated: 2018/10/25 16:14:27 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "ft_printf/ft_printf.h"

typedef struct s_malloc
{

}              t_malloc;

void	free(void *ptr);
void	*malloc(size_t s);
void	*realloc(void *ptr, size_t size);
void  show_alloc_mem();

#endif
