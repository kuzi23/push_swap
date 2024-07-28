#include "../push_swap.h"

void free_stack(node** a)
{
    while (*a != NULL)
    {
        node *temp = *a;
        *a = (*a)->next;
        free(temp);
    }
}

node* create_node(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        return (NULL);
    newNode->nbr = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return (newNode);
}

static void push(node **a, int value)
{
    node *newNode = create_node(value);

    if (*a == NULL)
    {
        *a = newNode;
        newNode->prev = NULL;
    }
    else
    {
        {
            newNode->next = *a;
            (*a)->prev = newNode;
            *a = newNode;
        }
    }
    
}

int init_stack_a(node** a, char **argv)
{
    char *endptr;
    long value;
    int i;

    i = 0;
    endptr = NULL;
    while (argv[i] != NULL)
    {
        errno = 0;
        value = strtol(argv[i], &endptr, 10);
        if (errno == ERANGE || *endptr != '\0' || value > INT_MAX || value < INT_MIN)
        {
            printf("long ints only\n");
            free_stack(a);
            return (-1);
        }
        else
        {
            push(a, value);
        }
        i++;
    }
    return (0);
}