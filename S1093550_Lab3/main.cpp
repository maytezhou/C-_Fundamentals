/*Stack for evaluating balanced parenthesis */
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;
void CheckExpression(string str, Stack &S);

int main()
{   string str;
    int stackSize;
    int numberOfExpressions;
    Stack S; // creating stack object
    cin >> stackSize; // receiving the size from user
    S.setSize(stackSize);// setting size of the stack
    cin >> numberOfExpressions; // receiving the number of expressions to be evaluated from the user
    S.createEmptyStack(); // creating empty array which will be used to store the elements of the stack
    for (int i = 0 ; i < numberOfExpressions ; i ++ ){
        S.reset(); // for each expression  that is going to be evaluated the stack needs to be reset, and be empty again
        cin >> str;
        CheckExpression(str,S);
    }

    return 0;
}

void CheckExpression(string str, Stack &S) {

       int isEvaluated  =  0 ;
       for(int i = 0; i < str.length(); i++) {
		if( str[i] == '(' ){
            if (S.isFull()){
                cout << "stack full "  << endl;
                isEvaluated = 1 ;
                break;
            }
            if (!S.isFull()){// only if the stack is not full ,we can push an element into the stack
                S.push(str[i]);
            }
        }

		else if( str[i] == ')')
		{
			if( S.isEmpty()  ){
			 cout << " more ) \' s" << endl;
             isEvaluated = 1 ;
             break;

            }
            if (!S.isEmpty()){ // only if the stack is not empty ,we can pop an element from the stack
                S.pop();

            }


		}
	}


    if (!S.isEmpty() && isEvaluated == 0){
          cout << " more ( \' s" << endl;

	}
	if(S.isEmpty() && isEvaluated == 0 ){
          cout << "correct" << endl ;
	}


	return;
}


