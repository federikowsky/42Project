/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 02:05:54 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 23:55:25 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(unsigned int n, int base);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_putnbr_base(long int n, char *base);
int 	ft_fastncmp(const char *ptr0, const char *ptr1, int len);
/*
Return a substring of s from start to end exclude
*/
char	*ft_substr2(const char *s, int start, int end);

/* 
Returns the index of the first occurrence of a char 
passed as argument from the starting position
if not found -1 is returned
*/
int		ft_strfocc(char *s, int start, int c);

/* 
Returns the index of the last occurrence of a char 
passed as argument from the starting position
if not found -1 is returned
*/
int		ft_strlocc(char *s, int start, int c);

/*
returns 1 if the current character is contained 
within a set of characters that it should belong to
0 otherwise
*/
int		ft_strcfnd(char c, char const *set);

/*
take 1 * N matrix where N is number of 
allocated and stored string and
print the matrix
*/
void	ft_sosprint(char **ss);

/*
take 1 * N matrix where N is number of 
allocated and stored string and
Return number of string allocated in matrix
*/
int		ft_soslen(char **matrix);

/*
take 1 * N matrix where N is number of 
allocated and stored string and
free the input matrix 
*/
int		ft_sosfree(char **matrix);

/*
take 1 * N matrix where N is number of 
allocated and stored string and
allocate a new matrix then copy the input matrix 
and return a pointer to it.
*/
char	**ft_soscpy(char **mat);

/*
take 1 * N matrix where N is number of 
allocated and stored string and
copies the input matrix and adds the string passed 
as argument in a matrix allocated with malloc(). 
Free the old matrix and return a pointer to the new matrix
*/
char	**ft_sosadd(char **ss, char *cmd);
#endif