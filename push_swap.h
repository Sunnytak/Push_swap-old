/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:03:45 by stak              #+#    #+#             */
/*   Updated: 2024/03/25 12:16:44 by stak             ###   ########.fr       */
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
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
	bool			above_median;
	bool			cheapest;
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
int			ft_sign(char n);
int			ft_checker(char *argv);
static int	check_overflow(long int i, long int check, long int sign);
long int	ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_dup_check(char **argv, int i);

//list
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);

//swap
void		swap_sa(t_list **a);
void		swap_sb(t_list **b);
void		swap_ss(t_list **a, t_list **b);

//rotate
void		rotate_ra(t_list **a);
void		rotate_rb(t_list **b);
void		rotate_rr(t_list **a, t_list **b);

//push
void		push_pa(t_list **a, t_list **b);
void		push_pb(t_list **a, t_list **b);

//reverse
void		reverse_rotate_rra(t_list **a);
void		reverse_rotate_rrb(t_list **b);
void		reverse_rotate_rrr(t_list **a, t_list **b);

//sort_helper
t_list		*highest(t_list **stack);
t_list		*lowest(t_list **stack);
t_list		*find_last(t_list *stack);

//sort

void		sort_3(t_list	**stack);

#endif