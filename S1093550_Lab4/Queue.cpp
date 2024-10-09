#include<iostream>
#include<cstdlib>
#include "Queue.h"
using namespace std;

Queue::Queue(int sz, int front, int rear, int count,int * intQueue ){
    size = sz; //size = 10
    front = front; // initializes front = 0
    rear = rear;  // initializes rear = 0
    count = count ;  // initializes count = 0
    this->intQueue = new int[sz]; // there is a name collision between the name of the parameter  and the name of the private data, to avoid it we use this->
    cout << "A queue of size " << size << " is created." << endl;

}

 Queue:: ~Queue(){
    cout << "A queue of size " << size << " is destroyed." << endl;
};

void Queue :: createQueue (){
    intQueue = new int[size];
}

void Queue :: setQueueSize (int queueSize){
    size =  queueSize;

}

void Queue :: enqueue(int newItem){

    if (!isFull () ){ // only  if the queue  is not full, we can insert an element
        if ( isEmpty() ){ //  if the list is empty insert the first element , here also count should be = 0  front = 0 rear = 0

                intQueue[rear] = newItem ;
                count ++;

        }else{ // insert an element

                rear++;
                intQueue [rear ] = newItem;
                count ++ ;
        }
    }


}

int Queue:: dequeue() {
    int elementToBeDeleted;
    if (!isEmpty () ){ //  only if the queue is not empty we can delete an element
        if ( front == rear){ //  if there is only one element in the list
            elementToBeDeleted = intQueue[front] ;
            front++ ; // front > rear // delete an element
            count --; // decrease number of elements in the queue

        }else{ // if there are more elements in the queue
          elementToBeDeleted = intQueue[front] ;
          front++ ; // delete an element
          count -- ; // decrease number of elements in the queue

        }
    }
 return elementToBeDeleted;
}



int Queue:: peek(){
   int peek;
   if (!isEmpty()){
     peek = intQueue [front];
   }
   return peek;
}

int Queue:: getCount(){

  return count;


}


int Queue:: getSize(){
  return size;
}

bool Queue:: isEmpty(){
  bool isEmpty;
  if ( count == 0 ){
      isEmpty = true;
  }else{
      isEmpty = false;
  }
  return isEmpty;
}

bool Queue:: isFull(){
    bool isFull;

    if (count  == size ){
         isFull = true;

    }else{
        isFull = false;
    }
    return isFull;
}

void Queue:: clearQueue () {

    front = 0;
    rear = 0;
    count = 0 ;


}


void Queue:: printQueue(){

   if (!isEmpty()){// only if the queue is not empty, we can display
    if (front > rear){ // a[7],...a[10],a[0],a[1],a[2]
        for (int i = front ; i < size ; i ++ ){ // to print from front to the final element a[7],...a[10]
                cout <<  intQueue[i] << ' ';

        }

         for (int i = 0 ; i <= rear ; i ++ ){ // to print from the beginning to rear   a[0],a[1],a[2]
                cout <<  intQueue[i] << ' ';

        }
    }else {
     for (int i = front ; i < rear +1  ; i ++){
        cout <<  intQueue[i] << ' ';
    }

    }


   }
   cout << endl;


}
