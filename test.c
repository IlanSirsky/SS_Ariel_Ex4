#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"

#define IN 99

edge *newEdge(int weight, pnode dest)
{
    edge *e = (edge *)malloc(sizeof(edge));
    if (e == NULL)
    {
        return NULL;
    }
    e->weight = weight;
    e->endpoint = dest;
    e->next = NULL;
    return e;
}

void insertLastE(pnode dest, int w, pnode *head)
{
    pedge e = (*head) -> edges;

    pedge ed = newEdge(w, dest);

    if(!e){
        (*head) -> edges = ed;
    }
    else{
        while (e -> next)
        {
            e = e -> next;
        }
        e -> next  = ed;
    }
}

void addEdge(int src, int dest, int w, pnode *head){
    pnode curr = *head;
    pnode nsrc = NULL;
    pnode ndest = NULL;

    while(curr){

        if(curr -> id == src){
            nsrc = curr;
        }
        if (curr -> id == dest){
            ndest = curr;
        }

        curr = curr -> next;
    }

    if(!nsrc || !ndest){
        return;
    }

    insertLastE(ndest, w, &nsrc);
}

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

node *newNode(int id)
{
    pnode p = (pnode)malloc(sizeof(node));
    p->id = id;
    p->next = NULL;
    p->edges = NULL;
    return p;
}

void insertLast(int id, pnode *head)
{
    pnode *p = head;
    while (*p)
        p = &((*p)->next);
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

void freeNodes(node **h){
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

/** strrev - reverse string, swaps src & dest each iteration.
*  Takes valid string and reverses, original is not preserved.
*  If str is valid, returns pointer to str, NULL otherwise.
*/
char *strrev (char *str)
{
    if (!str) { 
        fprintf (stderr, "%s() Error: invalid string\n", __func__); 
        return NULL; 
    }

    char *begin = str;
    char *end = *begin ? str + strlen (str) - 1 : begin;  /* ensure non-empty */
    char tmp;

    while (end > begin)
    {
        tmp = *end;
        *end-- = *begin;
        *begin++ = tmp;
    }

    return str;
}

int dijsktra(pnode *head ,int source,int target)
{

    pnode curr = *head;
    int N = 0;
    while(curr){
        curr = curr->next;
        N++;
    }

    int cost[N][N];

    memset(cost, IN, N*N*sizeof(int));

    curr = *head;
    while(curr){
        pedge ed = curr -> edges;
        while(ed){
            cost[curr->id][ed->endpoint->id] = ed->weight;
            ed = ed->next;
        }
        curr = curr ->next;
    }

    int dist[N],prev[N];
    int selected[N];
    memset(selected, 0, N*sizeof(int));
    int i,m,min,start,d,j;
    char path[N];
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
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
    while(start != -1 && start < N)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    return dist[target];
}

int main()
{
    pnode head = NULL;

    head = newNode(0);
    // printf("%d \n", head -> id);
    insertLast(1, &head);
    insertLast(2, &head);
    // deleteFromList(0, &head);
    pnode run = head;

    // addEdge(0,2,5,&head);
    // addEdge(1,0,10,&head);
    // addEdge(1,2,5,&head);

    addEdge(0,1,5,&head);
    addEdge(0,2,10,&head);
    addEdge(1,2,2,&head);

    // addEdge(1,2,7,&head);

    // run = head -> next;
    // insertLastE(head, 5, &run);

    // run = head;

    while(run){
        printf("Node{%d} -- Edges{", run -> id);

        pedge ed = run -> edges;

        while(ed){
            printf("%d -> %d -- %d,  ", run -> id, ed -> endpoint -> id, ed -> weight);
            ed = ed -> next;
        }
        run = run -> next;

        printf("}\n");
    }

    int dist = dijsktra(&head, 0,2);
    printf("DISTANCE = %d\n", dist);
}