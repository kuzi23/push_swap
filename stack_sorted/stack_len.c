#include "../push_swap.h"

int stack_len(node *stack)
{
    int i;
    node *current = stack;

    i = 0;
    if (!(current))
        return (0);
    while (current != NULL)
    {
        i += 1;
        current = current->next;
    }
    return (i);
}
