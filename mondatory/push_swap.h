/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:46:14 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/16 16:37:55 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

# define RA 3
# define RB 4
# define RRA 5
# define RRB 6

# define STACK_A 1
# define STACK_B 2

# define UP 1
# define DOWN -1

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	top;
	int	length;
}	t_stack;

# define INT_MAX_LENGTH 11

void	init_stack(t_stack *stack, int size);
void	push_to_stack(t_stack *stack, int element);
int		pop_from_stack(t_stack *stack);
int		get_top_from_stack(t_stack *stack);

int		check_valid_args(char **av);
void	initialize_stack_a(t_stack *stack, int ac, char **av);
int		check_duplicate(t_stack *stack);

char	**parse_args(int ac, char **av);

void	custom_exit(char *s);
void	custom_exit_clean(char *s);

char	**free_matrix(char **grid);
long	ft_atol(const char *nptr);

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


void	sort_array(int *arr, int size);
int		*clone_array(int *arr, int size);
int		index_of(int *arr, int size, int item);
int		ft_min(int *a, int size);
int		ft_max(int *a, int size);
int		ft_abs(int a);
int		ft_max_2(int a, int b);

void	sort_stack_first(char **str, int size);
void	back_to_a(t_stack *stack_a, t_stack *stack_b, int size);
void	from_a_to_b(t_stack *stack_a, t_stack *stack_b);
void	how_to_top_a_methode_2(t_stack *a, int *inst, int index);
int		handle_shared(t_stack *stack_a, t_stack *stack_b,
			int *insta, int *instb);
void	do_shared_instruction_based_on_dir(t_stack *a, t_stack *b,
			int *inst, int *instb);
void	do_instruction_based_on_dir(t_stack *a, t_stack *b,
			int *inst, int stack);
int		is_stack_sorted(t_stack *a);
void	sort_stack_of_3(t_stack *stack);
int		get_cheapest_index(t_stack *a, t_stack *b);
int		calcul_cost(t_stack *a, t_stack *b, int a_index);
int		get_move_direction(t_stack *stack, int index);
void	bring_top_top_a(t_stack *stack, int target_index);
void	bring_top_top_b(t_stack *stack, int target_index);
int		get_terget_index(t_stack *b, int item);
void	init_stacks_a_b(t_stack *a, t_stack *b, char **str, int size);
void	duplicate_and_sort(t_stack *a, t_stack *b);
int		get_move_index(t_stack *stack, int index);
void	check_and_sort(t_stack *stack_a, t_stack *stack_b);

void	clean_stacks(t_stack *a, t_stack *b);

#endif