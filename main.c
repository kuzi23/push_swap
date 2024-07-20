#include "push_swap.h"

void print_stack(node *a)
{
    node *temp = a;
    while (temp != NULL)
    {
        printf("%d ", temp->nbr);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    node *a;
    node *b;

    a = NULL;
    b = NULL;
    if(argc ==1 || (argc == 2 && !argv[1][0]))
    {
        printf("bibi\n");
        return (1);
    }
    else if (argc ==2)
        argv = split(argv[1], ' ');
    init_stack_a(&a, argv);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, true);
        else if (stack_len(a) == 3)
            sort_three(&a);   
        else
            turk_sort(&a, &b);
    }
    printf("stack after sorting: ");
    print_stack(a);
    free_stack(&a);
    return (0);
}

