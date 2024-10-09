#include <iostream>
#include <cstdlib>
#include "Stack.h"
using namespace std;

Stack::Stack(int stackSize,int stackPtr, char* charStack){ // constructor that initializes the Stack
    stackSize = stackSize; // initializes stackSize = 1
    stackPtr = stackPtr; // initializes stackPtr = 0
    charStack = charStack; //  initializes  char* charStack = NULL;
}

void Stack::setSize( int sizeStack ) {
    stackSize = sizeStack ;//  setting StackSize to the value enter by the user

}

void Stack :: createEmptyStack(){
    charStack = new char[stackSize]; // creating the  empty array dynamically
}


void Stack :: push(char ch){
    charStack[stackPtr] = ch;// 0  1 2  3   pushing each element inside the array
    stackPtr ++ ;//1 2 3 4 // incrementing the number of elements in the array
}


char Stack :: pop (){
    char ch;
    if(!isEmpty()){
       ch = charStack [stackPtr]; //  represents the element to be deleted
       stackPtr -- ; //  decrementing the numbers of elements in the array
    }
    return ch; // returns the element that was deleted
}

void Stack :: reset (){
    stackPtr = 0 ; // when stackPtr is = 0 , it means  the stack is empty
}

bool Stack :: isFull (){
    bool isFull;
    if (stackPtr == (stackSize) ){
        isFull = true;
    }else{
        isFull = false;
    }
    return isFull;
}

bool Stack :: isEmpty (){
    bool isEmpty;
    if (stackPtr == 0 ) {
        isEmpty = true;
    }else{
        isEmpty = false;
    }
    return isEmpty;
}
