/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:52 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/26 05:27:00 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 10000
# ifndef OPEN_MAX
#  define OPEN_MAX 1000
# endif
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <wchar.h>
# include <unistd.h>
# include <limits.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_nbr_part
{
	unsigned long long	sitp;
	long long			intp;
	double				dp;
}						t_nbr_part;

int						ft_ipower(int c, int power);
double					ft_npower(double c, int power);
uintmax_t				ft_bigpower(int nbr, int exp);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putwchar(wchar_t c);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putlstr(char const *s, int len);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putnbr(int n);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_itoa(int n);
char					*ft_itoa_base(intmax_t nbr, int base);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memalloc(size_t size);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
int						ft_isdigit(int c);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strstr(const char *haystack, const char *needle);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *h, const char *n, size_t len);
size_t					ft_strnboccur(char const *str, int c);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					ft_memdel(void **ap);
char					*ft_rchr(char *str, char c);
char					*ft_strnew(size_t size);
char					*ft_strnew_free(size_t size, char *str);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strsub_free(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_memljoin(char const *s1, char const *s2, int n,
						int l);
char					*ft_strjoin_free(char const *s1, char const *s2,
						int n);
char					*ft_strjoin_freei(char const *s1, char const *s2, int n,
						int pos);
char					*ft_strnjoin(char const *s1, char const *s2,
						size_t len);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_strdup(const char *s1);
char					*ft_strdup_free(const char *s1, char *str);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *new);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
t_list					*ft_lstcpy(t_list *list);
void					ft_push_back(t_list **head, void *content);
size_t					ft_wordcount(char *str, char c);
long long int			ft_atol(const char *str);
void					push_back(t_list **head, void *content);
size_t					ft_strchri(const char *s, int c);
int						ft_ispowerof2(int x);
int						ft_nbdigit(int nbr);
int						ft_llnbdigit(long long nbr);
char					*ft_ftoa(long double nbr, int prec);
char					*round_str_double(char *str);
int						get_next_line(const int fd, char **line);

#endif
