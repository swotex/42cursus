/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njegat <njegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:10:08 by njegat            #+#    #+#             */
/*   Updated: 2023/01/10 14:58:15 by njegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

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
void	ft_addinstruction(char *new, char **instruction);
void	ft_printall(char **instruction);
void	ft_sort_three(t_stack *stack_a, char **instruction);
void	ft_sort_five(t_stack **stack_a, char **instruction);
t_stack	*ft_create_stack(char **array);
void	ft_sort_all(t_stack **stack_a, char **instruction);
t_stack	*ft_stacknew(int number);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackdelone(t_stack *lst);
void	ft_stackclear(t_stack **lst);
int		ft_stacklen(t_stack *lst);
void	ft_swap(t_stack *stack_swap, int target, char **instruction);
void	ft_rotate(t_stack *stack_rotate, int target, char **instruction);
void	ft_reverse_rotate(t_stack *stack_rrotate, int target, char **inst);
void	ft_push(t_stack **stack_s, t_stack **stack_c, int target, char **inst);
void	ft_double_free(char **array);
int		ft_alreadysort(t_stack *stack_sort);
int		ft_whereis_number(t_stack *stack_rch, int number);
void	ft_rotate_top(t_stack **stack_r, int number, int target, char **inst);
int		ft_whatis_max(t_stack *stack_rch);
void	ft_secondsort(t_stack **stack_a, t_stack **stack_b, char **instruction);
int		ft_smart_rotate(t_stack **stk_a, t_stack **stk_b, int nb, char **inst);
void	ft_butterfly(t_stack **stk_a, t_stack **stk_b, int cut, char **inst);
int		ft_sort(t_stack **stack_a);

#endif