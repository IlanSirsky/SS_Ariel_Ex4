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

void freeNodes(pnode *head)
{
    if (!head)
    {
        return;
    }
    pnode n = *head;
    pnode *prev = head;
    pnode temp = n;
    while (n)
    {
        *prev = n->next;
        temp = n;
        while (temp)
        {
            pedge *tempEdge = &(temp->edges);
            deleteFromListE(n->id, tempEdge, head);
            temp = temp->next;
        }
        deleteFromListN(n->id, head);
        n = *prev;
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