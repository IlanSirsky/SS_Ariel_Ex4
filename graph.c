#include <stdio.h>
#include "graph.h"


void build_graph_cmd(pnode *head){
    freeNodes(head);
    int count = 0;
    scanf("%d", &count);
    if(count > 0){
        *head = (pedge)malloc(sizeof(node));
    }
    pnode curr = *head;
    for(int i = 0; i<count; i++){
        pnode nd = (pnode)malloc(sizeof(node));
        nd->node_num = i;
        nd->edges = (pnode)malloc(sizeof(edge));
        curr -> next = nd;
        curr = nd;
    }
}

void insert_node_cmd(pnode *head){
}

void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);