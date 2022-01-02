#ifndef GRAPH_
#define GRAPH_

#include "nodes.h"
#include "edges.h"
// Graph

// --------------------------------------- //
void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode *head); //for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

int shortsPath(pnode head, int, int);
char *strrev(char *);

void adapter_cmd(char, pnode *head);

#endif
