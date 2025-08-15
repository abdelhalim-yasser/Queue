package mypackage;
import java.util.Random;



// Circular Queue Class
class Queue{
    protected int size;
    protected int rear;
    protected int front;
    protected int[] array;
    
    // Define the Queue
    public Queue(int size){
        this.rear = -1;
        this.front = -1;
        this.size = size;
        this.array = new int[size];
    }
    
    // Insertion functions
    // Queue enqueue function to append the element in the queue
    public void enqueue(int data){
        if(isEmpty()){
            System.out.println("Queue overflow.");
            return;
        }
        
        if(isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % size;

        array[rear] = data;
    }
    
    // Deletion functions
    // Queue dequeue function to delete the first element in the queue
    public int dequeue(){
        if(!isEmpty()){
            System.out.println("Queue underflow.");
            System.exit(0);
        }
        
        int data = array[front];
        
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        
        return data;
    }
    
    // Queue clear function to clear all the queue elements
    public void clear(){
        front = rear = -1;
    }
    
    // Search functions
    // Queue getFront to get the front of the Queue
    public int getFront(){
        if(!isEmpty()){
            System.out.println("Queue is Empty");
            System.exit(0);
        }
        
        return front;
    }
    
    // Queue getRear to get the rear of the Queue
    public int getRear(){
        if(!isEmpty()){
            System.out.println("Queue is Empty");
            System.exit(0);
        }
        
        return rear;
    }
    
    // Queue getMiddle to get the middle of the Queue
    public int getMiddle(){
        if(!isEmpty()){
            System.out.println("Queue is Empty");
            System.exit(0);
        }
        
        return (front + rear)/2;
    }
    
    // Queue getSize to get the size of the Queue
    public int getSize(){
        if(!isEmpty()){
            System.out.println("Queue is Empty");
            System.exit(0);
        }
        
        return rear - front;
    }
    
    // // Queue getElement to get the specific element from the index in the Queue
    // public int getElement(int index){
        
    // }
    
    // // Queue getIndex to get the index of specific element in the Queue
    // public int getIndex(int element){
        
    // }
    
    // // Queue isFound to check the Queue's element is found or not
    // public boolean isFound(){
        
    // }
    
    // Queue isEmpty to check if the queue is empty
    public boolean isEmpty() 
    {
        return front == -1 && rear == -1;
    }
}
