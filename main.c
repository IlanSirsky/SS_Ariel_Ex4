#include <stdio.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"

int main()
{
    pnode graph = NULL;
    char in;
    while (scanf(" %c", &in) != EOF){
        adapter_cmd(in, &graph);
    }
    freeNodes(&graph);
    return 0;
}