#ifndef nodes
#define nodes

typedef struct Node
{
    int dest;
    int id;
    struct Node *next;
} Node;

Node *newNode(int, Node *);
void insertLast(int, struct Node **);
void deleteFromList(int, Node **);


#endif