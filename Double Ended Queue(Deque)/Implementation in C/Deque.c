#include <stdio.h>
#include <stdbool.h>
#define CAPACITY 10

// Implementation of Deque using circular array
// Define the Deque
typedef struct {
	int front;                // The front of the Deque
	int rear;                // The rear of the Deque
	int size;               // The size index of the Deque
	int array[CAPACITY];   // The circular array of the Deque
} Deque;



// Create the Deque
void createDeque(Deque* deque) {
	rear = 0;
	size = 0;
	front = -1;
}




// Insertation functions
// Deque insertFront to insert at the front of the Deque
void insertFront(Deque* deque, int data) {
	if(deque->size == CAPACITY) {
		printf("Deque Overflow.\n");
		return;
	}

	if(deque->size == 0)
		deque->front++;
	else
		deque->front = (deque->front + CAPACITY - 1) % CAPACITY;

	deque->array[deque->front] = data;
	deque->size++;
}

// Deque insertRear to insert at the rear of the Deque
void insertRear(Deque* deque, int data) {
	if(deque->size == CAPACITY) {
		printf("Deque Overflow.\n");
		return;
	}

	if(deque->size == 0)
		deque->front = deque->rear = 0;
	else
		deque->rear = (deque->rear + 1) % CAPACITY;

	deque->array[deque->rear] = data;
	deque->size++;
}




// Deletion functions
// Deque deleteFront to delete the front of the Deque
int deleteFront(Deque* deque){
    if(deque->size == CAPACITY){
        printf("Deque Underflow\n");
        return;
    }
    
    int data = deque->array[deque->front];
    
    if(size == 1){
        front = -1;
        rear = 0;
    }
    else
        deque->front = (deque->front + 1) % CAPACITY;
    
    deque->size--;
    
    return data;
}

// Deque deleteRear to delete the rear of the Deque
int deleteRear(Deque* deque){
    if(deque->size == CAPACITY){
        printf("Deque Underflow.\n");
        return;
    }
    
    int data = deque->array[deque->rear];
    
    if(deque->size == 1){
        deque->rear = 0;
        deque->front = -1;
    }
    else
        deque->rear = (deque->rear + CAPACITY - 1) % CAPACITY;
        
    deque->size--;
    
    return data;
}

// Deque clear to clear the Queue
void clear(Deque* deque){
    deque->size = 0;
    deque->rear = 0;
    deque->front = -1;
}




// Search functions
// Deque getFront to get the front of the Deque
int getFront(Deque* deque){
    if(size == CAPACITY)
        return -999;
        
    return deque->array[deque->front];
}

// Deque getRear to get the rear of the Deque
int getRear(Deque* deque){
    if(size == CAPACITY)
        return -999;
        
    return deque->array[deque->rear];    
}

// Deque getMiddle to get the middle element of the Deque
public int getMiddle(Deque* deque){
    if(size == CAPACITY)
        return -999;
    
    int middle = (deque->front + (deque->size - 1) / 2) % CAPACITY;
    
    return deque->array[middle];
}

// Deque isFound function to check is the element found
bool isFound(Deque* deque, int data){
    if(size == 0)
        return false;
    
    for(int i = 0; i < deque->size; i++){
        index = (deque->front + i) % CAPACITY;
        if(deque->array[index] != data)
            return false;
    }
    
    return true;
}

// Deque getIndex function to get the index of specific element
int getIndex(Deque* deque, int element){
    if(deque->size == 0)
        return -1;
        
    for(int i = 0; i < deque->size; i++){
        int index = (deque->front + i) % CAPACITY;
        if(deque->array[index] == element)
            return i;
    }
    
    return -1;
}

// Deque getElement function to get an element in specific index
int getElement(Deque* deque, int index){
    if(deque->size == 0 || index < 0 || index >= deque->size)
        return -999;
    
    int currentIndex = (deque->front + index) % CAPACITY;
    
    return deque->array[currentIndex];
}

// Deque isFull to check is the Queue is full or not
bool isFull(Deque* deque){
    return deque->size == CAPACITY;
}

// Deque isEmpty to check is the Queue is Empty or not
bool isEmpty(Deque* deque){
    return deque->size == 0;
}




// Stats functions
// Deque getSize to get the size of the Queue
int getSize(Deque* deque)

// Deque sum function to get the sum of the Queue
int sum(Deque* deque)

// Deque average function to get the average of the Queue
float average(Deque* deque)

// Deque repeated function to return number of repetion of num in the Queue
int repeated(Deque* deque, int data)

// Deque max function to return the maxmuim num
int max(Deque* deque)

// Deque min function to return the minimuim num
int min(Deque* deque)




//Utilities functions
// Deque printDeque function to print all the Queue elements
void printDeque(Deque* deque)

// Deque removeDuplicates function to remove the duplictaes in the Queue
void removeDuplicates(Deque* deque)

// Deque reverse function to reverse the Queue
void reverse(Deque* deque)

// Deque sort function to sort the Queue
void sort(Deque* deque)

// Deque randomize to randomize the Queue
void randomize(Deque* deque)

// Deque swapData to swap two elements in the Queue
void swapData(Deque* deque, int data1, int data2)

// Deque swapIndex to swap the elements in the given index in the Queue
void swapIndex(Deque* deque, int index1, int index2)
