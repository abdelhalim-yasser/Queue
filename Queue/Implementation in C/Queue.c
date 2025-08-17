
#include <stdio.h>
#include <stdbool.h>
#define capacity 10

typedef struct{
    int front;
    int rear;
    int capacity;
    int array[capacity];
}Queue;

// Queue Basic Functions
// Queue createQueue function to creat the Queue
void createQueue(&queue){
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// Queue isFull function to check if queue is full
bool isFull(&queue){
    return queue->size = capacity;
}

// Queue isEmpty function to check if queue is empty
bool isEmpty(&queue){
    return size == 0;
}

// Queue enqueue function that add element in the last index
void enqueu(int data, &queue){
    if (isFull()) {
		printf("Queue overflow.\n");
		return;
	}
    
    queue->rear++;
    queue->array[rear] = data;
    queue->size++;
}

// Queue dequeue function that returns and remove the first element
void dequeue(&queue){
    if (isEmpty()) {
		printf("Queue underflow.\n");
		return;
	}
	
	int data = array[front];
	queue->front++;
	queue->size--;
	
	return data;
}

// Queue clear function to clear the Queue
void clear(&queue){
    queue->front = queue->size = 0;
    queue->rear = -1;
}

// Queue peek function that returns the first(front) element
void peek(&queue){
    if (isEmpty())
		return;
	
    return queue->array[front];
}



// Queue printQueue function that prints all Queue elements
void printQueue(&queue){
    if (isEmpty())
		return;
		
	for (int i = queue->front; i <= queue->rear; i++)
		printf("[%d] -> %d", i, queue->array[i]);
}


int main()
{
    printf("Hello World");

    return 0;
}
