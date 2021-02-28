/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:02:41 by nieyraud          #+#    #+#             */
/*   Updated: 2020/10/19 14:12:19 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);
void	        *ft_ralloc(void *ptr, size_t size, size_t new_size);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_find_char(const char c, const char *str);
char			*ft_itoa(int n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
int				ft_search(char *str, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
float			ft_strfloat(const char *str, int *offset, int *error);
char			*ft_strjoin_free(char *s1, char *s2, char state);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
