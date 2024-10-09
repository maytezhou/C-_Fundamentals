#ifndef STACK_H // These two lines and the last line are called preprocessor wrapper.
#define STACK_H // The class declaration is enclosed between ifndef and endif.
// This prevents a header file from being included many times.

class Stack {
public :
    Stack(int = 1, int = 0 , char* = NULL);
    void setSize(int);
    void createEmptyStack();
    void push (char );
    char pop();
    void reset();
    bool isFull();
    bool isEmpty();
private :
    int stackSize;
    int stackPtr;
    char* charStack;

};


#endif

