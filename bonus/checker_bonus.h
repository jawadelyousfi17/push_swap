/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:09 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/18 15:39:31 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <limits.h>

# define INT_MAX_LENGTH 11

# define SA 1
# define SB 2
# define RA 3
# define RB 4
# define RRA 5
# define RRB 6
# define PA 7
# define PB 8
# define RR 9
# define RRR 10
# define SS 11
# define INVL_INST 12 

# define START 1
# define END 2

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	top;
	int	length;
}	t_stack;

void	init_stack(t_stack *stack, int size);
void	push_to_stack(t_stack *stack, int element);
int		pop_from_stack(t_stack *stack);
int		get_top_from_stack(t_stack *stack);
void	init_stacks_a_b(t_stack *a, t_stack *b, char **str, int size);
int		is_stack_sorted(t_stack *a);

int		check_valid_args(char **av);
void	initialize_stack_a(t_stack *stack, int ac, char **av);
int		check_duplicate(t_stack *stack);
char	**parse_args(int ac, char **av);

void	custom_exit(char *s);

char	**free_matrix(char **grid);
long	ft_atol(const char *nptr);
char	*ft_strjoin_2(const char *s1, const char *s2);
char	*get_next_line_2(int fd, int flag);

int		compare_str(char *str, char *str1);
int		get_instruction(char *inst);
void	do_inst(t_stack *a, t_stack *b, char *inst);
void	invalid_inst(t_stack *a, t_stack *b, char *str);
void	clean_stacks_and_exit(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b, int flag);
void	pa(t_stack *a, t_stack *b, int flag);
void	sa(t_stack *a, int flag);
void	rra(t_stack *a, int flag);
void	ra(t_stack *a, int flag);
void	rrb(t_stack *a, int flag);
void	rb(t_stack *a, int flag);
void	sb(t_stack *a, int flag);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif