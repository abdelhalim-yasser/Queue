// Implementation of Deque using circular array
class Deque {
	protected int size;            // The size index of the Deque
	protected int rear;           // The rear of the Deque
	protected int front;         // The front of the Deque
	protected int[] array;      // The array of the Deque
	protected int capacity;    // maxmuim size of the Deque

	// Constractor to create the Deque
	public Deque(int capacity) {
		this.size = 0;
		this.rear = 0;
		this.front = -1;
		this.capacity = capacity
		                this.array = new int[size];
	}

	// Insertation functions
	// Deque insertFront to insert at the front of the Deque
	public void insertFront(int data) {
		if(size == capacity) {
			System.out.println("Deque overflow.");
			return;
		}

		front = (front + capacity - 1) % capacity;
		array[front] = data;
		size++;
	}

	// Deque insertRear to insert at the rear of the Deque
	public void insertRear(int data) {
		if(size == capacity) {
			System.out.println("Deque overflow.");
			return;
		}

		rear = (front + size) % capacity;
		array[rear] = data;
		size++;
	}



	// Deletion functions
	// Deque deleteFront to delete the front of the Deque
	public int deleteFront() {
		if(size == 0) {
			System.out.println("Deque underflow.");
			return -1;
		}

		int data = array[front];
		front = (front + 1) % capacity;
		size--;

		return data;
	}

	// Deque deleteRear to delete the rear of the Deque
	public void insertRear() {
		if(size == 0) {
			System.out.println("Deque underflow.");
			return -1;
		}

		int data = array[rear];
		rear = (front + size - 1) % capacity;
		size--;

		return data;
	}

	// Deque clear to clear the Queue
	public void clear() {
		if(size == 0)
			return;

		size = rear = 0;
		front = -1;
	}


	// Search functions
	// Deque getFront to get the front of the Deque
	public int getFront() {
		if(size == 0)
			return -999;

		return array[front];
	}

	// Deque getRear to get the rear of the Deque
	public int getRear() {
		if(size == 0)
			return -999;

		return array[rear];
	}

	// Deque getMiddle to get the middle element of the Deque
	public int getMiddle() {
		if(size == 0)
			return -999;

		int middle = (front + (size - 1) / 2) % capacity;

		return array[middle];
	}

	// Deque isFound function to check is the element found
	public int isFound(int data) {
		if(size == 0)
			return false;

		for(int i = 0; i <= size; i++) {
			int index = (front + i) % capacity;
			if(array[index] == data)
				return true;
		}

		return false;
	}

	// Deque getIndex function to get the index of specific element
	public int getIndex(int element) {
		if(size == 0)
			return -1;

		for(int i = 0; i < size; i++) {
			int index = (front + i) % capacity;
			if(array[index] == element)
				return i;
		}

		System.out.println("Element not found");
		return -1;
	}

	// Deque getElement function to get an element in specific index
	public int getElement(int index) {
		if(size == 0 || index < 0 || index > size - 1))
			return -999;

			int currentIndex = (front + index) % capacity;

			return array[currentIndex];
		}

	// Deque isFull to check is the Queue is full or not
	public boolean isFull() {
		return size == capacity;
	}

	// Deque isEmpty to check is the Queue is Empty or not
	public boolean isEmpty() {
		return size == 0;
	}


	// Stats functions
	// Deque sum function to get the sum of the Queue
	public int sum() {
		if(size == 0)
			return -999;

		int sum = 0;

		for(int i = 0; i < size; i++) {
			int index = (front + i) % capacity;
			sum += array[index];
		}

		return sum;
	}

	// Deque average function to get the average of the Queue
	public double sum() {
		if(size == 0)
			return -999;

		return (double)sum() / size;
	}

	// Deque repeated function to return number of repetion of num in the Queue
	public int repeated(int data) {
		if(size == 0)
			return -1;

		int repeation = 0;

		for(int i = 0; i < size; i++) {
			int index = (front + i) % capacity;
			if(array[index] == data)
				repeation++;
		}

		return repeation;
	}

	// Deque max function to return the maxmuim num
	public int max() {
		if(size == 0)
			return -999;

		int max = array[front];

		for(int i = 0; i < size; i++) {
			int index = (front + i) % capacity;
			if(max < array[index])
				max = array[index];
		}

		return max;
	}

	// Deque min function to return the minimuim num
	public int min() {
		if(size == 0)
			return -999;

		int min = array[front];

		for(int i = 0; i < size; i++) {
			int index = (front + i) % capacity;
			if(min > array[index])
				min = array[index];
		}

		return min;
	}

	//Utilities functions
	// Deque print function to print all the Queue elements
	public void printQueue() {
		if(size == 0)
			return;

		for(int i = 0; i < size; i++) {
			int index = (front + i) % capacity;
			System.out.println("[" + i + "]" + " -> " + array[index]);
		}
	}

	// Deque removeDuplicates function to remove the duplictaes in the Queue
	public void removeDuplicates() {
		if(size == 0)
			return;

		int j = 0;
		int[] temp = new int[capacity];
		temp[capacity] = array[front];
		j++;

		for(int i = 0; i < size; i++) {
			int index = (front + i) % capacity;
			if(array[index] != temp[j - 1])
				temp[j++] == array[index];
		}


		array = temp;
	}

	// Deque reverse function to reverse the Queue
	public void reverse() {
		if(size == 0)
			return;
		
		sort();
		
		for(int i = 0; i < (size / 2); i++){
		    int index = (front + i) % capacity;
		    
		}
	}

	// Deque sort function to sort the Queue
	public void sort() {
		if(size == 0)
			return;
		
		boolean swapped;
			
		for(int i = 0; i < size; i++){
		    swapped = false;
		    
		    for(int j = i - 1; i < size - i; i++){
		        int index = (front + j) % capacity;
		        int nextIndex = (front + j + 1) % capacity;
		        
		        if(array[index] > array[nextIndex]){
		            int temp = array[index];
		            array[index] = array[nextIndex];
		            array[nextIndex] = temp;
		            swapped = true;
		        }
		    }
		    
		    if(!swapped)
		      break;
		}	
	}

	// Deque randomize to randomize the Queue
	public void randomize() {
		if(size == 0)
			return;
	}
}
