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

edge *newEdge(int , pnode);
void insertLastE(pnode, int , pnode *);
void deleteFromListE(int, pedge *);
void addEdge(int, int, int, pnode *);
void freeEdges(pedge *);
void addEdge(int , int , int , pnode *);

#endif