#include "../push_swap.h"

bool stack_sorted(node* stack)
{
    if (!(stack))
        return (1);
    while(stack->next != NULL)
    {
        if(stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}