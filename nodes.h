#ifndef nodes
#define nodes

typedef struct edge_ edge, *pedge;

// Node
typedef struct node_
{
    int id;
    pedge edges;
    struct node_ *next;
} node, *pnode;

node *newNode(int, node *);
void insertLastN(int, pnode *);
void deleteFromListN(int, node **);
void freeNodes(node **);

#endif