#include <stdio.h>
#include <stdlib.h>

#include "edges.h"
#include "nodes.h"
#include "graph.h"

node *newNode(int id)
{
    pnode p = (pnode)malloc(sizeof(node));
    p->id = id;
    p->next = NULL;
    p->edges = NULL;
    return p;
}

void insertLastN(int id, pnode *head)
{
    pnode *p = head;
    while (*p){
        p = &((*p)->next);
    }
    *p = newNode(id);
}

void deleteFromList(int id, node **h)
{
    if (!*h)
        return;
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

void freeNodes(pnode *h){
    if (!h){
        return;
    }
    pnode p = *h;
    pnode *prev = h;
    while(p){
        *prev = p->next;
        edge **pe = &(p->edges);
        free(p);
        freeEdges(pe);
        p = *prev;
    }
}