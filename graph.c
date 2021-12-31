#include <stdio.h>
#include <stdlib.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"

void build_graph_cmd(pnode *head)
{
    freeNodes(head);
    int count = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) //need fix
    {
        insertLastN(i, head);
    }
    char c = 0;
    scanf(" %c", &c);
    while (c == 'n')
    {
        int src = -1;
        scanf("%d", &src);
        pnode p = *head;
        while (p->id != src){
            p = p->next;
        }
        int dest = -1, weight = 0;
        char t;
        while (dest != 'n')
        {
            scanf("%d", &dest);
            t = getchar();
            printf("%d",dest);
            if (t == 'n')
            {
                break;
            }
            scanf("%d", &weight);
            insertLastE(dest, &(p->edges), weight, head);
        }
        c = t;
    }
}

void insert_node_cmd(pnode *head) {}
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);