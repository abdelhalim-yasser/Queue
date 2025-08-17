package mypackage;


// Implementation of the Queue
public class Queue {
	protected int[] arr;
	protected int capacity;
	protected int front;
	protected int rear;
	protected int size;

	// Constructor that defines the Queue
	public Queue(int capacity) {
		this.capacity = capacity;
		arr = new int[capacity];
		front = 0;
		rear = -1;
		size = 0;
	}


	// Queue Basic Functions
	// Queue enqueue function that add element in the last index
	public void enqueue(int data) {
		if (isFull()) {
			System.out.println("Queue overflow.");
			return;
		}

		rear++;
		arr[rear] = data;
		size++;
	}

	// Queue dequeue function that returns and remove the first element
	public int dequeue() {
		if (isEmpty()) {
			System.out.println("Queue underflow.");
			return -1;
		}

		int data = arr[front];
		front++;
		size--;
		return data;
	}

	// Queue clear function to clear the Queue
	public void clear() {
		front = size = 0;
		rear = -1;
	}

	// Queue peek function that returns the first(front) element
	public int peek() {
		if (isEmpty())
			return -1;

		return arr[front];
	}

	// Check if queue is full
	public boolean isFull() {
		return size == capacity;
	}

	// Check if queue is empty
	public boolean isEmpty() {
		return size == 0;
	}


	// Queue printQueue function that prints all Queue elements
	public void printQueue() {
		if (isEmpty())
			return;

		System.out.print("Queue elements: ");
		for (int i = front; i <= rear; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}
