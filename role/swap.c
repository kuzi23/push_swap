#include "../push_swap.h"

static void swap(node** stack)
{
    node *temp;

    if (!(*stack) || !((*stack)->next))
        return;
    temp = *stack;
    *stack = (*stack)->next;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
}

void sa(node** a, bool print)
{
    swap(a);
    if (print == true)
    {
        write(1, "sa\n", 3);
    }
}

void sb(node** b, bool print)
{
    swap(b);
    if(print == true)
    {
        write(1, "sb\n", 3);
    }
}