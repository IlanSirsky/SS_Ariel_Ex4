#ifndef GRAPH_
#define GRAPH_

// Edge
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

edge *addEdge(int, pnode, edge *);
void insertLast(int, struct edge **);
void deleteFromList(int, edge **);
void freeEdges(edge **);

// Node
typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

node *newNode(int, node *);
void insertLast(int, struct node **);
void deleteFromList(int, node **);
void freeNodes(node **);

// Graph
// --------------------------------------- //

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
