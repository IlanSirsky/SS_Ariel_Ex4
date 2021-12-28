#include <stdio.h>
#include "nodes.h"

typedef struct Node
{
    int dest;
    int id;
    struct Node *next;
} Node;

Node *newNode(int id, Node *next)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = id;
    p->next = next;
    return p;
}

void insertLast(int id, struct Node **head)
{
    struct Node **p = head;
    while (*p)
        p = &((*p)->next);
    *p = newNode(id, NULL);
}

void deleteFromList(int id, Node **h)
{
    if (!*h)
        return;
    Node *p = *h;
    Node **prev = h;
    while (p)
    {
        if (p->id == id)
        {
            *prev = p->next;
            free(p);
            p = *prev;
        }
        else
        {
            prev = &(p->next);
            p = p->next;
        }
    }
}