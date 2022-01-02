#include <stdio.h>
#include <stdlib.h>

#include "edges.h"
#include "nodes.h"
#include "graph.h"

node *newNode(int id)
{
    pnode p = (pnode)malloc(sizeof(node));
    if (p == NULL){
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
    while (*p){
        p = &((*p)->next);
    }
    *p = newNode(id);
}

void deleteFromListN(int id, pnode *h)
{
    if (!*h){
        return;
    }
    node *p = *h;
    pnode *prev = h;
    while (p)
    {
        if (p->id == id)
        {
            *prev = p->next;
            pedge *pe = &(p->edges);
            free(p);
            printf("4\n");
            freeEdges(pe);
            printf("10\n");
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
        pedge *pe = &(p->edges);
        free(p);
        freeEdges(pe);
        p = *prev;
    }
}

pnode getNode (pnode *head, int id){
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