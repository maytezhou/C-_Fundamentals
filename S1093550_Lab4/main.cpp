/* Program for  Task rescheduling */
#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;

int main()
{
   int sizeQueue;
   int testCases;
   int numberOfTasks;
   int idealOrder;
   int arrivingOrder;

   cin >> sizeQueue;// receiving the size from user

   Queue Q(sizeQueue); // creating the Ideal Queue object
   Queue W(sizeQueue); // creating the Waiting List Queue object

   cin >> testCases; // receiving number of test cases
   for (int i = 0 ; i < testCases; i ++){
        Q.clearQueue() ;// for each  test case that is going to be evaluated the  ideal Queue needs to be reset, and be empty again
        W.clearQueue(); // for each  test case that is going to be evaluated the  waiting Queue needs to be reset, and be empty again

        cin >> numberOfTasks; // receiving the number of tasks for each test case
        for (int j = 0 ; j < numberOfTasks ; j ++){
            cin >> idealOrder;
            Q.enqueue(idealOrder);


        }

        for (int k = 0 ; k < numberOfTasks ; k ++){
            cin >> arrivingOrder;
            W.enqueue(arrivingOrder);


        }

        int time = 0 ;
        int elementDeleted ;
        cout << "Test " << i +1 << ":" << endl ;

        while ( !Q.isEmpty() && !W.isEmpty()){  // while both Queues are  not empty
                if ( Q.peek() == W.peek()){ // if the front elements of both lists are the same, execute the task and delete it from both queues
                        time = time + 2 ;  // takes only  2 seconds  for execution
                        Q.dequeue(); // the element is deleted from ideal list
                        W.dequeue(); // the element is deleted from Waiting list

                }else { //it means Q front and W front are different
                        time ++ ; // it takes 1 second to reschedule
                        elementDeleted =  W.dequeue(); // deletes the element in the front of waiting list and returns it
                        W.enqueue(elementDeleted); // inserting the element deleted at the rear - rescheduling
                        W.printQueue();
                }

        }
        cout << time << endl;



    }



}
