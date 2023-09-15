/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:45:19 by tdhaussy          #+#    #+#             */
/*   Updated: 2023/07/26 01:51:26 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*---------------------------------LIBFT--------------------------------------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*---------------------------------FT_PRINTF----------------------------------*/

int		ft_printf_fd(int fd, const char *s, ...);
int		ft_putnbr_base_fd(long n, char *base, int fd);
int		ft_putptr_pf_fd(unsigned long n, int fd);
int		ft_putstr_pf_fd(char *s, int fd);
int		ft_putchar_pf_fd(char c, int fd);

/*---------------------------------GET_NEXT_LINE------------------------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	gnl_free_all(char **s1, char **s2);
void	gnl_free_one(char **s);
char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_realloc_stock(char *s);
int		gnl_find_nl(char *s);

/*---------------------------------NEW_UTILS----------------------------------*/

int		ft_strcmp(const char *s1, const char *s2);
char	**copy_tab(char **tab);
void	ft_swap_string(char **tab, int first, int second);
void	del_char(char *str, char c);
void	del_single_char(char *str, int index);
char	*ft_strjoin_free_first(char *s1, char *s2);
int		consecutive_char(char c, char *str);
void	ft_free_tab(char **tab);
char	*ft_dtoa(double d, int digits);

#endif
