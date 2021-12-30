#include <stdio.h>
#include "graph.h"

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

node *newNode(int id, node *next)
{
    node *p = (node *)malloc(sizeof(node));
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
            edge **pe = &(p->edges)
            free(p);
            freeEdges(pe)
            p = *prev;
        }
        else
        {
            prev = &(p->next);
            p = p->next;
        }
    }
}

void freeNodes(node **h){
    node p = *h;
    node *prev = h;
    while(p){
        *prev = p->next;
        edge **pe = &(p->edges)
        free(p);
        freeEdges(pe)
        p = *prev;
    }
}