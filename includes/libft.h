/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:11 by rantario          #+#    #+#             */
/*   Updated: 2022/01/24 17:01:49 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define UI unsigned int 
# define ULI unsigned long int 
# define ULLI unsigned long long int 
# define LI long int 
# define LLI long long int 
# define UC unsigned char
# define ULC unsigned long char

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	ft_linebreak(char *line);
char	**ft_split_str(char const *s, char *c);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(const char *str, UI start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(UI, char));
void	ft_striteri(char *s, void (*f)(UI, char *));
void	save_free(char **str);

void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *str);
void	ft_intswap(int *a, int *b);

void	*ft_memset(void *str, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memfree(void **ptr);

void	quick_sort(int *arr, int low, int high);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_iscount(int c, char *base);
int		ft_isin(int c, char *base);
int		ft_isspace(int c);
int		ft_isspace(int c);
int		ft_iswhere(int c, char *base);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

int		ft_abs(long num);
int		ft_baselen(long num, int base);
int		ft_hexlen(long num);
float	ft_invsqrt(float x);
int		ft_nbrlen(long num);
int		ft_power(int num, unsigned int power);
float	ft_invsqrt(float number);
float	to_degrees(float radians);
float	to_radians(float degrees);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putendl(char *s);
void	ft_putnbr(int n);

t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif