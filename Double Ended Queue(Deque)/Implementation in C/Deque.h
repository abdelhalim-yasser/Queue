#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#define CAPACITY 10

// Implementation of Deque using circular array
// Define the Deque
typedef struct{
    int front;                // The front of the Deque
    int rear;                // The rear of the Deque
    int size;               // The size index of the Deque
    int array[CAPACITY];        // The circular array of the Deque
}Deque;


// Create the Deque
void createDeque(Deque* deque);



// Insertation functions
// Deque insertFront to insert at the front of the Deque
void insertFront(int data);

// Deque insertRear to insert at the rear of the Deque
void insertRear(int data);




// Deletion functions
// Deque deleteFront to delete the front of the Deque
int deleteFront();

// Deque deleteRear to delete the rear of the Deque
int deleteRear();

// Deque clear to clear the Queue
void clear(); 




// Search functions
// Deque getFront to get the front of the Deque
int getFront();

// Deque getRear to get the rear of the Deque
int getRear();

// Deque getMiddle to get the middle element of the Deque
public int getMiddle();

// Deque isFound function to check is the element found
bool isFound(int data);

// Deque getIndex function to get the index of specific element
int getIndex(int element);

// Deque getElement function to get an element in specific index
int getElement(int index);

// Deque isFull to check is the Queue is full or not
bool isFull();

// Deque isEmpty to check is the Queue is Empty or not
bool isEmpty();




// Stats functions
// Deque getSize to get the size of the Queue
int getSize();

// Deque sum function to get the sum of the Queue
int sum();

// Deque average function to get the average of the Queue
float average();

// Deque repeated function to return number of repetion of num in the Queue
int repeated(int data);

// Deque max function to return the maxmuim num
int max();

// Deque min function to return the minimuim num
int min();



//Utilities functions
// Deque printDeque function to print all the Queue elements
void printDeque();

// Deque removeDuplicates function to remove the duplictaes in the Queue
void removeDuplicates();

// Deque reverse function to reverse the Queue
void reverse();

// Deque sort function to sort the Queue
void sort();

// Deque randomize to randomize the Queue
void randomize();

// Deque swapData to swap two elements in the Queue
void swapData(int data1, int data2);

// Deque swapIndex to swap the elements in the given index in the Queue
void swapIndex(int index1, int index2);



#endif // DEQUE_H_INCLUDED
