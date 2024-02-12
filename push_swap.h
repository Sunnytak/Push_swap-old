/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:03:45 by stak              #+#    #+#             */
/*   Updated: 2024/02/12 17:44:54 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				lst;
	int				new;
	long int		content;
	int				push_cost;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

static int	ft_countstr(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
static int	ft_countstr(char const *s, char c);
static char	**ft_free(char **result, size_t j);
static char	**ft_strwordcount(char const *s, char c, char **string);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
int			ft_isdigit(char n);
int	ft_sign(char n);
int ft_checker(char *argv);
static int	check_overflow(long int i, long int check, long int sign);
long int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_dup_check(char **argv, int i);
void	ft_lstadd_back(t_list **lst, t_list *new);
static void	swap(t_list **head);
int	ft_lstsize(t_list *lst);
void	ss(t_list **a, t_list **b, bool checker);
void	sb(t_list **b, bool checker);
void	sa(t_list	**a, bool checker);
#endif