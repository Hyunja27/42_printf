/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:32:23 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/21 10:16:14 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;

char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_isdigit(int n);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t			ft_strlen(const char *str);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void			inttochar_fd(int n, int fd);
char			*ft_strchr(const char *str, int tg);
void			ft_bzero(void *p, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_isascii(int n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
void			*ft_memccpy(void *dest, void *src, int c, size_t n);
int				ft_isprint(int n);
void			ft_putendl_fd(char *s, int fd);
int				ft_toupper(int n);
char			*ft_strrchr(char *str, int tg);
int				ft_isalpha(int c);
void			*ft_memchr(const void *p, int tg, size_t n);
void			ft_putchar_fd(char c, int fd);
void			*ft_memset(void *p, int tg, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			*ft_memmove(void *dest, void *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t many, size_t size);
char			*ft_strdup(const char *str);
int				ft_atoi(const char *str);
int				ft_isalnum(int n);
char			*ft_itoa(int n);
int				ft_tolower(int n);
char			**ft_split(char const *str, char c);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s1, char const *set);

//add on..
char			*ft_strndup(const char *str, size_t n);
char			*ft_strchrs(const char *str, char *to_find);
void			*ft_memset_chr(char *p, char c, int n);
long long		ft_int_len(long long n);
char			*ft_itoa_no_minus(int n);
char			*ft_ltoa(long long n);
int				is_space(char c);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
char			*ft_print_memory(void *addr, unsigned int size);
char			*ft_strcat_chr(char const *s1, char c);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));
#endif
