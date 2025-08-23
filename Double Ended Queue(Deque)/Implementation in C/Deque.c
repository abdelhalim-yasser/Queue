#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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
	deque->rear = 0;
	deque->size = 0;
	deque->front = -1;
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
int deleteFront(Deque* deque) {
	if(deque->size == 0) {
		printf("Deque Underflow\n");
		return -999;
	}

	int data = deque->array[deque->front];

	if(deque->size == 1) {
		deque->front = -1;
		deque->rear = 0;
	}
	else
		deque->front = (deque->front + 1) % CAPACITY;

	deque->size--;

	return data;
}

// Deque deleteRear to delete the rear of the Deque
int deleteRear(Deque* deque) {
	if(deque->size == 0) {
		printf("Deque Underflow.\n");
		return -999;
	}

	int data = deque->array[deque->rear];

	if(deque->size == 1) {
		deque->rear = 0;
		deque->front = -1;
	}
	else
		deque->rear = (deque->rear + CAPACITY - 1) % CAPACITY;

	deque->size--;

	return data;
}

// Deque clear to clear the Queue
void clear(Deque* deque) {
	deque->size = 0;
	deque->rear = 0;
	deque->front = -1;
}




// Search functions
// Deque getFront to get the front of the Deque
int getFront(Deque* deque) {
	if(deque->size == 0)
		return -999;

	return deque->array[deque->front];
}

// Deque getRear to get the rear of the Deque
int getRear(Deque* deque) {
	if(deque->size == 0)
		return -999;

	return deque->array[deque->rear];
}

// Deque getMiddle to get the middle element of the Deque
int getMiddle(Deque* deque) {
	if(deque->size == 0)
		return -999;

	int middle = (deque->front + (deque->size - 1) / 2) % CAPACITY;

	return deque->array[middle];
}

// Deque isFound function to check is the element found
bool isFound(Deque* deque, int data) {
	if(deque->size == 0)
		return false;

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		if(deque->array[index] != data)
			return false;
	}

	return true;
}

// Deque getIndex function to get the index of specific element
int getIndex(Deque* deque, int element) {
	if(deque->size == 0)
		return -1;

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		if(deque->array[index] == element)
			return i;
	}

	return -1;
}

// Deque getElement function to get an element in specific index
int getElement(Deque* deque, int index) {
	if(deque->size == 0 || index < 0 || index >= deque->size)
		return -999;

	int currentIndex = (deque->front + index) % CAPACITY;

	return deque->array[currentIndex];
}

// Deque isFull to check is the Queue is full or not
bool isFull(Deque* deque) {
	return deque->size == CAPACITY;
}

// Deque isEmpty to check is the Queue is Empty or not
bool isEmpty(Deque* deque) {
	return deque->size == 0;
}




// Stats functions
// Deque getSize to get the size of the Queue
int getSize(Deque* deque) {
	return deque->size;
}

// Deque sum function to get the sum of the Queue
int sum(Deque* deque) {
	if(deque->size == 0)
		return -999;

	int sum = 0;

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		sum += deque->array[index];
	}

	return sum;
}

// Deque average function to get the average of the Queue
float average(Deque* deque) {
	if(deque->size == 0)
		return -999;

	int sum = 0;

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		sum += deque->array[index];
	}

	return sum / deque->size;
}

// Deque repeated function to return number of repetion of num in the Queue
int repeated(Deque* deque, int data) {
	if(deque->size == 0)
		return -999;

	int count = 0;

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		if(deque->array[index] == data)
			count++;
	}

	return count;
}

// Deque max function to return the maxmuim num
int max(Deque* deque) {
	if(deque->size == 0)
		return -999;

	int max = deque->array[deque->front];

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		if(max < deque->array[index])
			max = deque->array[index];
	}

	return max;
}

// Deque min function to return the minimuim num
int min(Deque* deque) {
	if(deque->size == 0)
		return -999;

	int min = deque->array[deque->front];

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		if(min > deque->array[index])
			min = deque->array[index];
	}

	return min;
}




//Utilities functions
// Deque printDeque function to print all the Queue elements
void printDeque(Deque* deque) {
	if(deque->size == 0) {
		printf("Deque is Empty.\n");
		return;
	}

	for(int i = 0; i < deque->size; i++) {
		int index = (deque->front + i) % CAPACITY;
		printf("[%d] -> %d\n", i, deque->array[index]);
	}
}

// Deque sort function to sort the Queue
void sort(Deque* deque) {
	if(deque->size == 0)
		return;

	bool swapped;

	for(int i = 0; i < deque->size; i++) {
		swapped = false;
		for(int j = 0; j < deque->size - i; i++) {
			int index = (deque->front + j) % CAPACITY;
			int nextIndex = (deque->front + j + 1) % CAPACITY;

			if(deque->array[nextIndex] > deque->array[index]) {
				int temp = deque->array[index];
				deque->array[index] = deque->array[nextIndex];
				deque->array[nextIndex] = temp;
				swapped = true;
			}
		}

		if(!swapped)
			break;
	}
}

// Deque removeDuplicates function to remove the duplictaes in the Queue
void removeDuplicates(Deque* deque) {
    if (deque->size <= 1) {
        return;
    }
    
    sort(deque);
    int temp[CAPACITY];
    int j = 0;
    temp[j] = deque->array[deque->front];
    j++;
    
    for (int i = 1; i < deque->size; i++) {
        int index = (deque->front + i) % CAPACITY;
        if (deque->array[index] != temp[j - 1]) {
            temp[j++] = deque->array[index];
        }
    }
    
    clear(deque);
    
    for (int i = 0; i < j; i++)
        insertRear(deque, temp[i]);
}

// Deque reverse function to reverse the Queue
void reverse(Deque* deque) {
	if(deque->size == 0)
		return;

	for(int i = 0; i < (deque->size) / 2; i++){
	    int index = (deque->front + i) % CAPACITY;
	    int index2 = (deque->rear + CAPACITY - i) % CAPACITY;
	    int temp = deque->array[index];
	    deque->array[index] = deque->array[index2];
	    deque->array[index2] = temp;
	}
	
}

// Deque randomize to randomize the Queue
void randomize(Deque* deque) {
    if(deque->size == 0)
        return;
    
    srand(time(NULL));
    
    for (int i = deque->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int index = (deque->front + i) % CAPACITY;
        int randIndex = (deque->front + j) % CAPACITY;
        int temp = deque->array[index];
        deque->array[index] = deque->array[randIndex];
        deque->array[randIndex] = temp;
    }   
}

// Deque swapData to swap two elements in the Queue
bool swapData(Deque* deque, int data1, int data2) {
    if (deque->size == 0) {
        return false;
    }
    int index1 = -1, index2 = -1;
    for (int i = 0; i < deque->size; i++) {
        int index = (deque->front + i) % CAPACITY;
        if (deque->array[index] == data1 && index1 == -1) {
            index1 = index;
        } else if (deque->array[index] == data2 && index2 == -1) {
            index2 = index;
        }
    }
    if (index1 == -1 || index2 == -1) {
        return false;
    }
    int temp = deque->array[index1];
    deque->array[index1] = deque->array[index2];
    deque->array[index2] = temp;
    return true;
}

// Deque swapIndex to swap the elements in the given index in the Queue
bool swapIndex(Deque* deque, int index1, int index2) {
    if (deque->size == 0 || index1 < 0 || index1 >= deque->size || index2 < 0 || index2 >= deque->size)
        return false;
 
    int physicalIndex1 = (deque->front + index1) % CAPACITY;
    int physicalIndex2 = (deque->front + index2) % CAPACITY;
    
    int temp = deque->array[physicalIndex1];
    deque->array[physicalIndex1] = deque->array[physicalIndex2];
    deque->array[physicalIndex2] = temp;
    return true;
}















int main()
{
	Deque deque;
    createDeque(&deque);
    printf("=== Testing Basic Operations ===\n");
    
    // Test insertions
    insertRear(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 30);
    insertFront(&deque, 40);
    printDeque(&deque);  // Expected: Deque elements: 40 30 10 20
    printf("Size: %d\n", getSize(&deque));  // Expected: 4
    printf("Is empty? %d\n", isEmpty(&deque));  // Expected: 0
    printf("Is full? %d\n", isFull(&deque));    // Expected: 0
    
    // Test deletions
    printf("Delete front: %d\n", deleteFront(&deque));  // Expected: 40
    printf("Delete rear: %d\n", deleteRear(&deque));    // Expected: 20
    printDeque(&deque);  // Expected: Deque elements: 30 10
    printf("Size: %d\n", getSize(&deque));  // Expected: 2
    
    // Test clear
    clear(&deque);
    printDeque(&deque);  // Expected: Deque is empty
    printf("Is empty? %d\n", isEmpty(&deque));  // Expected: 1

    printf("\n=== Testing Search Operations ===\n");
    insertRear(&deque, 10);
    insertRear(&deque, 20);
    insertRear(&deque, 10);
    printDeque(&deque);  // Expected: Deque elements: 10 20 10
    printf("Front: %d\n", getFront(&deque));     // Expected: 10
    printf("Rear: %d\n", getRear(&deque));       // Expected: 10
    printf("Middle: %d\n", getMiddle(&deque));   // Expected: 20
    printf("Is 20 found? %d\n", isFound(&deque, 20));  // Expected: 1
    printf("Is 50 found? %d\n", isFound(&deque, 50));  // Expected: 0
    printf("Index of 20: %d\n", getIndex(&deque, 20)); // Expected: 1
    printf("Element at index 1: %d\n", getElement(&deque, 1)); // Expected: 20
    printf("Element at invalid index: %d\n", getElement(&deque, 5)); // Expected: Invalid index, -1

    printf("\n=== Testing Statistics ===\n");
    printf("Sum: %d\n", sum(&deque));             // Expected: 40
    printf("Average: %.2f\n", average(&deque));   // Expected: 13.33
    printf("Repeated 10: %d\n", repeated(&deque, 10)); // Expected: 2
    printf("Max: %d\n", max(&deque));             // Expected: 20
    printf("Min: %d\n", min(&deque));             // Expected: 10

    printf("\n=== Testing Utilities ===\n");
    removeDuplicates(&deque);
    printDeque(&deque);  // Expected: Deque elements: 10 20
    reverse(&deque);
    printDeque(&deque);  // Expected: Deque elements: 20 10
    sort(&deque);
    printDeque(&deque);  // Expected: Deque elements: 10 20
    printf("Swap data 10 and 20: %d\n", swapData(&deque, 10, 20)); // Expected: 1
    printDeque(&deque);  // Expected: Deque elements: 20 10
    printf("Swap indices 0 and 1: %d\n", swapIndex(&deque, 0, 1)); // Expected: 1
    printDeque(&deque);  // Expected: Deque elements: 10 20
    randomize(&deque);
    printf("After randomize:\n");
    printDeque(&deque);  // Expected: Random order (e.g., 20 10 or 10 20)

    printf("\n=== Testing Edge Cases ===\n");
    clear(&deque);
    printDeque(&deque);  // Expected: Deque is empty
    printf("Delete front on empty: %d\n", deleteFront(&deque)); // Expected: Deque Underflow, -1
    Deque fullDeque;
    createDeque(&fullDeque);
    insertRear(&fullDeque, 1);
    insertRear(&fullDeque, 2);
    insertRear(&fullDeque, 3);
    insertRear(&fullDeque, 4);
    insertRear(&fullDeque, 5);
    insertRear(&fullDeque, 6);
    insertRear(&fullDeque, 7);
    insertRear(&fullDeque, 8);
    insertRear(&fullDeque, 9);
    insertRear(&fullDeque, 10);
    printf("Is full? %d\n", isFull(&fullDeque)); // Expected: 1
    insertRear(&fullDeque, 11); // Expected: Deque Overflo

	return 0;
}
