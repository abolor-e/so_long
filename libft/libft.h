/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:02:11 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/22 16:46:02 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t		ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Structure for gnl!
typedef struct s_gnl
{
	char			*str_buf;
	struct s_gnl	*next;
}				t_gnl;

// get_next_line functions!
char	*get_next_line(int fd);
void	create_buffer_list(t_gnl **list, int fd);
void	include_list(t_gnl **list, char *res);
char	*get_until_newline(t_gnl *list);
void	prep_for_next_line(t_gnl **list);
int		newline_check_list(t_gnl *list);
int		len_until_newline(t_gnl *list);
void	copy(t_gnl *list, char *new_str);
void	free_list(t_gnl **list, t_gnl *new_node, char *str);
t_gnl	*ft_lstlast(t_gnl *list);

// Printf functions!
int		ft_printf(const char *format, ...);
int		ft_vprint(const char *fmt, va_list args, int *count);
int		check(unsigned long args, char c, int *count);
int		ft_nputchar(char c, int *count);
int		ft_nputnbr(long n, int *count);
int		ft_pputnbr(unsigned int n, int *count);
int		ft_nputstr(char *str, int *count);
int		ft_lowhexa(unsigned int lh, int *count);
int		ft_upphexa(unsigned int uh, int *count);
int		ft_add(unsigned long addr, int *count);
int		ft_putaddr(void *addr, int *count);

/* Bonus Functions */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif