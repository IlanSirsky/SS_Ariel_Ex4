#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"

#define IN 9999999

void build_graph_cmd(pnode *head)
{
    freeNodes(head);
    int count = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        insertLastN(i, head);
    }
    char c = 0;
    while (scanf(" %c", &c) != 0)
    {
        if (c == 'n')
        {
            int src = -1;
            scanf("%d", &src);
            int dest, weight;
            while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
            {
                if (isalpha(dest))
                {
                    break;
                }
                addEdge(src, dest, weight, head);
            }
        }
        else
        {
            break;
        }
    }
}

void insert_node_cmd(pnode *head)
{
    int ind;
    scanf("%d", &ind);
    int dest, weight;
    pnode newNode = getNode(head, ind);
    if (newNode == NULL)
    {
        insertLastN(ind, head);
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest))
            {
                break;
            }
            addEdge(ind, dest, weight, head);
        }
    }
    else
    {
        pedge *pe = &(newNode->edges);
        freeEdges(pe);
        newNode->edges = NULL;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest))
            {
                break;
            }
            addEdge(ind, dest, weight, head);
        }
    }
}
void delete_node_cmd(pnode *head) {
    int ind;
    scanf("%d", &ind);
    deleteFromListN(ind, head);
    printGraph_cmd(head);
    pnode temp = *head;
    while (temp)
    {
        pedge *tempEdge = &(temp->edges);
        deleteFromListE(ind, tempEdge);
        temp = temp->next;
    }
}

void printGraph_cmd(pnode *head)
{ //for self debug
    if (!head)
    {
        return;
    }
    pnode temp = *head;
    while (temp)
    {
        printf("Node{%d} -- Edges{", temp->id);
        pedge ed = temp->edges;
        while (ed != NULL)
        {
            printf("%d -> %d -- %d,  ", temp->id, ed->endpoint->id, ed->weight);
            ed = ed->next;
        }
        temp = temp->next;
        printf("}\n");
    }
    printf("\n");
}

void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);


void TSP_cmd(pnode head) {
    int count;
    scanf("%d", &count);
    if (count == 0){
        return;
    }
    int cities[count];
    for (size_t i = 0; i < count; i++)
    {
        scanf("%d", &cities[i]);
    }
    
}

int dijsktra(pnode *head, int source, int target)
{
    pnode curr = *head;
    int N = 0;
    while (curr)
    {
        curr = curr->next;
        N++;
    }

    int cost[N][N];

    memset(cost, IN, N * N * sizeof(int));

    curr = *head;
    while (curr)
    {
        pedge ed = curr->edges;
        while (ed)
        {
            cost[curr->id][ed->endpoint->id] = ed->weight;
            ed = ed->next;
        }
        curr = curr->next;
    }

    int dist[N], prev[N];
    int selected[N];
    memset(selected, 0, N * sizeof(int));
    int i, m, min, start, d, j;
    char path[N];
    for (i = 1; i < N; i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start] = 1;
    dist[start] = 0;
    while (selected[target] == 0)
    {
        min = IN;
        m = 0;
        for (i = 1; i < N; i++)
        {
            d = dist[start] + cost[start][i];
            if (d < dist[i] && selected[i] == 0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if (min > dist[i] && selected[i] == 0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while (start != -1 && start < N)
    {
        path[j++] = start + 65;
        start = prev[start];
    }
    path[j] = '\0';
    strrev(path);
    return dist[target];
}

char *strrev(char *str)
{
    if (!str)
    {
        return NULL;
    }
    char *begin = str;
    char *end = *begin ? str + strlen(str) - 1 : begin; /* ensure non-empty */
    char tmp;
    while (end > begin)
    {
        tmp = *end;
        *end-- = *begin;
        *begin++ = tmp;
    }
    return str;
}