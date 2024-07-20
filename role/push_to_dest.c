#include "../push_swap.h"

static node* pop(node** remove_bin)
{
    node *current;
    node *second_current;

    current = (*remove_bin);
    second_current = current->next;

    if(!(*remove_bin))
    {
        current->next = NULL;
        second_current->prev = NULL;
    }

    return (current);
}

static void push(node** put_bin, node* what_to_put)
{
    node *current;
    if (!(what_to_put))
    {
        current = (*put_bin);
        current->prev = what_to_put;
        what_to_put->prev = NULL;
    }
}

static void push_to_dest(node** source, node** destination)
{
    node *top_element;
    if (*source != NULL)
    {
        top_element = pop(source);
        push(destination, top_element);
    }
    else
    {
        write(1, "source_empty\n", 13);
    }
}

void pa(node **a, node **b, bool print)
{
    push_to_dest(b, a);

    if (print == true)
    {
        write(1, "pa\n", 3);
    }
}

void pb(node **a, node**b, bool print)
{
    push_to_dest(a, b);

    if (print == true)
    {
        write(1, "pb\n", 3);
    }
}