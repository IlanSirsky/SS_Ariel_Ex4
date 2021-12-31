#ifndef GRAPH_
#define GRAPH_

#include "nodes.h"
#include "edges.h"
// Graph
// typedef struct graph_{
//     struct node * head;
//     void (*build_graph_cmd)(pnode *head);
//     void (*insert_node_cmd)(pnode *head);
//     void (*delete_node_cmd)(pnode *head);
//     void (*printGraph_cmd)(pnode head);
//     void (*deleteGraph_cmd)(pnode* head);
//     void (*shortsPath_cmd)(pnode head);
//     void (*TSP_cmd)(pnode head);
// } graph;
// --------------------------------------- //
void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
