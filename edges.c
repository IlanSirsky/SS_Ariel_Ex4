#include <stdio.h>
#include "graph.h"

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

edge *newEdge(int weight, pnode endpoint,edge *next)
{
    edge *p = (edge *)malloc(sizeof(edge));
    p->weight = weight;
    p->endpoint = endpoint;
    p->next = next;
    return p;
}

void insertLast(int id, struct edge **head)
{
    edge **p = head;
    while (*p)
        p = &((*p)->next);
    *p = newEdge(id, NULL);
}

void deleteFromList(int id, edge **h)
{
    if (!*h)
        return;
    edge *p = *h;
    edge **prev = h;
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

void freeEdges(edge **h){
    pedge p = *h;
    pedge *prev = h;
    while(p){
        *prev = p->next;
        free(p);
        p = *prev;
    }
}