/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:24:16 by njegat            #+#    #+#             */
/*   Updated: 2023/01/08 16:14:29 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stack_list
{
	int					number;
	struct s_stack_list	*next;
}	t_stack;

int		ft_check_empty(char **argv, int argc);
char	**ft_check_double(char **array);
int		ft_tab_len(char **array);
char	**ft_symplify(char **array);
char	**ft_check_entry(int argc, char **argv);
t_stack	*ft_create_stack(char **array);
t_stack	*ft_stacknew(int number);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackdelone(t_stack *lst);
void	ft_stackclear(t_stack **lst);
int		ft_stacklen(t_stack *lst);
void	ft_swap(t_stack *stack_swap);
void	ft_rotate(t_stack *stack_rotate);
void	ft_reverse_rotate(t_stack *stack_rrotate);
void	ft_push(t_stack **stack_s, t_stack **stack_c);
void	ft_double_free(char **array);
int		ft_alreadysort(t_stack *stack_sort);

#endif