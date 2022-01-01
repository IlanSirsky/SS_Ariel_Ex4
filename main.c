#include <stdio.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"


int main()
{
    pnode graph = NULL;
    char in = 1;
    while (scanf(" %c", &in) != EOF)
    {
        if (in == 'A'){
            build_graph_cmd(&graph);
            printGraph_cmd(&graph);
            continue;
        }

        if (in == 'B'){
            insert_node_cmd(&graph);
            continue;
        }

        if (in == 'D'){
            delete_node_cmd(&graph);
            continue;
        }

        if (in == 'S'){
            int src = 0, dst = 0;
            scanf("%d", &src);
            scanf("%d", &dst);
            printf("src = %d , dst = %d\n", src,dst);
            printf("%d\n",dijsktra(&graph,src,dst));
            continue;
        }

        if (in == 'T'){
            TSP_cmd(graph);
            continue;
        }

    }
    return 0;
}