/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:36:59 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/16 18:48:09 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void	      *ft_memcpy(void *dest, const void *src, size_t n);
int					ft_strlen_2(char *s, int i);
int					ft_taille_nb(long int nb, int base);
size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strcat_2(char *s1, const char *s2, int *t);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_taille_size_t(size_t nb, int base);
int					ft_strlenw(int *s);
char				*ft_strcat(char *s1, const char *s2);

#endif
