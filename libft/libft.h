/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:33:50 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/21 20:20:33 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_strchr(const char *str, char *cmp);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalpha(int c);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*get_next_line(int fd);
void	ft_putstr(char *str);

#endif
