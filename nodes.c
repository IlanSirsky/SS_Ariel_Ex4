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
        printf("not allocated");
        return NULL;
    }
    p->id = id;
    p->next = next;
    return p;
}

void insertLastN(int id, pnode *head)
{
    pnode *p = head;
    printf("im here1\n");
    while (p != NULL)
    {
        p = &((*p)->next);
    }
    *p = newNode(id, NULL);

    //create a new node
    
    // node *newNode = (node *)malloc(sizeof(node));
    // if (newNode == NULL)
    // {
    //     printf("not allocated");
    //     return;
    // }
    // newNode->id = id;
    // newNode->next = NULL;
    // //if head is NULL, it is an empty list
    // if (*head == NULL)
    // {
    //     *head = newNode;
    //     printf("here1");
    // }
    // //Otherwise, find the last node and add the newNode
    // else
    // {
    //     node *lastNode = *head;
    //     //last node's next address will be NULL.
    //     while (lastNode->next != NULL)
    //     {
    //         lastNode = lastNode->next;
    //     }
    //     //add the newNode at the end of the linked list
    //     lastNode->next = newNode;
    // }
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
        prev = &(p->next);
        edge **pe = &(p->edges);
        freeEdges(pe);
        free(p);
        p = *prev;
    }
}