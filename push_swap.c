/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:49:12 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 19:30:56 by jel-yous         ###   ########.fr       */
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
