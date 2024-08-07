#include "../push_swap.h"

static void rotate(node** stack)
{
    node *last_node = lastnode(stack);
    node *firstnode = (*stack);
    node *secondnode = firstnode->next;

    firstnode->next = NULL;
    secondnode->prev = NULL;

    firstnode->prev = last_node;
    last_node->next = firstnode;

    (*stack) = secondnode;
}

void ra(node** a, bool print)
{
    rotate(a);
    if (print == true)
    {
        write(1, "ra\n", 3);
    }
}

void rb(node** b, bool print)
{
    rotate(b);
    if(print == true)
    {
        write(1, "rb\n", 3);
    }
}

void rr(node**a, node**b, bool print)
{
    rotate(a);
    rotate(b);
    if (print == true)
    {
        write(1, "rb\n", 3);
    }
}