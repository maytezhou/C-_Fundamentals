#ifndef QUEUE_H
#define QUEUE_H


class Queue{
public:
    Queue(int = 10, int = 0 , int = 0 , int = 0 ,int * = NULL ); // constructor with queue size initialized to 10
    ~Queue();// destructor
    void createQueue ();
    void setQueueSize (int);
    void enqueue(int); // Insert an element in the rear end of a queue
    int dequeue(); //  delete the front most element and return it
    int peek(); // return the front most element in the queue
    int getCount(); // return the number of elements stored in the queue
    int getSize(); // return queue size
    bool isEmpty(); // return true if queue is empty
    bool isFull(); // return true if queue is full
    void clearQueue(); // clear the content of queue and reset front, rear, and count
    void printQueue(); // print the content of a queue from front to rear.
private :
    int size;
    int front;
    int rear;
    int count;
    int *intQueue;
};

#endif



























