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
        }

        if (in == 'B'){
            //fun2();
            break;
        }

        if (in == 'D'){
            break;
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