#ifndef edgesh
#define edgesh

typedef struct node_ node, *pnode;

// Edge
typedef struct edge_
{
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

edge *newEdge(int, int, edge *, pnode *);
void insertLastE(int, edge **, int, pnode *);
void freeEdges(edge **);

#endif