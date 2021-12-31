#include <stdio.h>
#include <stdlib.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"

edge *newEdge(int weight, int dest, edge *next, pnode *head)
{
    edge *e = (edge *)malloc(sizeof(edge));
    if (e == NULL)
    {
        return NULL;
    }
    pnode temp = head;
    while (temp->id != dest){
        temp = temp->next;
    }
    e->weight = weight;
    e->endpoint = temp;
    e->next = next;
    return e;
}

void insertLastE(int dest, edge **hEdges, int w, pnode *head)
{
    edge **e = hEdges;
    while (*e)
    {
        e = &((*e)->next);
    }
    *e = newEdge(w, dest, NULL, head);
}

// void deleteFromListE(int id, edge **h)
// {
//     if (!*h)
//         return;
//     edge *p = *h;
//     edge **prev = h;
//     while (p)
//     {
//         if (p->id == id)
//         {
//             *prev = p->next;
//             free(p);
//             p = *prev;
//         }
//         else
//         {
//             prev = &(p->next);
//             p = p->next;
//         }
//     }
// }

void freeEdges(edge **edge)
{
    pedge p = *edge;
    pedge *prev = edge;
    while (p)
    {
        *prev = p->next;
        free(p);
        p = *prev;
    }
}