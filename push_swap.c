/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:49:12 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 19:21:39 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_stack(t_stack stack)
{
    int i = stack.top;
    if (stack.top == -1)
        ft_printf("Stack is empty \n");
    while (i >= 0)
    {
        ft_printf("%d\n", stack.arr[i]);
        i--;
    }
    ft_printf("\n");
}

int get_move_index(t_stack *stack, int index)
{
    if (index <= stack->length / 2)
        return index + 1;
    return stack->length - index - 1;
}

void duplicate_and_sort(t_stack *a, t_stack *b)
{
    int *duplicate;
    int i;
    int size;

    size = a->size;
    duplicate = clone_array(a->arr, a->size);
    if (!duplicate)
    {
        free(a->arr);
        free(b->arr);
        custom_exit("ERROR IN ALLOCATION OF duplicate\n");
    }
    sort_array(duplicate, a->size);
    i = 0;
    while (i < size)
    {
        a->arr[i] = index_of(duplicate, size, a->arr[i]);
        i++;
    }
    free(duplicate);
}

void init_stacks_a_b(t_stack *a, t_stack *b, char **str, int size)
{
    init_stack(a, size);
    if (!a->arr)
    {
        free_matrix(str);
        custom_exit("ERROR\n");
    }
    initialize_stack_a(a, size, str);
    if (!check_duplicate(a))
    {
        free(a->arr);
        free_matrix(str);
        custom_exit("ERROR DIPLUCATION\n");
    }
    init_stack(b, size);
    if (!b->arr)
    {
        free_matrix(str);
        free(a->arr);
        custom_exit("ERROR\n");
    }
    free_matrix(str);
    duplicate_and_sort(a, b);
}

int get_terget_index(t_stack *b, int item)
{
    int max;
    int i;
    int closetNumber;

    i = 0;
    closetNumber = -1;
    max = ft_max(b->arr, b->length);
    if (item < ft_min(b->arr, b->length) || item > max)
        return index_of(b->arr, b->length, max);
    while (i < b->length && closetNumber == -1)
    {
        if (b->arr[i] < item)
            closetNumber = b->arr[i];
        i++;
    }
    while (i < b->length)
    {
        int e = b->arr[i];
        if (e < item && ft_abs(e - item) < ft_abs(closetNumber - item))
            closetNumber = e;
        i++;
    }
    return index_of(b->arr, b->length, closetNumber);
}

void bring_top_top_b(t_stack *stack, int target_index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(stack, target_index);
    if (target_index <= stack->length / 2)
        instruction = RRB;
    else
        instruction = RB;
    i = 0;
    while (i < moves_count)
    {
        if (instruction == RB)
            rb(stack, 1);
        if (instruction == RRB)
            rrb(stack, 1);
        i++;
    }
}

void bring_top_top_a(t_stack *stack, int target_index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(stack, target_index);
    if (target_index <= stack->length / 2)
        instruction = RRA;
    else
        instruction = RA;
    i = 0;
    while (i < moves_count)
    {
        if (instruction == RA)
            ra(stack, 1);
        if (instruction == RRA)
            rra(stack, 1);
        i++;
    }
}
int get_move_direction(t_stack *stack, int index)
{
    if (index <= stack->length / 2)
        return UP;
    return DOWN;
}
int calcul_cost(t_stack *a, t_stack *b, int a_index)
{
    int a_cost;
    int b_cost;
    int a_move_direction;
    int b_move_direction;

    a_move_direction = get_move_direction(a, a_index);
    b_move_direction = get_move_direction(b, get_terget_index(b, a->arr[a_index]));
    a_cost = get_move_index(a, a_index);
    b_cost = get_move_index(b, get_terget_index(b, a->arr[a_index]));
    if (a_move_direction == b_move_direction)
        return a_cost > b_cost ? a_cost : b_cost;
    return a_cost + b_cost;
}

int get_cheapest_index(t_stack *a, t_stack *b)
{
    int cheapest_move_index;
    int cost;
    int temp_cost;
    int i;

    i = 1;
    cheapest_move_index = 0;
    cost = calcul_cost(a, b, 0);
    while (i < a->length)
    {
        temp_cost = calcul_cost(a, b, i);
        if (temp_cost < cost)
        {
            cost = temp_cost;
            cheapest_move_index = i;
        }
        i++;
    }
    return cheapest_move_index;
}

void sort_stack_of_3(t_stack *stack)
{
    int a;
    int b;
    int c;

    a = stack->arr[2];
    b = stack->arr[1];
    c = stack->arr[0];
    if (a == ft_min(stack->arr, 3))
    {
        if (b > c)
        {
            rra(stack, 1);
            sa(stack, 1);
        }
    }
    else if (a == ft_max(stack->arr, 3))
    {
        ra(stack, 1);
        if (b > c)
            sa(stack, 1);
    }
    else if (b < c)
        sa(stack, 1);
    else
        rra(stack, 1);
}

int is_stack_sorted(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->length - 1)
    {
        if (a->arr[i] < a->arr[i + 1])
            return 0;
        i++;
    }
    return 1;
}

void do_instruction_based_on_dir(t_stack *a, t_stack *b, int *inst, int stack)
{
    int dir;

    dir = inst[1];
    if (stack == STACK_A)
    {
        if (dir == UP)
            ra(a, 1);
        if (dir == DOWN)
            rra(a, 1);
    }
    else
    {
        if (dir == UP)
            rb(b, 1);
        if (dir == DOWN)
            rrb(b, 1);
    }
    inst[0]--;
}

void do_shared_instruction_based_on_dir(t_stack *a, t_stack *b, int *inst, int *instb)
{
    if (inst[1] == UP)
        rr(a, b);
    if (inst[1] == DOWN)
        rrr(a, b);
    inst[0]--;
    instb[0]--;
}

int handle_shared(t_stack *stack_a, t_stack *stack_b, int *insta, int *instb)
{
    if (insta[1] == instb[1])
    {
        while (insta[0] && instb[0])
            do_shared_instruction_based_on_dir(stack_a, stack_b, insta, instb);
        while (insta[0])
            do_instruction_based_on_dir(stack_a, stack_b, insta, STACK_A);
        while (instb[0])
            do_instruction_based_on_dir(stack_a, stack_b, instb, STACK_B);
    }
    else
    {
        while (insta[0])
            do_instruction_based_on_dir(stack_a, stack_b, insta, STACK_A);
        while (instb[0])
            do_instruction_based_on_dir(stack_a, stack_b, instb, STACK_B);
    }
    return 0;
}

void how_to_top_a_methode_2(t_stack *a, int *inst, int index)
{
    int instruction;
    int moves_count;

    moves_count = get_move_index(a, index);
    if (index <= a->length / 2)
        instruction = DOWN;
    else
        instruction = UP;
    inst[0] = moves_count;
    inst[1] = instruction;
}

void from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int inst_a[2];
    int inst_b[2];
    int i;

    i = 0;
    while (stack_a->length > 3)
    {
        int cheapest_index = get_cheapest_index(stack_a, stack_b);
        int target_index = get_terget_index(stack_b, stack_a->arr[cheapest_index]);
        how_to_top_a_methode_2(stack_a, inst_a, cheapest_index);
        how_to_top_a_methode_2(stack_b, inst_b, target_index);
        handle_shared(stack_a, stack_b, inst_a, inst_b);
        pb(stack_a, stack_b, 1);
    }
}

void back_to_a(t_stack *stack_a, t_stack *stack_b, int size)
{
    int k;
    int a;

    a = 0;
    k = 0;
    while (size)
    {
        if (stack_b->arr[stack_b->top] > ft_max(stack_a->arr, stack_a->length) || stack_a->arr[stack_a->top] == stack_b->arr[stack_b->top] + 1)
            pa(stack_a, stack_b, 1);
        else
        {
            a = index_of(stack_a->arr, stack_a->size,
                         stack_b->arr[stack_b->top] + 1);
            k = 0;
            while (k < a + 1)
            {
                rra(stack_a, 1);
                k++;
            }
            pa(stack_a, stack_b, 1);
        }
        size--;
    }
}

void sort_stack_first(char **str, int size)
{
    t_stack stack_a;
    t_stack stack_b;
    int max_index;

    init_stacks_a_b(&stack_a, &stack_b, str, size);
    if (is_stack_sorted(&stack_a))
    {
         free(stack_a.arr);
        free(stack_b.arr);
        return;       
    }
    if (stack_a.length == 2)
    {
        sa(&stack_a, 1);
            free(stack_a.arr);
        free(stack_b.arr);
        return ;
    }
    if (stack_a.length == 3)
    {
        sort_stack_of_3(&stack_a);
        free(stack_a.arr);
        free(stack_b.arr);
        return;
    }
    if (stack_a.length > 4)
        pb(&stack_a, &stack_b, 1);
    pb(&stack_a, &stack_b, 1);
    from_a_to_b(&stack_a, &stack_b);
    max_index = index_of(stack_b.arr, stack_b.length, ft_max(stack_b.arr, stack_b.length));
    if (stack_b.length > 1)
        bring_top_top_b(&stack_b, max_index);
    sort_stack_of_3(&stack_a);
    back_to_a(&stack_a, &stack_b, stack_b.length);
    while (!is_stack_sorted(&stack_a))
        rra(&stack_a, 1);
    free(stack_a.arr);
    free(stack_b.arr);
}

int main(int ac, char **av)
{
    int size;
    char **str;

    if (ac < 2)
        return (EXIT_FAILURE);
    str = parse_args(ac, av);
    if (!str)
        custom_exit("ERROR\n");
    size = check_valid_args(str);
    if (!size)
    {
        free_matrix(str);
        custom_exit("ERROR\n");
    }
    sort_stack_first(str, size);
    return 0;
}
