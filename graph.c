#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"

#define IN 999999

void adapter_cmd(char c, pnode *graph)
{
    if (c == 'A')
    {
        build_graph_cmd(graph);
    }

    else if (c == 'B')
    {
        insert_node_cmd(graph);
        printGraph_cmd(graph);
    }

    else if (c == 'D')
    {
        delete_node_cmd(graph);
        printGraph_cmd(graph);
    }

    else if (c == 'S')
    {
        shortsPath_cmd(*graph);
    }

    else if (c == 'T')
    {
        TSP_cmd(*graph);
    }
}

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
    printGraph_cmd(head);
    adapter_cmd(c, head);
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
    adapter_cmd(getchar(), head);
}
void delete_node_cmd(pnode *head)
{
    int ind;
    scanf("%d", &ind);

    pnode temp = *head;
    while (temp)
    {
        pedge *tempEdge = &(temp->edges);
        deleteFromListE(ind, tempEdge, head);
        temp = temp->next;
    }

    printGraph_cmd(head);
    deleteFromListN(ind, head);
    printGraph_cmd(head);

    adapter_cmd(getchar(), head);
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

void shortsPath_cmd(pnode head)
{
    int src = 0, dst = 0;
    scanf("%d", &src);
    scanf("%d", &dst);
    printf("%d\n", shortsPath(head, src, dst));
}

void TSP_cmd(pnode head)
{
    int count;
    scanf("%d", &count);
    if (count == 0)
    {
        return;
    }
    int cities[count];
    for (size_t i = 0; i < count; i++)
    {
        scanf("%d", &cities[i]);
    }
}

int min(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int shortsPath(pnode head, int source, int target)
{
    if (!head)
    {
        return -1;
    }

    pnode curr = head;
    int N = 0;
    while (curr)
    {
        if (N < curr->id){
            N = curr->id;
        }
        curr = curr->next;
    }

    int mat[N][N];
    
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            mat[k][i] = IN;
        }
    }

    curr = head;
    while (curr)
    {
        pedge ed = curr->edges;
        while (ed)
        {
            mat[curr->id][ed->endpoint->id] = ed->weight;
            ed = ed->next;
        }
        curr = curr->next;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    mat[i][i] = 0;
                }
                else if (i == k || j == k)
                {
                    mat[i][j] = mat[i][j];
                }
                else
                {
                    int val = mat[i][k] + mat[k][j];
                    if (mat[i][k] == 0 || mat[k][j] == 0)
                    {
                        val = 0;
                    }
                    mat[i][j] = min(mat[i][j], val);
                }
            }
        }
    }

    if (mat[source][target] == IN) {
        return -1;
    }
    return mat[source][target];
}