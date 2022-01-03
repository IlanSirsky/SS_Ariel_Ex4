#include <stdio.h>
#include <stdlib.h>

#include "edges.h"
#include "nodes.h"
#include "graph.h"

node *newNode(int id)
{
    pnode p = (pnode)malloc(sizeof(node));
    if (p == NULL)
    {
        return NULL;
    }
    p->id = id;
    p->next = NULL;
    p->edges = NULL;
    return p;
}

void insertLastN(int id, pnode *head)
{
    pnode *p = head;
    while (*p)
    {
        p = &((*p)->next);
    }
    *p = newNode(id);
}

void deleteFromListN(int id, pnode *h)
{
    if (!h || !*h)
    {
        return;
    }
    if ((*h)->id == id)
    {
        pnode hold = *h;
        *h = (*h)->next;
        free(hold);
    }
    pnode p = *h;
    while (p->next && p->next->id != id)
    {
        p = p->next;
    }
    if (!p->next)
    {
        return;
    }
    pnode tmp = p->next;
    p->next = p->next->next;
    free(tmp);
}

void freeNodes(pnode *h)
{
    if (!h)
    {
        return;
    }
    printf("im here\n");
    pnode p = *h;
    pnode *prev = h;
    while (p)
    {
        *prev = p->next;
        pedge *pe = &(p->edges);
        free(p);
        freeEdges(pe);
        p = *prev;
    }
}

pnode getNode(pnode *head, int id)
{
    pnode h = *head;
    while (h)
    {
        if (h->id == id)
        {
            return h;
        }
        h = h->next;
    }
    return NULL;
}