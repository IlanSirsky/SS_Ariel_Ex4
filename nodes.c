#include <stdio.h>
#include <stdlib.h>

#include "edges.h"
#include "nodes.h"
#include "graph.h"

node *newNode(int id, node *next)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        return NULL;
    }
    p->id = id;
    p->next = next;
    return p;
}

void insertLastN(int id, node **head)
{
    node **p = head;
    while (*p)
    {
        p = &((*p)->next);
    }
    *p = newNode(id, NULL);
}

void deleteFromListN(int id, node **h)
{
    if (!*h)
    {
        return;
    }
    node *p = *h;
    node **prev = h;
    while (p)
    {
        if (p->id == id)
        {
            *prev = p->next;
            edge **pe = &(p->edges);
            free(p);
            freeEdges(pe);
            p = *prev;
        }
        else
        {
            prev = &(p->next);
            p = p->next;
        }
    }
}

void freeNodes(node **head)
{
    pnode p = *head;
    pnode *prev = head;
    while (p != NULL)
    {
        *prev = p->next;
        edge **pe = &(p->edges);
        freeEdges(pe);
        free(p);
        p = *prev;
    }
}