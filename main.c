#include <stdio.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"

pnode *graph;

int main()
{
    char in = 1;
    while (in != 'D')
    {
        scanf(" %c", &in);
        switch (in)
        {
        case 'A':
            build_graph_cmd(graph);
            break;

        case 'B':
            //fun2();
            break;

        case 'C':
            //fun3();
            break;

        case 'D':
            break;

        // command doesn't match any case constant A, B, C, D
        default:
            printf("Error! command isn't correct \n");
        }
    }
    return 0;
}