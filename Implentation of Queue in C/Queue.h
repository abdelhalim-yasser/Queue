#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX 10

typedef struct
{
    int front;
    int rear;
    int size;
    entry array[MAX];
}Queue;


#endif // QUEUE_H_INCLUDED
